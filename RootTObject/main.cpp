#include <iostream>
#include "CustomClass.h"
#include "TFile.h"
#include "TTree.h"
#include "TCanvas.h"
#include "TSystem.h"

std::string m_Folder = "../../RootFile/";
std::string m_pathRootFile = "../../RootFile/user.arej.23642758._000033.output.root";

void getFilesFromFolder(std::string path){
  std::string strings = static_cast<const char *>(gSystem->GetFromPipe("ls ../../RootFile/"));
  std::cout<<strings<<std::endl;

}

/*
int main() {
  CustomClass file;
  const char* name = file.ClassName();
  file.Dump();
  file.DrawClass();
  std::cout<<name<<std::endl;
  return 0;
}
 */
int main(){
   getFilesFromFolder(m_Folder);

  TFile *rootFile = TFile::Open(m_pathRootFile.c_str());
  TTree *tree = nullptr;
  auto *c = new TCanvas();
  c->cd();
  tree = (TTree*)rootFile->Get("nominal");
  auto clonedtree =  tree->Clone();
  c->SaveAs("something.png");

}

