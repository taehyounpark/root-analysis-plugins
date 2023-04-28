#include "RAnalysis/CsvData.h"

#include "TROOT.h"

#include "ana/concurrent.h"
#include "ana/strutils.h"
#include "ana/vecutils.h"

CsvData::CsvData(const std::string& csvFile) :
  // m_csv(ROOT::RDF::RCsvDS(csvFile.c_str())),
  m_rds(std::make_unique<RCsvDS>(csvFile))
{}

ana::input::partition CsvData::allocate()
{
  // force multithreading
  ROOT::EnableImplicitMT(ana::multithread::concurrency());
  // get ROOT thread size
  size_t imtps = ROOT::GetThreadPoolSize();

  // get allocation
  m_rds->SetNSlots(imtps);
  auto slots = m_rds->GetEntryRanges();
  ana::input::partition partition;
  for (size_t islot=0 ; islot<slots.size() ; ++islot) {
    partition.add_part(islot, slots[islot].first, slots[islot].second);
  }
  // allocation is determined by ROOT -- fix partition to indicate this
  partition.fixed = true;

  return partition;
}

void CsvData::start()
{
  m_rds->Initialise();
}

void CsvData::finish()
{
  m_rds->Finalise();
}

std::shared_ptr<CsvData::Reader> CsvData::open(const ana::input::range& range) const
{
	return std::make_shared<Reader>(range, *m_rds);
}

CsvData::Reader::Reader(const ana::input::range& range, RCsvDS& rds) :
	ana::input::reader<Reader>(range),
  m_rds(&rds)
{
  // std::cout << range.begin << range.end << std::endl;
}

void CsvData::Reader::begin()
{
  m_rds->InitSlot(m_part.slot, m_part.begin);
	m_current = m_part.begin;
}

bool CsvData::Reader::next()
{
  // std::cout << m_current <<std::endl;
  // std::cout << m_part.end <<std::endl;
  if (m_current < m_part.end) {
    return m_rds->SetEntry(m_part.slot, m_current++);
  }
  return false;
}

void CsvData::Reader::end()
{
  m_rds->FinaliseSlot(m_part.slot);
}