#include <iostream>
//#include "RooMyPDF_BW.h"
#include "TStyle.h"
#include "RooRealVar.h"
//#include "RooAbsPdf.h"
#include "RooPlot.h"
#include "TLegend.h"
#include "TCanvas.h"
#include "TH1D.h"
#include "TAxis.h"
#include "TFile.h"
#include "RooFitResult.h"
#include "RooVoigtian.h"
#include "RooCBShape.h"
#include "RooCrystalBall.h"
#include "RooBreitWigner.h"
#include "RooFFTConvPdf.h"
#include "TVirtualFFT.h"
//#include "RooAbsCachedPdf.h"
//#include "FFTCacheElem"
void BW_function(TH1D*);
void voig_function(TH1D*);
int main(){
  std::cout<<" pritn"<<std::endl;

  TFile *file = TFile::Open("/Users/buddha/CLionProjects/FFT_program//DY_ntuple_inclusive.root", "READ");
  TH1D* h = (TH1D*) file->Get("gen_Zmass");

//  BW_function(h);
  voig_function(h);
return 0;
}
void voig_function(TH1D * hist){
  TH1D *my_hist = (TH1D*) hist->Clone();
  std::cout<<" started declaring variables"<<std::endl;
	 RooRealVar mass_var("mass_var", " mass Z ", 70,110); 
	 RooDataHist histo("histo","mass dataset",mass_var,my_hist);
   RooRealVar mean_mass("mean_mass","mean of Z mass",91.19,88,94);
   RooRealVar gamma("gamma","gamma of Z mass",2.49,1,5);
   std::cout<<" before calling BW"<<std::endl;
//   RooMyPDF_BW BW("BW","Breit Wigner fit",mass_var, mean_mass,gamma);
   RooBreitWigner BW("BW","Breit Wigner fit",mass_var, mean_mass,gamma);
   std::cout<<" after calling BW"<<std::endl;
   RooPlot *xframe=mass_var.frame();
   histo.plotOn(xframe);
   std::cout<<"before fitting  BW"<<std::endl;
   BW.fitTo(histo,RooFit::Range(84,98));
   BW.plotOn(xframe,RooFit::LineColor(kRed+2),RooFit::Name("BW_sig"));
   BW.paramOn(xframe,RooFit::Layout(0.6,0.9,0.7));
 
    TCanvas *tmp = new TCanvas("tmp","Gen Z mass", 900,600);
    tmp->cd();
    gPad->SetLeftMargin(0.15);
    xframe->getAttText()->SetTextSize(0.025);
    xframe->GetXaxis()->SetTitle("m_{#mu^{+}#mu^{-}} (GeV)");
    xframe->SetTitle("");
    xframe->GetYaxis()->SetTitle("N/0.5 (GeV)");
    xframe->Draw();
   float chi_square_value = xframe->chiSquare();
   TLegend* leg2 = new TLegend(0.7, 0.7, 0.88, 0.88);
   leg2->SetFillColor(kWhite);
   leg2->SetLineColor(kBlack);
   leg2->AddEntry("histo","Gen Z", "EP");
   leg2->AddEntry("BW_sig","BW fit","LP");
   leg2->AddEntry("xframe->chiSquare()",Form("#chi^{2}/ndf= %.2f",xframe->chiSquare()),"");
   leg2->AddEntry("histo.sumEntries()",Form("Events= %.0f",histo.sumEntries()),"");
   leg2->Draw("same");
   gStyle->SetOptStat();
   tmp->SaveAs("BW_fit.pdf");
//RooRealVar cbmean("cbmean", "cbmean" , 91,87,95) ;
 RooRealVar cbmean("cbmean", "cbmean" , 0,-5,5) ;
RooRealVar cbsigmaL("cbsigmaL", "cbsigmaL" , 2, 0.1, 100) ;
RooRealVar cbsigmaR("cbsigmaR", "cbsigmaR" , 2, 0.1,100) ;
RooRealVar alphaL("alphaL","alphaL", 1, 0.1, 10);
RooRealVar alphaR("alphaR","alphaR", 1, 0.1, 10);
RooRealVar nL("nL", "nL", 5, 0.1, 100);
RooRealVar nR("nR", "nR", 5, 0.1, 100);
RooCrystalBall DSCB("DSCB", "DSCB", mass_var, cbmean, cbsigmaL, cbsigmaR, alphaL, nL, alphaR, nR);
//RooCrystalBall BW_DSCB("BW_DSCB", "BW_DSCB", mass_var, cbmean, cbsigmaL, cbsigmaR, alphaL, nL, alphaR, nR);

   mass_var.setBins(50000, "cache");
   std::cout<<" created DCB "<<std::endl;
   RooFFTConvPdf BW_DSCB("BW_DSCB", "BW (X) DSCB", mass_var, BW, DSCB);  

  std::cout<<" started declaring variables"<<std::endl;
//	RooRealVar mass_var("mass_var", " mass Z ", 70,110); 
 	 RooDataHist histo1("histo1","mass dataset",mass_var,my_hist);
  // RooRealVar mean_mass("mean_mass","mean of Z mass",91.19,85,97);

   //mean_mass.setConstant(true);
   //gamma.setConstant(true);
   //RooRealVar gamma("gamma","gamma of Z mass",2.63036, 2.5, 2.8);
   //gamma.setConstant(true);
  // RooRealVar sigma("sigma","sigma of Z mass",0.1,0.001,1);
  // std::cout<<" before calling BW"<<std::endl;
  // RooVoigtian voig("voig","voig",mass_var, mean_mass,gamma, sigma);
  // std::cout<<" after calling voig "<<std::endl;
   RooPlot *xframe1=mass_var.frame();
   histo1.plotOn(xframe1);
   std::cout<<"before fitting  BW"<<std::endl;
   BW_DSCB.fitTo(histo1,RooFit::Range(70,100),RooFit::Optimize(false));
   BW_DSCB.plotOn(xframe1,RooFit::LineColor(kRed+2),RooFit::Name("BW_DSCB_sig"));
   //BW_DSCB.paramOn(xframe1,RooFit::Layout(0.6,0.9,0.7));
 
    tmp->cd();
    gPad->SetLeftMargin(0.15);
    xframe1->getAttText()->SetTextSize(0.025);
    xframe1->GetXaxis()->SetTitle("m_{#mu^{+}#mu^{-}} (GeV)");
    xframe1->SetTitle("");
  xframe1->GetYaxis()->SetTitle("N/0.5 (GeV)");
    xframe1->Draw();
   chi_square_value = xframe1->chiSquare();
   TLegend* leg = new TLegend(0.7, 0.7, 0.88, 0.88);
   leg->SetFillColor(kWhite);
   leg->SetLineColor(kBlack);
   leg->AddEntry("histo","Gen Z", "EP");
   //leg->AddEntry("BW_DSCB","BW DSCB fit","LP");
   leg->AddEntry("xframe1->chiSquare()",Form("#chi^{2}/ndf= %.2f",xframe1->chiSquare()),"");
   leg->AddEntry("histo1.sumEntries()",Form("Events= %.0f",histo.sumEntries()),"");
   leg->Draw("same");
   gStyle->SetOptStat();
   tmp->SaveAs("voig_fit.pdf");
 }

void BW_function(TH1D * hist){
 }

