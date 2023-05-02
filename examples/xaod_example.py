import os
import numpy as np

import ROOT
ROOT.xAOD.Init().ignore()
ROOT.xAOD.MuonContainer()
ROOT.xAOD.PhotonContainer()
ana = ROOT.ana

test_file_paths = ROOT.std.vector['string']()
test_file_paths.push_back(os.environ['ASG_TEST_FILE_MC'])

ana.multithread.enable(2)
ttbar = ROOT.ana.analysis['Event']()
ttbar.open(test_file_paths,'CollectionTree')

event_info = ttbar.read['xAOD::EventInfo']('EventInfo')
muons = ttbar.read['ConstDataVector<xAOD::MuonContainer>']('Muons')

'''
ana::analysis<T> has no Pythonized layer
its C++ function calls must provide exactly the correct types
'''
ROOT.gInterpreter.Declare(
'''
class MCEventWeight : public ana::column::definition<double(xAOD::EventInfo)>
{
public:
  MCEventWeight() {}
  virtual ~MCEventWeight() = default;
  virtual double evaluate( ana::observable<xAOD::EventInfo> eventInfo ) const override {
    return eventInfo->mcEventWeight();
  }
};
class MuonSelection : public ana::column::definition<ConstDataVector<xAOD::MuonContainer>(ConstDataVector<xAOD::MuonContainer>)>
{
public:
  MuonSelection(double eta_max) : m_eta_max(eta_max) {}
  virtual ~MuonSelection() = default;
  virtual ConstDataVector<xAOD::MuonContainer> evaluate( ana::observable<ConstDataVector<xAOD::MuonContainer>> muons ) const override {
    ConstDataVector<xAOD::MuonContainer> selected_muons( SG::VIEW_ELEMENTS );
    for( const xAOD::Muon* mu : *muons ) {
      if( TMath::Abs( mu->eta() ) < 1.5 ) {
        selected_muons.push_back( mu );
      }
    }
    return selected_muons;
  }
protected:
  double m_eta_max;
};
class GetMuonPts : public ana::column::definition<ROOT::RVec<double>(ConstDataVector<xAOD::MuonContainer>)>
{
public:
  GetMuonPts() {}
  virtual ~GetMuonPts() = default;
  virtual ROOT::RVec<double> evaluate( ana::observable<ConstDataVector<xAOD::MuonContainer>> muons ) const override {
    ROOT::RVec<double> pts;
    for( const xAOD::Muon* mu : *muons ) {
      pts.push_back(mu->pt());
    }
    return pts;
  }
};
'''
)

GetMuonPts = ROOT.GetMuonPts()
# print(GetMuonPts)

mc_event_weight = ttbar.define['MCEventWeight']()(event_info)
muons = ttbar.define['MuonSelection'](1.5)(muons)
muons_pt = ttbar.define['GetMuonPts']()(muons)

mcew_applied = ttbar.filter['ana::selection::weight']('mcEventWeight')(mc_event_weight)

test = ttbar.constant(1.0)
muons_pt_hist = ttbar.book['Histogram<1,float>']('muons_pt',100,0,200).fill(test)
print(muons_pt_hist)


muons_pt_hist.result().Draw()
ROOT.gPad.Print("ttbar.pdf")