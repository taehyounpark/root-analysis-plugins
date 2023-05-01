#include "RAnalysis/RDS.h"

#include "TROOT.h"

#include "ana/concurrent.h"
#include "ana/strutils.h"
#include "ana/vecutils.h"

RDS::RDS(std::unique_ptr<RDataSource> rds) :
	m_rds(std::move(rds))
{}

ana::input::partition RDS::allocate()
{
  // force multithreading
  if (ana::multithread::status()) {
    ROOT::EnableImplicitMT(ana::multithread::concurrency());
  }
  m_rds->SetNSlots(ROOT::GetThreadPoolSize() ? ROOT::GetThreadPoolSize() : 1);

  // get allocated slots 
  auto slots = m_rds->GetEntryRanges();
  ana::input::partition partition;
  for (size_t islot=0 ; islot<slots.size() ; ++islot) {
    partition.add_part(islot, slots[islot].first, slots[islot].second);
  }

  // use whatever ROOT has decided
  partition.fixed = true;
  return partition;
}

void RDS::start()
{
  m_rds->Initialise();
}

void RDS::finish()
{
  m_rds->Finalise();
}

std::shared_ptr<RDS::Reader> RDS::open(const ana::input::range& part) const
{
	return std::make_shared<Reader>(part, *m_rds);
}

RDS::Reader::Reader(const ana::input::range& part, RDataSource& rds) :
  ana::input::reader<Reader>(part),
  m_rds(&rds)
{}

void RDS::Reader::begin()
{
  m_rds->InitSlot(m_part.slot, m_part.begin);
	m_current = m_part.begin;
}

bool RDS::Reader::next()
{
  if (m_current < m_part.end) {
    return m_rds->SetEntry(m_part.slot, m_current++);
  }
  return false;
}

void RDS::Reader::end()
{
  m_rds->FinaliseSlot(m_part.slot);
}