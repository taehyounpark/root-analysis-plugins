#pragma once

#include <string>
#include <vector>
#include <memory>

#include "TDirectory.h"
#include "TFile.h"
#include "TTree.h"
#include "TChain.h"
#include "TString.h"

#include "xAODRootAccess/Init.h"
#include "xAODRootAccess/TEvent.h"
#include "xAODRootAccess/TStore.h"

#include "ana/analysis.h"

class Event : public ana::dataset::input<Event>
{

public:
	class Loop;

	template <typename T>
	class Container;

public:
	Event(const std::vector<std::string>& inputFiles, const std::string& collection = "CollectionTree", const std::string& metadata = "MetaData");
	~Event() = default;

	ana::dataset::partition allocate();
	double normalize();

	std::unique_ptr<Loop> read(const ana::dataset::range& part) const;

protected:
	std::vector<std::string> m_inputFiles;
	std::string m_treeName;
	std::string m_metaName;

	std::vector<std::string> m_goodFiles;
};

class Event::Loop : public ana::dataset::reader<Loop>
{
public:
	Loop(TTree* tree);
	~Loop() = default;

	template <typename U>
	std::unique_ptr<Container<U>> read(const ana::dataset::range& part, const std::string& name) const;

 	void start(const ana::dataset::range& part);
	void next(const ana::dataset::range& part, unsigned long long entry);
 	void finish(const ana::dataset::range& part);

protected:
  std::unique_ptr<xAOD::TEvent> m_event;
  long long                     m_current;
  long long                     m_end;

};

template <typename T>
class Event::Container : public ana::column::reader<T>
{

public:
	Container(const std::string& containerName, xAOD::TEvent& event) :
	m_containerName(containerName),
	m_event(&event)
	{}
	~Container() = default;

	virtual T const& read(const ana::dataset::range& part, unsigned long long entry) const override
	{
		T const* container(nullptr);
    if (m_event->retrieve(container,this->m_containerName.c_str()).isFailure()) {
      throw std::runtime_error(TString::Format("failed to retrieve '%s' from event",this->m_containerName.c_str()));
    }
    return *container;
	}

protected:
	std::string m_containerName;
  xAOD::TEvent* m_event;

};

template <typename U>
std::unique_ptr<Event::Container<U>> Event::Loop::read(const ana::dataset::range&, const std::string& containerName) const
{
	return std::make_unique<Container<U>>(containerName,*m_event);
}
