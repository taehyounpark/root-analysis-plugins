#pragma once

#include <string>
#include <vector>
#include <memory>

#include "TProfile.h"
#include "TProfile2D.h"

#include "ana/counter.h"

template <unsigned int Dim>
class Profile;

template <>
class Profile<1> : public ana::counter::logic<std::shared_ptr<TProfile>(double,double)>
{

public:
	Profile(const std::string&, const std::vector<double>&);
	virtual ~Profile() = default;

	virtual void fill(ana::observable<double>, ana::observable<double>, double) override;
	virtual std::shared_ptr<TProfile> result() const override;
	virtual void merge(std::shared_ptr<TProfile>) override;

protected:
	/// histogram
	std::shared_ptr<TProfile> m_prof;

};

template <>
class Profile<2> : public ana::counter::logic<std::shared_ptr<TProfile2D>(double,double,double)>
{

public:
	Profile(const std::string&, const std::vector<double>&, const std::vector<double>&);
	virtual ~Profile() = default;

	virtual void fill(ana::observable<double>, ana::observable<double>, ana::observable<double>, double) override;
	virtual std::shared_ptr<TProfile2D> result() const override;
	virtual void merge(std::shared_ptr<TProfile2D>) override;

protected:
	std::shared_ptr<TProfile2D> m_prof;

};

Profile<1>::Profile(const std::string& name, const std::vector<double>& xbins) :
	ana::counter::logic<std::shared_ptr<TProfile>(double,double)>(name)
{
  m_prof = std::make_shared<TProfile>(name.c_str(),name.c_str(), xbins.size()-1,&xbins[0]);
  m_prof->SetDirectory(0);
}

void Profile<1>::fill(ana::observable<double> x, ana::observable<double> y, double w)
{
	m_prof->Fill(x.value(),y.value(),w);
}

void Profile<1>::merge(std::shared_ptr<TProfile> hist)
{
	m_prof->Add(hist.get());
}

std::shared_ptr<TProfile> Profile<1>::result() const
{
	return m_prof;
}

Profile<2>::Profile(const std::string& name, const std::vector<double>& xbins, const std::vector<double>& ybins) :
	ana::counter::logic<std::shared_ptr<TProfile2D>(double,double,double)>(name)
{
  m_prof = std::make_shared<TProfile2D>(name.c_str(),name.c_str(), xbins.size()-1,&xbins[0], ybins.size()-1,&ybins[0]);
  m_prof->SetDirectory(0);
}

void Profile<2>::fill(ana::observable<double> x, ana::observable<double> y, ana::observable<double> z, double w)
{
	m_prof->Fill(x.value(),y.value(),z.value(),w);
}

void Profile<2>::merge(std::shared_ptr<TProfile2D> hist)
{
	m_prof->Add(hist.get());
}

std::shared_ptr<TProfile2D> Profile<2>::result() const
{
	return m_prof;
}