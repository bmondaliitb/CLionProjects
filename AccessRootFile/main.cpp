#include <iostream>
#include "TTree.h"
#include "TFile.h"
#include ""

std::string rootFile = "/cvmfs/atlas.cern.ch/repo/sw/database/GroupData/dev/AnalysisTop/ContinuousIntegration/MC/p4174/mc16_13TeV.410470.PhPy8EG_A14_ttbar_hdamp258p75_nonallhad.deriv.DAOD_TOPQ1.e6337_s3126_r9364_p4174/test.pool.root";

void AccessRootFile(std::string& rootfile){
  TTree *tree = nullptr;
  TFile *file = nullptr;
  file = new TFile(rootfile.c_str());
  xAOD::TEvent event( xAOD::TEvent::kClassAccess );
  tree = static_cast<TTree*>(file->Get("MetaData"));
  tree->Print();



}


int main() {
  std::cout << "Hello, World!" << std::endl;
  AccessRootFile(rootFile);
  return 0;
}
