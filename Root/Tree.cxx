#include "RAnalysis/Tree.h"

#include "TROOT.h"
#include "TTreeReader.h"
#include "TTreeReaderValue.h"
#include "TTreeReaderArray.h"

#include "ana/strutils.h"
#include "ana/vecutils.h"
#include "ana/sample.h"

Tree::Tree(const std::string& treeName, const std::vector<std::string>& allFiles) :
	m_treeName(treeName),
	m_allFiles(allFiles)
{
	ROOT::EnableThreadSafety();
	ROOT::EnableImplicitMT();
}

ana::input::partition Tree::allocate()
{
	TDirectory::TContext c;
	ana::input::partition parts;

	// offset to account for global entry position
	long long offset = 0ll;
	size_t islot=0;
	for (const auto& filePath : m_allFiles) {
		// check file
		std::unique_ptr<TFile> file(TFile::Open(filePath.c_str()));
		if (!file) {
			continue;
		} else if (file->IsZombie()) {
			continue;
		}

		// check tree
		auto tree = file->Get<TTree>(m_treeName.c_str());
		if (!tree) {
			continue;
		}

		// tree good
		m_goodFiles.push_back(filePath);

		// add tree clusters
		auto fileEntries = tree->GetEntries();
		auto clusterIterator = tree->GetClusterIterator(0);
		long long start = 0ll, end = 0ll;
		while ( (start=clusterIterator.Next())<fileEntries ) {
			end = clusterIterator.GetNextEntry();
			parts.add(islot++, offset+start, offset+end);
		}
		// remember offset for next file
		offset += fileEntries;
	}

	return parts;
}

std::shared_ptr<Tree::Reader> Tree::open(const ana::input::range& part) const
{
	auto tree = std::make_unique<TChain>(m_treeName.c_str(),m_treeName.c_str());
	tree->ResetBit(kMustCleanup);
	for (auto const& filePath : m_goodFiles) {
		tree->Add(filePath.c_str());
	}
	return std::make_shared<Reader>(part,std::move(tree));
}

Tree::Reader::Reader(const ana::input::range& part, std::unique_ptr<TTree> tree) :
	ana::input::reader<Reader>(part),
	m_tree(std::move(tree))
{
	m_treeReader = std::make_unique<TTreeReader>(m_tree.get());
}

void Tree::Reader::begin()
{
	m_treeReader->SetEntriesRange(m_part.begin,m_part.end);
}

bool Tree::Reader::next()
{
	return m_treeReader->Next();
}
