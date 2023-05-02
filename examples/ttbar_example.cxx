

void ttbar_example() {


  auto ttbar = ana::analysis<Event>();
  ttbar.open(std::vector<std::string>{"/cvmfs/atlas-nightlies.cern.ch/repo/data/data-art/ASG/DAOD_PHYS/p5169/mc20_13TeV.410470.PhPy8EG_A14_ttbar_hdamp258p75_nonallhad.deriv.DAOD_PHYS.e6337_s3681_r13167_p5169/DAOD_PHYS.29445530._000001.pool.root.1"});

  auto allMuons = ttbar.read<xAOD::MuonContainer>("Muons");
  auto eventInfo = ttbar.read<xAOD::EventInfo>("EventInfo");

  class MuonSelection : public ana::column::definition<ConstDataVector<xAOD::MuonContainer>(xAOD::MuonContainer)>
  {
  public:
    MuonSelection(double eta_max) : m_eta_max(eta_max) {}
    virtual ~MuonSelection() = default;
    virtual ConstDataVector<xAOD::MuonContainer> evaluate( ana::observable<xAOD::MuonContainer> muons ) const override {
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

  std::cout << "hi";

  auto selectedMuons = ttbar.define<MuonSelection>(1.5)(allMuons);
  auto selectedMuonsPt = ttbar.define(
    [](ConstDataVector<xAOD::MuonContainer> const& muons){
      ROOT::RVec<double> pts;
      for( const xAOD::Muon* mu : muons ) {
        pts.push_back(mu->pt()/1000.0);
      }
    return pts;
    })
    (selectedMuons);
  // auto selectedMuonsPt = ttbar.constant(ROOT::RVec<float>({1,2,3,}));


  auto mcEventWeight = ttbar.define([](const xAOD::EventInfo& eventInfo){return eventInfo.mcEventWeight();})(eventInfo);
  auto mcEventWeightApplied = ttbar.filter<ana::selection::cut>("mcEventWeight")(mcEventWeight);

  auto muons_pt_hist = ttbar.book<Histogram<1,ROOT::RVec<float>>>("muons_pt",100,0,100).fill(selectedMuonsPt).at(mcEventWeightApplied);

  muons_pt_hist.result()->Draw();
  gPad->Print("muons_pt.pdf");


  std::cout << "ho";

}