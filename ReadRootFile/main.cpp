#include <iostream>
#include "TFileCollection.h"
#include "TFile.h"
#include "TTree.h"

int main() {
    std::cout << "Hello, World!" << std::endl;
    TFile* file = nullptr;
    file = new TFile("testfile.root", "RECREATE");
    int i=0;
    TTree *myTree = nullptr;
    while (i<3){
    myTree = new TTree("myTree","here");
    double a = 8;
    myTree->Branch("a",&a);
    myTree->Fill();
    i++;
    }

    file->Write();
    return 0;
}
