import os
import numpy as np

import ROOT
ana = ROOT.ana

ana.multithread.enable(2)
hww = ana.analysis['Tree']( ['hww.root'], 'mini' )
# hww.open( ['hww.root'], 'mini' )

mc_weight = hww.read['float']("mcWeight")
el_sf = hww.read['float']("scaleFactor_ELE")
mu_sf = hww.read['float']("scaleFactor_MUON")

lep_pt_MeV = hww.read['ROOT::RVec<float>']("lep_pt")
lep_eta = hww.read['ROOT::RVec<float>']("lep_eta")
lep_phi = hww.read['ROOT::RVec<float>']("lep_phi")
lep_E_MeV = hww.read['ROOT::RVec<float>']("lep_E")
lep_Q = hww.read['ROOT::RVec<float>']("lep_charge")
lep_type = hww.read['ROOT::RVec<unsigned int>']("lep_type")
met_MeV = hww.read['float']("met_et")
met_phi = hww.read['float']("met_phi")

print(mc_weight)

ROOT.gInterpreter.Declare('''
template <typename T> using RVec = ROOT::RVec<T>;
using RVecF = ROOT::RVec<float>;
using RVecD = ROOT::RVec<double>;
using RVecUI = ROOT::RVec<unsigned int>;
using TLV = TLorentzVector;
class NthP4 : public ana::column::definition<TLV(RVecD, RVecD, RVecD, RVecD)>
{

public:

  NthP4(unsigned int index) : 
    ana::column::definition<TLV(RVecD, RVecD, RVecD, RVecD)>(),
    m_index(index)
  {}

  virtual ~NthP4() = default;

  virtual TLV evaluate(ana::observable<RVecD> pt, ana::observable<RVecD> eta, ana::observable<RVecD> phi, ana::observable<RVecD> es) const override {
    TLV p4;
    p4.SetPtEtaPhiE(pt->at(m_index),eta->at(m_index),phi->at(m_index),es->at(m_index));
    return p4;
  }

protected:

  unsigned int m_index;

};

auto test_fn = std::function{[](int x){return x;}};
''')

l1p4 = hww.define['NthP4'](0)
print(l1p4)
l1p4 = l1p4.evaluate(lep_pt_MeV, lep_eta, lep_phi, lep_E_MeV)
print(l1p4)

lep_pt_GeV = hww.constant(10) + hww.constant(1000.0)
print(lep_pt_GeV)

print(type(ROOT.test_fn))
print(hww.calculate[type(ROOT.test_fn)](ROOT.test_fn))

mc_weighted = hww.filter['ana::selection::cut']("mcWeight")
print(mc_weighted)
mc_weighted = mc_weighted.evaluate(mc_weight)
print(mc_weighted)


hist = hww.book['Histogram<1,float>']('pt',100,0,100)
booked = hist.at(mc_weighted)

print(hist)

# lep_pt_hist = hww.book['Histogram<1,float>']("lep_pt",100,0,200).fill(lep_pt_MeV)

# print(lep_pt_hist)

# lep_pt_hist.result().Draw()
# ROOT.gPad.Print("lep_pt.pdf")
