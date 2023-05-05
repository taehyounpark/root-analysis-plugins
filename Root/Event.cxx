#include "RAnalysis/Event.h"

#include "TROOT.h"

#include "xAODCutFlow/CutBookkeeper.h"
#include "xAODCutFlow/CutBookkeeperContainer.h"
#include "xAODCutFlow/CutBookkeeperAuxContainer.h"

Event::Event(const std::vector<std::string>& inputFiles, const std::string& collection, const std::string& metadata) :
	m_inputFiles(inputFiles),
	m_treeName(collection),
	m_metaName(metadata)
{
	ROOT::EnableThreadSafety();
	xAOD::Init().ignore();
}

double Event::normalize() const
{
	return 1.0;  // can (should?) normalize xAOD::CutBookkeeper sumOfWeights
}

ana::input::partition Event::allocate()
{
	TDirectory::TContext c;

	ana::input::partition parts;
	unsigned int ipart = 0;
	long long offset = 0;

	// check all files for tree clusters
	for (const auto& filePath : m_inputFiles) {

		// check file
		auto file = std::unique_ptr<TFile>(TFile::Open(filePath.c_str()));
		if (!file) {
			continue;
		} else if (file->IsZombie()) {
			continue;
		}

		// check tree
		auto tree = file->Get<TTree>(m_treeName.c_str());
		auto event = std::make_unique<xAOD::TEvent>();
		if (!tree || event->readFrom(tree).isFailure()) {
			continue;
		}

		// get file entries
		long long fileEntries = event->getEntries();
		// add part to parts
		m_goodFiles.push_back(filePath);
		parts.add_part(ipart++,offset,offset+fileEntries);
		offset += fileEntries;
	}

	return parts;
}

std::shared_ptr<Event::Loop> Event::open(const ana::input::range& part) const 
{
	auto tree = std::make_unique<TChain>(m_treeName.c_str(),m_treeName.c_str());
	for (auto const& filePath : m_goodFiles) {
		tree->Add(filePath.c_str());
	}
	tree->ResetBit(kMustCleanup);
	return std::make_shared<Loop>(part, tree.release());
}

Event::Loop::Loop(const ana::input::range& part, TTree* tree) :
	ana::input::reader<Loop>(part)
{
	m_event = std::make_unique<xAOD::TEvent>();
  if (m_event->readFrom(tree).isFailure()) {
		throw std::runtime_error("failed to read event");
	};
}

void Event::Loop::begin()
{
	m_current = m_part.begin;
	m_end = m_part.end;
}

bool Event::Loop::next()
{
	if (m_current < m_end) {
    if (m_event->getEntry(m_current++)<0) {
			throw std::runtime_error("failed to get entry");
		} 
		return true;
  }
  return false;
}