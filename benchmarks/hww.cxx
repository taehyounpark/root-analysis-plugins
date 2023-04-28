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

class NthFourMomentum : public ana::column::definition<TLorentzVector(ROOT::RVec<double>, ROOT::RVec<double>, ROOT::RVec<double>, ROOT::RVec<double>)>
{
public:
  NthFourMomentum(unsigned int index=0) : 
    ana::column::definition<TLorentzVector(ROOT::RVec<double>, ROOT::RVec<double>, ROOT::RVec<double>, ROOT::RVec<double>)>(),
    m_index(index)
  {}
  virtual ~NthFourMomentum() = default;

  virtual TLorentzVector evaluate(ana::observable<ROOT::RVec<double>> pts, ana::observable<ROOT::RVec<double>> etas, ana::observable<ROOT::RVec<double>> phis, ana::observable<ROOT::RVec<double>> es) const override {
    TLorentzVector p4;
    p4.SetPtEtaPhiE(pts->at(m_index),etas->at(m_index),phis->at(m_index),es->at(m_index));
    return p4;
  }

protected:
  unsigned int m_index;
};
 
int main(int argc, char* argv[]) {

  std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();

  unsigned int nthreads;
  std::stringstream strthreads;
  if (argc) { strthreads << argv[1]; strthreads >> nthreads; };
  nthreads ? ana::multithread::enable(nthreads) : ana::multithread::disable();

  // ana::analysis<Tree> data;

  auto data = ana::analysis<TreeData>();

  data.open("mini", std::vector<std::string>{"hww.root"});

  auto mcEventWeight = data.read<float>("mcWeight");
  auto puScaleFactor = data.read<float>("scaleFactor_PILEUP");
  auto btagScaleFactor = data.read<float>("scaleFactor_BTAG");
  auto elScaleFactor = data.read<float>("scaleFactor_ELE");
  auto muScaleFactor = data.read<float>("scaleFactor_MUON");
  auto trigScaleFactor = data.read<float>("scaleFactor_TRIGGER");
  auto jvfScaleFactor = data.read<float>("scaleFactor_JVFSF");
  auto zvtxScaleFactor = data.read<float>("scaleFactor_ZVERTEX");

  data.filter<ana::selection::weight>("mcEventWeight", mcEventWeight);

  auto nlep = data.read<unsigned int>("lep_n");
  // auto lepPts = data.read<ROOT::RVec<float>>("lep_pt");
  // auto lepEtas = data.read<ROOT::RVec<float>>("lep_eta");
  // auto lepPhis = data.read<ROOT::RVec<float>>("lep_phi");
  // auto lepEs = data.read<ROOT::RVec<float>>("lep_E");
  // auto lepCharges = data.read<ROOT::RVec<float>>("lep_charge");
  // auto lepTypes = data.read<ROOT::RVec<unsigned int>>("lep_type");
  // auto met = data.read<float>("met_et");
  // auto metPhi = data.read<float>("met_phi");

  // auto leadLepP4 = data.define<NthFourMomentum>(0);
  // leadLepP4.evaluate(lepPts, lepEtas, lepPhis, lepEs);

  // auto subleadLepP4 = data.define<NthFourMomentum>(1);
  // subleadLepP4.evaluate(lepPts, lepEtas, lepPhis, lepEs);

  // auto dilepP4 = data.evaluate([](const TLorentzVector& p4, const TLorentzVector& q4){return (p4+q4);}, leadLepP4,subleadLepP4 );
  // auto higgsPt = data.evaluate(
  //   [](const TLorentzVector& dilep_p4, float met, float met_phi) {
  //     TVector2 ptll; ptll.SetMagPhi(dilep_p4.Pt(), dilep_p4.Phi());
  //     TVector2 met2d; met2d.SetMagPhi(met, met_phi);
  //     return (ptll+met2d).Mod();
  //   },
  //   dilepP4, met, metPhi
  // );

  auto cut2l = data.filter<ana::selection::cut>("2l", [](const int& nlep){return (nlep == 2);}, nlep);
  // auto cut2los = cut2l.filter<ana::selection::cut>("2los", [](const ROOT::RVec<float>& lep_charge){return (lep_charge.at(0) + lep_charge.at(1) == 0);}, lepCharges);
  // auto cut2ldf = cut2los.filter<ana::selection::cut>("2ldf", [](const ROOT::RVec<int>& lep_type){return (lep_type.at(0) + lep_type.at(1) == 24);}, lepTypes);
  // auto cut2lsf = cut2los.filter<ana::selection::cut>("2lsf", [](const ROOT::RVec<int>& lep_type){return ((lep_type.at(0) + lep_type.at(1) == 22) || (lep_type.at(0) + lep_type.at(1) == 26));}, lepTypes);

  auto higgsPtSpectrum = data.count<Histogram<1,float>>(std::string("higgsPtSpectrum"), 100,0,2e5);
  higgsPtSpectrum.fill(higgsPt);
  // higgsPtSpectrum.book(cut2los, cut2ldf, cut2lsf);
  higgsPtSpectrum.book(cut2l);

  // data analysis is not executed until results are accessed
  // auto higgsPtSpectrum_2ldf = higgsPtSpectrum["2los/2ldf"].result();
  // all other results are already obtained instantaneously
  // auto higgsPtSpectrum_2lsf = higgsPtSpectrum["2los/2lsf"].result();

  std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
  std::cout << "Elapsed time = " << std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count() << "[µs]" << std::endl;

  higgsPtSpectrum_2ldf->Draw();
  higgsPtSpectrum_2lsf->Draw("same");
  gPad->Print("higgsPt.pdf");

  auto outputFile = TFile::Open("hww_results.root","recreate");
  ana::output::dump<Folder>(higgsPtSpectrum,*outputFile);
  delete outputFile;

  return 0;
}