#include <memory>
#include <chrono>
#include <iostream>
#include <sstream>

#include <ROOT/RVec.hxx>
#include "TPad.h"
#include "TFile.h"
#include "TLorentzVector.h"
#include "TTreeReaderValue.h"
#include "TTreeReader.h"
#include "TVector2.h"
#include "TH1F.h"

#include "ana/analysis.h"
#include "ana/definition.h"
#include "ana/output.h"

#include "RAnalysis/Event.h"
#include "RAnalysis/Histogram.h"
#include "RAnalysis/Folder.h"

#include <xAODEventInfo/EventInfo.h>
#include <xAODMuon/MuonContainer.h>

using RVecF = ROOT::RVec<float>;
using RVecD = ROOT::RVec<double>;
using TLV = TLorentzVector;

int main() {

  auto ttbar = ana::analysis<Event>({"/cvmfs/atlas-nightlies.cern.ch/repo/data/data-art/ASG/DAOD_PHYS/p5169/mc20_13TeV.410470.PhPy8EG_A14_ttbar_hdamp258p75_nonallhad.deriv.DAOD_PHYS.e6337_s3681_r13167_p5169/DAOD_PHYS.29445530._000001.pool.root.1"},"CollectionTree");

  auto allMuons = ttbar.read<xAOD::MuonContainer>("Muons");
  auto eventInfo = ttbar.read<xAOD::EventInfo>("EventInfo");

  class MuonSelection : public ana::column::definition<ConstDataVector<xAOD::MuonContainer>(xAOD::MuonContainer)>
  {
  public:
    MuonSelection(double etaMax) : m_etaMax(etaMax) {}
    virtual ~MuonSelection() = default;
    virtual ConstDataVector<xAOD::MuonContainer> evaluate( ana::observable<xAOD::MuonContainer> muons ) const override {
      ConstDataVector<xAOD::MuonContainer> selMuons( SG::VIEW_ELEMENTS );
      for( const xAOD::Muon* mu : *muons ) {
        if( TMath::Abs( mu->eta() ) < 1.5 ) {
          selMuons.push_back( mu );
        }
      }
      return selMuons;
    }
  protected:
    double m_etaMax;
  };

  auto selMuons = ttbar.define<MuonSelection>(1.5)(allMuons);
  auto selMuonsPtMeV = ttbar.calculate(
    [](ConstDataVector<xAOD::MuonContainer> const& muons){
      RVecD pts;
      for( const xAOD::Muon* mu : muons ) {
        pts.push_back(mu->pt());
      }
    return pts;
    })
    (selMuons);
  auto selMuonsPt = selMuonsPtMeV / ttbar.constant(1000.);

  using cut = ana::selection::cut;
  using weight = ana::selection::weight;

  auto mcEventWeight = ttbar.calculate([](const xAOD::EventInfo& eventInfo){return eventInfo.mcEventWeight();})(eventInfo);
  auto mcEventWeighted = ttbar.filter<weight>("mcEventWeight")(mcEventWeight);

  auto selMuonsPtHist = ttbar.book<Histogram<1,RVecF>>("muons_pt",100,0,100).fill(selMuonsPt).at(mcEventWeighted);

  selMuonsPtHist.result()->Draw();
  gPad->Print("muons_pt.pdf");

  return 0;
}