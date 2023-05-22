#pragma once

#include <string>
#include <vector>
#include <memory>

#include "TH1.h"
#include "TH2.h"
#include "TH3.h"
#include <ROOT/RVec.hxx>

#include "ana/counter.h"

template <int Dim, typename Prec>
class Histogram;

template <typename Prec>
class Histogram<1,Prec> : public ana::counter::logic<std::shared_ptr<TH1>(Prec)>
{

public:
	Histogram(const std::string&, unsigned int, double, double);
	Histogram(const std::string&, const std::vector<double>&);
	virtual ~Histogram() = default;

	virtual void fill(ana::observable<Prec>, double) override;
	virtual std::shared_ptr<TH1> result() const override;
	virtual std::shared_ptr<TH1> merge(std::vector<std::shared_ptr<TH1>> results) const override;

protected:
	// histogram
	std::shared_ptr<TH1> m_hist; //!

};

template <typename Prec>
class Histogram<2,Prec> : public ana::counter::logic<std::shared_ptr<TH2>(Prec,Prec)>
{

public:
	Histogram(const std::string&, const std::vector<double>&, const std::vector<double>&);
	virtual ~Histogram() = default;

	virtual void fill(ana::observable<Prec>, ana::observable<Prec>, double) override;
	virtual std::shared_ptr<TH2> result() const override;
	virtual std::shared_ptr<TH2> merge(std::vector<std::shared_ptr<TH2>> results) const override;

protected:
	std::shared_ptr<TH2> m_hist; //!

};

template <typename Prec>
class Histogram<3,Prec> : public ana::counter::logic<std::shared_ptr<TH3>(Prec,Prec,Prec)>
{

public:
	Histogram(const std::string&, const std::vector<double>&, const std::vector<double>&, const std::vector<double>&);
	virtual ~Histogram() = default;

	virtual void fill(ana::observable<Prec>, ana::observable<Prec>, ana::observable<Prec>, double) override;
	virtual std::shared_ptr<TH3> result() const override;
	virtual std::shared_ptr<TH3> merge(std::vector<std::shared_ptr<TH3>> results) const override;

protected:
	std::shared_ptr<TH3> m_hist; //!

};

template <typename Prec>
class Histogram<1,ROOT::RVec<Prec>> : public ana::counter::logic<std::shared_ptr<TH1>(ROOT::RVec<Prec>)>
{

public:
	Histogram(const std::string& name, unsigned int nbins, double min, double xmax);
	Histogram(const std::string& name, const std::vector<double>& xbins);
	virtual ~Histogram() = default;

	virtual void fill(ana::observable<ROOT::RVec<Prec>>, double) override;
	virtual std::shared_ptr<TH1> result() const override;
	virtual std::shared_ptr<TH1> merge(std::vector<std::shared_ptr<TH1>> results) const override;

protected:
	// histogram
	std::shared_ptr<TH1> m_hist; //!

};

template <typename Prec>
class Histogram<2,ROOT::RVec<Prec>> : public ana::counter::logic<std::shared_ptr<TH2>(ROOT::RVec<Prec>,ROOT::RVec<Prec>)>
{

public:
	Histogram(const std::string&, const std::vector<double>&, const std::vector<double>&);
	virtual ~Histogram() = default;

	virtual void fill(ana::observable<ROOT::RVec<Prec>>, ana::observable<ROOT::RVec<Prec>>, double) override;
	virtual std::shared_ptr<TH2> result() const override;
	virtual std::shared_ptr<TH2> merge(std::vector<std::shared_ptr<TH2>> results) const override;

protected:
	// histogram
	std::shared_ptr<TH2> m_hist; //!

};

template <typename Prec>
class Histogram<3,ROOT::RVec<Prec>> : public ana::counter::logic<std::shared_ptr<TH3>(ROOT::RVec<Prec>,ROOT::RVec<Prec>,ROOT::RVec<Prec>)>
{

public:
	Histogram(const std::string&, const std::vector<double>&, const std::vector<double>&, const std::vector<double>&);
	virtual ~Histogram() = default;

	virtual void fill(ana::observable<ROOT::RVec<Prec>>, ana::observable<ROOT::RVec<Prec>>, ana::observable<ROOT::RVec<Prec>>, double) override;
	virtual std::shared_ptr<TH3> result() const override;
	virtual std::shared_ptr<TH3> merge(std::vector<std::shared_ptr<TH3>> results) const override;

protected:
	// histogram
	std::shared_ptr<TH3> m_hist; //!

};

#include "RAnalysis/HistogramUtils.h"

template <typename Prec>
Histogram<1,Prec>::Histogram(const std::string& name, unsigned int nbins, double xmin, double xmax) :
	ana::counter::logic<std::shared_ptr<TH1>(Prec)>()
{
	m_hist = HistogramUtils::makeHist<1,Prec>(nbins, xmin, xmax);
	m_hist->SetName(name.c_str());
}

template <typename Prec>
Histogram<1,Prec>::Histogram(const std::string& name, const std::vector<double>& xbins) :
	ana::counter::logic<std::shared_ptr<TH1>(Prec)>()
{
	m_hist = HistogramUtils::makeHist<1,Prec>(xbins);
	m_hist->SetName(name.c_str());
}

template <typename Prec>
void Histogram<1,Prec>::fill(ana::observable<Prec> x, double w)
{
	m_hist->Fill(x.value(),w);
}

template <typename Prec>
std::shared_ptr<TH1> Histogram<1,Prec>::merge(std::vector<std::shared_ptr<TH1>> results) const
{
	auto merged_result = std::shared_ptr<TH1>(static_cast<TH1*>(results[0]->Clone()));
	merged_result->Reset();
	for (auto const& result : results) {
		merged_result->Add(result.get());
	}
	return merged_result;
}

template <typename Prec>
std::shared_ptr<TH1> Histogram<1,Prec>::result() const
{
	return m_hist;
}

template <typename Prec>
Histogram<2,Prec>::Histogram(const std::string& name, const std::vector<double>& xbins, const std::vector<double>& ybins) :
	ana::counter::logic<std::shared_ptr<TH2>(Prec,Prec)>()
{
	m_hist = std::static_pointer_cast<TH2>(HistogramUtils::makeHist<2,Prec>(xbins,ybins));
	m_hist->SetName(name.c_str());
}

template <typename Prec>
void Histogram<2,Prec>::fill(ana::observable<Prec> x, ana::observable<Prec> y, double w)
{
	m_hist->Fill(x.value(),y.value(),w);
}

template <typename Prec>
std::shared_ptr<TH2> Histogram<2,Prec>::merge(std::vector<std::shared_ptr<TH2>> results) const
{
	auto merged_result = std::shared_ptr<TH2>(static_cast<TH2*>(results[0]->Clone()));
	merged_result->Reset();
	for (auto const& result : results) {
		merged_result->Add(result.get());
	}
	return merged_result;
}

template <typename Prec>
std::shared_ptr<TH2> Histogram<2,Prec>::result() const
{
	return m_hist;
}

template <typename Prec>
Histogram<3,Prec>::Histogram(const std::string& name, const std::vector<double>& xbins, const std::vector<double>& ybins, const std::vector<double>& zbins) :
	ana::counter::logic<std::shared_ptr<TH3>(Prec,Prec,Prec)>()
{
	m_hist = std::static_pointer_cast<TH3>(HistogramUtils::makeHist<3,Prec>(xbins,ybins,zbins));
	m_hist->SetName(name.c_str());
}

template <typename Prec>
void Histogram<3,Prec>::fill(ana::observable<Prec> x, ana::observable<Prec> y, ana::observable<Prec> z, double w)
{
	m_hist->Fill(x.value(),y.value(),z.value(),w);
}

template <typename Prec>
std::shared_ptr<TH3> Histogram<3,Prec>::merge(std::vector<std::shared_ptr<TH3>> results) const
{
	auto merged_result = std::shared_ptr<TH3>(static_cast<TH3*>(results[0]->Clone()));
	merged_result->Reset();
	for (auto const& result : results) {
		merged_result->Add(result.get());
	}
	return merged_result;
}

template <typename Prec>
std::shared_ptr<TH3> Histogram<3,Prec>::result() const
{
	return m_hist;
}

// vector<T>

template <typename Prec>
Histogram<1,ROOT::RVec<Prec>>::Histogram(const std::string& name, unsigned int nbins, double xmin, double xmax) :
	ana::counter::logic<std::shared_ptr<TH1>(ROOT::RVec<Prec>)>()
{
	m_hist = HistogramUtils::makeHist<1,Prec>(nbins,xmin,xmax);
	m_hist->SetName(name.c_str());
}

template <typename Prec>
Histogram<1,ROOT::RVec<Prec>>::Histogram(const std::string& name, const std::vector<double>& xbins) :
	ana::counter::logic<std::shared_ptr<TH1>(ROOT::RVec<Prec>)>()
{
	m_hist = HistogramUtils::makeHist<1,Prec>(xbins);
	m_hist->SetName(name.c_str());
}

template <typename Prec>
void Histogram<1,ROOT::RVec<Prec>>::fill(ana::observable<ROOT::RVec<Prec>> xs, double w)
{
	for (size_t ix ; ix<xs->size() ; ++ix) {
		m_hist->Fill(xs.value()[ix],w);
	}
}

template <typename Prec>
std::shared_ptr<TH1> Histogram<1,ROOT::RVec<Prec>>::merge(std::vector<std::shared_ptr<TH1>> results) const
{
	auto merged_result = std::shared_ptr<TH1>(static_cast<TH1*>(results[0]->Clone()));
	merged_result->Reset();
	for (auto const& result : results) {
		merged_result->Add(result.get());
	}
	return merged_result;
}

template <typename Prec>
std::shared_ptr<TH1> Histogram<1,ROOT::RVec<Prec>>::result() const
{
	return m_hist;
}

template <typename Prec>
Histogram<2,ROOT::RVec<Prec>>::Histogram(const std::string& name, const std::vector<double>& xbins, const std::vector<double>& ybins) :
	ana::counter::logic<std::shared_ptr<TH2>(ROOT::RVec<Prec>,ROOT::RVec<Prec>)>()
{
	m_hist = std::static_pointer_cast<TH2>(HistogramUtils::makeHist<2,Prec>(xbins,ybins));
	m_hist->SetName(name.c_str());
}

template <typename Prec>
void Histogram<2,ROOT::RVec<Prec>>::fill(ana::observable<ROOT::RVec<Prec>> xs, ana::observable<ROOT::RVec<Prec>> ys, double w)
{
	if (xs->size() != ys->size()) {
		throw std::runtime_error("x- and y-arrays do not share the same size");
	}
	for (size_t ix ; ix<xs->size() ; ++ix) {
		m_hist->Fill(xs.value()[ix],ys.value()[ix],w);
	}
}

template <typename Prec>
std::shared_ptr<TH2> Histogram<2,ROOT::RVec<Prec>>::merge(std::vector<std::shared_ptr<TH2>> results) const
{
	auto merged_result = std::shared_ptr<TH2>(static_cast<TH2*>(results[0]->Clone()));
	merged_result->Reset();
	for (auto const& result : results) {
		merged_result->Add(result.get());
	}
	return merged_result;
}

template <typename Prec>
std::shared_ptr<TH2> Histogram<2,ROOT::RVec<Prec>>::result() const
{
	return m_hist;
}

template <typename Prec>
Histogram<3,ROOT::RVec<Prec>>::Histogram(const std::string& name, const std::vector<double>& xbins, const std::vector<double>& ybins, const std::vector<double>& zbins) :
	ana::counter::logic<std::shared_ptr<TH3>(ROOT::RVec<Prec>,ROOT::RVec<Prec>,ROOT::RVec<Prec>)>()
{
	m_hist = std::static_pointer_cast<TH3>(HistogramUtils::makeHist<3,Prec>(xbins,ybins,zbins));
	m_hist->SetName(name.c_str());
}

template <typename Prec>
void Histogram<3,ROOT::RVec<Prec>>::fill(ana::observable<ROOT::RVec<Prec>> xs, ana::observable<ROOT::RVec<Prec>> ys, ana::observable<ROOT::RVec<Prec>> zs, double w)
{
	if (xs->size() != ys->size()) {
		throw std::runtime_error("x- and y-arrays do not share the same size");
	}
	if (xs->size() != zs->size()) {
		throw std::runtime_error("x- and z-arrays do not share the same size");
	}
	for (size_t ix ; ix<xs->size() ; ++ix) {
		m_hist->Fill(xs.value()[ix],ys.value()[ix],zs.value()[ix],w);
	}
}

template <typename Prec>
std::shared_ptr<TH3> Histogram<3,ROOT::RVec<Prec>>::merge(std::vector<std::shared_ptr<TH3>> results) const
{
	auto merged_result = std::shared_ptr<TH3>(static_cast<TH3*>(results[0]->Clone()));
	merged_result->Reset();
	for (auto const& result : results) {
		merged_result->Add(result.get());
	}
	return merged_result;
}

template <typename Prec>
std::shared_ptr<TH3> Histogram<3,ROOT::RVec<Prec>>::result() const
{
	return m_hist;
}

template class Histogram<1,float>;
template class Histogram<2,float>;
template class Histogram<3,float>;
template class Histogram<1,ROOT::RVec<float>>;
template class Histogram<2,ROOT::RVec<float>>;
template class Histogram<3,ROOT::RVec<float>>;