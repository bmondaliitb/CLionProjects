#ifndef MyAnalysis_MyxAODAnalysis_H
#define MyAnalysis_MyxAODAnalysis_H

#include <TH1.h>

#include <AnaAlgorithm/AnaAlgorithm.h>

#include <xAODMuon/MuonContainer.h>
#include <SystematicsHandles/SysReadHandle.h>
#include <SystematicsHandles/SysListHandle.h>

class MyxAODAnalysis : public EL::AnaAlgorithm
{
public:
  // this is a standard algorithm constructor
  MyxAODAnalysis (const std::string& name, ISvcLocator* pSvcLocator);

  // these are the functions inherited from Algorithm
  virtual StatusCode initialize () override;
  virtual StatusCode execute () override;
  virtual StatusCode finalize () override;

private:
  // Configuration, and any other types of variables go here.
  //float m_cutValue;
  //TTree *m_myTree;
  //TH1 *m_myHist;

private:
  /// Electron pT cut
  double m_electronPtCut;
  /// Sample name
  std::string m_sampleName;
public:
    /*
  TH1 *m_sumPtHist {nullptr};
  TH1 *m_ptFirstMuon{nullptr};
  TH1 *m_sumPtHistTight {nullptr};
  TH1 *m_ptFirstMuonTight {nullptr};
*/
    std::unordered_map<CP::SystematicSet, TH1*> m_sumPtHist;

  /// \brief the systematics list we run
private:
    CP::SysListHandle m_systematicsList {this};

    /// \brief the muon collection we run on
    CP::SysReadHandle<xAOD::MuonContainer > m_muonHandle {this, "muons", "AnalysisMuonsMedium_%SYS%",
                                                          "the muon collection to run on"};
};

#endif
