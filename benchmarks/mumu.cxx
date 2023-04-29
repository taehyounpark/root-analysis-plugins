#include <memory>
#include <chrono>
#include <iostream>
#include <sstream>
#include <cmath>

#include <ROOT/RVec.hxx>
#include "TPad.h"
#include "TFile.h"
#include "TLorentzVector.h"
#include "TVector2.h"
#include "TH1F.h"

#include "ana/analysis.h"
#include "ana/selection.h"
#include "ana/varied.h"
#include "ana/column.h"
#include "ana/definition.h"
#include "ana/output.h"

#include "RAnalysis/CsvData.h"
#include "RAnalysis/Histogram.h"
#include "RAnalysis/Folder.h"

int main(int argc, char* argv[]) {

  unsigned int nthreads;
  std::stringstream strthreads;
  if (argc) { strthreads << argv[1]; strthreads >> nthreads; };
  nthreads ? ana::multithread::enable(nthreads) : ana::multithread::disable();

  ana::analysis<CsvData> data(100000);
  data.open("mumu.csv");

  auto runNumber = data.read<Long64_t>("Run");

  auto Q1 = data.read<Long64_t>("Q1");
  auto Q2 = data.read<Long64_t>("Q2");

  auto eventWeight = data.filter<ana::selection::weight>("weight",[](){return 1;})();
  auto cut2LOS = eventWeight.filter<ana::selection::cut>("2LOS", [](const Long64_t& q1, const Long64_t& q2){return (q1*q2==-1);})(Q1, Q2);

  auto px1 = data.read<double>("px1").vary("calib_up", "px2");
  auto py1 = data.read<double>("py1");
  auto pz1 = data.read<double>("pz1");
  auto E1 = data.read<double>("E1");
  auto type1 = data.read<std::string>("Type1");

  // auto px2 = data.read<double>("px2");
  // auto py2 = data.read<double>("py2");
  // auto pz2 = data.read<double>("pz2");
  // auto E2 = data.read<double>("E2");
  // auto type2 = data.read<std::string>("Type2");

  // auto E1syst = data.define([](double x){return x;}).vary("calib_up", [](double x){return x+10;});

  // auto E1vars = E1syst.evaluate(E1);

  // auto mll = data.define([](double const& E1, double const& px1, double const& py1, double const& pz1, double const& E2, double const& px2, double const& py2, double const& pz2) {
  //   return (sqrt(pow(E1 + E2, 2) - (pow(px1 + px2, 2) + pow(py1 + py2, 2) + pow(pz1 + pz2, 2))));
  // }
  // )(E1, px1, py1, pz1, E2, px2, py2, pz2);

  auto mll2LOS = data.book<Histogram<1,float>>(std::string("mll"), 100, 0.0, 200).fill(px1).at(cut2LOS);

  std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();

  auto mllHist = mll2LOS["calib_up"].result();

  std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
  std::cout << "Elapsed time = " << std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count() << "[µs]" << std::endl;

  mll2LOS.nominal().result()->Draw();
  mllHist->Draw("same");
  gPad->Print("mll.pdf");

  return 0;
}