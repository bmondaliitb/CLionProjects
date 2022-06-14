#include <iostream>
#include "TTree.h"
#include "TFile.h"
#include <xAODEventInfo/EventInfo.h>
//#include <xAODCutFlow/CutBookkeeper.h>
#include <AsgTools/MessageCheck.h>
#include <AnaAlgorithm/AnaAlgorithm.h>

std::string rootFile = "/cvmfs/atlas.cern.ch/repo/sw/database/GroupData/dev/AnalysisTop/ContinuousIntegration/MC/p4174/mc16_13TeV.410470.PhPy8EG_A14_ttbar_hdamp258p75_nonallhad.deriv.DAOD_TOPQ1.e6337_s3126_r9364_p4174/test.pool.root";

void AccessRootFile(std::string& rootfile){
  TTree *tree = nullptr;
  TFile *file = nullptr;
  file = new TFile(rootfile.c_str());
  // retrieve the eventInfo object from the event store
  const xAOD::EventInfo *eventInfo = nullptr;
  //ANA_CHECK (evtStore()->retrieve (eventInfo, "EventInfo"));

 // tree = static_cast<TTree*>(file->Get("MetaData"));
 // tree->GetEntry(0);
 // auto ptr = std::make_unique<xAOD::CutBookkeeper>();
 // std::string cutbookkeeperName = ptr->name();
 // std::cout<<"name of the cutbookkeeper: "<<cutbookkeeperName<<std::endl;



}


int main() {
  std::cout << "Hello, World!" << std::endl;
  AccessRootFile(rootFile);
  return 0;
}
