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
#include "ana/multiverse.h"
#include "ana/selection.h"
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

  // ana::analysis<CsvData>::multiverse data({"JES_up", "JES_down"});
  // data.open("mumu.csv");

  // auto pt1 = data.read<double>("pt1");

  return 0;
}