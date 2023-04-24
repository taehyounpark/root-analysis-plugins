#include "RAnalysis/RData.h"

#include "TROOT.h"

#include "ana/concurrent.h"
#include "ana/strutils.h"
#include "ana/vecutils.h"

RData::RData(std::unique_ptr<RDataSource> rds) :
	m_rds(std::move(rds))
{}

ana::input::partition RData::allocate()
{
  // force multithreading
  ROOT::EnableImplicitMT(ana::multithread::s_suggestion);
  // get ROOT thread size
  size_t imtps = ROOT::GetThreadPoolSize();

  // get allocation
  m_rds->SetNSlots(imtps);
  auto slots = m_rds->GetEntryRanges();
  ana::input::partition partition;
  for (size_t islot=0 ; islot<slots.size() ; ++islot) {
    partition.add(islot, slots[islot].first, slots[islot].second);
  }
  // allocation is determined by ROOT -- fix partition to indicate this
  partition.fixed = true;

  return partition;
}

void RData::start()
{
  m_rds->Initialise();
}

void RData::finish()
{
  m_rds->Finalise();
}

std::shared_ptr<RData::Reader> RData::open(const ana::input::range& part) const
{
	return std::make_shared<Reader>(part, *m_rds);
}

RData::Reader::Reader(const ana::input::range& part, RDataSource& rds) :
  ana::input::reader<Reader>(part),
  m_rds(&rds)
{}

void RData::Reader::begin()
{
  m_rds->InitSlot(m_part.slot, m_part.begin);
	m_current = m_part.begin;
}

bool RData::Reader::next()
{
  if (m_current < m_part.end) {
    return m_rds->SetEntry(m_part.slot, m_current++);
  }
  return false;
}

void RData::Reader::end()
{
  m_rds->FinaliseSlot(m_part.slot);
}