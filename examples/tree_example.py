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

mc_weighted = hww.filter['ana::selection::cut']("mcWeight")
mc_weighted = hww.evaluate_selection(mc_weighted,mc_weight)

print(mc_weighted)

# lep_pt_hist = hww.book['Histogram<1,float>']("lep_pt",100,0,200).fill(lep_pt_MeV)

# print(lep_pt_hist)

# lep_pt_hist.result().Draw()
# ROOT.gPad.Print("lep_pt.pdf")
