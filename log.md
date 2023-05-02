G++ compilation error (`hww_example.cxx`):
```cpp
In file included from /home/thpark/ana/AnalysisExample/ana/ana/analysis.h:220,
                 from /home/thpark/ana/AnalysisExample/RAnalysis/examples/hww_example.cxx:13:
/home/thpark/ana/AnalysisExample/ana/ana/delayed.h: In instantiation of 'auto ana::analysis<T>::delayed<U>::operator/(const Arg&) const [with Arg = ana::analysis<Tree>::delayed<ana::column::constant<double> >; V = Tree::Branch<ROOT::VecOps::RVec<float> >; std::enable_if_t<(is_column_v<V> && has_division_v<typename std::decay<decltype (declval<V>().value())>::type, typename std::decay<decltype (declval<typename Arg::action_type>().value())>::type>), V>* <anonymous> = 0; U = Tree::Branch<ROOT::VecOps::RVec<float> >; T = Tree]':
/home/thpark/ana/AnalysisExample/ana/ana/varied.h:348:1:   required by substitution of 'template<class Arg> ana::analysis<Tree>::varied<typename decltype (declval<ana::analysis<Tree>::delayed<Tree::Branch<ROOT::VecOps::RVec<float> > > >().ana::analysis<Tree>::delayed<Tree::Branch<ROOT::VecOps::RVec<float> > >::operator/<Arg, V, <anonymous> >(forward<Arg>(b).nominal()))::action_type> ana::analysis<Tree>::varied<Tree::Branch<ROOT::VecOps::RVec<float> > >::operator/<Arg>(Arg&&) const [with Arg = ana::analysis<Tree>::delayed<ana::column::constant<double> >&]'
/home/thpark/ana/AnalysisExample/RAnalysis/examples/hww_example.cxx:72:30:   required from here
/home/thpark/ana/AnalysisExample/ana/ana/delayed.h:23:40: error: no matching function for call to 'ana::analysis<Tree>::define(ana::analysis<Tree>::delayed<Tree::Branch<ROOT::VecOps::RVec<float> > >::operator/<ana::analysis<Tree>::delayed<ana::column::constant<double> > >(const ana::analysis<Tree>::delayed<ana::column::constant<double> >&) const::<lambda(ana::cell_value_t<Tree::Branch<ROOT::VecOps::RVec<float> > >&, ana::cell_value_t<ana::column::constant<double> >&)>)'
   23 |         return this->m_analysis->define([](cell_value_t<V> const& me, cell_value_t<typename Arg::action_type> const& you){ return me op_symbol you; })(*this,other);\
      |                ~~~~~~~~~~~~~~~~~~~~~~~~^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
/home/thpark/ana/AnalysisExample/ana/ana/delayed.h:311:9: note: in expansion of macro 'DEFINE_DELAYED_BINARY_OP'
  311 |         DEFINE_DELAYED_BINARY_OP(division,/)
      |         ^~~~~~~~~~~~~~~~~~~~~~~~
In file included from /home/thpark/ana/AnalysisExample/RAnalysis/examples/hww_example.cxx:13:
/home/thpark/ana/AnalysisExample/ana/ana/analysis.h:107:8: note: candidate: 'template<class Def, class ... Args> ana::analysis<T>::delayed<ana::column::calculator<Def> > ana::analysis<T>::define(const Args& ...) [with Def = Def; Args = {Args ...}; T = Tree]'
  107 |   auto define(const Args&... arguments) -> delayed<column::calculator<Def>>;
      |        ^~~~~~
/home/thpark/ana/AnalysisExample/ana/ana/analysis.h:107:8: note:   template argument deduction/substitution failed:
In file included from /home/thpark/ana/AnalysisExample/ana/ana/analysis.h:220,
                 from /home/thpark/ana/AnalysisExample/RAnalysis/examples/hww_example.cxx:13:
/home/thpark/ana/AnalysisExample/ana/ana/delayed.h:23:40: note:   couldn't deduce template parameter 'Def'
   23 |         return this->m_analysis->define([](cell_value_t<V> const& me, cell_value_t<typename Arg::action_type> const& you){ return me op_symbol you; })(*this,other);\
      |                ~~~~~~~~~~~~~~~~~~~~~~~~^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
/home/thpark/ana/AnalysisExample/ana/ana/delayed.h:311:9: note: in expansion of macro 'DEFINE_DELAYED_BINARY_OP'
  311 |         DEFINE_DELAYED_BINARY_OP(division,/)
      |         ^~~~~~~~~~~~~~~~~~~~~~~~
In file included from /home/thpark/ana/AnalysisExample/RAnalysis/examples/hww_example.cxx:13:
/home/thpark/ana/AnalysisExample/ana/ana/analysis.h:109:8: note: candidate: 'template<class Lmbd> ana::analysis<T>::delayed<ana::column::calculator<typename decltype (ana::column::make_equation((function<...auto...>)(declval<Lmbd>())))::element_type> > ana::analysis<T>::define(const Lmbd&) [with Lmbd = Lmbd; T = Tree]'
  109 |   auto define(Lmbd const& lmbd) -> delayed<column::calculator<column::equation_t<Lmbd>>>;
      |        ^~~~~~
/home/thpark/ana/AnalysisExample/ana/ana/analysis.h:109:8: note:   template argument deduction/substitution failed:
In file included from /home/thpark/ana/AnalysisExample/ana/ana/computation.h:11,
                 from /home/thpark/ana/AnalysisExample/ana/ana/looper.h:8,
                 from /home/thpark/ana/AnalysisExample/ana/ana/sample.h:5,
                 from /home/thpark/ana/AnalysisExample/ana/ana/analysis.h:12,
                 from /home/thpark/ana/AnalysisExample/RAnalysis/examples/hww_example.cxx:13:
/home/thpark/ana/AnalysisExample/ana/ana/column.h: In substitution of 'template<class Lmbd> ana::analysis<Tree>::delayed<ana::column::calculator<typename decltype (ana::column::make_equation((Tree)(declval<Lmbd>())))::element_type> > ana::analysis<Tree>::define<Lmbd>(const Lmbd&) [with Lmbd = ana::analysis<Tree>::delayed<Tree::Branch<ROOT::VecOps::RVec<float> > >::operator/<ana::analysis<Tree>::delayed<ana::column::constant<double> > >(const ana::analysis<Tree>::delayed<ana::column::constant<double> >&) const::<lambda(ana::cell_value_t<Tree::Branch<ROOT::VecOps::RVec<float> > >&, ana::cell_value_t<ana::column::constant<double> >&)>]':
/home/thpark/ana/AnalysisExample/ana/ana/delayed.h:311:2:   required from 'auto ana::analysis<T>::delayed<U>::operator/(const Arg&) const [with Arg = ana::analysis<Tree>::delayed<ana::column::constant<double> >; V = Tree::Branch<ROOT::VecOps::RVec<float> >; std::enable_if_t<(is_column_v<V> && has_division_v<typename std::decay<decltype (declval<V>().value())>::type, typename std::decay<decltype (declval<typename Arg::action_type>().value())>::type>), V>* <anonymous> = 0; U = Tree::Branch<ROOT::VecOps::RVec<float> >; T = Tree]'
/home/thpark/ana/AnalysisExample/ana/ana/varied.h:348:1:   required by substitution of 'template<class Arg> ana::analysis<Tree>::varied<typename decltype (declval<ana::analysis<Tree>::delayed<Tree::Branch<ROOT::VecOps::RVec<float> > > >().ana::analysis<Tree>::delayed<Tree::Branch<ROOT::VecOps::RVec<float> > >::operator/<Arg, V, <anonymous> >(forward<Arg>(b).nominal()))::action_type> ana::analysis<Tree>::varied<Tree::Branch<ROOT::VecOps::RVec<float> > >::operator/<Arg>(Arg&&) const [with Arg = ana::analysis<Tree>::delayed<ana::column::constant<double> >&]'
/home/thpark/ana/AnalysisExample/RAnalysis/examples/hww_example.cxx:72:30:   required from here
/home/thpark/ana/AnalysisExample/ana/ana/column.h:44:84: error: no matching function for call to 'Tree::Tree(ana::analysis<Tree>::delayed<Tree::Branch<ROOT::VecOps::RVec<float> > >::operator/<ana::analysis<Tree>::delayed<ana::column::constant<double> > >(const ana::analysis<Tree>::delayed<ana::column::constant<double> >&) const::<lambda(ana::cell_value_t<Tree::Branch<ROOT::VecOps::RVec<float> > >&, ana::cell_value_t<ana::column::constant<double> >&)>)'
   44 |   template <typename Lmbd> using equation_t = typename decltype(make_equation(std::function(std::declval<Lmbd>())))::element_type;
      |                                                                                    ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
In file included from /home/thpark/ana/AnalysisExample/RAnalysis/examples/hww_example.cxx:17:
/home/thpark/ana/AnalysisExample/RAnalysis/RAnalysis/Tree.h:32:9: note: candidate: 'Tree::Tree(const string&, const std::vector<std::__cxx11::basic_string<char> >&)'
   32 |         Tree(const std::string& treeName, const std::vector<std::string>& allFiles);
      |         ^~~~
/home/thpark/ana/AnalysisExample/RAnalysis/RAnalysis/Tree.h:32:9: note:   candidate expects 2 arguments, 1 provided
/home/thpark/ana/AnalysisExample/RAnalysis/RAnalysis/Tree.h:31:9: note: candidate: 'Tree::Tree(const string&, std::initializer_list<std::__cxx11::basic_string<char> >)'
   31 |         Tree(const std::string& treeName, std::initializer_list<std::string> allFiles);
      |         ^~~~
/home/thpark/ana/AnalysisExample/RAnalysis/RAnalysis/Tree.h:31:9: note:   candidate expects 2 arguments, 1 provided
/home/thpark/ana/AnalysisExample/RAnalysis/RAnalysis/Tree.h:21:7: note: candidate: 'Tree::Tree(const Tree&)'
   21 | class Tree : public ana::input::dataset<Tree>
      |       ^~~~
/home/thpark/ana/AnalysisExample/RAnalysis/RAnalysis/Tree.h:21:7: note:   no known conversion for argument 1 from 'ana::analysis<Tree>::delayed<Tree::Branch<ROOT::VecOps::RVec<float> > >::operator/<ana::analysis<Tree>::delayed<ana::column::constant<double> > >(const ana::analysis<Tree>::delayed<ana::column::constant<double> >&) const::<lambda(ana::cell_value_t<Tree::Branch<ROOT::VecOps::RVec<float> > >&, ana::cell_value_t<ana::column::constant<double> >&)>' to 'const Tree&'
/home/thpark/ana/AnalysisExample/RAnalysis/examples/hww_example.cxx: In function 'int main(int, char**)':
/home/thpark/ana/AnalysisExample/RAnalysis/examples/hww_example.cxx:72:28: error: no match for 'operator/' (operand types are 'ana::analysis<Tree>::varied<Tree::Branch<ROOT::VecOps::RVec<float> > >' and 'ana::analysis<Tree>::delayed<ana::column::constant<double> >')
   72 |   auto lep_pt = lep_pt_MeV / GeV;  // RVec<float> / double
      |                 ~~~~~~~~~~ ^ ~~~
      |                 |            |
      |                 |            ana::analysis<Tree>::delayed<ana::column::constant<double> >
      |                 ana::analysis<Tree>::varied<Tree::Branch<ROOT::VecOps::RVec<float> > >
In file included from /home/thpark/ana/AnalysisExample/ana/ana/delayed.h:351,
                 from /home/thpark/ana/AnalysisExample/ana/ana/analysis.h:220,
                 from /home/thpark/ana/AnalysisExample/RAnalysis/examples/hww_example.cxx:13:
/home/thpark/ana/AnalysisExample/ana/ana/varied.h:21:6: note: candidate: 'template<class Arg> ana::analysis<T>::varied<typename decltype (declval<ana::analysis<T>::delayed<U> >().operator/(forward<Arg>(b).nominal()))::action_type> ana::analysis<T>::varied<U>::operator/(Arg&&) const [with Arg = Arg; Act = Tree::Branch<ROOT::VecOps::RVec<float> >; T = Tree]'
   21 | auto operator op_symbol(Arg&& b) const  -> varied<typename decltype(std::declval<delayed<Act>>().operator op_symbol(std::forward<Arg>(b).nominal()))::action_type>;
      |      ^~~~~~~~
/home/thpark/ana/AnalysisExample/ana/ana/varied.h:138:9: note: in expansion of macro 'DECLARE_VARIED_BINARY_OP'
  138 |         DECLARE_VARIED_BINARY_OP(/)
      |         ^~~~~~~~~~~~~~~~~~~~~~~~
/home/thpark/ana/AnalysisExample/ana/ana/varied.h:21:6: note:   substitution of deduced template arguments resulted in errors seen above
   21 | auto operator op_symbol(Arg&& b) const  -> varied<typename decltype(std::declval<delayed<Act>>().operator op_symbol(std::forward<Arg>(b).nominal()))::action_type>;
      |      ^~~~~~~~
/home/thpark/ana/AnalysisExample/ana/ana/varied.h:138:9: note: in expansion of macro 'DECLARE_VARIED_BINARY_OP'
  138 |         DECLARE_VARIED_BINARY_OP(/)
      |         ^~~~~~~~~~~~~~~~~~~~~~~~
In file included from /home/thpark/ana/AnalysisExample/RAnalysis/examples/hww_example.cxx:6:
/cvmfs/atlas.cern.ch/repo/sw/software/22.2/AnalysisBaseExternals/22.2.110/InstallArea/x86_64-centos7-gcc11-opt/include/ROOT/RVec.hxx:1597:1: note: candidate: 'template<class T0, class T1> ROOT::VecOps::RVec<decltype ((v[0] / y))> ROOT::VecOps::operator/(const ROOT::VecOps::RVec<T>&, const T1&)'
 1597 | RVEC_BINARY_OPERATOR(/)
      | ^~~~~~~~~~~~~~~~~~~~
/cvmfs/atlas.cern.ch/repo/sw/software/22.2/AnalysisBaseExternals/22.2.110/InstallArea/x86_64-centos7-gcc11-opt/include/ROOT/RVec.hxx:1597:1: note:   template argument deduction/substitution failed:
/home/thpark/ana/AnalysisExample/RAnalysis/examples/hww_example.cxx:72:30: note:   'ana::analysis<Tree>::varied<Tree::Branch<ROOT::VecOps::RVec<float> > >' is not derived from 'const ROOT::VecOps::RVec<T>'
   72 |   auto lep_pt = lep_pt_MeV / GeV;  // RVec<float> / double
      |                              ^~~
In file included from /home/thpark/ana/AnalysisExample/RAnalysis/examples/hww_example.cxx:6:
/cvmfs/atlas.cern.ch/repo/sw/software/22.2/AnalysisBaseExternals/22.2.110/InstallArea/x86_64-centos7-gcc11-opt/include/ROOT/RVec.hxx:1597:1: note: candidate: 'template<class T0, class T1> ROOT::VecOps::RVec<decltype ((x / v[0]))> ROOT::VecOps::operator/(const T0&, const ROOT::VecOps::RVec<T1>&)'
 1597 | RVEC_BINARY_OPERATOR(/)
      | ^~~~~~~~~~~~~~~~~~~~
/cvmfs/atlas.cern.ch/repo/sw/software/22.2/AnalysisBaseExternals/22.2.110/InstallArea/x86_64-centos7-gcc11-opt/include/ROOT/RVec.hxx:1597:1: note:   template argument deduction/substitution failed:
/home/thpark/ana/AnalysisExample/RAnalysis/examples/hww_example.cxx:72:30: note:   'ana::analysis<Tree>::delayed<ana::column::constant<double> >' is not derived from 'const ROOT::VecOps::RVec<T1>'
   72 |   auto lep_pt = lep_pt_MeV / GeV;  // RVec<float> / double
      |                              ^~~
In file included from /home/thpark/ana/AnalysisExample/RAnalysis/examples/hww_example.cxx:6:
/cvmfs/atlas.cern.ch/repo/sw/software/22.2/AnalysisBaseExternals/22.2.110/InstallArea/x86_64-centos7-gcc11-opt/include/ROOT/RVec.hxx:1597:1: note: candidate: 'template<class T0, class T1> ROOT::VecOps::RVec<decltype ((v0[0] / v1[0]))> ROOT::VecOps::operator/(const ROOT::VecOps::RVec<T>&, const ROOT::VecOps::RVec<T1>&)'
 1597 | RVEC_BINARY_OPERATOR(/)
      | ^~~~~~~~~~~~~~~~~~~~
/cvmfs/atlas.cern.ch/repo/sw/software/22.2/AnalysisBaseExternals/22.2.110/InstallArea/x86_64-centos7-gcc11-opt/include/ROOT/RVec.hxx:1597:1: note:   template argument deduction/substitution failed:
/home/thpark/ana/AnalysisExample/RAnalysis/examples/hww_example.cxx:72:30: note:   'ana::analysis<Tree>::varied<Tree::Branch<ROOT::VecOps::RVec<float> > >' is not derived from 'const ROOT::VecOps::RVec<T>'
   72 |   auto lep_pt = lep_pt_MeV / GeV;  // RVec<float> / double
      |                              ^~~
In file included from /cvmfs/atlas.cern.ch/repo/sw/software/22.2/AnalysisBaseExternals/22.2.110/InstallArea/x86_64-centos7-gcc11-opt/include/TVector3.h:15,
                 from /cvmfs/atlas.cern.ch/repo/sw/software/22.2/AnalysisBaseExternals/22.2.110/InstallArea/x86_64-centos7-gcc11-opt/include/TLorentzVector.h:25,
                 from /home/thpark/ana/AnalysisExample/RAnalysis/examples/hww_example.cxx:9:
/cvmfs/atlas.cern.ch/repo/sw/software/22.2/AnalysisBaseExternals/22.2.110/InstallArea/x86_64-centos7-gcc11-opt/include/TVector2.h:159:21: note: candidate: 'TVector2 operator/(const TVector2&, Double_t)'
  159 | inline TVector2     operator / (const TVector2& v, Double_t s) {
      |                     ^~~~~~~~
/cvmfs/atlas.cern.ch/repo/sw/software/22.2/AnalysisBaseExternals/22.2.110/InstallArea/x86_64-centos7-gcc11-opt/include/TVector2.h:159:49: note:   no known conversion for argument 1 from 'ana::analysis<Tree>::varied<Tree::Branch<ROOT::VecOps::RVec<float> > >' to 'const TVector2&'
  159 | inline TVector2     operator / (const TVector2& v, Double_t s) {
      |                                 ~~~~~~~~~~~~~~~~^
In file included from /cvmfs/atlas.cern.ch/repo/sw/software/22.2/AnalysisBaseExternals/22.2.110/InstallArea/x86_64-centos7-gcc11-opt/include/TH1F.h:24,
                 from /home/thpark/ana/AnalysisExample/RAnalysis/examples/hww_example.cxx:11:
/cvmfs/atlas.cern.ch/repo/sw/software/22.2/AnalysisBaseExternals/22.2.110/InstallArea/x86_64-centos7-gcc11-opt/include/TH1.h:489:6: note: candidate: 'TH1C operator/(const TH1C&, const TH1C&)'
  489 | TH1C operator/(const TH1C &h1, const TH1C &h2);
      |      ^~~~~~~~
/cvmfs/atlas.cern.ch/repo/sw/software/22.2/AnalysisBaseExternals/22.2.110/InstallArea/x86_64-centos7-gcc11-opt/include/TH1.h:476:43: note:   no known conversion for argument 1 from 'ana::analysis<Tree>::varied<Tree::Branch<ROOT::VecOps::RVec<float> > >' to 'const TH1C&'
  476 |    friend  TH1C     operator/(const TH1C &h1, const TH1C &h2);
      |                               ~~~~~~~~~~~~^~
/cvmfs/atlas.cern.ch/repo/sw/software/22.2/AnalysisBaseExternals/22.2.110/InstallArea/x86_64-centos7-gcc11-opt/include/TH1.h:530:6: note: candidate: 'TH1S operator/(const TH1S&, const TH1S&)'
  530 | TH1S operator/(const TH1S &h1, const TH1S &h2);
      |      ^~~~~~~~
/cvmfs/atlas.cern.ch/repo/sw/software/22.2/AnalysisBaseExternals/22.2.110/InstallArea/x86_64-centos7-gcc11-opt/include/TH1.h:517:43: note:   no known conversion for argument 1 from 'ana::analysis<Tree>::varied<Tree::Branch<ROOT::VecOps::RVec<float> > >' to 'const TH1S&'
  517 |    friend  TH1S     operator/(const TH1S &h1, const TH1S &h2);
      |                               ~~~~~~~~~~~~^~
/cvmfs/atlas.cern.ch/repo/sw/software/22.2/AnalysisBaseExternals/22.2.110/InstallArea/x86_64-centos7-gcc11-opt/include/TH1.h:571:6: note: candidate: 'TH1I operator/(const TH1I&, const TH1I&)'
  571 | TH1I operator/(const TH1I &h1, const TH1I &h2);
      |      ^~~~~~~~
/cvmfs/atlas.cern.ch/repo/sw/software/22.2/AnalysisBaseExternals/22.2.110/InstallArea/x86_64-centos7-gcc11-opt/include/TH1.h:558:43: note:   no known conversion for argument 1 from 'ana::analysis<Tree>::varied<Tree::Branch<ROOT::VecOps::RVec<float> > >' to 'const TH1I&'
  558 |    friend  TH1I     operator/(const TH1I &h1, const TH1I &h2);
      |                               ~~~~~~~~~~~~^~
/cvmfs/atlas.cern.ch/repo/sw/software/22.2/AnalysisBaseExternals/22.2.110/InstallArea/x86_64-centos7-gcc11-opt/include/TH1.h:614:6: note: candidate: 'TH1F operator/(const TH1F&, const TH1F&)'
  614 | TH1F operator/(const TH1F &h1, const TH1F &h2);
      |      ^~~~~~~~
/cvmfs/atlas.cern.ch/repo/sw/software/22.2/AnalysisBaseExternals/22.2.110/InstallArea/x86_64-centos7-gcc11-opt/include/TH1.h:601:43: note:   no known conversion for argument 1 from 'ana::analysis<Tree>::varied<Tree::Branch<ROOT::VecOps::RVec<float> > >' to 'const TH1F&'
  601 |    friend  TH1F     operator/(const TH1F &h1, const TH1F &h2);
      |                               ~~~~~~~~~~~~^~
/cvmfs/atlas.cern.ch/repo/sw/software/22.2/AnalysisBaseExternals/22.2.110/InstallArea/x86_64-centos7-gcc11-opt/include/TH1.h:657:6: note: candidate: 'TH1D operator/(const TH1D&, const TH1D&)'
  657 | TH1D operator/(const TH1D &h1, const TH1D &h2);
      |      ^~~~~~~~
/cvmfs/atlas.cern.ch/repo/sw/software/22.2/AnalysisBaseExternals/22.2.110/InstallArea/x86_64-centos7-gcc11-opt/include/TH1.h:644:43: note:   no known conversion for argument 1 from 'ana::analysis<Tree>::varied<Tree::Branch<ROOT::VecOps::RVec<float> > >' to 'const TH1D&'
  644 |    friend  TH1D     operator/(const TH1D &h1, const TH1D &h2);
      |                               ~~~~~~~~~~~~^~
In file included from /home/thpark/ana/AnalysisExample/ana/ana/analysis.h:220,
                 from /home/thpark/ana/AnalysisExample/RAnalysis/examples/hww_example.cxx:13:
/home/thpark/ana/AnalysisExample/ana/ana/delayed.h: In instantiation of 'auto ana::analysis<T>::delayed<U>::operator/(const Arg&) const [with Arg = ana::analysis<Tree>::delayed<ana::column::constant<double> >; V = Tree::Branch<float>; std::enable_if_t<(is_column_v<V> && has_division_v<typename std::decay<decltype (declval<V>().value())>::type, typename std::decay<decltype (declval<typename Arg::action_type>().value())>::type>), V>* <anonymous> = 0; U = Tree::Branch<float>; T = Tree]':
/home/thpark/ana/AnalysisExample/RAnalysis/examples/hww_example.cxx:74:24:   required from here
/home/thpark/ana/AnalysisExample/ana/ana/delayed.h:23:40: error: no matching function for call to 'ana::analysis<Tree>::define(ana::analysis<Tree>::delayed<Tree::Branch<float> >::operator/<ana::analysis<Tree>::delayed<ana::column::constant<double> > >(const ana::analysis<Tree>::delayed<ana::column::constant<double> >&) const::<lambda(ana::cell_value_t<Tree::Branch<float> >&, ana::cell_value_t<ana::column::constant<double> >&)>)'
   23 |         return this->m_analysis->define([](cell_value_t<V> const& me, cell_value_t<typename Arg::action_type> const& you){ return me op_symbol you; })(*this,other);\
      |                ~~~~~~~~~~~~~~~~~~~~~~~~^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
/home/thpark/ana/AnalysisExample/ana/ana/delayed.h:311:9: note: in expansion of macro 'DEFINE_DELAYED_BINARY_OP'
  311 |         DEFINE_DELAYED_BINARY_OP(division,/)
      |         ^~~~~~~~~~~~~~~~~~~~~~~~
In file included from /home/thpark/ana/AnalysisExample/RAnalysis/examples/hww_example.cxx:13:
/home/thpark/ana/AnalysisExample/ana/ana/analysis.h:107:8: note: candidate: 'template<class Def, class ... Args> ana::analysis<T>::delayed<ana::column::calculator<Def> > ana::analysis<T>::define(const Args& ...) [with Def = Def; Args = {Args ...}; T = Tree]'
  107 |   auto define(const Args&... arguments) -> delayed<column::calculator<Def>>;
      |        ^~~~~~
/home/thpark/ana/AnalysisExample/ana/ana/analysis.h:107:8: note:   template argument deduction/substitution failed:
In file included from /home/thpark/ana/AnalysisExample/ana/ana/analysis.h:220,
                 from /home/thpark/ana/AnalysisExample/RAnalysis/examples/hww_example.cxx:13:
/home/thpark/ana/AnalysisExample/ana/ana/delayed.h:23:40: note:   couldn't deduce template parameter 'Def'
   23 |         return this->m_analysis->define([](cell_value_t<V> const& me, cell_value_t<typename Arg::action_type> const& you){ return me op_symbol you; })(*this,other);\
      |                ~~~~~~~~~~~~~~~~~~~~~~~~^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
/home/thpark/ana/AnalysisExample/ana/ana/delayed.h:311:9: note: in expansion of macro 'DEFINE_DELAYED_BINARY_OP'
  311 |         DEFINE_DELAYED_BINARY_OP(division,/)
      |         ^~~~~~~~~~~~~~~~~~~~~~~~
In file included from /home/thpark/ana/AnalysisExample/RAnalysis/examples/hww_example.cxx:13:
/home/thpark/ana/AnalysisExample/ana/ana/analysis.h:109:8: note: candidate: 'template<class Lmbd> ana::analysis<T>::delayed<ana::column::calculator<typename decltype (ana::column::make_equation((function<...auto...>)(declval<Lmbd>())))::element_type> > ana::analysis<T>::define(const Lmbd&) [with Lmbd = Lmbd; T = Tree]'
  109 |   auto define(Lmbd const& lmbd) -> delayed<column::calculator<column::equation_t<Lmbd>>>;
      |        ^~~~~~
/home/thpark/ana/AnalysisExample/ana/ana/analysis.h:109:8: note:   template argument deduction/substitution failed:
In file included from /home/thpark/ana/AnalysisExample/ana/ana/computation.h:11,
                 from /home/thpark/ana/AnalysisExample/ana/ana/looper.h:8,
                 from /home/thpark/ana/AnalysisExample/ana/ana/sample.h:5,
                 from /home/thpark/ana/AnalysisExample/ana/ana/analysis.h:12,
                 from /home/thpark/ana/AnalysisExample/RAnalysis/examples/hww_example.cxx:13:
/home/thpark/ana/AnalysisExample/ana/ana/column.h: In substitution of 'template<class Lmbd> ana::analysis<Tree>::delayed<ana::column::calculator<typename decltype (ana::column::make_equation((Tree)(declval<Lmbd>())))::element_type> > ana::analysis<Tree>::define<Lmbd>(const Lmbd&) [with Lmbd = ana::analysis<Tree>::delayed<Tree::Branch<float> >::operator/<ana::analysis<Tree>::delayed<ana::column::constant<double> > >(const ana::analysis<Tree>::delayed<ana::column::constant<double> >&) const::<lambda(ana::cell_value_t<Tree::Branch<float> >&, ana::cell_value_t<ana::column::constant<double> >&)>]':
/home/thpark/ana/AnalysisExample/ana/ana/delayed.h:311:2:   required from 'auto ana::analysis<T>::delayed<U>::operator/(const Arg&) const [with Arg = ana::analysis<Tree>::delayed<ana::column::constant<double> >; V = Tree::Branch<float>; std::enable_if_t<(is_column_v<V> && has_division_v<typename std::decay<decltype (declval<V>().value())>::type, typename std::decay<decltype (declval<typename Arg::action_type>().value())>::type>), V>* <anonymous> = 0; U = Tree::Branch<float>; T = Tree]'
/home/thpark/ana/AnalysisExample/RAnalysis/examples/hww_example.cxx:74:24:   required from here
/home/thpark/ana/AnalysisExample/ana/ana/column.h:44:84: error: no matching function for call to 'Tree::Tree(ana::analysis<Tree>::delayed<Tree::Branch<float> >::operator/<ana::analysis<Tree>::delayed<ana::column::constant<double> > >(const ana::analysis<Tree>::delayed<ana::column::constant<double> >&) const::<lambda(ana::cell_value_t<Tree::Branch<float> >&, ana::cell_value_t<ana::column::constant<double> >&)>)'
   44 |   template <typename Lmbd> using equation_t = typename decltype(make_equation(std::function(std::declval<Lmbd>())))::element_type;
      |                                                                                    ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
In file included from /home/thpark/ana/AnalysisExample/RAnalysis/examples/hww_example.cxx:17:
/home/thpark/ana/AnalysisExample/RAnalysis/RAnalysis/Tree.h:32:9: note: candidate: 'Tree::Tree(const string&, const std::vector<std::__cxx11::basic_string<char> >&)'
   32 |         Tree(const std::string& treeName, const std::vector<std::string>& allFiles);
      |         ^~~~
/home/thpark/ana/AnalysisExample/RAnalysis/RAnalysis/Tree.h:32:9: note:   candidate expects 2 arguments, 1 provided
/home/thpark/ana/AnalysisExample/RAnalysis/RAnalysis/Tree.h:31:9: note: candidate: 'Tree::Tree(const string&, std::initializer_list<std::__cxx11::basic_string<char> >)'
   31 |         Tree(const std::string& treeName, std::initializer_list<std::string> allFiles);
      |         ^~~~
/home/thpark/ana/AnalysisExample/RAnalysis/RAnalysis/Tree.h:31:9: note:   candidate expects 2 arguments, 1 provided
/home/thpark/ana/AnalysisExample/RAnalysis/RAnalysis/Tree.h:21:7: note: candidate: 'Tree::Tree(const Tree&)'
   21 | class Tree : public ana::input::dataset<Tree>
      |       ^~~~
/home/thpark/ana/AnalysisExample/RAnalysis/RAnalysis/Tree.h:21:7: note:   no known conversion for argument 1 from 'ana::analysis<Tree>::delayed<Tree::Branch<float> >::operator/<ana::analysis<Tree>::delayed<ana::column::constant<double> > >(const ana::analysis<Tree>::delayed<ana::column::constant<double> >&) const::<lambda(ana::cell_value_t<Tree::Branch<float> >&, ana::cell_value_t<ana::column::constant<double> >&)>' to 'const Tree&'
/home/thpark/ana/AnalysisExample/RAnalysis/examples/hww_example.cxx:77:27: error: no matching function for call to 'ana::analysis<Tree>::define(main(int, char**)::<lambda(RVecF)>)'
   77 |   auto Escale = hww.define([](RVecF E){return E*1.0;}).vary("lp4_up",[](RVecF E){return E*1.01;}).vary("lp4_dn",[](RVecF E){return E*0.99;});
      |                 ~~~~~~~~~~^~~~~~~~~~~~~~~~~~~~~~~~~~~~
In file included from /home/thpark/ana/AnalysisExample/RAnalysis/examples/hww_example.cxx:13:
/home/thpark/ana/AnalysisExample/ana/ana/analysis.h:107:8: note: candidate: 'template<class Def, class ... Args> ana::analysis<T>::delayed<ana::column::calculator<Def> > ana::analysis<T>::define(const Args& ...) [with Def = Def; Args = {Args ...}; T = Tree]'
  107 |   auto define(const Args&... arguments) -> delayed<column::calculator<Def>>;
      |        ^~~~~~
/home/thpark/ana/AnalysisExample/ana/ana/analysis.h:107:8: note:   template argument deduction/substitution failed:
/home/thpark/ana/AnalysisExample/RAnalysis/examples/hww_example.cxx:77:27: note:   couldn't deduce template parameter 'Def'
   77 |   auto Escale = hww.define([](RVecF E){return E*1.0;}).vary("lp4_up",[](RVecF E){return E*1.01;}).vary("lp4_dn",[](RVecF E){return E*0.99;});
      |                 ~~~~~~~~~~^~~~~~~~~~~~~~~~~~~~~~~~~~~~
In file included from /home/thpark/ana/AnalysisExample/RAnalysis/examples/hww_example.cxx:13:
/home/thpark/ana/AnalysisExample/ana/ana/analysis.h:109:8: note: candidate: 'template<class Lmbd> ana::analysis<T>::delayed<ana::column::calculator<typename decltype (ana::column::make_equation((function<...auto...>)(declval<Lmbd>())))::element_type> > ana::analysis<T>::define(const Lmbd&) [with Lmbd = Lmbd; T = Tree]'
  109 |   auto define(Lmbd const& lmbd) -> delayed<column::calculator<column::equation_t<Lmbd>>>;
      |        ^~~~~~
/home/thpark/ana/AnalysisExample/ana/ana/analysis.h:109:8: note:   template argument deduction/substitution failed:
In file included from /home/thpark/ana/AnalysisExample/ana/ana/computation.h:11,
                 from /home/thpark/ana/AnalysisExample/ana/ana/looper.h:8,
                 from /home/thpark/ana/AnalysisExample/ana/ana/sample.h:5,
                 from /home/thpark/ana/AnalysisExample/ana/ana/analysis.h:12,
                 from /home/thpark/ana/AnalysisExample/RAnalysis/examples/hww_example.cxx:13:
/home/thpark/ana/AnalysisExample/ana/ana/column.h: In substitution of 'template<class Lmbd> ana::analysis<Tree>::delayed<ana::column::calculator<typename decltype (ana::column::make_equation((Tree)(declval<Lmbd>())))::element_type> > ana::analysis<Tree>::define<Lmbd>(const Lmbd&) [with Lmbd = main(int, char**)::<lambda(RVecF)>]':
/home/thpark/ana/AnalysisExample/RAnalysis/examples/hww_example.cxx:77:27:   required from here
/home/thpark/ana/AnalysisExample/ana/ana/column.h:44:84: error: no matching function for call to 'Tree::Tree(main(int, char**)::<lambda(RVecF)>)'
   44 |   template <typename Lmbd> using equation_t = typename decltype(make_equation(std::function(std::declval<Lmbd>())))::element_type;
      |                                                                                    ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
In file included from /home/thpark/ana/AnalysisExample/RAnalysis/examples/hww_example.cxx:17:
/home/thpark/ana/AnalysisExample/RAnalysis/RAnalysis/Tree.h:32:9: note: candidate: 'Tree::Tree(const string&, const std::vector<std::__cxx11::basic_string<char> >&)'
   32 |         Tree(const std::string& treeName, const std::vector<std::string>& allFiles);
      |         ^~~~
/home/thpark/ana/AnalysisExample/RAnalysis/RAnalysis/Tree.h:32:9: note:   candidate expects 2 arguments, 1 provided
/home/thpark/ana/AnalysisExample/RAnalysis/RAnalysis/Tree.h:31:9: note: candidate: 'Tree::Tree(const string&, std::initializer_list<std::__cxx11::basic_string<char> >)'
   31 |         Tree(const std::string& treeName, std::initializer_list<std::string> allFiles);
      |         ^~~~
/home/thpark/ana/AnalysisExample/RAnalysis/RAnalysis/Tree.h:31:9: note:   candidate expects 2 arguments, 1 provided
/home/thpark/ana/AnalysisExample/RAnalysis/RAnalysis/Tree.h:21:7: note: candidate: 'Tree::Tree(const Tree&)'
   21 | class Tree : public ana::input::dataset<Tree>
      |       ^~~~
/home/thpark/ana/AnalysisExample/RAnalysis/RAnalysis/Tree.h:21:7: note:   no known conversion for argument 1 from 'main(int, char**)::<lambda(RVecF)>' to 'const Tree&'
In file included from /home/thpark/ana/AnalysisExample/ana/ana/analysis.h:220,
                 from /home/thpark/ana/AnalysisExample/RAnalysis/examples/hww_example.cxx:13:
/home/thpark/ana/AnalysisExample/ana/ana/delayed.h: In instantiation of 'auto ana::analysis<T>::delayed<U>::operator<(const Arg&) const [with Arg = ana::analysis<Tree>::delayed<ana::column::constant<double> >; V = Tree::Branch<ROOT::VecOps::RVec<float> >; std::enable_if_t<(is_column_v<V> && has_less_than_v<typename std::decay<decltype (declval<V>().value())>::type, typename std::decay<decltype (declval<typename Arg::action_type>().value())>::type>), V>* <anonymous> = 0; U = Tree::Branch<ROOT::VecOps::RVec<float> >; T = Tree]':
/home/thpark/ana/AnalysisExample/RAnalysis/examples/hww_example.cxx:78:47:   required from here
/home/thpark/ana/AnalysisExample/ana/ana/delayed.h:23:40: error: no matching function for call to 'ana::analysis<Tree>::define(ana::analysis<Tree>::delayed<Tree::Branch<ROOT::VecOps::RVec<float> > >::operator< <ana::analysis<Tree>::delayed<ana::column::constant<double> > >(const ana::analysis<Tree>::delayed<ana::column::constant<double> >&) const::<lambda(ana::cell_value_t<Tree::Branch<ROOT::VecOps::RVec<float> > >&, ana::cell_value_t<ana::column::constant<double> >&)>)'
   23 |         return this->m_analysis->define([](cell_value_t<V> const& me, cell_value_t<typename Arg::action_type> const& you){ return me op_symbol you; })(*this,other);\
      |                ~~~~~~~~~~~~~~~~~~~~~~~~^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
/home/thpark/ana/AnalysisExample/ana/ana/delayed.h:315:9: note: in expansion of macro 'DEFINE_DELAYED_BINARY_OP'
  315 |         DEFINE_DELAYED_BINARY_OP(less_than,<)
      |         ^~~~~~~~~~~~~~~~~~~~~~~~
In file included from /home/thpark/ana/AnalysisExample/RAnalysis/examples/hww_example.cxx:13:
/home/thpark/ana/AnalysisExample/ana/ana/analysis.h:107:8: note: candidate: 'template<class Def, class ... Args> ana::analysis<T>::delayed<ana::column::calculator<Def> > ana::analysis<T>::define(const Args& ...) [with Def = Def; Args = {Args ...}; T = Tree]'
  107 |   auto define(const Args&... arguments) -> delayed<column::calculator<Def>>;
      |        ^~~~~~
/home/thpark/ana/AnalysisExample/ana/ana/analysis.h:107:8: note:   template argument deduction/substitution failed:
In file included from /home/thpark/ana/AnalysisExample/ana/ana/analysis.h:220,
                 from /home/thpark/ana/AnalysisExample/RAnalysis/examples/hww_example.cxx:13:
/home/thpark/ana/AnalysisExample/ana/ana/delayed.h:23:40: note:   couldn't deduce template parameter 'Def'
   23 |         return this->m_analysis->define([](cell_value_t<V> const& me, cell_value_t<typename Arg::action_type> const& you){ return me op_symbol you; })(*this,other);\
      |                ~~~~~~~~~~~~~~~~~~~~~~~~^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
/home/thpark/ana/AnalysisExample/ana/ana/delayed.h:315:9: note: in expansion of macro 'DEFINE_DELAYED_BINARY_OP'
  315 |         DEFINE_DELAYED_BINARY_OP(less_than,<)
      |         ^~~~~~~~~~~~~~~~~~~~~~~~
In file included from /home/thpark/ana/AnalysisExample/RAnalysis/examples/hww_example.cxx:13:
/home/thpark/ana/AnalysisExample/ana/ana/analysis.h:109:8: note: candidate: 'template<class Lmbd> ana::analysis<T>::delayed<ana::column::calculator<typename decltype (ana::column::make_equation((function<...auto...>)(declval<Lmbd>())))::element_type> > ana::analysis<T>::define(const Lmbd&) [with Lmbd = Lmbd; T = Tree]'
  109 |   auto define(Lmbd const& lmbd) -> delayed<column::calculator<column::equation_t<Lmbd>>>;
      |        ^~~~~~
/home/thpark/ana/AnalysisExample/ana/ana/analysis.h:109:8: note:   template argument deduction/substitution failed:
In file included from /home/thpark/ana/AnalysisExample/ana/ana/computation.h:11,
                 from /home/thpark/ana/AnalysisExample/ana/ana/looper.h:8,
                 from /home/thpark/ana/AnalysisExample/ana/ana/sample.h:5,
                 from /home/thpark/ana/AnalysisExample/ana/ana/analysis.h:12,
                 from /home/thpark/ana/AnalysisExample/RAnalysis/examples/hww_example.cxx:13:
/home/thpark/ana/AnalysisExample/ana/ana/column.h: In substitution of 'template<class Lmbd> ana::analysis<Tree>::delayed<ana::column::calculator<typename decltype (ana::column::make_equation((Tree)(declval<Lmbd>())))::element_type> > ana::analysis<Tree>::define<Lmbd>(const Lmbd&) [with Lmbd = ana::analysis<Tree>::delayed<Tree::Branch<ROOT::VecOps::RVec<float> > >::operator< <ana::analysis<Tree>::delayed<ana::column::constant<double> > >(const ana::analysis<Tree>::delayed<ana::column::constant<double> >&) const::<lambda(ana::cell_value_t<Tree::Branch<ROOT::VecOps::RVec<float> > >&, ana::cell_value_t<ana::column::constant<double> >&)>]':
/home/thpark/ana/AnalysisExample/ana/ana/delayed.h:315:2:   required from 'auto ana::analysis<T>::delayed<U>::operator<(const Arg&) const [with Arg = ana::analysis<Tree>::delayed<ana::column::constant<double> >; V = Tree::Branch<ROOT::VecOps::RVec<float> >; std::enable_if_t<(is_column_v<V> && has_less_than_v<typename std::decay<decltype (declval<V>().value())>::type, typename std::decay<decltype (declval<typename Arg::action_type>().value())>::type>), V>* <anonymous> = 0; U = Tree::Branch<ROOT::VecOps::RVec<float> >; T = Tree]'
/home/thpark/ana/AnalysisExample/RAnalysis/examples/hww_example.cxx:78:47:   required from here
/home/thpark/ana/AnalysisExample/ana/ana/column.h:44:84: error: no matching function for call to 'Tree::Tree(ana::analysis<Tree>::delayed<Tree::Branch<ROOT::VecOps::RVec<float> > >::operator< <ana::analysis<Tree>::delayed<ana::column::constant<double> > >(const ana::analysis<Tree>::delayed<ana::column::constant<double> >&) const::<lambda(ana::cell_value_t<Tree::Branch<ROOT::VecOps::RVec<float> > >&, ana::cell_value_t<ana::column::constant<double> >&)>)'
   44 |   template <typename Lmbd> using equation_t = typename decltype(make_equation(std::function(std::declval<Lmbd>())))::element_type;
      |                                                                                    ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
In file included from /home/thpark/ana/AnalysisExample/RAnalysis/examples/hww_example.cxx:17:
/home/thpark/ana/AnalysisExample/RAnalysis/RAnalysis/Tree.h:32:9: note: candidate: 'Tree::Tree(const string&, const std::vector<std::__cxx11::basic_string<char> >&)'
   32 |         Tree(const std::string& treeName, const std::vector<std::string>& allFiles);
      |         ^~~~
/home/thpark/ana/AnalysisExample/RAnalysis/RAnalysis/Tree.h:32:9: note:   candidate expects 2 arguments, 1 provided
/home/thpark/ana/AnalysisExample/RAnalysis/RAnalysis/Tree.h:31:9: note: candidate: 'Tree::Tree(const string&, std::initializer_list<std::__cxx11::basic_string<char> >)'
   31 |         Tree(const std::string& treeName, std::initializer_list<std::string> allFiles);
      |         ^~~~
/home/thpark/ana/AnalysisExample/RAnalysis/RAnalysis/Tree.h:31:9: note:   candidate expects 2 arguments, 1 provided
/home/thpark/ana/AnalysisExample/RAnalysis/RAnalysis/Tree.h:21:7: note: candidate: 'Tree::Tree(const Tree&)'
   21 | class Tree : public ana::input::dataset<Tree>
      |       ^~~~
/home/thpark/ana/AnalysisExample/RAnalysis/RAnalysis/Tree.h:21:7: note:   no known conversion for argument 1 from 'ana::analysis<Tree>::delayed<Tree::Branch<ROOT::VecOps::RVec<float> > >::operator< <ana::analysis<Tree>::delayed<ana::column::constant<double> > >(const ana::analysis<Tree>::delayed<ana::column::constant<double> >&) const::<lambda(ana::cell_value_t<Tree::Branch<ROOT::VecOps::RVec<float> > >&, ana::cell_value_t<ana::column::constant<double> >&)>' to 'const Tree&'
In file included from /home/thpark/ana/AnalysisExample/ana/ana/analysis.h:220,
                 from /home/thpark/ana/AnalysisExample/RAnalysis/examples/hww_example.cxx:13:
/home/thpark/ana/AnalysisExample/ana/ana/delayed.h: In instantiation of 'auto ana::analysis<T>::delayed<U>::operator-() const [with V = ana::column::constant<double>; std::enable_if_t<(is_column_v<V> && has_minus_v<typename std::decay<decltype (declval<V>().value())>::type>), V>* <anonymous> = 0; U = ana::column::constant<double>; T = Tree]':
/home/thpark/ana/AnalysisExample/RAnalysis/examples/hww_example.cxx:78:74:   required from here
/home/thpark/ana/AnalysisExample/ana/ana/delayed.h:35:40: error: no matching function for call to 'ana::analysis<Tree>::define(ana::analysis<Tree>::delayed<ana::column::constant<double> >::operator-<>() const::<lambda(ana::cell_value_t<ana::column::constant<double> >&)>)'
   35 |         return this->m_analysis->define([](cell_value_t<V> const& me){ return (op_symbol me); })(*this);\
      |                ~~~~~~~~~~~~~~~~~~~~~~~~^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
/home/thpark/ana/AnalysisExample/ana/ana/delayed.h:320:9: note: in expansion of macro 'DEFINE_DELAYED_UNARY_OP'
  320 |         DEFINE_DELAYED_UNARY_OP(minus,-)
      |         ^~~~~~~~~~~~~~~~~~~~~~~
In file included from /home/thpark/ana/AnalysisExample/RAnalysis/examples/hww_example.cxx:13:
/home/thpark/ana/AnalysisExample/ana/ana/analysis.h:107:8: note: candidate: 'template<class Def, class ... Args> ana::analysis<T>::delayed<ana::column::calculator<Def> > ana::analysis<T>::define(const Args& ...) [with Def = Def; Args = {Args ...}; T = Tree]'
  107 |   auto define(const Args&... arguments) -> delayed<column::calculator<Def>>;
      |        ^~~~~~
/home/thpark/ana/AnalysisExample/ana/ana/analysis.h:107:8: note:   template argument deduction/substitution failed:
In file included from /home/thpark/ana/AnalysisExample/ana/ana/analysis.h:220,
                 from /home/thpark/ana/AnalysisExample/RAnalysis/examples/hww_example.cxx:13:
/home/thpark/ana/AnalysisExample/ana/ana/delayed.h:35:40: note:   couldn't deduce template parameter 'Def'
   35 |         return this->m_analysis->define([](cell_value_t<V> const& me){ return (op_symbol me); })(*this);\
      |                ~~~~~~~~~~~~~~~~~~~~~~~~^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
/home/thpark/ana/AnalysisExample/ana/ana/delayed.h:320:9: note: in expansion of macro 'DEFINE_DELAYED_UNARY_OP'
  320 |         DEFINE_DELAYED_UNARY_OP(minus,-)
      |         ^~~~~~~~~~~~~~~~~~~~~~~
In file included from /home/thpark/ana/AnalysisExample/RAnalysis/examples/hww_example.cxx:13:
/home/thpark/ana/AnalysisExample/ana/ana/analysis.h:109:8: note: candidate: 'template<class Lmbd> ana::analysis<T>::delayed<ana::column::calculator<typename decltype (ana::column::make_equation((function<...auto...>)(declval<Lmbd>())))::element_type> > ana::analysis<T>::define(const Lmbd&) [with Lmbd = Lmbd; T = Tree]'
  109 |   auto define(Lmbd const& lmbd) -> delayed<column::calculator<column::equation_t<Lmbd>>>;
      |        ^~~~~~
/home/thpark/ana/AnalysisExample/ana/ana/analysis.h:109:8: note:   template argument deduction/substitution failed:
In file included from /home/thpark/ana/AnalysisExample/ana/ana/computation.h:11,
                 from /home/thpark/ana/AnalysisExample/ana/ana/looper.h:8,
                 from /home/thpark/ana/AnalysisExample/ana/ana/sample.h:5,
                 from /home/thpark/ana/AnalysisExample/ana/ana/analysis.h:12,
                 from /home/thpark/ana/AnalysisExample/RAnalysis/examples/hww_example.cxx:13:
/home/thpark/ana/AnalysisExample/ana/ana/column.h: In substitution of 'template<class Lmbd> ana::analysis<Tree>::delayed<ana::column::calculator<typename decltype (ana::column::make_equation((Tree)(declval<Lmbd>())))::element_type> > ana::analysis<Tree>::define<Lmbd>(const Lmbd&) [with Lmbd = ana::analysis<Tree>::delayed<ana::column::constant<double> >::operator-<>() const::<lambda(ana::cell_value_t<ana::column::constant<double> >&)>]':
/home/thpark/ana/AnalysisExample/ana/ana/delayed.h:320:2:   required from 'auto ana::analysis<T>::delayed<U>::operator-() const [with V = ana::column::constant<double>; std::enable_if_t<(is_column_v<V> && has_minus_v<typename std::decay<decltype (declval<V>().value())>::type>), V>* <anonymous> = 0; U = ana::column::constant<double>; T = Tree]'
/home/thpark/ana/AnalysisExample/RAnalysis/examples/hww_example.cxx:78:74:   required from here
/home/thpark/ana/AnalysisExample/ana/ana/column.h:44:84: error: no matching function for call to 'Tree::Tree(ana::analysis<Tree>::delayed<ana::column::constant<double> >::operator-<>() const::<lambda(ana::cell_value_t<ana::column::constant<double> >&)>)'
   44 |   template <typename Lmbd> using equation_t = typename decltype(make_equation(std::function(std::declval<Lmbd>())))::element_type;
      |                                                                                    ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
In file included from /home/thpark/ana/AnalysisExample/RAnalysis/examples/hww_example.cxx:17:
/home/thpark/ana/AnalysisExample/RAnalysis/RAnalysis/Tree.h:32:9: note: candidate: 'Tree::Tree(const string&, const std::vector<std::__cxx11::basic_string<char> >&)'
   32 |         Tree(const std::string& treeName, const std::vector<std::string>& allFiles);
      |         ^~~~
/home/thpark/ana/AnalysisExample/RAnalysis/RAnalysis/Tree.h:32:9: note:   candidate expects 2 arguments, 1 provided
/home/thpark/ana/AnalysisExample/RAnalysis/RAnalysis/Tree.h:31:9: note: candidate: 'Tree::Tree(const string&, std::initializer_list<std::__cxx11::basic_string<char> >)'
   31 |         Tree(const std::string& treeName, std::initializer_list<std::string> allFiles);
      |         ^~~~
/home/thpark/ana/AnalysisExample/RAnalysis/RAnalysis/Tree.h:31:9: note:   candidate expects 2 arguments, 1 provided
/home/thpark/ana/AnalysisExample/RAnalysis/RAnalysis/Tree.h:21:7: note: candidate: 'Tree::Tree(const Tree&)'
   21 | class Tree : public ana::input::dataset<Tree>
      |       ^~~~
/home/thpark/ana/AnalysisExample/RAnalysis/RAnalysis/Tree.h:21:7: note:   no known conversion for argument 1 from 'ana::analysis<Tree>::delayed<ana::column::constant<double> >::operator-<>() const::<lambda(ana::cell_value_t<ana::column::constant<double> >&)>' to 'const Tree&'
/home/thpark/ana/AnalysisExample/RAnalysis/examples/hww_example.cxx:82:30: error: no matching function for call to 'ana::analysis<Tree>::define(main(int, char**)::<lambda(const RVecF&)>)'
   82 |   auto n_lep_sel = hww.define([](RVecF const& lep){return lep.size();})(lep_pt_sel);
      |                    ~~~~~~~~~~^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
In file included from /home/thpark/ana/AnalysisExample/RAnalysis/examples/hww_example.cxx:13:
/home/thpark/ana/AnalysisExample/ana/ana/analysis.h:107:8: note: candidate: 'template<class Def, class ... Args> ana::analysis<T>::delayed<ana::column::calculator<Def> > ana::analysis<T>::define(const Args& ...) [with Def = Def; Args = {Args ...}; T = Tree]'
  107 |   auto define(const Args&... arguments) -> delayed<column::calculator<Def>>;
      |        ^~~~~~
/home/thpark/ana/AnalysisExample/ana/ana/analysis.h:107:8: note:   template argument deduction/substitution failed:
/home/thpark/ana/AnalysisExample/RAnalysis/examples/hww_example.cxx:82:30: note:   couldn't deduce template parameter 'Def'
   82 |   auto n_lep_sel = hww.define([](RVecF const& lep){return lep.size();})(lep_pt_sel);
      |                    ~~~~~~~~~~^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
In file included from /home/thpark/ana/AnalysisExample/RAnalysis/examples/hww_example.cxx:13:
/home/thpark/ana/AnalysisExample/ana/ana/analysis.h:109:8: note: candidate: 'template<class Lmbd> ana::analysis<T>::delayed<ana::column::calculator<typename decltype (ana::column::make_equation((function<...auto...>)(declval<Lmbd>())))::element_type> > ana::analysis<T>::define(const Lmbd&) [with Lmbd = Lmbd; T = Tree]'
  109 |   auto define(Lmbd const& lmbd) -> delayed<column::calculator<column::equation_t<Lmbd>>>;
      |        ^~~~~~
/home/thpark/ana/AnalysisExample/ana/ana/analysis.h:109:8: note:   template argument deduction/substitution failed:
In file included from /home/thpark/ana/AnalysisExample/ana/ana/computation.h:11,
                 from /home/thpark/ana/AnalysisExample/ana/ana/looper.h:8,
                 from /home/thpark/ana/AnalysisExample/ana/ana/sample.h:5,
                 from /home/thpark/ana/AnalysisExample/ana/ana/analysis.h:12,
                 from /home/thpark/ana/AnalysisExample/RAnalysis/examples/hww_example.cxx:13:
/home/thpark/ana/AnalysisExample/ana/ana/column.h: In substitution of 'template<class Lmbd> ana::analysis<Tree>::delayed<ana::column::calculator<typename decltype (ana::column::make_equation((Tree)(declval<Lmbd>())))::element_type> > ana::analysis<Tree>::define<Lmbd>(const Lmbd&) [with Lmbd = main(int, char**)::<lambda(const RVecF&)>]':
/home/thpark/ana/AnalysisExample/RAnalysis/examples/hww_example.cxx:82:30:   required from here
/home/thpark/ana/AnalysisExample/ana/ana/column.h:44:84: error: no matching function for call to 'Tree::Tree(main(int, char**)::<lambda(const RVecF&)>)'
   44 |   template <typename Lmbd> using equation_t = typename decltype(make_equation(std::function(std::declval<Lmbd>())))::element_type;
      |                                                                                    ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
In file included from /home/thpark/ana/AnalysisExample/RAnalysis/examples/hww_example.cxx:17:
/home/thpark/ana/AnalysisExample/RAnalysis/RAnalysis/Tree.h:32:9: note: candidate: 'Tree::Tree(const string&, const std::vector<std::__cxx11::basic_string<char> >&)'
   32 |         Tree(const std::string& treeName, const std::vector<std::string>& allFiles);
      |         ^~~~
/home/thpark/ana/AnalysisExample/RAnalysis/RAnalysis/Tree.h:32:9: note:   candidate expects 2 arguments, 1 provided
/home/thpark/ana/AnalysisExample/RAnalysis/RAnalysis/Tree.h:31:9: note: candidate: 'Tree::Tree(const string&, std::initializer_list<std::__cxx11::basic_string<char> >)'
   31 |         Tree(const std::string& treeName, std::initializer_list<std::string> allFiles);
      |         ^~~~
/home/thpark/ana/AnalysisExample/RAnalysis/RAnalysis/Tree.h:31:9: note:   candidate expects 2 arguments, 1 provided
/home/thpark/ana/AnalysisExample/RAnalysis/RAnalysis/Tree.h:21:7: note: candidate: 'Tree::Tree(const Tree&)'
   21 | class Tree : public ana::input::dataset<Tree>
      |       ^~~~
/home/thpark/ana/AnalysisExample/RAnalysis/RAnalysis/Tree.h:21:7: note:   no known conversion for argument 1 from 'main(int, char**)::<lambda(const RVecF&)>' to 'const Tree&'
/home/thpark/ana/AnalysisExample/RAnalysis/examples/hww_example.cxx:87:25: error: no matching function for call to 'ana::analysis<Tree>::define(main(int, char**)::<lambda(const TLV&, const TLV&)>)'
   87 |   auto llp4 = hww.define([](const TLV& p4, const TLV& q4){return (p4+q4);})(l1p4,l2p4);
      |               ~~~~~~~~~~^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
In file included from /home/thpark/ana/AnalysisExample/RAnalysis/examples/hww_example.cxx:13:
/home/thpark/ana/AnalysisExample/ana/ana/analysis.h:107:8: note: candidate: 'template<class Def, class ... Args> ana::analysis<T>::delayed<ana::column::calculator<Def> > ana::analysis<T>::define(const Args& ...) [with Def = Def; Args = {Args ...}; T = Tree]'
  107 |   auto define(const Args&... arguments) -> delayed<column::calculator<Def>>;
      |        ^~~~~~
/home/thpark/ana/AnalysisExample/ana/ana/analysis.h:107:8: note:   template argument deduction/substitution failed:
/home/thpark/ana/AnalysisExample/RAnalysis/examples/hww_example.cxx:87:25: note:   couldn't deduce template parameter 'Def'
   87 |   auto llp4 = hww.define([](const TLV& p4, const TLV& q4){return (p4+q4);})(l1p4,l2p4);
      |               ~~~~~~~~~~^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
In file included from /home/thpark/ana/AnalysisExample/RAnalysis/examples/hww_example.cxx:13:
/home/thpark/ana/AnalysisExample/ana/ana/analysis.h:109:8: note: candidate: 'template<class Lmbd> ana::analysis<T>::delayed<ana::column::calculator<typename decltype (ana::column::make_equation((function<...auto...>)(declval<Lmbd>())))::element_type> > ana::analysis<T>::define(const Lmbd&) [with Lmbd = Lmbd; T = Tree]'
  109 |   auto define(Lmbd const& lmbd) -> delayed<column::calculator<column::equation_t<Lmbd>>>;
      |        ^~~~~~
/home/thpark/ana/AnalysisExample/ana/ana/analysis.h:109:8: note:   template argument deduction/substitution failed:
In file included from /home/thpark/ana/AnalysisExample/ana/ana/computation.h:11,
                 from /home/thpark/ana/AnalysisExample/ana/ana/looper.h:8,
                 from /home/thpark/ana/AnalysisExample/ana/ana/sample.h:5,
                 from /home/thpark/ana/AnalysisExample/ana/ana/analysis.h:12,
                 from /home/thpark/ana/AnalysisExample/RAnalysis/examples/hww_example.cxx:13:
/home/thpark/ana/AnalysisExample/ana/ana/column.h: In substitution of 'template<class Lmbd> ana::analysis<Tree>::delayed<ana::column::calculator<typename decltype (ana::column::make_equation((Tree)(declval<Lmbd>())))::element_type> > ana::analysis<Tree>::define<Lmbd>(const Lmbd&) [with Lmbd = main(int, char**)::<lambda(const TLV&, const TLV&)>]':
/home/thpark/ana/AnalysisExample/RAnalysis/examples/hww_example.cxx:87:25:   required from here
/home/thpark/ana/AnalysisExample/ana/ana/column.h:44:84: error: no matching function for call to 'Tree::Tree(main(int, char**)::<lambda(const TLV&, const TLV&)>)'
   44 |   template <typename Lmbd> using equation_t = typename decltype(make_equation(std::function(std::declval<Lmbd>())))::element_type;
      |                                                                                    ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
In file included from /home/thpark/ana/AnalysisExample/RAnalysis/examples/hww_example.cxx:17:
/home/thpark/ana/AnalysisExample/RAnalysis/RAnalysis/Tree.h:32:9: note: candidate: 'Tree::Tree(const string&, const std::vector<std::__cxx11::basic_string<char> >&)'
   32 |         Tree(const std::string& treeName, const std::vector<std::string>& allFiles);
      |         ^~~~
/home/thpark/ana/AnalysisExample/RAnalysis/RAnalysis/Tree.h:32:9: note:   candidate expects 2 arguments, 1 provided
/home/thpark/ana/AnalysisExample/RAnalysis/RAnalysis/Tree.h:31:9: note: candidate: 'Tree::Tree(const string&, std::initializer_list<std::__cxx11::basic_string<char> >)'
   31 |         Tree(const std::string& treeName, std::initializer_list<std::string> allFiles);
      |         ^~~~
/home/thpark/ana/AnalysisExample/RAnalysis/RAnalysis/Tree.h:31:9: note:   candidate expects 2 arguments, 1 provided
/home/thpark/ana/AnalysisExample/RAnalysis/RAnalysis/Tree.h:21:7: note: candidate: 'Tree::Tree(const Tree&)'
   21 | class Tree : public ana::input::dataset<Tree>
      |       ^~~~
/home/thpark/ana/AnalysisExample/RAnalysis/RAnalysis/Tree.h:21:7: note:   no known conversion for argument 1 from 'main(int, char**)::<lambda(const TLV&, const TLV&)>' to 'const Tree&'
/home/thpark/ana/AnalysisExample/RAnalysis/examples/hww_example.cxx:88:24: error: no matching function for call to 'ana::analysis<Tree>::define(main(int, char**)::<lambda(const TLV&, float, float)>)'
   88 |   auto pth = hww.define(
      |              ~~~~~~~~~~^
   89 |     [](const TLV& llp4, float met, float met_phi) {
      |     ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
   90 |       TVector2 ptll; ptll.SetMagPhi(llp4.Pt(), llp4.Phi());
      |       ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
   91 |       TVector2 met2d; met2d.SetMagPhi(met, met_phi);
      |       ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
   92 |       return (ptll+met2d).Mod();
      |       ~~~~~~~~~~~~~~~~~~~~~~~~~~
   93 |     })(llp4, met, met_phi);
      |     ~~                  
In file included from /home/thpark/ana/AnalysisExample/RAnalysis/examples/hww_example.cxx:13:
/home/thpark/ana/AnalysisExample/ana/ana/analysis.h:107:8: note: candidate: 'template<class Def, class ... Args> ana::analysis<T>::delayed<ana::column::calculator<Def> > ana::analysis<T>::define(const Args& ...) [with Def = Def; Args = {Args ...}; T = Tree]'
  107 |   auto define(const Args&... arguments) -> delayed<column::calculator<Def>>;
      |        ^~~~~~
/home/thpark/ana/AnalysisExample/ana/ana/analysis.h:107:8: note:   template argument deduction/substitution failed:
/home/thpark/ana/AnalysisExample/RAnalysis/examples/hww_example.cxx:88:24: note:   couldn't deduce template parameter 'Def'
   88 |   auto pth = hww.define(
      |              ~~~~~~~~~~^
   89 |     [](const TLV& llp4, float met, float met_phi) {
      |     ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
   90 |       TVector2 ptll; ptll.SetMagPhi(llp4.Pt(), llp4.Phi());
      |       ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
   91 |       TVector2 met2d; met2d.SetMagPhi(met, met_phi);
      |       ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
   92 |       return (ptll+met2d).Mod();
      |       ~~~~~~~~~~~~~~~~~~~~~~~~~~
   93 |     })(llp4, met, met_phi);
      |     ~~                  
In file included from /home/thpark/ana/AnalysisExample/RAnalysis/examples/hww_example.cxx:13:
/home/thpark/ana/AnalysisExample/ana/ana/analysis.h:109:8: note: candidate: 'template<class Lmbd> ana::analysis<T>::delayed<ana::column::calculator<typename decltype (ana::column::make_equation((function<...auto...>)(declval<Lmbd>())))::element_type> > ana::analysis<T>::define(const Lmbd&) [with Lmbd = Lmbd; T = Tree]'
  109 |   auto define(Lmbd const& lmbd) -> delayed<column::calculator<column::equation_t<Lmbd>>>;
      |        ^~~~~~
/home/thpark/ana/AnalysisExample/ana/ana/analysis.h:109:8: note:   template argument deduction/substitution failed:
In file included from /home/thpark/ana/AnalysisExample/ana/ana/computation.h:11,
                 from /home/thpark/ana/AnalysisExample/ana/ana/looper.h:8,
                 from /home/thpark/ana/AnalysisExample/ana/ana/sample.h:5,
                 from /home/thpark/ana/AnalysisExample/ana/ana/analysis.h:12,
                 from /home/thpark/ana/AnalysisExample/RAnalysis/examples/hww_example.cxx:13:
/home/thpark/ana/AnalysisExample/ana/ana/column.h: In substitution of 'template<class Lmbd> ana::analysis<Tree>::delayed<ana::column::calculator<typename decltype (ana::column::make_equation((Tree)(declval<Lmbd>())))::element_type> > ana::analysis<Tree>::define<Lmbd>(const Lmbd&) [with Lmbd = main(int, char**)::<lambda(const TLV&, float, float)>]':
/home/thpark/ana/AnalysisExample/RAnalysis/examples/hww_example.cxx:88:24:   required from here
/home/thpark/ana/AnalysisExample/ana/ana/column.h:44:84: error: no matching function for call to 'Tree::Tree(main(int, char**)::<lambda(const TLV&, float, float)>)'
   44 |   template <typename Lmbd> using equation_t = typename decltype(make_equation(std::function(std::declval<Lmbd>())))::element_type;
      |                                                                                    ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
In file included from /home/thpark/ana/AnalysisExample/RAnalysis/examples/hww_example.cxx:17:
/home/thpark/ana/AnalysisExample/RAnalysis/RAnalysis/Tree.h:32:9: note: candidate: 'Tree::Tree(const string&, const std::vector<std::__cxx11::basic_string<char> >&)'
   32 |         Tree(const std::string& treeName, const std::vector<std::string>& allFiles);
      |         ^~~~
/home/thpark/ana/AnalysisExample/RAnalysis/RAnalysis/Tree.h:32:9: note:   candidate expects 2 arguments, 1 provided
/home/thpark/ana/AnalysisExample/RAnalysis/RAnalysis/Tree.h:31:9: note: candidate: 'Tree::Tree(const string&, std::initializer_list<std::__cxx11::basic_string<char> >)'
   31 |         Tree(const std::string& treeName, std::initializer_list<std::string> allFiles);
      |         ^~~~
/home/thpark/ana/AnalysisExample/RAnalysis/RAnalysis/Tree.h:31:9: note:   candidate expects 2 arguments, 1 provided
/home/thpark/ana/AnalysisExample/RAnalysis/RAnalysis/Tree.h:21:7: note: candidate: 'Tree::Tree(const Tree&)'
   21 | class Tree : public ana::input::dataset<Tree>
      |       ^~~~
/home/thpark/ana/AnalysisExample/RAnalysis/RAnalysis/Tree.h:21:7: note:   no known conversion for argument 1 from 'main(int, char**)::<lambda(const TLV&, float, float)>' to 'const Tree&'
In file included from /home/thpark/ana/AnalysisExample/ana/ana/analysis.h:220,
                 from /home/thpark/ana/AnalysisExample/RAnalysis/examples/hww_example.cxx:13:
/home/thpark/ana/AnalysisExample/ana/ana/delayed.h: In instantiation of 'auto ana::analysis<T>::delayed<U>::operator*(const Arg&) const [with Arg = ana::analysis<Tree>::delayed<Tree::Branch<float> >; V = Tree::Branch<float>; std::enable_if_t<(is_column_v<V> && has_multiplication_v<typename std::decay<decltype (declval<V>().value())>::type, typename std::decay<decltype (declval<typename Arg::action_type>().value())>::type>), V>* <anonymous> = 0; U = Tree::Branch<float>; T = Tree]':
/home/thpark/ana/AnalysisExample/RAnalysis/examples/hww_example.cxx:99:66:   required from here
/home/thpark/ana/AnalysisExample/ana/ana/delayed.h:23:40: error: no matching function for call to 'ana::analysis<Tree>::define(ana::analysis<Tree>::delayed<Tree::Branch<float> >::operator*<ana::analysis<Tree>::delayed<Tree::Branch<float> > >(const ana::analysis<Tree>::delayed<Tree::Branch<float> >&) const::<lambda(ana::cell_value_t<Tree::Branch<float> >&, ana::cell_value_t<Tree::Branch<float> >&)>)'
   23 |         return this->m_analysis->define([](cell_value_t<V> const& me, cell_value_t<typename Arg::action_type> const& you){ return me op_symbol you; })(*this,other);\
      |                ~~~~~~~~~~~~~~~~~~~~~~~~^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
/home/thpark/ana/AnalysisExample/ana/ana/delayed.h:310:9: note: in expansion of macro 'DEFINE_DELAYED_BINARY_OP'
  310 |         DEFINE_DELAYED_BINARY_OP(multiplication,*)
      |         ^~~~~~~~~~~~~~~~~~~~~~~~
In file included from /home/thpark/ana/AnalysisExample/RAnalysis/examples/hww_example.cxx:13:
/home/thpark/ana/AnalysisExample/ana/ana/analysis.h:107:8: note: candidate: 'template<class Def, class ... Args> ana::analysis<T>::delayed<ana::column::calculator<Def> > ana::analysis<T>::define(const Args& ...) [with Def = Def; Args = {Args ...}; T = Tree]'
  107 |   auto define(const Args&... arguments) -> delayed<column::calculator<Def>>;
      |        ^~~~~~
/home/thpark/ana/AnalysisExample/ana/ana/analysis.h:107:8: note:   template argument deduction/substitution failed:
In file included from /home/thpark/ana/AnalysisExample/ana/ana/analysis.h:220,
                 from /home/thpark/ana/AnalysisExample/RAnalysis/examples/hww_example.cxx:13:
/home/thpark/ana/AnalysisExample/ana/ana/delayed.h:23:40: note:   couldn't deduce template parameter 'Def'
   23 |         return this->m_analysis->define([](cell_value_t<V> const& me, cell_value_t<typename Arg::action_type> const& you){ return me op_symbol you; })(*this,other);\
      |                ~~~~~~~~~~~~~~~~~~~~~~~~^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
/home/thpark/ana/AnalysisExample/ana/ana/delayed.h:310:9: note: in expansion of macro 'DEFINE_DELAYED_BINARY_OP'
  310 |         DEFINE_DELAYED_BINARY_OP(multiplication,*)
      |         ^~~~~~~~~~~~~~~~~~~~~~~~
In file included from /home/thpark/ana/AnalysisExample/RAnalysis/examples/hww_example.cxx:13:
/home/thpark/ana/AnalysisExample/ana/ana/analysis.h:109:8: note: candidate: 'template<class Lmbd> ana::analysis<T>::delayed<ana::column::calculator<typename decltype (ana::column::make_equation((function<...auto...>)(declval<Lmbd>())))::element_type> > ana::analysis<T>::define(const Lmbd&) [with Lmbd = Lmbd; T = Tree]'
  109 |   auto define(Lmbd const& lmbd) -> delayed<column::calculator<column::equation_t<Lmbd>>>;
      |        ^~~~~~
/home/thpark/ana/AnalysisExample/ana/ana/analysis.h:109:8: note:   template argument deduction/substitution failed:
In file included from /home/thpark/ana/AnalysisExample/ana/ana/computation.h:11,
                 from /home/thpark/ana/AnalysisExample/ana/ana/looper.h:8,
                 from /home/thpark/ana/AnalysisExample/ana/ana/sample.h:5,
                 from /home/thpark/ana/AnalysisExample/ana/ana/analysis.h:12,
                 from /home/thpark/ana/AnalysisExample/RAnalysis/examples/hww_example.cxx:13:
/home/thpark/ana/AnalysisExample/ana/ana/column.h: In substitution of 'template<class Lmbd> ana::analysis<Tree>::delayed<ana::column::calculator<typename decltype (ana::column::make_equation((Tree)(declval<Lmbd>())))::element_type> > ana::analysis<Tree>::define<Lmbd>(const Lmbd&) [with Lmbd = ana::analysis<Tree>::delayed<Tree::Branch<float> >::operator*<ana::analysis<Tree>::delayed<Tree::Branch<float> > >(const ana::analysis<Tree>::delayed<Tree::Branch<float> >&) const::<lambda(ana::cell_value_t<Tree::Branch<float> >&, ana::cell_value_t<Tree::Branch<float> >&)>]':
/home/thpark/ana/AnalysisExample/ana/ana/delayed.h:310:2:   required from 'auto ana::analysis<T>::delayed<U>::operator*(const Arg&) const [with Arg = ana::analysis<Tree>::delayed<Tree::Branch<float> >; V = Tree::Branch<float>; std::enable_if_t<(is_column_v<V> && has_multiplication_v<typename std::decay<decltype (declval<V>().value())>::type, typename std::decay<decltype (declval<typename Arg::action_type>().value())>::type>), V>* <anonymous> = 0; U = Tree::Branch<float>; T = Tree]'
/home/thpark/ana/AnalysisExample/RAnalysis/examples/hww_example.cxx:99:66:   required from here
/home/thpark/ana/AnalysisExample/ana/ana/column.h:44:84: error: no matching function for call to 'Tree::Tree(ana::analysis<Tree>::delayed<Tree::Branch<float> >::operator*<ana::analysis<Tree>::delayed<Tree::Branch<float> > >(const ana::analysis<Tree>::delayed<Tree::Branch<float> >&) const::<lambda(ana::cell_value_t<Tree::Branch<float> >&, ana::cell_value_t<Tree::Branch<float> >&)>)'
   44 |   template <typename Lmbd> using equation_t = typename decltype(make_equation(std::function(std::declval<Lmbd>())))::element_type;
      |                                                                                    ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
In file included from /home/thpark/ana/AnalysisExample/RAnalysis/examples/hww_example.cxx:17:
/home/thpark/ana/AnalysisExample/RAnalysis/RAnalysis/Tree.h:32:9: note: candidate: 'Tree::Tree(const string&, const std::vector<std::__cxx11::basic_string<char> >&)'
   32 |         Tree(const std::string& treeName, const std::vector<std::string>& allFiles);
      |         ^~~~
/home/thpark/ana/AnalysisExample/RAnalysis/RAnalysis/Tree.h:32:9: note:   candidate expects 2 arguments, 1 provided
/home/thpark/ana/AnalysisExample/RAnalysis/RAnalysis/Tree.h:31:9: note: candidate: 'Tree::Tree(const string&, std::initializer_list<std::__cxx11::basic_string<char> >)'
   31 |         Tree(const std::string& treeName, std::initializer_list<std::string> allFiles);
      |         ^~~~
/home/thpark/ana/AnalysisExample/RAnalysis/RAnalysis/Tree.h:31:9: note:   candidate expects 2 arguments, 1 provided
/home/thpark/ana/AnalysisExample/RAnalysis/RAnalysis/Tree.h:21:7: note: candidate: 'Tree::Tree(const Tree&)'
   21 | class Tree : public ana::input::dataset<Tree>
      |       ^~~~
/home/thpark/ana/AnalysisExample/RAnalysis/RAnalysis/Tree.h:21:7: note:   no known conversion for argument 1 from 'ana::analysis<Tree>::delayed<Tree::Branch<float> >::operator*<ana::analysis<Tree>::delayed<Tree::Branch<float> > >(const ana::analysis<Tree>::delayed<Tree::Branch<float> >&) const::<lambda(ana::cell_value_t<Tree::Branch<float> >&, ana::cell_value_t<Tree::Branch<float> >&)>' to 'const Tree&'
/home/thpark/ana/AnalysisExample/RAnalysis/examples/hww_example.cxx:100:30: error: expected primary-expression before '>' token
  100 |                   .filter<cut>("2l")(n_lep_sel == n_lep_req);
      |                              ^
/home/thpark/ana/AnalysisExample/RAnalysis/examples/hww_example.cxx:100:60: error: expression cannot be used as a function
  100 |                   .filter<cut>("2l")(n_lep_sel == n_lep_req);
      |                                                            ^
/home/thpark/ana/AnalysisExample/RAnalysis/examples/hww_example.cxx:102:35: error: expected primary-expression before '>' token
  102 |   auto cut2los = cut2l.channel<cut>("2los",  [](const RVecF& lep_charge){return lep_charge.at(0)+lep_charge.at(1)==0;})(lep_Q);
      |                                   ^
/home/thpark/ana/AnalysisExample/RAnalysis/examples/hww_example.cxx:102:37: warning: left operand of comma operator has no effect [-Wunused-value]
  102 |   auto cut2los = cut2l.channel<cut>("2los",  [](const RVecF& lep_charge){return lep_charge.at(0)+lep_charge.at(1)==0;})(lep_Q);
      |                                     ^~~~~~
/home/thpark/ana/AnalysisExample/RAnalysis/examples/hww_example.cxx:102:120: error: no match for call to '(main(int, char**)::<lambda(const RVecF&)>) (ana::analysis<Tree>::delayed<Tree::Branch<ROOT::VecOps::RVec<float> > >&)'
  102 |   auto cut2los = cut2l.channel<cut>("2los",  [](const RVecF& lep_charge){return lep_charge.at(0)+lep_charge.at(1)==0;})(lep_Q);
      |                                    ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~^~~~~~~
/home/thpark/ana/AnalysisExample/RAnalysis/examples/hww_example.cxx:102:120: note: candidate: 'bool (*)(const RVecF&)' {aka 'bool (*)(const ROOT::VecOps::RVec<float>&)'} (conversion)
/home/thpark/ana/AnalysisExample/RAnalysis/examples/hww_example.cxx:102:120: note:   candidate expects 2 arguments, 2 provided
/home/thpark/ana/AnalysisExample/RAnalysis/examples/hww_example.cxx:102:46: note: candidate: 'main(int, char**)::<lambda(const RVecF&)>'
  102 |   auto cut2los = cut2l.channel<cut>("2los",  [](const RVecF& lep_charge){return lep_charge.at(0)+lep_charge.at(1)==0;})(lep_Q);
      |                                              ^
/home/thpark/ana/AnalysisExample/RAnalysis/examples/hww_example.cxx:102:46: note:   no known conversion for argument 1 from 'ana::analysis<Tree>::delayed<Tree::Branch<ROOT::VecOps::RVec<float> > >' to 'const RVecF&' {aka 'const ROOT::VecOps::RVec<float>&'}
/home/thpark/ana/AnalysisExample/RAnalysis/examples/hww_example.cxx:103:36: error: expected primary-expression before '>' token
  103 |   auto cut2ldf = cut2los.filter<cut>("2ldf", [](const ROOT::RVec<int>& lep_type){return lep_type.at(0)+lep_type.at(1)==24;})(lep_type);
      |                                    ^
/home/thpark/ana/AnalysisExample/RAnalysis/examples/hww_example.cxx:103:38: warning: left operand of comma operator has no effect [-Wunused-value]
  103 |   auto cut2ldf = cut2los.filter<cut>("2ldf", [](const ROOT::RVec<int>& lep_type){return lep_type.at(0)+lep_type.at(1)==24;})(lep_type);
      |                                      ^~~~~~
/home/thpark/ana/AnalysisExample/RAnalysis/examples/hww_example.cxx:103:125: error: no match for call to '(main(int, char**)::<lambda(const ROOT::VecOps::RVec<int>&)>) (ana::analysis<Tree>::delayed<Tree::Branch<ROOT::VecOps::RVec<unsigned int> > >&)'
  103 |   auto cut2ldf = cut2los.filter<cut>("2ldf", [](const ROOT::RVec<int>& lep_type){return lep_type.at(0)+lep_type.at(1)==24;})(lep_type);
      |                                     ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~^~~~~~~~~~
/home/thpark/ana/AnalysisExample/RAnalysis/examples/hww_example.cxx:103:125: note: candidate: 'bool (*)(const ROOT::VecOps::RVec<int>&)' (conversion)
/home/thpark/ana/AnalysisExample/RAnalysis/examples/hww_example.cxx:103:125: note:   candidate expects 2 arguments, 2 provided
/home/thpark/ana/AnalysisExample/RAnalysis/examples/hww_example.cxx:103:46: note: candidate: 'main(int, char**)::<lambda(const ROOT::VecOps::RVec<int>&)>'
  103 |   auto cut2ldf = cut2los.filter<cut>("2ldf", [](const ROOT::RVec<int>& lep_type){return lep_type.at(0)+lep_type.at(1)==24;})(lep_type);
      |                                              ^
/home/thpark/ana/AnalysisExample/RAnalysis/examples/hww_example.cxx:103:46: note:   no known conversion for argument 1 from 'ana::analysis<Tree>::delayed<Tree::Branch<ROOT::VecOps::RVec<unsigned int> > >' to 'const ROOT::VecOps::RVec<int>&'
/home/thpark/ana/AnalysisExample/RAnalysis/examples/hww_example.cxx:104:36: error: expected primary-expression before '>' token
  104 |   auto cut2lsf = cut2los.filter<cut>("2lsf", [](const ROOT::RVec<int>& lep_type){return (lep_type.at(0)+lep_type.at(1)==22)||(lep_type.at(0)+lep_type.at(1)==26);})(lep_type);
      |                                    ^
/home/thpark/ana/AnalysisExample/RAnalysis/examples/hww_example.cxx:104:38: warning: left operand of comma operator has no effect [-Wunused-value]
  104 |   auto cut2lsf = cut2los.filter<cut>("2lsf", [](const ROOT::RVec<int>& lep_type){return (lep_type.at(0)+lep_type.at(1)==22)||(lep_type.at(0)+lep_type.at(1)==26);})(lep_type);
      |                                      ^~~~~~
/home/thpark/ana/AnalysisExample/RAnalysis/examples/hww_example.cxx:104:164: error: no match for call to '(main(int, char**)::<lambda(const ROOT::VecOps::RVec<int>&)>) (ana::analysis<Tree>::delayed<Tree::Branch<ROOT::VecOps::RVec<unsigned int> > >&)'
  104 |   auto cut2lsf = cut2los.filter<cut>("2lsf", [](const ROOT::RVec<int>& lep_type){return (lep_type.at(0)+lep_type.at(1)==22)||(lep_type.at(0)+lep_type.at(1)==26);})(lep_type);
      |                                     ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~^~~~~~~~~~
/home/thpark/ana/AnalysisExample/RAnalysis/examples/hww_example.cxx:104:164: note: candidate: 'bool (*)(const ROOT::VecOps::RVec<int>&)' (conversion)
/home/thpark/ana/AnalysisExample/RAnalysis/examples/hww_example.cxx:104:164: note:   candidate expects 2 arguments, 2 provided
/home/thpark/ana/AnalysisExample/RAnalysis/examples/hww_example.cxx:104:46: note: candidate: 'main(int, char**)::<lambda(const ROOT::VecOps::RVec<int>&)>'
  104 |   auto cut2lsf = cut2los.filter<cut>("2lsf", [](const ROOT::RVec<int>& lep_type){return (lep_type.at(0)+lep_type.at(1)==22)||(lep_type.at(0)+lep_type.at(1)==26);})(lep_type);
      |                                              ^
/home/thpark/ana/AnalysisExample/RAnalysis/examples/hww_example.cxx:104:46: note:   no known conversion for argument 1 from 'ana::analysis<Tree>::delayed<Tree::Branch<ROOT::VecOps::RVec<unsigned int> > >' to 'const ROOT::VecOps::RVec<int>&'
/home/thpark/ana/AnalysisExample/RAnalysis/examples/hww_example.cxx:109:27: error: no matching function for call to 'ana::analysis<Tree>::define(main(int, char**)::<lambda(const TLV&)>)'
  109 |   auto get_pt = hww.define([](TLV const& p4){return p4.Pt();});
      |                 ~~~~~~~~~~^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
In file included from /home/thpark/ana/AnalysisExample/RAnalysis/examples/hww_example.cxx:13:
/home/thpark/ana/AnalysisExample/ana/ana/analysis.h:107:8: note: candidate: 'template<class Def, class ... Args> ana::analysis<T>::delayed<ana::column::calculator<Def> > ana::analysis<T>::define(const Args& ...) [with Def = Def; Args = {Args ...}; T = Tree]'
  107 |   auto define(const Args&... arguments) -> delayed<column::calculator<Def>>;
      |        ^~~~~~
/home/thpark/ana/AnalysisExample/ana/ana/analysis.h:107:8: note:   template argument deduction/substitution failed:
/home/thpark/ana/AnalysisExample/RAnalysis/examples/hww_example.cxx:109:27: note:   couldn't deduce template parameter 'Def'
  109 |   auto get_pt = hww.define([](TLV const& p4){return p4.Pt();});
      |                 ~~~~~~~~~~^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
In file included from /home/thpark/ana/AnalysisExample/RAnalysis/examples/hww_example.cxx:13:
/home/thpark/ana/AnalysisExample/ana/ana/analysis.h:109:8: note: candidate: 'template<class Lmbd> ana::analysis<T>::delayed<ana::column::calculator<typename decltype (ana::column::make_equation((function<...auto...>)(declval<Lmbd>())))::element_type> > ana::analysis<T>::define(const Lmbd&) [with Lmbd = Lmbd; T = Tree]'
  109 |   auto define(Lmbd const& lmbd) -> delayed<column::calculator<column::equation_t<Lmbd>>>;
      |        ^~~~~~
/home/thpark/ana/AnalysisExample/ana/ana/analysis.h:109:8: note:   template argument deduction/substitution failed:
In file included from /home/thpark/ana/AnalysisExample/ana/ana/computation.h:11,
                 from /home/thpark/ana/AnalysisExample/ana/ana/looper.h:8,
                 from /home/thpark/ana/AnalysisExample/ana/ana/sample.h:5,
                 from /home/thpark/ana/AnalysisExample/ana/ana/analysis.h:12,
                 from /home/thpark/ana/AnalysisExample/RAnalysis/examples/hww_example.cxx:13:
/home/thpark/ana/AnalysisExample/ana/ana/column.h: In substitution of 'template<class Lmbd> ana::analysis<Tree>::delayed<ana::column::calculator<typename decltype (ana::column::make_equation((Tree)(declval<Lmbd>())))::element_type> > ana::analysis<Tree>::define<Lmbd>(const Lmbd&) [with Lmbd = main(int, char**)::<lambda(const TLV&)>]':
/home/thpark/ana/AnalysisExample/RAnalysis/examples/hww_example.cxx:109:27:   required from here
/home/thpark/ana/AnalysisExample/ana/ana/column.h:44:84: error: no matching function for call to 'Tree::Tree(main(int, char**)::<lambda(const TLV&)>)'
   44 |   template <typename Lmbd> using equation_t = typename decltype(make_equation(std::function(std::declval<Lmbd>())))::element_type;
      |                                                                                    ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
In file included from /home/thpark/ana/AnalysisExample/RAnalysis/examples/hww_example.cxx:17:
/home/thpark/ana/AnalysisExample/RAnalysis/RAnalysis/Tree.h:32:9: note: candidate: 'Tree::Tree(const string&, const std::vector<std::__cxx11::basic_string<char> >&)'
   32 |         Tree(const std::string& treeName, const std::vector<std::string>& allFiles);
      |         ^~~~
/home/thpark/ana/AnalysisExample/RAnalysis/RAnalysis/Tree.h:32:9: note:   candidate expects 2 arguments, 1 provided
/home/thpark/ana/AnalysisExample/RAnalysis/RAnalysis/Tree.h:31:9: note: candidate: 'Tree::Tree(const string&, std::initializer_list<std::__cxx11::basic_string<char> >)'
   31 |         Tree(const std::string& treeName, std::initializer_list<std::string> allFiles);
      |         ^~~~
/home/thpark/ana/AnalysisExample/RAnalysis/RAnalysis/Tree.h:31:9: note:   candidate expects 2 arguments, 1 provided
/home/thpark/ana/AnalysisExample/RAnalysis/RAnalysis/Tree.h:21:7: note: candidate: 'Tree::Tree(const Tree&)'
   21 | class Tree : public ana::input::dataset<Tree>
      |       ^~~~
/home/thpark/ana/AnalysisExample/RAnalysis/RAnalysis/Tree.h:21:7: note:   no known conversion for argument 1 from 'main(int, char**)::<lambda(const TLV&)>' to 'const Tree&'
/home/thpark/ana/AnalysisExample/RAnalysis/examples/hww_example.cxx:51:14: warning: unused parameter 'argc' [-Wunused-parameter]
   51 | int main(int argc, char* argv[]) {
      |          ~~~~^~~~
/home/thpark/ana/AnalysisExample/RAnalysis/examples/hww_example.cxx:51:26: warning: unused parameter 'argv' [-Wunused-parameter]
   51 | int main(int argc, char* argv[]) {
      |                    ~~~~~~^~~~~~
In file included from /home/thpark/ana/AnalysisExample/RAnalysis/examples/hww_example.cxx:18:
/home/thpark/ana/AnalysisExample/RAnalysis/RAnalysis/Histogram.h: In instantiation of 'void Histogram<1, ROOT::VecOps::RVec<T> >::fill(ana::observable<ROOT::VecOps::RVec<T> >, double) [with Prec = float]':
/home/thpark/ana/AnalysisExample/RAnalysis/RAnalysis/Histogram.h:313:16:   required from here
/home/thpark/ana/AnalysisExample/RAnalysis/RAnalysis/Histogram.h:234:27: warning: comparison of integer expressions of different signedness: 'int' and 'size_t' {aka 'long unsigned int'} [-Wsign-compare]
  234 |         for (int ix=0 ; ix<xs->size() ; ++ix) {
      |                         ~~^~~~~~~~~~~
/home/thpark/ana/AnalysisExample/RAnalysis/RAnalysis/Histogram.h: In instantiation of 'void Histogram<2, ROOT::VecOps::RVec<T> >::fill(ana::observable<ROOT::VecOps::RVec<T> >, ana::observable<ROOT::VecOps::RVec<T> >, double) [with Prec = float]':
/home/thpark/ana/AnalysisExample/RAnalysis/RAnalysis/Histogram.h:314:16:   required from here
/home/thpark/ana/AnalysisExample/RAnalysis/RAnalysis/Histogram.h:263:27: warning: comparison of integer expressions of different signedness: 'int' and 'size_t' {aka 'long unsigned int'} [-Wsign-compare]
  263 |         for (int ix=0 ; ix<xs->size() ; ++ix) {
      |                         ~~^~~~~~~~~~~
/home/thpark/ana/AnalysisExample/RAnalysis/RAnalysis/Histogram.h: In instantiation of 'void Histogram<3, ROOT::VecOps::RVec<T> >::fill(ana::observable<ROOT::VecOps::RVec<T> >, ana::observable<ROOT::VecOps::RVec<T> >, ana::observable<ROOT::VecOps::RVec<T> >, double) [with Prec = float]':
/home/thpark/ana/AnalysisExample/RAnalysis/RAnalysis/Histogram.h:315:16:   required from here
/home/thpark/ana/AnalysisExample/RAnalysis/RAnalysis/Histogram.h:293:27: warning: comparison of integer expressions of different signedness: 'int' and 'size_t' {aka 'long unsigned int'} [-Wsign-compare]
  293 |         for (int ix=0 ; ix<xs->size() ; ++ix) {
      |                         ~~^~~~~~~~~~~
In file included from /home/thpark/ana/AnalysisExample/RAnalysis/examples/hww_example.cxx:13:
/home/thpark/ana/AnalysisExample/ana/ana/analysis.h: In instantiation of 'ana::analysis<T>::delayed<ana::selection::calculator<ana::column::equation<double(double)> > > ana::analysis<T>::filter(const string&) [with Sel = ana::selection::weight; T = Tree; std::string = std::__cxx11::basic_string<char>]':
/home/thpark/ana/AnalysisExample/RAnalysis/examples/hww_example.cxx:99:34:   required from here
/home/thpark/ana/AnalysisExample/ana/ana/analysis.h:296:168: error: no matching function for call to 'ana::looper<Tree::Reader>::filter<ana::selection::weight>(const string&, ana::analysis<Tree>::filter<ana::selection::weight>(const string&)::<lambda(ana::looper<Tree::Reader>&)>::<lambda(double)>)'
  296 |         auto sel = delayed<simple_selection_calculator_type>(*this, this->m_loopers.from_slots( [=](looper<dataset_reader_type>& lpr) { return lpr.template filter<Sel>(name,[](double x){return x;}); } ));
      |                                                                                                                                                ~~~~~~~~~~~~~~~~~~~~~~~~^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
In file included from /home/thpark/ana/AnalysisExample/ana/ana/experiment.h:8,
                 from /home/thpark/ana/AnalysisExample/ana/ana/looper.h:9,
                 from /home/thpark/ana/AnalysisExample/ana/ana/sample.h:5,
                 from /home/thpark/ana/AnalysisExample/ana/ana/analysis.h:12,
                 from /home/thpark/ana/AnalysisExample/RAnalysis/examples/hww_example.cxx:13:
/home/thpark/ana/AnalysisExample/ana/ana/cutflow.h:24:14: note: candidate: 'template<class Sel, class Lmbd> std::shared_ptr<ana::selection::calculator<typename decltype (ana::column::make_equation((function<...auto...>)(declval<Lmbd>())))::element_type> > ana::selection::cutflow::filter(const string&, Lmbd&&)'
   24 |         auto filter(const std::string& name, Lmbd&& lmbd) -> std::shared_ptr<calculator<column::equation_t<Lmbd>>>;
      |              ^~~~~~
/home/thpark/ana/AnalysisExample/ana/ana/cutflow.h:24:14: note:   template argument deduction/substitution failed:
In file included from /home/thpark/ana/AnalysisExample/ana/ana/computation.h:11,
                 from /home/thpark/ana/AnalysisExample/ana/ana/looper.h:8,
                 from /home/thpark/ana/AnalysisExample/ana/ana/sample.h:5,
                 from /home/thpark/ana/AnalysisExample/ana/ana/analysis.h:12,
                 from /home/thpark/ana/AnalysisExample/RAnalysis/examples/hww_example.cxx:13:
/home/thpark/ana/AnalysisExample/ana/ana/column.h: In substitution of 'template<class Sel, class Lmbd> std::shared_ptr<ana::selection::calculator<typename decltype (ana::column::make_equation((function<...auto...>)(declval<Lmbd>())))::element_type> > ana::selection::cutflow::filter(const string&, Lmbd&&) [with Sel = ana::selection::weight; Lmbd = ana::analysis<Tree>::filter<ana::selection::weight>(const string&)::<lambda(ana::looper<Tree::Reader>&)>::<lambda(double)>]':
/home/thpark/ana/AnalysisExample/ana/ana/analysis.h:296:161:   required from 'ana::analysis<T>::delayed<ana::selection::calculator<ana::column::equation<double(double)> > > ana::analysis<T>::filter(const string&) [with Sel = ana::selection::weight; T = Tree; std::string = std::__cxx11::basic_string<char>]'
/home/thpark/ana/AnalysisExample/RAnalysis/examples/hww_example.cxx:99:34:   required from here
/home/thpark/ana/AnalysisExample/ana/ana/column.h:44:84: error: no matching function for call to 'ana::selection::weight::weight(ana::analysis<Tree>::filter<ana::selection::weight>(const string&)::<lambda(ana::looper<Tree::Reader>&)>::<lambda(double)>)'
   44 |   template <typename Lmbd> using equation_t = typename decltype(make_equation(std::function(std::declval<Lmbd>())))::element_type;
      |                                                                                    ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
In file included from /home/thpark/ana/AnalysisExample/ana/ana/cutflow.h:10,
                 from /home/thpark/ana/AnalysisExample/ana/ana/experiment.h:8,
                 from /home/thpark/ana/AnalysisExample/ana/ana/looper.h:9,
                 from /home/thpark/ana/AnalysisExample/ana/ana/sample.h:5,
                 from /home/thpark/ana/AnalysisExample/ana/ana/analysis.h:12,
                 from /home/thpark/ana/AnalysisExample/RAnalysis/examples/hww_example.cxx:13:
/home/thpark/ana/AnalysisExample/ana/ana/weight.h:17:9: note: candidate: 'ana::selection::weight::weight(const string&)'
   17 |         weight(const std::string& name);
      |         ^~~~~~
/home/thpark/ana/AnalysisExample/ana/ana/weight.h:17:35: note:   no known conversion for argument 1 from 'ana::analysis<Tree>::filter<ana::selection::weight>(const string&)::<lambda(ana::looper<Tree::Reader>&)>::<lambda(double)>' to 'const string&' {aka 'const std::__cxx11::basic_string<char>&'}
   17 |         weight(const std::string& name);
      |                ~~~~~~~~~~~~~~~~~~~^~~~
/home/thpark/ana/AnalysisExample/ana/ana/weight.h:9:18: note: candidate: 'ana::selection::weight::weight(const ana::selection::weight&)'
    9 | class selection::weight : public selection
      |                  ^~~~~~
/home/thpark/ana/AnalysisExample/ana/ana/weight.h:9:18: note:   no known conversion for argument 1 from 'ana::analysis<Tree>::filter<ana::selection::weight>(const string&)::<lambda(ana::looper<Tree::Reader>&)>::<lambda(double)>' to 'const ana::selection::weight&'
In file included from /home/thpark/ana/AnalysisExample/ana/ana/experiment.h:8,
                 from /home/thpark/ana/AnalysisExample/ana/ana/looper.h:9,
                 from /home/thpark/ana/AnalysisExample/ana/ana/sample.h:5,
                 from /home/thpark/ana/AnalysisExample/ana/ana/analysis.h:12,
                 from /home/thpark/ana/AnalysisExample/RAnalysis/examples/hww_example.cxx:13:
/home/thpark/ana/AnalysisExample/ana/ana/analysis.h: In instantiation of 'ana::analysis<T>::delayed<ana::selection::calculator<ana::column::equation<double(double)> > > ana::analysis<T>::filter(const string&) [with Sel = ana::selection::weight; T = Tree; std::string = std::__cxx11::basic_string<char>]':
/home/thpark/ana/AnalysisExample/RAnalysis/examples/hww_example.cxx:99:34:   required from here
/home/thpark/ana/AnalysisExample/ana/ana/cutflow.h:30:14: note: candidate: 'template<class Sel, class Lmbd> std::shared_ptr<ana::selection::calculator<typename decltype (ana::column::make_equation((function<...auto...>)(declval<Lmbd>())))::element_type> > ana::selection::cutflow::filter(const ana::selection&, const string&, Lmbd&&)'
   30 |         auto filter(selection const& prev, const std::string& name, Lmbd&& lmbd) -> std::shared_ptr<calculator<column::equation_t<Lmbd>>>;
      |              ^~~~~~
/home/thpark/ana/AnalysisExample/ana/ana/cutflow.h:30:14: note:   template argument deduction/substitution failed:
In file included from /home/thpark/ana/AnalysisExample/RAnalysis/examples/hww_example.cxx:13:
/home/thpark/ana/AnalysisExample/ana/ana/analysis.h:296:168: note:   candidate expects 3 arguments, 2 provided
  296 |         auto sel = delayed<simple_selection_calculator_type>(*this, this->m_loopers.from_slots( [=](looper<dataset_reader_type>& lpr) { return lpr.template filter<Sel>(name,[](double x){return x;}); } ));
      |                                                                                                                                                ~~~~~~~~~~~~~~~~~~~~~~~~^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
/home/thpark/ana/AnalysisExample/ana/ana/analysis.h:296:95: error: no matching function for call to 'ana::concurrent<ana::looper<Tree::Reader> >::from_slots(ana::analysis<Tree>::filter<ana::selection::weight>(const string&)::<lambda(ana::looper<Tree::Reader>&)>)'
  296 |         auto sel = delayed<simple_selection_calculator_type>(*this, this->m_loopers.from_slots( [=](looper<dataset_reader_type>& lpr) { return lpr.template filter<Sel>(name,[](double x){return x;}); } ));
      |                                                                     ~~~~~~~~~~~~~~~~~~~~~~~~~~^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
In file included from /home/thpark/ana/AnalysisExample/ana/ana/sample.h:3,
                 from /home/thpark/ana/AnalysisExample/ana/ana/analysis.h:12,
                 from /home/thpark/ana/AnalysisExample/RAnalysis/examples/hww_example.cxx:13:
/home/thpark/ana/AnalysisExample/ana/ana/concurrent.h:67:8: note: candidate: 'template<class Lmbd, class ... Args> ana::concurrent<typename std::invoke_result<Lmbd, T&, Args& ...>::type::element_type> ana::concurrent<T>::from_slots(Lmbd, const ana::concurrent<Args>& ...) const [with Lmbd = Lmbd; Args = {Args ...}; T = ana::looper<Tree::Reader>]'
   67 |   auto from_slots(Lmbd lmbd, const concurrent<Args>&... args) const -> concurrent<typename std::invoke_result_t<Lmbd,T&,Args&...>::element_type>;
      |        ^~~~~~~~~~
/home/thpark/ana/AnalysisExample/ana/ana/concurrent.h:67:8: note:   template argument deduction/substitution failed:
In file included from /home/thpark/ana/AnalysisExample/ana/ana/sample.h:3,
                 from /home/thpark/ana/AnalysisExample/ana/ana/analysis.h:12,
                 from /home/thpark/ana/AnalysisExample/RAnalysis/examples/hww_example.cxx:13:
/home/thpark/ana/AnalysisExample/ana/ana/concurrent.h: In substitution of 'template<class Lmbd, class ... Args> ana::concurrent<typename std::invoke_result<Lmbd, ana::looper<Tree::Reader>&, Args& ...>::type::element_type> ana::concurrent<ana::looper<Tree::Reader> >::from_slots<Lmbd, Args ...>(Lmbd, const ana::concurrent<Args>& ...) const [with Lmbd = ana::analysis<Tree>::filter<ana::selection::weight>(const string&)::<lambda(ana::looper<Tree::Reader>&)>; Args = {}]':
/home/thpark/ana/AnalysisExample/ana/ana/analysis.h:296:88:   required from 'ana::analysis<T>::delayed<ana::selection::calculator<ana::column::equation<double(double)> > > ana::analysis<T>::filter(const string&) [with Sel = ana::selection::weight; T = Tree; std::string = std::__cxx11::basic_string<char>]'
/home/thpark/ana/AnalysisExample/RAnalysis/examples/hww_example.cxx:99:34:   required from here
/home/thpark/ana/AnalysisExample/ana/ana/concurrent.h:158:6: error: no type named 'type' in 'struct std::invoke_result<ana::analysis<Tree>::filter<ana::selection::weight>(const string&)::<lambda(ana::looper<Tree::Reader>&)>, ana::looper<Tree::Reader>&>'
  158 | auto ana::concurrent<T>::from_slots(Lmbd lmbd, const concurrent<Args>&... args) const -> concurrent<typename std::invoke_result_t<Lmbd,T&,Args&...>::element_type>
      |      ^~~
In file included from /home/thpark/ana/AnalysisExample/ana/ana/delayed.h:352,
                 from /home/thpark/ana/AnalysisExample/ana/ana/analysis.h:220,
                 from /home/thpark/ana/AnalysisExample/RAnalysis/examples/hww_example.cxx:13:
/home/thpark/ana/AnalysisExample/ana/ana/reader.h: In instantiation of 'ana::term<T>::reader::reader(const string&) [with T = ROOT::VecOps::RVec<bool>; std::string = std::__cxx11::basic_string<char>]':
/home/thpark/ana/AnalysisExample/ana/ana/reader.h:48:23:   required from 'ana::column::reader<T>::reader(const string&) [with T = ROOT::VecOps::RVec<bool>; std::string = std::__cxx11::basic_string<char>]'
/home/thpark/ana/AnalysisExample/RAnalysis/RAnalysis/Tree.h:137:27:   required from here
/home/thpark/ana/AnalysisExample/ana/ana/reader.h:23:18: warning: 'ana::term<ROOT::VecOps::RVec<bool> >::reader::m_addr' will be initialized after [-Wreorder]
   23 |         const T* m_addr;
      |                  ^~~~~~
/home/thpark/ana/AnalysisExample/ana/ana/reader.h:22:21: warning:   'const string ana::term<ROOT::VecOps::RVec<bool> >::reader::m_name' [-Wreorder]
   22 |   const std::string m_name;
      |                     ^~~~~~
/home/thpark/ana/AnalysisExample/ana/ana/reader.h:40:2: warning:   when initialized here [-Wreorder]
   40 |  ana::term<T>::reader::reader(const std::string& name) :
      |  ^~~
/home/thpark/ana/AnalysisExample/ana/ana/reader.h: In instantiation of 'ana::term<T>::reader::reader(const string&) [with T = float; std::string = std::__cxx11::basic_string<char>]':
/home/thpark/ana/AnalysisExample/ana/ana/reader.h:48:23:   required from 'ana::column::reader<T>::reader(const string&) [with T = float; std::string = std::__cxx11::basic_string<char>]'
/home/thpark/ana/AnalysisExample/RAnalysis/RAnalysis/Tree.h:71:27:   required from 'Tree::Branch<T>::Branch(const string&, TTreeReader&) [with T = float; std::string = std::__cxx11::basic_string<char>]'
/cvmfs/sft.cern.ch/lcg/releases/gcc/11.2.0-8a51a/x86_64-centos7/include/c++/11.2.0/ext/new_allocator.h:162:4:   required from 'void __gnu_cxx::new_allocator<_Tp>::construct(_Up*, _Args&& ...) [with _Up = Tree::Branch<float>; _Args = {const std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> >&, TTreeReader&}; _Tp = Tree::Branch<float>]'
/cvmfs/sft.cern.ch/lcg/releases/gcc/11.2.0-8a51a/x86_64-centos7/include/c++/11.2.0/bits/alloc_traits.h:512:17:   required from 'static void std::allocator_traits<std::allocator<_Tp1> >::construct(std::allocator_traits<std::allocator<_Tp1> >::allocator_type&, _Up*, _Args&& ...) [with _Up = Tree::Branch<float>; _Args = {const std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> >&, TTreeReader&}; _Tp = Tree::Branch<float>; std::allocator_traits<std::allocator<_Tp1> >::allocator_type = std::allocator<Tree::Branch<float> >]'
/cvmfs/sft.cern.ch/lcg/releases/gcc/11.2.0-8a51a/x86_64-centos7/include/c++/11.2.0/bits/shared_ptr_base.h:519:39:   required from 'std::_Sp_counted_ptr_inplace<_Tp, _Alloc, _Lp>::_Sp_counted_ptr_inplace(_Alloc, _Args&& ...) [with _Args = {const std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> >&, TTreeReader&}; _Tp = Tree::Branch<float>; _Alloc = std::allocator<Tree::Branch<float> >; __gnu_cxx::_Lock_policy _Lp = __gnu_cxx::_S_atomic]'
/cvmfs/sft.cern.ch/lcg/releases/gcc/11.2.0-8a51a/x86_64-centos7/include/c++/11.2.0/bits/shared_ptr_base.h:650:16:   [ skipping 3 instantiation contexts, use -ftemplate-backtrace-limit=0 to disable ]
/cvmfs/sft.cern.ch/lcg/releases/gcc/11.2.0-8a51a/x86_64-centos7/include/c++/11.2.0/bits/shared_ptr.h:862:14:   required from 'std::shared_ptr<_Tp> std::allocate_shared(const _Alloc&, _Args&& ...) [with _Tp = Tree::Branch<float>; _Alloc = std::allocator<Tree::Branch<float> >; _Args = {const std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> >&, TTreeReader&}]'
/cvmfs/sft.cern.ch/lcg/releases/gcc/11.2.0-8a51a/x86_64-centos7/include/c++/11.2.0/bits/shared_ptr.h:878:39:   required from 'std::shared_ptr<_Tp> std::make_shared(_Args&& ...) [with _Tp = Tree::Branch<float>; _Args = {const std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> >&, TTreeReader&}]'
/home/thpark/ana/AnalysisExample/RAnalysis/RAnalysis/Tree.h:170:36:   required from 'std::shared_ptr<Tree::Branch<U> > Tree::Reader::read(const string&) const [with U = float; std::string = std::__cxx11::basic_string<char>]'
/home/thpark/ana/AnalysisExample/ana/ana/input.h:170:56:   required from 'decltype(auto) ana::input::reader<T>::read_column(const string&) const [with Val = float; T = Tree::Reader; std::string = std::__cxx11::basic_string<char>]'
/home/thpark/ana/AnalysisExample/ana/ana/analysis.h:236:6:   required by substitution of 'template<class Val> ana::analysis<Tree>::delayed<typename decltype (declval<Tree::Reader>().read_column<Val>(declval<std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > >()))::element_type> ana::analysis<Tree>::read<Val>(const string&) [with Val = float]'
/home/thpark/ana/AnalysisExample/RAnalysis/examples/hww_example.cxx:57:35:   required from here
/home/thpark/ana/AnalysisExample/ana/ana/reader.h:23:18: warning: 'ana::term<float>::reader::m_addr' will be initialized after [-Wreorder]
   23 |         const T* m_addr;
      |                  ^~~~~~
/home/thpark/ana/AnalysisExample/ana/ana/reader.h:22:21: warning:   'const string ana::term<float>::reader::m_name' [-Wreorder]
   22 |   const std::string m_name;
      |                     ^~~~~~
/home/thpark/ana/AnalysisExample/ana/ana/reader.h:40:2: warning:   when initialized here [-Wreorder]
   40 |  ana::term<T>::reader::reader(const std::string& name) :
      |  ^~~
/home/thpark/ana/AnalysisExample/ana/ana/reader.h: In instantiation of 'ana::term<T>::reader::reader(const string&) [with T = ROOT::VecOps::RVec<float>; std::string = std::__cxx11::basic_string<char>]':
/home/thpark/ana/AnalysisExample/ana/ana/reader.h:48:23:   required from 'ana::column::reader<T>::reader(const string&) [with T = ROOT::VecOps::RVec<float>; std::string = std::__cxx11::basic_string<char>]'
/home/thpark/ana/AnalysisExample/RAnalysis/RAnalysis/Tree.h:100:27:   required from 'Tree::Branch<ROOT::VecOps::RVec<T> >::Branch(const string&, TTreeReader&) [with T = float; std::string = std::__cxx11::basic_string<char>]'
/cvmfs/sft.cern.ch/lcg/releases/gcc/11.2.0-8a51a/x86_64-centos7/include/c++/11.2.0/ext/new_allocator.h:162:4:   required from 'void __gnu_cxx::new_allocator<_Tp>::construct(_Up*, _Args&& ...) [with _Up = Tree::Branch<ROOT::VecOps::RVec<float> >; _Args = {const std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> >&, TTreeReader&}; _Tp = Tree::Branch<ROOT::VecOps::RVec<float> >]'
/cvmfs/sft.cern.ch/lcg/releases/gcc/11.2.0-8a51a/x86_64-centos7/include/c++/11.2.0/bits/alloc_traits.h:512:17:   required from 'static void std::allocator_traits<std::allocator<_Tp1> >::construct(std::allocator_traits<std::allocator<_Tp1> >::allocator_type&, _Up*, _Args&& ...) [with _Up = Tree::Branch<ROOT::VecOps::RVec<float> >; _Args = {const std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> >&, TTreeReader&}; _Tp = Tree::Branch<ROOT::VecOps::RVec<float> >; std::allocator_traits<std::allocator<_Tp1> >::allocator_type = std::allocator<Tree::Branch<ROOT::VecOps::RVec<float> > >]'
/cvmfs/sft.cern.ch/lcg/releases/gcc/11.2.0-8a51a/x86_64-centos7/include/c++/11.2.0/bits/shared_ptr_base.h:519:39:   required from 'std::_Sp_counted_ptr_inplace<_Tp, _Alloc, _Lp>::_Sp_counted_ptr_inplace(_Alloc, _Args&& ...) [with _Args = {const std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> >&, TTreeReader&}; _Tp = Tree::Branch<ROOT::VecOps::RVec<float> >; _Alloc = std::allocator<Tree::Branch<ROOT::VecOps::RVec<float> > >; __gnu_cxx::_Lock_policy _Lp = __gnu_cxx::_S_atomic]'
/cvmfs/sft.cern.ch/lcg/releases/gcc/11.2.0-8a51a/x86_64-centos7/include/c++/11.2.0/bits/shared_ptr_base.h:650:16:   [ skipping 3 instantiation contexts, use -ftemplate-backtrace-limit=0 to disable ]
/cvmfs/sft.cern.ch/lcg/releases/gcc/11.2.0-8a51a/x86_64-centos7/include/c++/11.2.0/bits/shared_ptr.h:862:14:   required from 'std::shared_ptr<_Tp> std::allocate_shared(const _Alloc&, _Args&& ...) [with _Tp = Tree::Branch<ROOT::VecOps::RVec<float> >; _Alloc = std::allocator<Tree::Branch<ROOT::VecOps::RVec<float> > >; _Args = {const std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> >&, TTreeReader&}]'
/cvmfs/sft.cern.ch/lcg/releases/gcc/11.2.0-8a51a/x86_64-centos7/include/c++/11.2.0/bits/shared_ptr.h:878:39:   required from 'std::shared_ptr<_Tp> std::make_shared(_Args&& ...) [with _Tp = Tree::Branch<ROOT::VecOps::RVec<float> >; _Args = {const std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> >&, TTreeReader&}]'
/home/thpark/ana/AnalysisExample/RAnalysis/RAnalysis/Tree.h:170:36:   required from 'std::shared_ptr<Tree::Branch<U> > Tree::Reader::read(const string&) const [with U = ROOT::VecOps::RVec<float>; std::string = std::__cxx11::basic_string<char>]'
/home/thpark/ana/AnalysisExample/ana/ana/input.h:170:56:   required from 'decltype(auto) ana::input::reader<T>::read_column(const string&) const [with Val = ROOT::VecOps::RVec<float>; T = Tree::Reader; std::string = std::__cxx11::basic_string<char>]'
/home/thpark/ana/AnalysisExample/ana/ana/analysis.h:236:6:   required by substitution of 'template<class Val> ana::analysis<Tree>::delayed<typename decltype (declval<Tree::Reader>().read_column<Val>(declval<std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > >()))::element_type> ana::analysis<Tree>::read<Val>(const string&) [with Val = ROOT::VecOps::RVec<float>]'
/home/thpark/ana/AnalysisExample/RAnalysis/examples/hww_example.cxx:62:36:   required from here
/home/thpark/ana/AnalysisExample/ana/ana/reader.h:23:18: warning: 'ana::term<ROOT::VecOps::RVec<float> >::reader::m_addr' will be initialized after [-Wreorder]
   23 |         const T* m_addr;
      |                  ^~~~~~
/home/thpark/ana/AnalysisExample/ana/ana/reader.h:22:21: warning:   'const string ana::term<ROOT::VecOps::RVec<float> >::reader::m_name' [-Wreorder]
   22 |   const std::string m_name;
      |                     ^~~~~~
/home/thpark/ana/AnalysisExample/ana/ana/reader.h:40:2: warning:   when initialized here [-Wreorder]
   40 |  ana::term<T>::reader::reader(const std::string& name) :
      |  ^~~
/home/thpark/ana/AnalysisExample/ana/ana/reader.h: In instantiation of 'ana::term<T>::reader::reader(const string&) [with T = ROOT::VecOps::RVec<unsigned int>; std::string = std::__cxx11::basic_string<char>]':
/home/thpark/ana/AnalysisExample/ana/ana/reader.h:48:23:   required from 'ana::column::reader<T>::reader(const string&) [with T = ROOT::VecOps::RVec<unsigned int>; std::string = std::__cxx11::basic_string<char>]'
/home/thpark/ana/AnalysisExample/RAnalysis/RAnalysis/Tree.h:100:27:   required from 'Tree::Branch<ROOT::VecOps::RVec<T> >::Branch(const string&, TTreeReader&) [with T = unsigned int; std::string = std::__cxx11::basic_string<char>]'
/cvmfs/sft.cern.ch/lcg/releases/gcc/11.2.0-8a51a/x86_64-centos7/include/c++/11.2.0/ext/new_allocator.h:162:4:   required from 'void __gnu_cxx::new_allocator<_Tp>::construct(_Up*, _Args&& ...) [with _Up = Tree::Branch<ROOT::VecOps::RVec<unsigned int> >; _Args = {const std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> >&, TTreeReader&}; _Tp = Tree::Branch<ROOT::VecOps::RVec<unsigned int> >]'
/cvmfs/sft.cern.ch/lcg/releases/gcc/11.2.0-8a51a/x86_64-centos7/include/c++/11.2.0/bits/alloc_traits.h:512:17:   required from 'static void std::allocator_traits<std::allocator<_Tp1> >::construct(std::allocator_traits<std::allocator<_Tp1> >::allocator_type&, _Up*, _Args&& ...) [with _Up = Tree::Branch<ROOT::VecOps::RVec<unsigned int> >; _Args = {const std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> >&, TTreeReader&}; _Tp = Tree::Branch<ROOT::VecOps::RVec<unsigned int> >; std::allocator_traits<std::allocator<_Tp1> >::allocator_type = std::allocator<Tree::Branch<ROOT::VecOps::RVec<unsigned int> > >]'
/cvmfs/sft.cern.ch/lcg/releases/gcc/11.2.0-8a51a/x86_64-centos7/include/c++/11.2.0/bits/shared_ptr_base.h:519:39:   required from 'std::_Sp_counted_ptr_inplace<_Tp, _Alloc, _Lp>::_Sp_counted_ptr_inplace(_Alloc, _Args&& ...) [with _Args = {const std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> >&, TTreeReader&}; _Tp = Tree::Branch<ROOT::VecOps::RVec<unsigned int> >; _Alloc = std::allocator<Tree::Branch<ROOT::VecOps::RVec<unsigned int> > >; __gnu_cxx::_Lock_policy _Lp = __gnu_cxx::_S_atomic]'
/cvmfs/sft.cern.ch/lcg/releases/gcc/11.2.0-8a51a/x86_64-centos7/include/c++/11.2.0/bits/shared_ptr_base.h:650:16:   [ skipping 3 instantiation contexts, use -ftemplate-backtrace-limit=0 to disable ]
/cvmfs/sft.cern.ch/lcg/releases/gcc/11.2.0-8a51a/x86_64-centos7/include/c++/11.2.0/bits/shared_ptr.h:862:14:   required from 'std::shared_ptr<_Tp> std::allocate_shared(const _Alloc&, _Args&& ...) [with _Tp = Tree::Branch<ROOT::VecOps::RVec<unsigned int> >; _Alloc = std::allocator<Tree::Branch<ROOT::VecOps::RVec<unsigned int> > >; _Args = {const std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> >&, TTreeReader&}]'
/cvmfs/sft.cern.ch/lcg/releases/gcc/11.2.0-8a51a/x86_64-centos7/include/c++/11.2.0/bits/shared_ptr.h:878:39:   required from 'std::shared_ptr<_Tp> std::make_shared(_Args&& ...) [with _Tp = Tree::Branch<ROOT::VecOps::RVec<unsigned int> >; _Args = {const std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> >&, TTreeReader&}]'
/home/thpark/ana/AnalysisExample/RAnalysis/RAnalysis/Tree.h:170:36:   required from 'std::shared_ptr<Tree::Branch<U> > Tree::Reader::read(const string&) const [with U = ROOT::VecOps::RVec<unsigned int>; std::string = std::__cxx11::basic_string<char>]'
/home/thpark/ana/AnalysisExample/ana/ana/input.h:170:56:   required from 'decltype(auto) ana::input::reader<T>::read_column(const string&) const [with Val = ROOT::VecOps::RVec<unsigned int>; T = Tree::Reader; std::string = std::__cxx11::basic_string<char>]'
/home/thpark/ana/AnalysisExample/ana/ana/analysis.h:236:6:   required by substitution of 'template<class Val> ana::analysis<Tree>::delayed<typename decltype (declval<Tree::Reader>().read_column<Val>(declval<std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > >()))::element_type> ana::analysis<Tree>::read<Val>(const string&) [with Val = ROOT::VecOps::RVec<unsigned int>]'
/home/thpark/ana/AnalysisExample/RAnalysis/examples/hww_example.cxx:67:53:   required from here
/home/thpark/ana/AnalysisExample/ana/ana/reader.h:23:18: warning: 'ana::term<ROOT::VecOps::RVec<unsigned int> >::reader::m_addr' will be initialized after [-Wreorder]
   23 |         const T* m_addr;
      |                  ^~~~~~
/home/thpark/ana/AnalysisExample/ana/ana/reader.h:22:21: warning:   'const string ana::term<ROOT::VecOps::RVec<unsigned int> >::reader::m_name' [-Wreorder]
   22 |   const std::string m_name;
      |                     ^~~~~~
/home/thpark/ana/AnalysisExample/ana/ana/reader.h:40:2: warning:   when initialized here [-Wreorder]
   40 |  ana::term<T>::reader::reader(const std::string& name) :
      |  ^~~
make[2]: *** [RAnalysis/CMakeFiles/hww_example.dir/examples/hww_example.cxx.o] Error 1
make[1]: *** [RAnalysis/CMakeFiles/hww_example.dir/all] Error 2
make: *** [all] Error 2
```
PyROOT binding error (`tree_example.py`):
````cpp
input_line_74:7:181: error: no matching member function for call to 'fill'
      new (ret) (ana::analysis<Tree>::delayed<ana::counter::booker<Histogram<1,float> > >) (((const ana::analysis<Tree>::delayed<ana::counter::booker<Histogram<1,float> > >*)obj)->fill<ana::analysis<Tree>::delayed<Tree::Branch<ROOT::VecOps::RVec<float> > > , ana::counter::booker<Histogram<1, float> >, nullptr>((const ana::analysis<Tree>::delayed<Tree::Branch<ROOT::VecOps::RVec<float> > >&)*(const ana::analysis<Tree>::delayed<Tree::Branch<ROOT::VecOps::RVec<float> > >*)args[0]));
                                                                                            ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
/home/thpark/ana/build/x86_64-centos7-gcc11-opt/include/ana/delayed.h:214:7: note: candidate template ignored: invalid explicitly-specified argument for template parameter 'Args'
        auto fill(Args const&... args) const -> decltype(std::declval<delayed<V>>().fill_counter(std::declval<Args const&>()...))
             ^
input_line_74:11:102: error: no matching member function for call to 'fill'
      (void)(((const ana::analysis<Tree>::delayed<ana::counter::booker<Histogram<1,float> > >*)obj)->fill<ana::analysis<Tree>::delayed<Tree::Branch<ROOT::VecOps::RVec<float> > > , ana::counter::booker<Histogram<1, float> >, nullptr>((const ana::analysis<Tree>::delayed<Tree::Branch<ROOT::VecOps::RVec<float> > >&)*(const ana::analysis<Tree>::delayed<Tree::Branch<ROOT::VecOps::RVec<float> > >*)args[0]));
             ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
/home/thpark/ana/build/x86_64-centos7-gcc11-opt/include/ana/delayed.h:214:7: note: candidate template ignored: invalid explicitly-specified argument for template parameter 'Args'
        auto fill(Args const&... args) const -> decltype(std::declval<delayed<V>>().fill_counter(std::declval<Args const&>()...))
             ^
input_line_75:7:181: error: no matching member function for call to 'fill'
      new (ret) (ana::analysis<Tree>::delayed<ana::counter::booker<Histogram<1,float> > >) (((const ana::analysis<Tree>::delayed<ana::counter::booker<Histogram<1,float> > >*)obj)->fill<ana::analysis<Tree>::delayed<Tree::Branch<ROOT::VecOps::RVec<float> > > , ana::counter::booker<Histogram<1, float> >, nullptr>((const ana::analysis<Tree>::delayed<Tree::Branch<ROOT::VecOps::RVec<float> > >&)*(const ana::analysis<Tree>::delayed<Tree::Branch<ROOT::VecOps::RVec<float> > >*)args[0]));
                                                                                            ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
/home/thpark/ana/build/x86_64-centos7-gcc11-opt/include/ana/delayed.h:214:7: note: candidate template ignored: invalid explicitly-specified argument for template parameter 'Args'
        auto fill(Args const&... args) const -> decltype(std::declval<delayed<V>>().fill_counter(std::declval<Args const&>()...))
             ^
input_line_75:11:102: error: no matching member function for call to 'fill'
      (void)(((const ana::analysis<Tree>::delayed<ana::counter::booker<Histogram<1,float> > >*)obj)->fill<ana::analysis<Tree>::delayed<Tree::Branch<ROOT::VecOps::RVec<float> > > , ana::counter::booker<Histogram<1, float> >, nullptr>((const ana::analysis<Tree>::delayed<Tree::Branch<ROOT::VecOps::RVec<float> > >&)*(const ana::analysis<Tree>::delayed<Tree::Branch<ROOT::VecOps::RVec<float> > >*)args[0]));
             ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
/home/thpark/ana/build/x86_64-centos7-gcc11-opt/include/ana/delayed.h:214:7: note: candidate template ignored: invalid explicitly-specified argument for template parameter 'Args'
        auto fill(Args const&... args) const -> decltype(std::declval<delayed<V>>().fill_counter(std::declval<Args const&>()...))
             ^
Traceback (most recent call last):
  File "/home/thpark/ana/AnalysisExample/RAnalysis/examples/tree_example.py", line 28, in <module>
    lep_pt_hist = hww.book['Histogram<1,float>']("lep_pt",100,0,200).fill(lep_pt_MeV)
TypeError: Template method resolution failed:
  ana::analysis<Tree>::delayed<ana::counter::booker<Histogram<1,float> > > ana::analysis<Tree>::delayed<ana::counter::booker<Histogram<1,float> > >::fill(const ana::analysis<Tree>::delayed<Tree::Branch<ROOT::VecOps::RVec<float> > >& args) =>
    ValueError: nullptr result where temporary expected
  Failed to instantiate "fill(ana::analysis<Tree>::delayed<Tree::Branch<ROOT::VecOps::RVec<float> > >*)"
  ana::analysis<Tree>::delayed<ana::counter::booker<Histogram<1,float> > > ana::analysis<Tree>::delayed<ana::counter::booker<Histogram<1,float> > >::fill(const ana::analysis<Tree>::delayed<Tree::Branch<ROOT::VecOps::RVec<float> > >& args) =>
    ValueError: nullptr result where temporary expected
```