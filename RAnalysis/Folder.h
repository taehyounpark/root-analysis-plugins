#pragma once

#include "TObject.h"
#include "TDirectory.h"
#include "TFile.h"

#include "ana/counter.h"

class Folder : public ana::counter::summary<Folder>
{

public:
  static TDirectory* getDirectory(TDirectory& dir, const std::string& path)
  {
    dir.mkdir(path.c_str(), path.c_str(), true);
    return dir.GetDirectory(path.c_str());
  }

public:
  Folder(const std::string& basePath="") : m_basePath(basePath) {}
  ~Folder() = default;

  void record(const std::string& selectionPath, std::shared_ptr<TObject> counterResult)
  {
    m_resultAtPath.emplace(std::make_pair(selectionPath,counterResult));
  }

  void report(TFile& outputFile)
  {
    auto baseFolder = m_basePath.empty() ? &outputFile : this->getDirectory(outputFile, m_basePath);
    for (const auto& pathAndResult : m_resultAtPath) {
      auto selectionPath = pathAndResult.first;
      auto counterResult = pathAndResult.second;
      auto selectionFolder = this->getDirectory(*baseFolder, selectionPath);
      selectionFolder->WriteObject(counterResult->Clone(), counterResult->GetName());
    }
  }

public:
  std::string m_basePath;
  std::map<std::string, std::shared_ptr<TObject>> m_resultAtPath;
  
};