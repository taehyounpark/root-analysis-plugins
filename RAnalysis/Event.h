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

#include "ana/table.h"

class Event : public ana::input::dataset<Event>
{

public:
	class Loop;

	template <typename T>
	class Container;

public:
	Event(const std::vector<std::string>& inputFiles, const std::string& treeName = "CollectionTree");
	virtual ~Event() = default;

	virtual ana::input::partition allocate() override;

  // this can (should?) be implemented to normalize by xAOD::CutBookkeeper's sumOfWeights
	// virtual double normalize() override;

	std::shared_ptr<Loop> open(const ana::input::range& part) const;

protected:
	std::string m_treeName;
	std::vector<std::string> m_inputFiles;
	std::vector<std::string> m_goodFiles;

};

class Event::Loop : public ana::input::reader<Loop>
{
public:
	Loop(const ana::input::range& part, TTree* tree);
	~Loop() = default;

	template <typename U>
	std::shared_ptr<Container<U>> read(const std::string& name, std::string containerName="") const;

	virtual void begin() override;
	virtual bool next() override;

protected:
  std::unique_ptr<xAOD::TEvent> m_event;
  long long                     m_current;
  long long                     m_end;

};

template <typename T>
class Event::Container : public ana::column<T>::reader
{

public:
	Container(const std::string& name, const std::string& containerName, xAOD::TEvent& event) :
	ana::column<T>::reader(name),
	m_containerName(containerName),
	m_event(&event)
	{}
	~Container() = default;

	virtual void execute() override
	{
		const T* container(nullptr);
    if (m_event->retrieve(container,this->m_containerName.c_str()).isFailure()) {
      throw std::runtime_error(TString::Format("failed to retrieve '%s' from event",this->m_containerName.c_str()));
    }
    this->read(*container);
	}

protected:
	std::string m_containerName;
  xAOD::TEvent* m_event;

};

template <typename U>
std::shared_ptr<Event::Container<U>> Event::Loop::read(const std::string& name, std::string containerName) const
{
	if (containerName.empty()) containerName = name;
	return std::make_shared<Container<U>>(name,containerName,*m_event);
}
