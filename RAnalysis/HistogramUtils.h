#pragma once

#include <memory>
#include <vector>

#include "TH1.h"
#include "TH2.h"
#include "TH3.h"

#include "ana/vecutils.h"

namespace HistogramUtils
{

	size_t getDim(TH1& hist);

	// create the appropriate histogram given the dimensionality and precision of columns.
	// e.g. makeHist<1,float> -> TH1F
	template <unsigned int Dim, typename Prec>
	std::shared_ptr<TH1> makeHist(const std::vector<double>& xbins={0.0,1.0}, const std::vector<double>& ybins={0.0,1.0}, const std::vector<double>& zbins={0.0,1.0})
	{
		std::shared_ptr<TH1> hist;
		if constexpr(Dim==1) {
			if constexpr(std::is_same_v<Prec,char> || std::is_same_v<Prec,bool>) {
				hist = std::make_shared<TH1C>("","",xbins.size()-1,&xbins[0]);
			} else if constexpr(std::is_same_v<Prec,int>) {
				hist = std::make_shared<TH1I>("","",xbins.size()-1,&xbins[0]);
			} else if constexpr(std::is_same_v<Prec,float>) {
				hist = std::make_shared<TH1F>("","",xbins.size()-1,&xbins[0]);
			} else if constexpr(std::is_same_v<Prec,double>) {
				hist = std::make_shared<TH1D>("","",xbins.size()-1,&xbins[0]);
			}
		} else if constexpr(Dim==2) {
			if constexpr(std::is_same_v<Prec,char> || std::is_same_v<Prec,bool>) {
				hist = std::make_shared<TH2C>("","",xbins.size()-1,&xbins[0],ybins.size()-1,&ybins[0]);
			} else if constexpr(std::is_same_v<Prec,int>) {
				hist = std::make_shared<TH2I>("","",xbins.size()-1,&xbins[0],ybins.size()-1,&ybins[0]);
			} else if constexpr(std::is_same_v<Prec,float>) {
				hist = std::make_shared<TH2F>("","",xbins.size()-1,&xbins[0],ybins.size()-1,&ybins[0]);
			} else if constexpr(std::is_same_v<Prec,double>) {
				hist = std::make_shared<TH2D>("","",xbins.size()-1,&xbins[0],ybins.size()-1,&ybins[0]);
			}
		} else if constexpr(Dim==3) {
			if constexpr(std::is_same_v<Prec,char> || std::is_same_v<Prec,bool>) {
				hist = std::make_shared<TH3C>("","",xbins.size()-1,&xbins[0],ybins.size()-1,&ybins[0],zbins.size()-1,&zbins[0]);
			} else if constexpr(std::is_same_v<Prec,int>) {
				hist = std::make_shared<TH3I>("","",xbins.size()-1,&xbins[0],ybins.size()-1,&ybins[0],zbins.size()-1,&zbins[0]);
			} else if constexpr(std::is_same_v<Prec,float>) {
				hist = std::make_shared<TH3F>("","",xbins.size()-1,&xbins[0],ybins.size()-1,&ybins[0],zbins.size()-1,&zbins[0]);
			} else if constexpr(std::is_same_v<Prec,double>) {
				hist = std::make_shared<TH3D>("","",xbins.size()-1,&xbins[0],ybins.size()-1,&ybins[0],zbins.size()-1,&zbins[0]);
			}
		}
		hist->SetDirectory(nullptr);
		return hist;
	}

	// create the appropriate histogram given the dimensionality and precision of columns.
	// e.g. makeHist<1,float> -> TH1F
	template <unsigned int Dim, typename Prec>
	std::shared_ptr<TH1> makeHist(size_t nxbins, double xmin, double xmax, size_t nybins=1, double ymin=0, double ymax=1, size_t nzbins=1, double zmin=0, double zmax=1)
	{
		std::shared_ptr<TH1> hist = nullptr;
		if constexpr(Dim==1) {
			if constexpr(std::is_same_v<Prec,char> || std::is_same_v<Prec,bool>) {
				hist = std::make_shared<TH1C>("","",nxbins,xmin,xmax);
			} else if constexpr(std::is_same_v<Prec,int>) {
				hist = std::make_shared<TH1I>("","",nxbins,xmin,xmax);
			} else if constexpr(std::is_same_v<Prec,float>) {
				hist = std::make_shared<TH1F>("","",nxbins,xmin,xmax);
			} else if constexpr(std::is_same_v<Prec,double>) {
				hist = std::make_shared<TH1D>("","",nxbins,xmin,xmax);
			}
		} else if constexpr(Dim==2) {
			if constexpr(std::is_same_v<Prec,char> || std::is_same_v<Prec,bool>) {
				hist = std::make_shared<TH2C>("","",nxbins,xmin,xmax,nybins,ymin,ymax);
			} else if constexpr(std::is_same_v<Prec,int>) {
				hist = std::make_shared<TH2I>("","",nxbins,xmin,xmax,nybins,ymin,ymax);
			} else if constexpr(std::is_same_v<Prec,float>) {
				hist = std::make_shared<TH2F>("","",nxbins,xmin,xmax,nybins,ymin,ymax);
			} else if constexpr(std::is_same_v<Prec,double>) {
				hist = std::make_shared<TH2D>("","",nxbins,xmin,xmax,nybins,ymin,ymax);
			}
		} else if constexpr(Dim==3) {
			if constexpr(std::is_same_v<Prec,char> || std::is_same_v<Prec,bool>) {
				hist = std::make_shared<TH3C>("","",nxbins,xmin,xmax,nybins,ymin,ymax,nzbins,zmin,zmax);
			} else if constexpr(std::is_same_v<Prec,int>) {
				hist = std::make_shared<TH3I>("","",nxbins,xmin,xmax,nybins,ymin,ymax,nzbins,zmin,zmax);
			} else if constexpr(std::is_same_v<Prec,float>) {
				hist = std::make_shared<TH3F>("","",nxbins,xmin,xmax,nybins,ymin,ymax,nzbins,zmin,zmax);
			} else if constexpr(std::is_same_v<Prec,double>) {
				hist = std::make_shared<TH3D>("","",nxbins,xmin,xmax,nybins,ymin,ymax,nzbins,zmin,zmax);
			}
		}
		hist->SetDirectory(nullptr);
		return hist;
	}

	template <typename TH = TH1>
	std::shared_ptr<TH> clone(TH1& hist);

	double normalize(TH1& hist, double scale=1.0);
	int    rebin(TH1& fine, int rebin=-1);

	std::vector<double> getBinsX(TH1& hist);
	std::vector<double> getBinsY(TH1& hist);

	int findBinX(TH1& hist, double x);

	std::shared_ptr<TH1> add(TH1& a, TH1& b);
	std::shared_ptr<TH1> addWithoutError(TH1& a, TH1& b);
	std::shared_ptr<TH1> addInQuadrature(TH1& a, TH1& b);

	std::shared_ptr<TH1> scale(TH1& hist, double scale, double error=0.0, double correl=0.0);
	std::shared_ptr<TH1> multiply(TH1& a, TH1& b);
	std::shared_ptr<TH1> multiplyWithoutError(TH1& a, TH1& b);

	std::shared_ptr<TH1> divide(TH1& num, TH1& denom);
	std::shared_ptr<TH1> divideWithoutError(TH1& num, TH1& denom);

	std::shared_ptr<TH1> projectX(TH2& hist2d);
	std::shared_ptr<TH1> projectY(TH2& hist2d);

	std::shared_ptr<TH1> projectX(TH2& hist2d, int ybin);
	std::shared_ptr<TH1> projectY(TH2& hist2d, int xbin);

	std::shared_ptr<TH1> projectX(TH3& hist3d, int ybin, int zbin);
	std::shared_ptr<TH1> projectY(TH3& hist3d, int xbin, int zbin);
	std::shared_ptr<TH1> projectZ(TH3& hist3d, int xbin, int ybin);

	std::shared_ptr<TH2> projectXY(TH3& hist3d, int zbin);
	std::shared_ptr<TH2> projectYZ(TH3& hist3d, int xbin);
	std::shared_ptr<TH2> projectXZ(TH3& hist3d, int ybin);

	std::shared_ptr<TH1> cutLowX();
	std::shared_ptr<TH1> cutHighX();
	std::shared_ptr<TH1> cutWindowX(TH1& hist, int bin1, int max);

	std::shared_ptr<TH1> zoomLowX();
	std::shared_ptr<TH1> zoomHighX();
	std::shared_ptr<TH1> zoomWindowX();

	std::shared_ptr<TH1> includeUnderflow();
	std::shared_ptr<TH1> includeOverflow();
	std::shared_ptr<TH1> includeUnderOverflow();

}

template <typename TH>
std::shared_ptr<TH> HistogramUtils::clone(TH1& hist)
{
	auto cloned = std::shared_ptr<TH>(static_cast<TH*>(hist.Clone()));
	cloned->SetDirectory(nullptr);
	return cloned;
}