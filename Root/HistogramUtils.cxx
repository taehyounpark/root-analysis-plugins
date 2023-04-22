#include "AnalysisHelpers/HistogramUtils.h"

#include "TMath.h"

std::vector<double> HistogramUtils::getBinsX(TH1& hist)
{
  {
    std::vector<double> bins;
    for (int ix=0 ; ix<hist.GetNbinsX()+1 ; ++ix)
      bins.push_back(hist.GetXaxis()->GetBinLowEdge(ix+1));
    return bins;
  }
}

std::vector<double> HistogramUtils::getBinsY(TH1& hist)
{
  {
    std::vector<double> bins;
    for (int ix=0 ; ix<hist.GetNbinsY()+1 ; ++ix)
      bins.push_back(hist.GetYaxis()->GetBinLowEdge(ix+1));
    return bins;
  }
}

double HistogramUtils::normalize(TH1& hist, double scale)
{
  double nf = scale/hist.Integral("width");
  hist.Scale(nf);
  return nf;
}

int HistogramUtils::rebin(TH1& hist, int rb)
{
  // Get optimal bin withs using Scott's Choise
  double N=hist.GetEffectiveEntries();
  double optWidth = 3.49*hist.GetRMS()/TMath::Power(N,1.0/3);
  int Nbins=hist.GetNbinsX();
  double range=hist.GetBinLowEdge(Nbins+1)-hist.GetBinLowEdge(1);
  if (rb <0) {
    rb=1;
    double prevWidth=range/Nbins;
    for (int i=1;i<Nbins;++i) {
      if (Nbins%i!=0) continue;
      double binWidth=range/Nbins*i;
      if (binWidth<optWidth) rb=i;
      if (binWidth>=optWidth) break;
      prevWidth=binWidth;
    }
  } else if (rb==0) {
    rb = 1;
  }
  hist.Rebin(rb);
  return rb;
}

std::shared_ptr<TH1> HistogramUtils::projectX(TH2& hist, int ybin)
{
  auto projY = std::shared_ptr<TH1>(hist.ProjectionX("",ybin,ybin));
  projY->SetDirectory(0);
  return projY;
}

std::shared_ptr<TH1> HistogramUtils::projectX(TH2& hist)
{
  auto projY = std::shared_ptr<TH1>(hist.ProjectionX("",0,-1));
  projY->SetDirectory(0);
  return projY;
}

std::shared_ptr<TH1> HistogramUtils::projectY(TH2& hist, int xbin)
{
  auto projY = std::shared_ptr<TH1>(hist.ProjectionY("",xbin,xbin));
  projY->SetDirectory(0);
  return projY;
}

std::shared_ptr<TH1> HistogramUtils::projectY(TH2& hist)
{
  auto projY = std::shared_ptr<TH1>(hist.ProjectionY("",0,-1));
  projY->SetDirectory(0);
  return projY;
}