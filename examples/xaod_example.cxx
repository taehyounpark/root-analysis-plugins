

void ttbar_example() {

  auto ttbar = ana::analysis<Event>();
  ttbar.open(std::vector<std::string>{"/cvmfs/atlas-nightlies.cern.ch/repo/data/data-art/ASG/DAOD_PHYS/p5169/mc20_13TeV.410470.PhPy8EG_A14_ttbar_hdamp258p75_nonallhad.deriv.DAOD_PHYS.e6337_s3681_r13167_p5169/DAOD_PHYS.29445530._000001.pool.root.1"});

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
  auto selMuonsPtMeV = ttbar.define(
    [](ConstDataVector<xAOD::MuonContainer> const& muons){
      ROOT::RVec<double> pts;
      for( const xAOD::Muon* mu : muons ) {
        pts.push_back(mu->pt()/1000.0);
      }
    return pts;
    })
    (selMuons);
  auto selMuonsPt = selMuonsPtMeV / ttbar.constant(1000.0);

  auto mcEventWeight = ttbar.define([](const xAOD::EventInfo& eventInfo){return eventInfo.mcEventWeight();})(eventInfo);
  auto inclusiveWeighted = ttbar.filter<ana::selection::cut>("mcEventWeight")(mcEventWeight);
  auto selMuonsPtHist = ttbar.book<Histogram<1,ROOT::RVec<float>>>("muons_pt",100,0,100).fill(selMuonsPt).at(inclusiveWeighted);

  selMuonsPtHist.result()->Draw();
  gPad->Print("muons_pt.pdf");

}