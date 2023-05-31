#pragma once

#include <string>
#include <vector>
#include <memory>

#include <ROOT/RVec.hxx>

#include "TROOT.h"
#include "TDirectory.h"
#include "TFile.h"
#include "TTree.h"
#include "TChain.h"
#include "TTreeReader.h"
#include "TTreeReaderValue.h"
#include "TTreeReaderArray.h"

#include "ana/analysis.h"

class Tree : public ana::dataset::input<Tree>
{

public:
	class Reader;

	template <typename T>
	class Branch;

public:
	Tree(const std::vector<std::string>& filePaths, const std::string& treeName);
	~Tree() = default;

 	ana::dataset::partition allocate();
	std::shared_ptr<Reader> read() const;

protected:
	std::vector<std::string> m_allFiles;
	std::vector<std::string> m_goodFiles;
	std::string m_treeName;

};

class Tree::Reader : public ana::dataset::reader<Reader>
{
public:
	Reader(std::unique_ptr<TTree> tree);
	~Reader() = default;

	template <typename U>
	std::shared_ptr<Branch<U>> read(const ana::dataset::range&, const std::string& branchName) const;

 	void start(const ana::dataset::range& part);
	void next(const ana::dataset::range& part, unsigned long long entry);
 	void finish(const ana::dataset::range& part);

protected:
	std::unique_ptr<TTree>       m_tree; 
	std::unique_ptr<TTreeReader> m_treeReader;  

};

template <typename T>
class Tree::Branch : public ana::column::reader<T>
{

public:
	Branch(const std::string& branchName, TTreeReader& treeReader) :
		ana::column::reader<T>(branchName),
		m_branchName(branchName),
		m_treeReader(&treeReader)
	{}
	~Branch() = default;

	virtual void initialize(const ana::dataset::range&) override
	{
		m_treeReaderValue = std::make_unique<TTreeReaderValue<T>>(*m_treeReader,this->m_branchName.c_str());
	}

	virtual T const& read() const override
	{
		return **m_treeReaderValue;
	}

protected:
  std::string m_branchName;
	TTreeReader* m_treeReader;
  std::unique_ptr<TTreeReaderValue<T>> m_treeReaderValue;  

};

template <typename T>
class Tree::Branch<ROOT::RVec<T>> : public ana::column::reader<ROOT::RVec<T>>
{

public:
	Branch(const std::string& branchName, TTreeReader& treeReader) :
		ana::column::reader<ROOT::RVec<T>>(branchName),
		m_branchName(branchName),
		m_treeReader(&treeReader)
	{}
	~Branch() = default;

	virtual void initialize(const ana::dataset::range&) override
	{
		m_treeReaderArray = std::make_unique<TTreeReaderArray<T>>(*m_treeReader,this->m_branchName.c_str());
	}

	virtual ROOT::RVec<T> const& read() const override
	{
    if (auto arraySize = m_treeReaderArray->GetSize()) {
      ROOT::RVec<T> readArray(&m_treeReaderArray->At(0), arraySize);
      std::swap(m_readArray,readArray);
    } else {
      ROOT::RVec<T> emptyVector{};
      std::swap(m_readArray,emptyVector);
    }
		return m_readArray;
	}

protected:
  std::string m_branchName;
	TTreeReader* m_treeReader;
  std::unique_ptr<TTreeReaderArray<T>> m_treeReaderArray;
	mutable ROOT::RVec<T> m_readArray;

};

template <>
class Tree::Branch<ROOT::RVec<bool>> : public ana::column::reader<ROOT::RVec<bool>>
{

public:
	Branch(const std::string& branchName, TTreeReader& treeReader) :
		ana::column::reader<ROOT::RVec<bool>>(branchName),
		m_branchName(branchName),
		m_treeReader(&treeReader)
	{}
	~Branch() = default;

	virtual void initialize(const ana::dataset::range&) override
	{
		m_treeReaderArray = std::make_unique<TTreeReaderArray<bool>>(*m_treeReader,this->m_branchName.c_str());
	}

	virtual ROOT::RVec<bool> const& read() const override
	{
    if (m_treeReaderArray->GetSize()) {
      ROOT::RVec<bool> readArray(m_treeReaderArray->begin(), m_treeReaderArray->end());
      std::swap(m_readArray,readArray);
    } else {
      ROOT::RVec<bool> emptyVector{};
      std::swap(m_readArray,emptyVector);
    }
		return m_readArray;
	}

protected:
  std::string m_branchName;
	TTreeReader* m_treeReader;
  std::unique_ptr<TTreeReaderArray<bool>> m_treeReaderArray;
	mutable ROOT::RVec<bool> m_readArray;

};


template <typename U>
std::shared_ptr<Tree::Branch<U>> Tree::Reader::read(const ana::dataset::range&, const std::string& branchName) const
{
	return std::make_shared<Branch<U>>(branchName,*m_treeReader);
}