#include <memory>
#include <chrono>
#include <iostream>
#include <sstream>
#include <cmath>

#include <ROOT/RVec.hxx>
#include <ROOT/RCsvDS.hxx>
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

#include "RAnalysis/RDS.h"
#include "RAnalysis/Histogram.h"
#include "RAnalysis/Folder.h"

int main(int argc, char* argv[]) {

  unsigned int nthreads = 0;
  std::stringstream strthreads;
  if (argc>1) { strthreads << argv[1]; strthreads >> nthreads; };
  if (nthreads) ana::multithread::enable(nthreads); else ana::multithread::disable();

  ana::analysis<RDS> mumu;
  auto csv = std::make_unique<ROOT::RDF::RCsvDS>("dimuon.csv");
  mumu.open(std::move(csv));

  auto runNumber = mumu.read<Long64_t>("Run");

  auto Q1 = mumu.read<Long64_t>("Q1");
  auto Q2 = mumu.read<Long64_t>("Q2");

  auto eventWeight = mumu.filter<ana::selection::weight>("weight",[](){return 1;})();
  auto cut2LOS = eventWeight.filter<ana::selection::cut>("2LOS", [](const Long64_t& q1, const Long64_t& q2){return (q1*q2==-1);})(Q1, Q2);

  auto px1 = mumu.read<double>("px1");
  auto py1 = mumu.read<double>("py1");
  auto pz1 = mumu.read<double>("pz1");
  auto E1 = mumu.read<double>("E1");
  auto type1 = mumu.read<std::string>("Type1");

  auto px2 = mumu.read<double>("px2");
  auto py2 = mumu.read<double>("py2");
  auto pz2 = mumu.read<double>("pz2");
  auto E2 = mumu.read<double>("E2");
  auto type2 = mumu.read<std::string>("Type2");

  auto mll = mumu.define([](double const& E1, double const& px1, double const& py1, double const& pz1, double const& E2, double const& px2, double const& py2, double const& pz2) {
    return (sqrt(pow(E1 + E2, 2) - (pow(px1 + px2, 2) + pow(py1 + py2, 2) + pow(pz1 + pz2, 2))));
  }
  )(E1, px1, py1, pz1, E2, px2, py2, pz2);

  auto mll_2los = mumu.book<Histogram<1,float>>("mll", 100, 0.0, 200).fill(mll).at(cut2LOS);

  std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();

  mll_2los.result();

  std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
  std::cout << "Elapsed time = " << std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count() << " [µs]" << std::endl;

  mll_2los.result()->Draw();
  gPad->Print("mll.pdf");

  return 0;
}