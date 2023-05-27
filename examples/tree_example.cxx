#include <memory>
#include <chrono>
#include <iostream>
#include <sstream>
#include <functional>

#include <ROOT/RVec.hxx>
#include "TPad.h"
#include "TFile.h"
#include "TLorentzVector.h"
#include "TTreeReaderValue.h"
#include "TTreeReader.h"
#include "TVector2.h"
#include "TH1F.h"

#include "ana/abc.h"
#include "ana/analysis.h"

#include "rootana/Tree.h"
#include "rootana/Hist.h"
#include "rootana/Folder.h"

using cut = ana::selection::cut;
using weight = ana::selection::weight;

using VecF = ROOT::RVec<float>;
using VecD = ROOT::RVec<double>;
using VecI = ROOT::RVec<int>;
using VecUI = ROOT::RVec<unsigned int>;
using P4 = TLorentzVector;

class NthP4 : public ana::column::definition<P4(VecD, VecD, VecD, VecD)>
{

public:
  NthP4(unsigned int index) : 
    m_index(index)
  {}
  virtual ~NthP4() = default;

  virtual P4 evaluate(ana::observable<VecD> pt, ana::observable<VecD> eta, ana::observable<VecD> phi, ana::observable<VecD> es) const override {
    P4 p4;
    p4.SetPtEtaPhiE(pt->at(m_index),eta->at(m_index),phi->at(m_index),es->at(m_index));
    return p4;
  }

protected:
  const unsigned int m_index;

};
 
int main() {

  ana::analysis<Tree> ds( {"hww.root"}, "mini" );

  auto mc_weight = ds.read<float>("mcWeight");
  auto el_sf = ds.read<float>("scaleFactor_ELE").vary("sf_var","scaleFactor_PILEUP");
  auto mu_sf = ds.read<float>("scaleFactor_MUON");

  auto lep_pt_MeV = ds.read<VecF>("lep_pt");
  auto lep_eta = ds.read<VecF>("lep_eta");
  auto lep_phi = ds.read<VecF>("lep_phi");
  auto lep_E_MeV = ds.read<VecF>("lep_E");
  auto lep_Q = ds.read<VecF>("lep_charge");
  auto lep_type = ds.read<VecUI>("lep_type");
  auto met_MeV = ds.read<float>("met_et");
  auto met_phi = ds.read<float>("met_phi");

  auto MeV = ds.constant(1000.0);
  auto lep_pt = lep_pt_MeV / MeV;
  auto lep_E = lep_E_MeV / MeV;
  auto met = met_MeV / MeV;

  auto lep_eta_max = ds.constant(2.4);

  auto Escale = ds.define([](VecD E){return E;}).vary("lp4_up",[](VecD E){return E*1.01;}).vary("lp4_dn",[](VecD E){return E*0.99;});
  auto lep_pt_sel = Escale(lep_pt)[ lep_eta < lep_eta_max && lep_eta > (-lep_eta_max) ];
  auto lep_E_sel = Escale(lep_E)[ lep_eta < lep_eta_max && lep_eta > (-lep_eta_max) ];
  auto nlep_sel = ds.define([](VecD const& lep){return lep.size();})(lep_pt_sel);

  auto lep_eta_sel = lep_eta[ lep_eta < lep_eta_max && lep_eta > (-lep_eta_max) ];
  auto lep_phi_sel = lep_phi[ lep_eta < lep_eta_max && lep_eta > (-lep_eta_max) ];

  auto l1p4 = ds.define<NthP4>(0)(lep_pt_sel, lep_eta_sel, lep_phi_sel, lep_E_sel);
  auto l2p4 = ds.define<NthP4>(1)(lep_pt_sel, lep_eta_sel, lep_phi_sel, lep_E_sel);

  auto llp4 = l1p4+l2p4;
  auto mll = ds.define([](const P4& p4){return p4.M();})(llp4);
  auto pth = ds.define(
    [](const P4& p4, float q, float q_phi) {
      TVector2 p2; p2.SetMagPhi(p4.Pt(), p4.Phi());
      TVector2 q2; q2.SetMagPhi(q, q_phi);
      return (p2+q2).Mod();
    })(llp4, met, met_phi);

  auto incl = ds.filter<weight>("incl").evaluate(mc_weight * el_sf * mu_sf);

  auto nlep_req = ds.constant(2);
  auto cut_2los = incl.filter<cut>("2l")(nlep_sel == nlep_req).filter<cut>("2los", [](const VecF& lep_charge){return lep_charge.at(0)+lep_charge.at(1)==0;})(lep_Q);
  auto cut_2ldf = cut_2los.channel<cut>("2ldf", [](const VecI& lep_type){return lep_type.at(0)+lep_type.at(1)==24;})(lep_type);
  auto cut_2lsf = cut_2los.channel<cut>("2lsf", [](const VecI& lep_type){return (lep_type.at(0)+lep_type.at(1)==22)||(lep_type.at(0)+lep_type.at(1)==26);})(lep_type);

  auto mll_cut = ds.constant(80.0), met_cut = ds.constant(30.0);
  auto cut_2ldf_sr = cut_2ldf.filter<cut>("sr")(mll > mll_cut);
  auto cut_2lsf_sr = cut_2lsf.filter<cut>("sr")(met > met_cut);
  auto cut_2ldf_cr = cut_2ldf.filter<cut>("cr")(mll > mll_cut);
  auto cut_2lsf_cr = cut_2lsf.filter<cut>("cr")(met > met_cut);

  auto pth_hist = ds.book<Hist<1,float>>("pth",50,0,400).fill(pth);
  auto pth_2ldf_sr = pth_hist.at(cut_2ldf_sr);
  auto pth_2ldf_cr = pth_hist.at(cut_2ldf_cr);

  auto get_pt = ds.define([](P4 const& p4){return p4.Pt();});
  auto l1pt = get_pt(l1p4);
  auto l2pt = get_pt(l2p4);
  auto l1n2pt_hists = ds.book<Hist<1,float>>(std::string("l1n2pt"),50,0,200).fill(l1pt).fill(l2pt).at(cut_2los, cut_2lsf, cut_2ldf);
  auto pth_hists = ds.book<Hist<1,float>>("pth",50,0,400).fill(pth).at(cut_2los, cut_2ldf, cut_2lsf);

  auto out_file = TFile::Open("hww_results.root","recreate");
  ana::output::dump<Folder>(pth_hists, *out_file, "ggf");
  delete out_file;

  auto mll_vars_2los = ds.book<Hist<1,float>>("mll",50,0,100).fill(mll).at(cut_2los);
  auto mll_nom_2los = mll_vars_2los.get_nominal();
  auto mll_var_2los = mll_vars_2los["lp4_up"];
  mll_nom_2los->SetLineColor(kBlack); mll_nom_2los->Draw("hist");
  mll_var_2los->SetLineColor(kRed); mll_var_2los->Draw("E same");
  gPad->Print("mll_varied_2los.pdf");

  auto mll_vars_channels = ds.book<Hist<1,float>>("mll",50,0,200).fill(mll).at(cut_2ldf, cut_2lsf);
  std::cout << mll_vars_channels.get_nominal()["2ldf"].get_result() << std::endl;
  std::cout << mll_vars_channels["lp4_up"]["2lsf"].get_result() << std::endl;

  return 0;
}