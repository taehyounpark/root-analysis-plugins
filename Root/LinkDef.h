#include "ana/routine.h"
#include "ana/action.h"
#include "ana/concurrent.h"

#include "ana/column.h"
#include "ana/term.h"
#include "ana/constant.h"
#include "ana/definition.h"
#include "ana/equation.h"

#include "ana/selection.h"
#include "ana/cut.h"
#include "ana/weight.h"

#include "ana/counter.h"

#include "ana/computation.h"
#include "ana/experiment.h"
#include "ana/cutflow.h"

#include "ana/input.h"
#include "ana/sample.h"
#include "ana/analysis.h"
#include "ana/output.h"

#include "ana/strutils.h"
#include "ana/vecutils.h"

#include "RAnalysis/TreeData.h"
#include "RAnalysis/CsvData.h"

#include "RAnalysis/Histogram.h"

#ifdef __CINT__


#pragma link off all functions;
#pragma link off all classes;
#pragma link off all globals;

#pragma link C++ class ana::routine+;
#pragma link C++ class ana::action+;

#pragma link C++ class ana::term<float>+;
#pragma link C++ class ana::term<ROOT::RVec<float>>+;
#pragma link C++ class ana::observable<float>+;
#pragma link C++ class ana::variable<float>+;

#pragma link C++ class ana::selection+;
#pragma link C++ class ana::selection::cut+;
#pragma link C++ class ana::selection::weight+;
#pragma link C++ class ana::selection::cutflow+;

#pragma link C++ class ana::counter+;
#pragma link C++ class ana::counter::experiment+;

#pragma link C++ class ana::multithread+;
#pragma link C++ class ana::concurrent<ana::term<float>>+;

#pragma link C++ class Tree;
#pragma link C++ class CsvData;

#pragma link C++ class Histogram<1,float>+;
#pragma link C++ class Histogram<2,float>+;
#pragma link C++ class Histogram<3,float>+;
#pragma link C++ class Histogram<1,ROOT::RVec<float>>+;
#pragma link C++ class Histogram<2,ROOT::RVec<float>>+;
#pragma link C++ class Histogram<3,ROOT::RVec<float>>+;

#pragma link C++ class ana::sample<Tree>+;
#pragma link C++ class ana::analysis<Tree>+;

#pragma link C++ class ana::output+;
#pragma link C++ class Folder+;

#pragma link C++ nestedclass;
#pragma link C++ nestedtypedef;

#endif
