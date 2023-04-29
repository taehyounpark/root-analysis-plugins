#include <memory>
#include <chrono>
#include <iostream>
#include <sstream>

#include <ROOT/RVec.hxx>
#include "TPad.h"
#include "TFile.h"
#include "TLorentzVector.h"
#include "TVector2.h"
#include "TH1F.h"

#include "ana/analysis.h"
#include "ana/selection.h"
#include "ana/column.h"
#include "ana/definition.h"
#include "ana/output.h"

#include "RAnalysis/TreeData.h"
#include "RAnalysis/Histogram.h"
#include "RAnalysis/Folder.h"

class ScaledP4 : public ana::column::definition<TLorentzVector(ROOT::RVec<double>, ROOT::RVec<double>, ROOT::RVec<double>, ROOT::RVec<double>)>
{

public:

  ScaledP4(unsigned int index, double scale=1.0) : 
    ana::column::definition<TLorentzVector(ROOT::RVec<double>, ROOT::RVec<double>, ROOT::RVec<double>, ROOT::RVec<double>)>(),
    m_index(index),
    m_scale(scale)
  {}

  virtual ~ScaledP4() = default;

  virtual TLorentzVector evaluate(ana::observable<ROOT::RVec<double>> pt, ana::observable<ROOT::RVec<double>> eta, ana::observable<ROOT::RVec<double>> phi, ana::observable<ROOT::RVec<double>> es) const override {
    TLorentzVector p4;
    p4.SetPtEtaPhiE(pt->at(m_index)*m_scale,eta->at(m_index),phi->at(m_index),es->at(m_index)*m_scale);
    return p4;
  }

protected:

  unsigned int m_index;
  double m_scale;

};
 
int main(int argc, char* argv[]) {

  // ana::analysis<Tree> data;
  ana::multithread::disable();
  auto data = ana::analysis<TreeData>();
  data.open( "mini", {"hww_mc.root"} );

  auto mc_weight = data.read<float>("mcWeight");
  auto el_sf = data.read<float>("scaleFactor_ELE");
  auto mu_sf = data.read<float>("scaleFactor_MUON");

  auto n_lep = data.read<unsigned int>("lep_n");
  auto lep_pt_MeV = data.read<ROOT::RVec<float>>("lep_pt").vary("lep_ptcone30", "lep_ptcone30");
  auto lep_eta = data.read<ROOT::RVec<float>>("lep_eta");
  auto lep_phi = data.read<ROOT::RVec<float>>("lep_phi");
  auto lep_E_MeV = data.read<ROOT::RVec<float>>("lep_E");
  auto lep_Q = data.read<ROOT::RVec<float>>("lep_charge");
  auto lep_type = data.read<ROOT::RVec<unsigned int>>("lep_type");
  auto met_MeV = data.read<float>("met_et");
  auto met_phi = data.read<float>("met_phi");

  auto GeV = data.constant<double>(1000.0);
  auto lep_pt = lep_pt_MeV / GeV;
  auto lep_E = lep_E_MeV / GeV;
  auto met = met_MeV / GeV;

  auto l1p4 = data.define<ScaledP4>(0)\
                  .vary("lep_p4_up",0,1.1)\
                  .vary("lep_p4_dn",0,0.9)\
                  (lep_pt, lep_eta, lep_phi, lep_E);

  auto l2p4 = data.define<ScaledP4>(1)\
                  .vary("lep_p4_up",1,1.02)\
                  .vary("lep_p4_dn",1,0.98)\
                  (lep_pt, lep_eta, lep_phi, lep_E);

  auto llp4 = data.define([](const TLorentzVector& p4, const TLorentzVector& q4){return (p4+q4);})(l1p4,l2p4);
  auto pth = data.define(
    [](const TLorentzVector& dilep_p4, float met, float met_phi) {
      TVector2 ptll; ptll.SetMagPhi(dilep_p4.Pt(), dilep_p4.Phi());
      TVector2 met2d; met2d.SetMagPhi(met, met_phi);
      return (ptll+met2d).Mod();
    })(llp4, met, met_phi);
  std::cout << pth.list_variation_names().size() << std::endl;

  using cut = ana::selection::cut;
  using weight = ana::selection::weight;
  auto cut2l = data.filter<cut>("2l", [](int n_lep){return (n_lep == 2);})(n_lep)\
                 .filter<weight>("mc_weight")(mc_weight)\
                 .filter<weight>("el_sf")(el_sf)\
                 .filter<weight>("mu_sf")(mu_sf);

  auto cut2los = cut2l.channel<ana::selection::cut>("2los", [](const ROOT::RVec<float>& lep_charge){return lep_charge.at(0)+lep_charge.at(1)==0;})(lep_Q);
  auto cut2ldf = cut2los.filter<ana::selection::cut>("2ldf", [](const ROOT::RVec<int>& lep_type){return lep_type.at(0)+lep_type.at(1)==24;})(lep_type);
  auto cut2lsf = cut2los.filter<ana::selection::cut>("2lsf", [](const ROOT::RVec<int>& lep_type){return (lep_type.at(0)+lep_type.at(1)==22)||(lep_type.at(0)+lep_type.at(1)==26);})(lep_type);

  auto pth_hist_bkr = data.book<Histogram<1,float>>(std::string("pth"), 100,0,400).fill(pth);
  auto pth_hists = data.book<Histogram<1,float>>(std::string("pth"), 100,0,400).fill(pth).at(cut2lsf, cut2ldf);

  // std::cout << pth_hists.has_variation("lep_p4_up") << std::endl;

  std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();

  // data analysis is not executed until results are accessed
  // auto pth_2lsf_nom = pth_hists.nominal()["2los/2lsf"].result();
  // auto pth_2lsf_nom = pth_hists.nominal()["2los/2lsf"].result();

  auto pth_2ldf_nom = pth_hists.nominal()["2los/2ldf"].result();
  auto pth_2ldf_lep_p4_up = pth_hists["lep_p4_up"]["2los/2ldf"].result();

  std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
  std::cout << "Elapsed time = " << std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count() << "[µs]" << std::endl;

  pth_2ldf_nom->Draw();
  pth_2ldf_lep_p4_up->Draw("same hist");
  gPad->Print("pth.pdf");

  // auto outputFile = TFile::Open("hww_results.root","recreate");
  // ana::output::dump<Folder>(pth,*outputFile);
  // delete outputFile;

  return 0;
}