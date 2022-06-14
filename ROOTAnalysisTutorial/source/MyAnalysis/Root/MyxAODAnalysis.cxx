#include <xAODEventInfo/EventInfo.h>

#include <AsgTools/MessageCheck.h>
#include <MyAnalysis/MyxAODAnalysis.h>

#include <xAODJet/JetContainer.h>
#include <xAODCore/AuxContainerBase.h>

#include <xAODMuon/MuonContainer.h>




MyxAODAnalysis :: MyxAODAnalysis (const std::string& name,
                                  ISvcLocator *pSvcLocator)
    : EL::AnaAlgorithm (name, pSvcLocator)
{
  // Here you put any code for the base initialization of variables,
  // e.g. initialize all pointers to 0.  This is also where you
  // declare all properties for your algorithm.  Note that things like
  // resetting statistics variables or booking histograms should
  // rather go into the initialize() function.
  //
  declareProperty( "ElectronPtCut", m_electronPtCut = 25000.0,
                   "Minimum electron pT (in MeV)" );
  declareProperty( "SampleName", m_sampleName = "Unknown",
                   "Descriptive name for the processed sample" );
}



StatusCode MyxAODAnalysis :: initialize ()
{
  // Here you do everything that needs to be done at the very
  // beginning on each worker node, e.g. create histograms and output
  // trees.  This method gets called before any input files are
  // connected.
  ANA_MSG_INFO ("in initialize");

  ANA_CHECK (book (TH1F ("h_jetPt", "h_jetPt", 100, 0, 500))); // jet pt [GeV]

  ANA_MSG_INFO( "ElectronPtCut = " << m_electronPtCut );
  ANA_MSG_INFO( "SampleName    = " << m_sampleName );

  m_systematicsList.addHandle(m_muonHandle);
  ANA_CHECK(m_systematicsList.initialize());

  return StatusCode::SUCCESS;
}



StatusCode MyxAODAnalysis :: execute ()
{
  // Here you do everything that needs to be done on every single
  // events, e.g. read input variables, apply cuts, and fill
  // histograms and trees.  This is where most of your actual analysis
  // code will go.
  ANA_MSG_INFO("in execute");

// retrieve the eventInfo object from the event store
  const xAOD::EventInfo *eventInfo = nullptr;
  ANA_CHECK (evtStore()->retrieve (eventInfo, "EventInfo"));

  // print out run and event number from retrieved object
 // ANA_MSG_INFO ("in execute, runNumber = " << eventInfo->runNumber() << ", eventNumber = " << eventInfo->eventNumber());

// loop over the jets in the container
  const xAOD::JetContainer* jets = nullptr;
  ANA_CHECK (evtStore()->retrieve (jets, "AntiKt4EMTopoJets"));

  /*
  //create the new container and its auxiliary store.
  auto goodJets = std::make_unique<xAOD::JetContainer>();
  auto goodJetsAux = std::make_unique<xAOD::AuxContainerBase>();
  goodJets->setStore(goodJetsAux.get()); //< Connect the two

  for (auto jet : *jets) {
	  if(jet->pt() < 50e03) continue; //skip jets below 50 GeV
	  //copy this jet to the output container:
	  xAOD::Jet* goodJet = new xAOD::Jet();
	  goodJets->push_back(goodJet);  // jet acquires the goodJets auxstore
	  *goodJet = *jet;  //copies auxdata from one auxstore to the other
    //ANA_MSG_INFO("execute(): jet pt = " << (jet->pt()*0.001)<<"GeV");
    //hist ("h_jetPt")->Fill (jet->pt() * 0.001); // GeV
  } // end for loop over jets

  //Record the objects into the event store
  ANA_CHECK(evtStore()->record(goodJets.release(), "GoodJets"));
  ANA_CHECK(evtStore()->record(goodJetsAux.release(), "GoodJetsAux"));
  */

 //--------------
  // shallow copy 
  //--------------
  // "jets" jet container already defined above
  /*
  auto shallowCopy = xAOD::shallowCopyContainer (*jets);
  std::unique_ptr<xAOD::JetContainer> shallowJets (shallowCopy.first);
  std::unique_ptr<xAOD::ShallowAuxContainer> shallowAux (shallowCopy.second);

  // iterate over the shallow copy
  for (auto jetSC : *shallowJets) {
    // apply a shift in pt, up by 5%
    double newPt =  jetSC->pt() * (1 + 0.05);

    // from: https://gitlab.cern.ch/atlas/athena/tree/21.2/Event/xAOD/xAODJet/xAODJet/versions/Jet_v1.h
    xAOD::JetFourMom_t newp4 (newPt, jetSC->eta(), jetSC->phi(), jetSC->m());
    jetSC->setJetP4 (newp4); // we've overwritten the 4-momentum
  } // end iterator over jet shallow copy
  */

  /*
  // for CP algorithm part of the tutorial
  if (m_sumPtHist == nullptr)
  {
	std::string name = "sumPtHist";
	ANA_CHECK (book (TH1F (name.c_str(), "pt", 20, 0, 200e3)));
	m_sumPtHist = hist (name);
  }

  if(m_ptFirstMuon == nullptr)
  {
      std::string name = "ptFirstMuon";
      ANA_CHECK(book(TH1F(name.c_str(),"pt", 20, 0, 200e3)));
      m_ptFirstMuon = hist(name);
  }

  const xAOD::MuonContainer *muons = nullptr;
  ANA_CHECK (evtStore()->retrieve (muons, "AnalysisMuonsMedium_NOSYS"));
  float sumPt = 0;
  float firstPt = 0;
  int muonCounter = 0;
  for (const xAOD::Muon *muon : *muons){
      sumPt += muon->pt();
      if(muonCounter == 0) firstPt = muon->pt();
      muonCounter++;
  }

  m_sumPtHist->Fill (sumPt);
  m_ptFirstMuon->Fill(firstPt);

  // for CP algorithm part of the tutorial
  if (m_sumPtHistTight == nullptr)
  {
	std::string name = "sumPtHistTight";
	ANA_CHECK (book (TH1F (name.c_str(), "pt", 20, 0, 200e3)));
	m_sumPtHistTight = hist (name);
  }

  if(m_ptFirstMuonTight == nullptr)
  {
      std::string name = "ptFirstMuonTight";
      ANA_CHECK(book(TH1F(name.c_str(),"pt", 20, 0, 200e3)));
      m_ptFirstMuonTight = hist(name);
  }

  const xAOD::MuonContainer *muonsTight = nullptr;
  ANA_CHECK (evtStore()->retrieve (muonsTight, "AnalysisMuonsTight_NOSYS"));
  float sumPtTight = 0;
  float firstPtTight = 0;
  int muonCounterTight = 0;
  for (const xAOD::Muon *muon : *muonsTight){
      sumPt += muon->pt();
      if(muonCounterTight == 0) firstPtTight = muon->pt();
      muonCounterTight++;
  }

  m_sumPtHistTight->Fill (sumPtTight);
  m_ptFirstMuonTight->Fill(firstPtTight);
  */

  // systematics
  //const xAOD::MuonContainer *muons = nullptr;
  //return m_systematicsList.foreach ( [&](const CP::SystematicSet& sys) -> StatusCode{
  //    ANA_CHECK(m_muonHandle.retrieve(muons, sys));});

  //auto sumPtHist = m_sumPtHist.find(sys);

  return StatusCode::SUCCESS;
}



StatusCode MyxAODAnalysis :: finalize ()
{
  // This method is the mirror image of initialize(), meaning it gets
  // called after the last event has been processed on the worker node
  // and allows you to finish up any objects you created in
  // initialize() before they are written to disk.  This is actually
  // fairly rare, since this happens separately for each worker node.
  // Most of the time you want to do your post-processing on the
  // submission node after all your histogram outputs have been
  // merged.
  return StatusCode::SUCCESS;
}
