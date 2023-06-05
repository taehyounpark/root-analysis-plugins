#include "ana/analysis.h"

#include "rootana/Tree.h"
#include "rootana/RDS.h"

#include "rootana/Hist.h"

#ifdef __CINT__

#pragma link off all functions;
#pragma link off all classes;
#pragma link off all globals;

#pragma link C++ class ana::multithread+;
#pragma link C++ class ana::operation+;

#pragma link C++ class ana::term<float>+;
#pragma link C++ class ana::cell<float>+;
#pragma link C++ class ana::observable<float>+;
#pragma link C++ class ana::variable<float>+;

#pragma link C++ class ana::selection+;
#pragma link C++ class ana::selection::cut+;
#pragma link C++ class ana::selection::weight+;
#pragma link C++ class ana::selection::cutflow+;

#pragma link C++ class ana::aggregation+;
#pragma link C++ class ana::aggregation::experiment+;

#pragma link C++ class Hist<1,float>+;
#pragma link C++ class Hist<2,float>+;
#pragma link C++ class Hist<3,float>+;
#pragma link C++ class Hist<1,ROOT::RVec<float>>+;
#pragma link C++ class Hist<2,ROOT::RVec<float>>+;
#pragma link C++ class Hist<3,ROOT::RVec<float>>+;

#pragma link C++ class Tree+;
#pragma link C++ class RDS+;
#pragma link C++ class Event+;

#pragma link C++ class ana::dataflow<Tree>+;

#pragma link C++ class ana::output+;
#pragma link C++ class Folder+;

#pragma link C++ nestedclass;
#pragma link C++ nestedtypedef;

#endif
