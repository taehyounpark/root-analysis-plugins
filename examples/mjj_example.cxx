#include "ana/analysis.h"

#include "RAnalysis/Tree.h"
#include "RAnalysis/Histogram.h"

int main(void) {

  ana::multithread::enable();

  auto data = ana::analysis<Tree>();

  data.open("dijet.root", "AntiKt4EMPFlow");

  lepton_pTs = 

  return 0;
}