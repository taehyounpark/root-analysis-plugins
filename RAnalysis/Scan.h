#pragma once

#include <string>
#include <vector>
#include <memory>

#include <ROOT/RVec.hxx>
#include "TH2.h"
#include "TH3.h"

#include "ana/counter.h"
#include "AnalysisHelpers/HistogramUtils.h"

template <int Dim, typename Prec>
class Scan;

template <typename Prec>
class Scan<1,Prec> : public ana::counter::logic<std::shared_ptr<TH2>(std::vector<Prec>)>
{

public:
	Scan(const std::string& name, int nx, double xmin, double xmax, const std::vector<double>& ybins);
	virtual ~Scan() = default;

	virtual void fill(ana::observable<std::vector<Prec>>, double w) override;
	virtual std::shared_ptr<TH2> result() const override;
	virtual void merge(std::shared_ptr<TH2> scan) override;

protected:
	/// scanogram
	std::shared_ptr<TH2> m_scan;
  std::vector<double> m_xvals;

};

template <typename Prec>
class Scan<2,Prec> : public ana::counter::logic<std::shared_ptr<TH3>(std::vector<std::vector<Prec>>)>
{

public:
	Scan(const std::string& name, int nx, double xmin, double xmax, int ny, double ymin, double ymax, const std::vector<double>& zbins);
	virtual ~Scan() = default;

	virtual void fill(ana::observable<std::vector<std::vector<Prec>>>, double w) override;
	virtual std::shared_ptr<TH3> result() const override;
	virtual void merge(std::shared_ptr<TH3> scan) override;

protected:
	std::shared_ptr<TH3> m_scan;
  std::vector<double> m_xvals;
  std::vector<double> m_yvals;

};

#include "TH2.h"
#include "TH3.h"
#include "AnalysisHelpers/HistogramUtils.h"

template <typename Prec>
Scan<1,Prec>::Scan(const std::string& name, int nx, double xmin, double xmax, const std::vector<double>& ybins) :
	ana::counter::logic<std::shared_ptr<TH2>(std::vector<Prec>)>(name)
{
	m_xvals = vec::make_lin(nx,xmin,xmax);
	auto xw = (xmax-xmin)/nx;
	auto xbins = vec::make_lin(nx+1,xmin-xw*0.5,xmax+xw*0.5);
	m_scan = std::dynamic_pointer_cast<TH2>(HistogramUtils::makeHist<2,Prec>(xbins,ybins));
	m_scan->SetName(this->get_name().c_str());
}

template <typename Prec>
void Scan<1,Prec>::fill(ana::observable<std::vector<Prec>> yvals, double w)
{
  assert(m_xvals.size() == yvals->size());
  for (size_t ix=0 ; ix<m_xvals.size() ; ++ix) {
    m_scan->Fill(m_xvals[ix],yvals.value()[ix],w);
  }
}

template <typename Prec>
void Scan<1,Prec>::merge(std::shared_ptr<TH2> scan)
{
	m_scan->Add(scan.get());
}

template <typename Prec>
std::shared_ptr<TH2> Scan<1,Prec>::result() const
{
	return m_scan;
}

template <typename Prec>
Scan<2,Prec>::Scan(const std::string& name, int nx, double xmin, double xmax, int ny, double ymin, double ymax, const std::vector<double>& zbins) :
	ana::counter::logic<std::shared_ptr<TH3>(std::vector<std::vector<Prec>>)>(name)
{
	m_xvals = vec::make_lin(nx,xmin,xmax);
	auto xw = (xmax-xmin)/nx;
	auto xbins = vec::make_lin(nx+1,xmin-xw*0.5,xmax+xw*0.5);
	m_yvals = vec::make_lin(ny,ymin,ymax);
	auto yw = (ymax-ymin)/ny;
	auto ybins = vec::make_lin(ny+1,ymin-yw*0.5,ymax+yw*0.5);
	m_scan = std::dynamic_pointer_cast<TH3>(HistogramUtils::makeHist<3,Prec>(xbins,ybins,zbins));
	m_scan->SetName(this->get_name().c_str());
}

template <typename Prec>
void Scan<2,Prec>::fill(ana::observable<std::vector<std::vector<Prec>>> zvals, double w)
{
  assert(m_xvals.size() == zvals->size());
  for (size_t ix=0 ; ix<m_xvals.size() ; ++ix) {
    assert(m_yvals.size() == zvals.value()[ix].size());
    for (size_t iy=0 ; iy<m_yvals.size() ; ++iy) {
      m_scan->Fill(m_xvals[ix],m_yvals[iy],zvals.value()[ix][iy],w);
    }
  }
}

template <typename Prec>
void Scan<2,Prec>::merge(std::shared_ptr<TH3> scan)
{
	m_scan->Add(scan.get());
}

template <typename Prec>
std::shared_ptr<TH3> Scan<2,Prec>::result() const
{
	return m_scan;
}

template class Scan<1,float>;
template class Scan<2,float>;
