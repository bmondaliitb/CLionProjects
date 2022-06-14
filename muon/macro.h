//////////////////////////////////////////////////////////
// This class has been automatically generated on
// Mon Apr 19 17:47:38 2021 by ROOT version 6.20/06
// from TTree passedEvents/passedEvents
// found on file: Muon_gun_pt5_1stbin.root
//////////////////////////////////////////////////////////

#ifndef macro_h
#define macro_h

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>

// Header file for the classes stored in the TTree if any.
#include "vector"
#include "vector"


class Histograms{
	public:
		void giveAxisTitle();

	public:
   // Gen information
   TH1F *pt_gen = new TH1F("pt_gen","pt gen ",100,4.98,5.02);
   TH1F *eta_gen = new TH1F("eta_gen","eta gen ",100,0.01,0.02);
   TH1F *phi_gen = new TH1F("phi_gen","phi gen ",100,-3.15,3.15);
   TH1F *charge_gen = new TH1F("charge_gen","charge gen ",100,-1.2,1.2);


   // Reco information : without BS : isInnerMuon, reconstructed with innnerTrack
   TH1F *pt_reco = new TH1F("pt_reco","pt reco ",100,4.7,5.3);
   TH1F *eta_reco = new TH1F("eta_gen","eta reco",100,0.005,0.025);
   TH1F *phi_reco = new TH1F("phi_reco","phi reco ",100,-3.2,3.2);
   TH1F *dxy_reco_BS = new TH1F("dxy_reco_BS","dxy reco BS ",100,-.012,.012);
   TH1F *dxy_reco_PV = new TH1F("dxy_reco_PV","dxy reco PV ",100,-.012,.012);
   TH1F *charge_reco = new TH1F("charge_reco","charge reco ",100,-1.2,1.2);
   TH1F *delta_pT = new TH1F("delta_pT","delta pT/pT inner tracker",100,-0.03,0.03);

   
   TH1F *delta_pT_inverse = new TH1F("delta_pT_inverse","delta pT/pT inverse inner tracker",100,-0.03,0.03);
   TH1F *delta_pT_inverse_glb = new TH1F("delta_pT_inverse_glb","delta pT/pT inverse  global",100,-0.03,0.03);
   TH1F *delta_pT_inverse_tune = new TH1F("delta_pT_inverse_tune","delta pT/pT inverse tuned",100,-0.03,0.03);
   TH1F *delta_pT_inverse_inner_BS = new TH1F("delta_pT_inverse_inner_BS","delta pT/pT inverse inner BS tracker",100,-0.03,0.03);
   TH1F *delta_pT_inverse_FLO = new TH1F("delta_pT_inverse_FLO","delta pT/pT inverse flo",100,-0.03,0.03);
  // Reco Global muons : isGlobalMuon , reconstructed with GlobalTrack
  
   TH1F *pt_reco_glb = new TH1F("pt_reco_glb","pt reco global ",100,4.7,5.3);
   TH1F *eta_reco_glb = new TH1F("eta_gen_glb","eta reco global",100,0.005,0.025);
   TH1F *phi_reco_glb = new TH1F("phi_reco_glb","phi reco global ",100,-3.2,3.2);
   TH1F *dxy_reco_BS_glb = new TH1F("dxy_reco_BS_glb","dxy reco BS global ",100,-.012,.012);
   TH1F *dxy_reco_PV_glb = new TH1F("dxy_reco_PV_glb","dxy reco PV global ",100,-.012,.012);
   TH1F *charge_reco_glb = new TH1F("charge_reco_glb","charge reco global ",100,-1.2,1.2);
   TH1F *delta_pT_reco_glb = new TH1F("delta_pT_reco_glb","delta pT/pT glb",100,-0.03,0.03);


    // TUNEP muons : isGlobalMuon, reconstructed with tuneP algorithm
    TH1F *pt_reco_tune = new TH1F("pt_reco_tune","pt reco tune",100,4.7,5.3);
    TH1F *eta_reco_tune = new TH1F("eta_gen_tune","eta reco tune",100,0.005,0.025);
    TH1F *phi_reco_tune = new TH1F("phi_reco_tune","phi reco tune",100,-3.2,3.2);
    TH1F *dxy_reco_BS_tune = new TH1F("dxy_reco_BS_tune","dxy reco BS tune ",100,-.012,.012);
    TH1F *dxy_reco_PV_tune = new TH1F("dxy_reco_PV_tune","dxy reco PV tune  ",100,-.012,.012);
    TH1F *charge_reco_tune = new TH1F("charge_reco_tune","charge reco tune ",100,-1.2,1.2);
    TH1F *delta_pT_reco_tune = new TH1F("delta_pT_reco_tune","delta pT/pT tune",100,-0.03,0.03);

    // Information with BS : global muons + (VX+BS)
   TH1F *pt_flo = new TH1F("pt_flo","pt flo ",100,4.7,5.3);
   TH1F *eta_flo = new TH1F("eta_flo","eta flo ",100,0.005,0.025);
   TH1F *phi_flo = new TH1F("phi_flo","phi flo ",100,-3.2,3.2);
   TH1F *charge_flo = new TH1F("charge_flo","charge flo ",100,-1.2,1.2);
   TH1F *dxy_BS_flo_scale = new TH1F("dxy_BS_flo_scale","dxy BS flo axes",100,-.002,.002);
   TH1F *dxy_PV_flo_scale = new TH1F("dxy_PV_flo_scale","dxy PV flo axes ",100,-.002,.002);
   TH1F *dxy_BS_flo = new TH1F("dxy_BS_flo","dxy BS flo ",100,-.012,.012);
   TH1F *dxy_PV_flo = new TH1F("dxy_PV_flo","dxy PV flo ",100,-.012,.012);
   TH1F *delta_pT_flo = new TH1F("delta_pT_flo","delta pT/pT flo ",100,-0.03,0.03);

   // Information for innerTrack with BS i: innerTrack + (VX+BS)
   TH1F *pt_reco_inner_BS = new TH1F("pt_reco_inner_BS","pt inner track with BS",100,4.7,5.3);
   TH1F *eta_reco_inner_BS = new TH1F("eta_gen_inner_BS","eta inner track with BS",100,0.005,0.025);
   TH1F *phi_reco_inner_BS = new TH1F("phi_reco_inner_BS","phi inner track with BS",100,-3.2,3.2);
   TH1F *dxy_reco_inner_BS = new TH1F("dxy_reco_inner_BS","dxy inner track with BS ",100,-.012,.012);
   TH1F *dxy_reco_inner_PV = new TH1F("dxy_reco_inner_PV","dxy PV inner track with BS ",100,-.012,.012);
   TH1F *delta_pT_inner_BS = new TH1F("delta_pT_inner_BS","delta pT/pT inner tracker with BS",100,-0.03,0.03);


   // Beamspot and Primary vertex
   TH1F *beamspot_x = new TH1F("beamspot_x","beam spot x position",100,0.0106,0.011);
   TH1F *beamspot_y = new TH1F("beamspot_y","beam spot y position",100,0.041,0.043);
   TH1F *beamspot_z = new TH1F("beamspot_z","beam spot z position",100,0.02,0.03);
   TH1F *beamspot_x_err = new TH1F("beamspot_x_err","beam spot x err position",100,-0.001,0.001);
   TH1F *beamspot_y_err = new TH1F("beamspot_y_err","beam spot y err position",100,-0.001,0.001);
   TH1F *beamspot_z_err = new TH1F("beamspot_z_err","beam spot z err position",100,0.01,0.015);
   TH1F *beamspot_width_x = new TH1F("beamspot_width_x","beam spot x width",100,0,0.001);
   TH1F *beamspot_width_y = new TH1F("beamspot_width_y","beam spot y width",100,0,0.001);
   TH1F *beamspot_width_x_err = new TH1F("beamspot_width_x_err","beam spot x width  error",100,-0.001,0.001);
   TH1F *beamspot_width_y_err = new TH1F("beamspot_width_y_err","beam spot y width  error",100,-0.001,0.001);

   TH2F *primaryvertex_xy = new TH2F("primaryvertex_xy","primary vertex xy",100,-0.1,0.1,100,-0.1,0.1);
   TH2F *beamspot_xy = new TH2F("primaryvertex_xy","beamspot xy",100,-0.1,0.1,100,-0.1,0.1);
   TH1F *primary_vertex_x = new TH1F("primary_vertex_x","primary_vertex x position",100,-0.1,0.1);
   TH1F *primary_vertex_y = new TH1F("primary_vertex_y","primary_vertex y position",100,0,0.1);
   TH1F *primary_vertex_z = new TH1F("primary_vertex_z","primary_vertex z position",100,-0.1,0.1);
   TH1F *primary_vertex_x_err = new TH1F("primary_vertex_x_err","primary vertex x err position",100,-0.01, 0.01);
   TH1F *primary_vertex_y_err = new TH1F("primary_vertex_y_err","primary vertex y err position",100,-0.01,0.01);
   TH1F *primary_vertex_z_err = new TH1F("primary_vertex_z_err","primary vertex z err position",100,3.3,3.6);

};




class macro :public Histograms{
public :
   TTree          *fChain;   //!pointer to the analyzed TTree or TChain
   Int_t           fCurrent; //!current Tree number in a TChain

// Fixed size dimensions of array or collections stored in the TTree if any.

   // Declaration of leaf types
   vector<float>   *pt_GEN;
   vector<float>   *eta_GEN;
   vector<float>   *phi_GEN;
   vector<float>   *mass_GEN;
   vector<double>  *charge_GEN;
   vector<float>   *pt_glb;
   vector<float>   *eta_glb;
   vector<float>   *phi_glb;
   vector<float>   *mass_glb;
   vector<float>   *dxy_BS_glb;
   vector<float>   *dxy_PV_glb;
   vector<float>   *pt_glb_vtx;
   vector<float>   *eta_glb_vtx;
   vector<float>   *phi_glb_vtx;
   vector<float>   *mass_glb_vtx;
   vector<float>   *dxy_BS_glb_vtx;
   vector<float>   *pt_glb_single;
   vector<float>   *eta_glb_single;
   vector<float>   *phi_glb_single;
   vector<float>   *dxy_BS_glb_single;
   vector<float>   *pt_stdAlone;
   vector<float>   *eta_stdAlone;
   vector<float>   *phi_stdAlone;
   vector<double>  *charge_stdAlone;
   vector<float>   *dxy_BS_stdAlone;
   vector<float>   *pt_stdAlone_vtx;
   vector<float>   *eta_stdAlone_vtx;
   vector<float>   *phi_stdAlone_vtx;
   vector<float>   *dxy_BS_stdAlone_vtx;
   vector<float>   *pt_trk;
   vector<float>   *eta_trk;
   vector<float>   *phi_trk;
   vector<float>   *mass_trk;
   vector<float>   *dxy_BS_trk;
   vector<double>  *charge_trk;
   vector<double>  *d0_trk;
   vector<double>  *pt_trk_BS;
   vector<double>  *eta_trk_BS;
   vector<double>  *phi_trk_BS;
   vector<double>  *mass_trk_BS;
   vector<double>  *dxy_trk_BS_const;
   vector<double>  *dxy_trk_PV_const;
   vector<double>  *pt_tuned;
   vector<double>  *eta_tuned;
   vector<double>  *phi_tuned;
   vector<double>  *mass_tuned;
   vector<double>  *dxy_BS_tuned;
   vector<double>  *dxy_PV_tuned;
   vector<double>  *charge_tuned;
   vector<double>  *d0_tuned;
   vector<float>   *pt_glb_trk;
   vector<float>   *eta_glb_trk;
   vector<float>   *phi_glb_trk;
   vector<double>  *mass_glb_trk;
   vector<float>   *dxy_BS_glb_trk;
   vector<float>   *dxy_PV_glb_trk;
   vector<double>  *charge_glb_trk;
   vector<float>   *pt_stdAlone_trk;
   vector<float>   *eta_stdAlone_trk;
   vector<float>   *phi_stdAlone_trk;
   vector<double>  *mass_stdAlone_trk;
   vector<float>   *dxy_BS_stdAlone_trk;
   vector<double>  *charge_stdAlone_trk;
   vector<double>  *pt_global_not_tracker;
   vector<double>  *pt_standAlone_not_tracker;
   vector<double>  *dxy_PV_trk;
   vector<double>  *d0_BS_trk;
   vector<float>   *beam_x;
   vector<float>   *beam_y;
   vector<float>   *beam_z;
   vector<float>   *beam_x_err;
   vector<float>   *beam_y_err;
   vector<float>   *beam_z_err;
   vector<float>   *beam_width_x;
   vector<float>   *beam_width_y;
   vector<float>   *beam_width_x_err;
   vector<float>   *beam_width_y_err;
   vector<float>   *pv_x;
   vector<float>   *pv_y;
   vector<float>   *pv_z;
   vector<float>   *pv_x_err;
   vector<float>   *pv_y_err;
   vector<float>   *pv_z_err;
   vector<double>  *v_x;
   vector<double>  *v_y;
   vector<double>  *v_z;
   vector<double>  *dxy_thebeamspot_one;
   vector<double>  *dxy_thebeamspot_second;
   vector<double>  *dxy_primaryvertex_one;
   vector<double>  *dxy_without_argument;
   vector<float>   *pt_FLO_vtx;
   vector<float>   *eta_FLO_vtx;
   vector<float>   *phi_FLO_vtx;
   vector<float>   *dxy_BS_FLO_vtx;
   vector<double>  *dxy_PV_FLO_vtx;
   vector<float>   *dxy_BS_FLO_vtx_second_test;
   vector<float>   *pt_FLO;
   vector<float>   *eta_FLO;
   vector<float>   *phi_FLO;
   vector<float>   *dxy_BS_FLO;
   vector<float>   *dxy_PV_FLO;
   vector<double>  *charge_FLO;
   vector<float>   *bs_x_error_base;
   vector<float>   *bs_y_error_base;
   vector<float>   *bs_x_error_set;
   vector<float>   *bs_y_error_set;

   // List of branches
   TBranch        *b_pt_GEN;   //!
   TBranch        *b_eta_GEN;   //!
   TBranch        *b_phi_GEN;   //!
   TBranch        *b_mass_GEN;   //!
   TBranch        *b_charge_GEN;   //!
   TBranch        *b_pt_glb;   //!
   TBranch        *b_eta_glb;   //!
   TBranch        *b_phi_glb;   //!
   TBranch        *b_mass_glb;   //!
   TBranch        *b_dxy_BS_glb;   //!
   TBranch        *b_dxy_PV_glb;   //!
   TBranch        *b_pt_glb_vtx;   //!
   TBranch        *b_eta_glb_vtx;   //!
   TBranch        *b_phi_glb_vtx;   //!
   TBranch        *b_mass_glb_vtx;   //!
   TBranch        *b_dxy_BS_glb_vtx;   //!
   TBranch        *b_pt_glb_single;   //!
   TBranch        *b_eta_glb_single;   //!
   TBranch        *b_phi_glb_single;   //!
   TBranch        *b_dxy_BS_glb_single;   //!
   TBranch        *b_pt_stdAlone;   //!
   TBranch        *b_eta_stdAlone;   //!
   TBranch        *b_phi_stdAlone;   //!
   TBranch        *b_charge_stdAlone;   //!
   TBranch        *b_dxy_BS_stdAlone;   //!
   TBranch        *b_pt_stdAlone_vtx;   //!
   TBranch        *b_eta_stdAlone_vtx;   //!
   TBranch        *b_phi_stdAlone_vtx;   //!
   TBranch        *b_dxy_BS_stdAlone_vtx;   //!
   TBranch        *b_pt_trk;   //!
   TBranch        *b_eta_trk;   //!
   TBranch        *b_phi_trk;   //!
   TBranch        *b_mass_trk;   //!
   TBranch        *b_dxy_BS_trk;   //!
   TBranch        *b_charge_trk;   //!
   TBranch        *b_d0_trk;   //!
   TBranch        *b_pt_trk_BS;   //!
   TBranch        *b_eta_trk_BS;   //!
   TBranch        *b_phi_trk_BS;   //!
   TBranch        *b_mass_trk_BS;   //!
   TBranch        *b_dxy_trk_BS_const;   //!
   TBranch        *b_dxy_trk_PV_const;   //!
   TBranch        *b_pt_tuned;   //!
   TBranch        *b_eta_tuned;   //!
   TBranch        *b_phi_tuned;   //!
   TBranch        *b_mass_tuned;   //!
   TBranch        *b_dxy_BS_tuned;   //!
   TBranch        *b_dxy_PV_tuned;   //!
   TBranch        *b_charge_tuned;   //!
   TBranch        *b_d0_tuned;   //!
   TBranch        *b_pt_glb_trk;   //!
   TBranch        *b_eta_glb_trk;   //!
   TBranch        *b_phi_glb_trk;   //!
   TBranch        *b_mass_glb_trk;   //!
   TBranch        *b_dxy_BS_glb_trk;   //!
   TBranch        *b_dxy_PV_glb_trk;   //!
   TBranch        *b_charge_glb_trk;   //!
   TBranch        *b_pt_stdAlone_trk;   //!
   TBranch        *b_eta_stdAlone_trk;   //!
   TBranch        *b_phi_stdAlone_trk;   //!
   TBranch        *b_mass_stdAlone_trk;   //!
   TBranch        *b_dxy_BS_stdAlone_trk;   //!
   TBranch        *b_charge_stdAlone_trk;   //!
   TBranch        *b_pt_global_not_tracker;   //!
   TBranch        *b_pt_standAlone_not_tracker;   //!
   TBranch        *b_dxy_PV_trk;   //!
   TBranch        *b_d0_BS_trk;   //!
   TBranch        *b_beam_x;   //!
   TBranch        *b_beam_y;   //!
   TBranch        *b_beam_z;   //!
   TBranch        *b_beam_x_err;   //!
   TBranch        *b_beam_y_err;   //!
   TBranch        *b_beam_z_err;   //!
   TBranch        *b_beam_width_x;   //!
   TBranch        *b_beam_width_y;   //!
   TBranch        *b_beam_width_x_err;   //!
   TBranch        *b_beam_width_y_err;   //!
   TBranch        *b_pv_x;   //!
   TBranch        *b_pv_y;   //!
   TBranch        *b_pv_z;   //!
   TBranch        *b_pv_x_err;   //!
   TBranch        *b_pv_y_err;   //!
   TBranch        *b_pv_z_err;   //!
   TBranch        *b_v_x;   //!
   TBranch        *b_v_y;   //!
   TBranch        *b_v_z;   //!
   TBranch        *b_dxy_thebeamspot_one;   //!
   TBranch        *b_dxy_thebeamspot_second;   //!
   TBranch        *b_dxy_primaryvertex_one;   //!
   TBranch        *b_dxy_without_argument;   //!
   TBranch        *b_pt_FLO_vtx;   //!
   TBranch        *b_eta_FLO_vtx;   //!
   TBranch        *b_phi_FLO_vtx;   //!
   TBranch        *b_dxy_BS_FLO_vtx;   //!
   TBranch        *b_dxy_PV_FLO_vtx;   //!
   TBranch        *b_dxy_BS_FLO_vtx_second_test;   //!
   TBranch        *b_pt_FLO;   //!
   TBranch        *b_eta_FLO;   //!
   TBranch        *b_phi_FLO;   //!
   TBranch        *b_dxy_BS_FLO;   //!
   TBranch        *b_dxy_PV_FLO;   //!
   TBranch        *b_charge_FLO;   //!
   TBranch        *b_bs_x_error_base;   //!
   TBranch        *b_bs_y_error_base;   //!
   TBranch        *b_bs_x_error_set;   //!
   TBranch        *b_bs_y_error_set;   //!

	 // inputfile
	 std::string input_file = {};
	 // directory to save the historgram
	 std::string save_dir_path;

   macro(TTree *tree=0);
//   macro(std::string inputFile);
   virtual ~macro();
   virtual Int_t    Cut(Long64_t entry);
   virtual Int_t    GetEntry(Long64_t entry);
   virtual Long64_t LoadTree(Long64_t entry);
   virtual void     Init(TTree *tree);
   virtual void     Loop();
   virtual Bool_t   Notify();
   virtual void     Show(Long64_t entry = -1);
	 void giveAxisTitle();
	 void getInputFile(std::string fileName);
	 void initialization(TTree *tree=0);
	 // change the histograms ranges
	 void changeDeltaPtHist(double min, double max);

	 // change saving directory
	 void changeSavingDirectory(std::string savedir){save_dir_path = savedir;}

};

#endif

#ifdef macro_cxx
macro::macro(TTree *tree) : fChain(0) 
{
// if parameter tree is not specified (or zero), connect the file
// used to generate this class and read the Tree.
}

void macro::initialization(TTree *tree){
   if (tree == 0) {
      TFile *f = (TFile*)gROOT->GetListOfFiles()->FindObject(input_file.c_str());
      if (!f || !f->IsOpen()) {
         f = new TFile(input_file.c_str());
      }
      f->GetObject("passedEvents",tree);

   }
   Init(tree);


}

/*
macro::macro(std::string inputFile): fChain(0){
	TTree *tree=0;

	TFile *f = (TFile*)gROOT->GetListOfFiles()->FindObject(inputFile.c_str());
  f->GetObject("passedEvents",tree);
  Init(tree);

}
*/

macro::~macro()
{
   if (!fChain) return;
   delete fChain->GetCurrentFile();
}

Int_t macro::GetEntry(Long64_t entry)
{
// Read contents of entry.
   if (!fChain) return 0;
   return fChain->GetEntry(entry);
}
Long64_t macro::LoadTree(Long64_t entry)
{
// Set the environment to read one entry
   if (!fChain) return -5;
   Long64_t centry = fChain->LoadTree(entry);
   if (centry < 0) return centry;
   if (fChain->GetTreeNumber() != fCurrent) {
      fCurrent = fChain->GetTreeNumber();
      Notify();
   }
   return centry;
}

void macro::Init(TTree *tree)
{
   // The Init() function is called when the selector needs to initialize
   // a new tree or chain. Typically here the branch addresses and branch
   // pointers of the tree will be set.
   // It is normally not necessary to make changes to the generated
   // code, but the routine can be extended by the user if needed.
   // Init() will be called many times when running on PROOF
   // (once per file to be processed).

   // Set object pointer
   pt_GEN = 0;
   eta_GEN = 0;
   phi_GEN = 0;
   mass_GEN = 0;
   charge_GEN = 0;
   pt_glb = 0;
   eta_glb = 0;
   phi_glb = 0;
   mass_glb = 0;
   dxy_BS_glb = 0;
   dxy_PV_glb = 0;
   pt_glb_vtx = 0;
   eta_glb_vtx = 0;
   phi_glb_vtx = 0;
   mass_glb_vtx = 0;
   dxy_BS_glb_vtx = 0;
   pt_glb_single = 0;
   eta_glb_single = 0;
   phi_glb_single = 0;
   dxy_BS_glb_single = 0;
   pt_stdAlone = 0;
   eta_stdAlone = 0;
   phi_stdAlone = 0;
   charge_stdAlone = 0;
   dxy_BS_stdAlone = 0;
   pt_stdAlone_vtx = 0;
   eta_stdAlone_vtx = 0;
   phi_stdAlone_vtx = 0;
   dxy_BS_stdAlone_vtx = 0;
   pt_trk = 0;
   eta_trk = 0;
   phi_trk = 0;
   mass_trk = 0;
   dxy_BS_trk = 0;
   charge_trk = 0;
   d0_trk = 0;
   pt_trk_BS = 0;
   eta_trk_BS = 0;
   phi_trk_BS = 0;
   mass_trk_BS = 0;
   dxy_trk_BS_const = 0;
   dxy_trk_PV_const = 0;
   pt_tuned = 0;
   eta_tuned = 0;
   phi_tuned = 0;
   mass_tuned = 0;
   dxy_BS_tuned = 0;
   dxy_PV_tuned = 0;
   charge_tuned = 0;
   d0_tuned = 0;
   pt_glb_trk = 0;
   eta_glb_trk = 0;
   phi_glb_trk = 0;
   mass_glb_trk = 0;
   dxy_BS_glb_trk = 0;
   dxy_PV_glb_trk = 0;
   charge_glb_trk = 0;
   pt_stdAlone_trk = 0;
   eta_stdAlone_trk = 0;
   phi_stdAlone_trk = 0;
   mass_stdAlone_trk = 0;
   dxy_BS_stdAlone_trk = 0;
   charge_stdAlone_trk = 0;
   pt_global_not_tracker = 0;
   pt_standAlone_not_tracker = 0;
   dxy_PV_trk = 0;
   d0_BS_trk = 0;
   beam_x = 0;
   beam_y = 0;
   beam_z = 0;
   beam_x_err = 0;
   beam_y_err = 0;
   beam_z_err = 0;
   beam_width_x = 0;
   beam_width_y = 0;
   beam_width_x_err = 0;
   beam_width_y_err = 0;
   pv_x = 0;
   pv_y = 0;
   pv_z = 0;
   pv_x_err = 0;
   pv_y_err = 0;
   pv_z_err = 0;
   v_x = 0;
   v_y = 0;
   v_z = 0;
   dxy_thebeamspot_one = 0;
   dxy_thebeamspot_second = 0;
   dxy_primaryvertex_one = 0;
   dxy_without_argument = 0;
   pt_FLO_vtx = 0;
   eta_FLO_vtx = 0;
   phi_FLO_vtx = 0;
   dxy_BS_FLO_vtx = 0;
   dxy_PV_FLO_vtx = 0;
   dxy_BS_FLO_vtx_second_test = 0;
   pt_FLO = 0;
   eta_FLO = 0;
   phi_FLO = 0;
   dxy_BS_FLO = 0;
   dxy_PV_FLO = 0;
   charge_FLO = 0;
   bs_x_error_base = 0;
   bs_y_error_base = 0;
   bs_x_error_set = 0;
   bs_y_error_set = 0;
   // Set branch addresses and branch pointers
   if (!tree) return;
   fChain = tree;
   fCurrent = -1;
   fChain->SetMakeClass(1);

   fChain->SetBranchAddress("pt_GEN", &pt_GEN, &b_pt_GEN);
   fChain->SetBranchAddress("eta_GEN", &eta_GEN, &b_eta_GEN);
   fChain->SetBranchAddress("phi_GEN", &phi_GEN, &b_phi_GEN);
   fChain->SetBranchAddress("mass_GEN", &mass_GEN, &b_mass_GEN);
   fChain->SetBranchAddress("charge_GEN", &charge_GEN, &b_charge_GEN);
   fChain->SetBranchAddress("pt_glb", &pt_glb, &b_pt_glb);
   fChain->SetBranchAddress("eta_glb", &eta_glb, &b_eta_glb);
   fChain->SetBranchAddress("phi_glb", &phi_glb, &b_phi_glb);
   fChain->SetBranchAddress("mass_glb", &mass_glb, &b_mass_glb);
   fChain->SetBranchAddress("dxy_BS_glb", &dxy_BS_glb, &b_dxy_BS_glb);
   fChain->SetBranchAddress("dxy_PV_glb", &dxy_PV_glb, &b_dxy_PV_glb);
   fChain->SetBranchAddress("pt_glb_vtx", &pt_glb_vtx, &b_pt_glb_vtx);
   fChain->SetBranchAddress("eta_glb_vtx", &eta_glb_vtx, &b_eta_glb_vtx);
   fChain->SetBranchAddress("phi_glb_vtx", &phi_glb_vtx, &b_phi_glb_vtx);
   fChain->SetBranchAddress("mass_glb_vtx", &mass_glb_vtx, &b_mass_glb_vtx);
   fChain->SetBranchAddress("dxy_BS_glb_vtx", &dxy_BS_glb_vtx, &b_dxy_BS_glb_vtx);
   fChain->SetBranchAddress("pt_glb_single", &pt_glb_single, &b_pt_glb_single);
   fChain->SetBranchAddress("eta_glb_single", &eta_glb_single, &b_eta_glb_single);
   fChain->SetBranchAddress("phi_glb_single", &phi_glb_single, &b_phi_glb_single);
   fChain->SetBranchAddress("dxy_BS_glb_single", &dxy_BS_glb_single, &b_dxy_BS_glb_single);
   fChain->SetBranchAddress("pt_stdAlone", &pt_stdAlone, &b_pt_stdAlone);
   fChain->SetBranchAddress("eta_stdAlone", &eta_stdAlone, &b_eta_stdAlone);
   fChain->SetBranchAddress("phi_stdAlone", &phi_stdAlone, &b_phi_stdAlone);
   fChain->SetBranchAddress("charge_stdAlone", &charge_stdAlone, &b_charge_stdAlone);
   fChain->SetBranchAddress("dxy_BS_stdAlone", &dxy_BS_stdAlone, &b_dxy_BS_stdAlone);
   fChain->SetBranchAddress("pt_stdAlone_vtx", &pt_stdAlone_vtx, &b_pt_stdAlone_vtx);
   fChain->SetBranchAddress("eta_stdAlone_vtx", &eta_stdAlone_vtx, &b_eta_stdAlone_vtx);
   fChain->SetBranchAddress("phi_stdAlone_vtx", &phi_stdAlone_vtx, &b_phi_stdAlone_vtx);
   fChain->SetBranchAddress("dxy_BS_stdAlone_vtx", &dxy_BS_stdAlone_vtx, &b_dxy_BS_stdAlone_vtx);
   fChain->SetBranchAddress("pt_trk", &pt_trk, &b_pt_trk);
   fChain->SetBranchAddress("eta_trk", &eta_trk, &b_eta_trk);
   fChain->SetBranchAddress("phi_trk", &phi_trk, &b_phi_trk);
   fChain->SetBranchAddress("mass_trk", &mass_trk, &b_mass_trk);
   fChain->SetBranchAddress("dxy_BS_trk", &dxy_BS_trk, &b_dxy_BS_trk);
   fChain->SetBranchAddress("charge_trk", &charge_trk, &b_charge_trk);
   fChain->SetBranchAddress("d0_trk", &d0_trk, &b_d0_trk);
   fChain->SetBranchAddress("pt_trk_BS", &pt_trk_BS, &b_pt_trk_BS);
   fChain->SetBranchAddress("eta_trk_BS", &eta_trk_BS, &b_eta_trk_BS);
   fChain->SetBranchAddress("phi_trk_BS", &phi_trk_BS, &b_phi_trk_BS);
   fChain->SetBranchAddress("mass_trk_BS", &mass_trk_BS, &b_mass_trk_BS);
   fChain->SetBranchAddress("dxy_trk_BS_const", &dxy_trk_BS_const, &b_dxy_trk_BS_const);
   fChain->SetBranchAddress("dxy_trk_PV_const", &dxy_trk_PV_const, &b_dxy_trk_PV_const);
   fChain->SetBranchAddress("pt_tuned", &pt_tuned, &b_pt_tuned);
   fChain->SetBranchAddress("eta_tuned", &eta_tuned, &b_eta_tuned);
   fChain->SetBranchAddress("phi_tuned", &phi_tuned, &b_phi_tuned);
   fChain->SetBranchAddress("mass_tuned", &mass_tuned, &b_mass_tuned);
   fChain->SetBranchAddress("dxy_BS_tuned", &dxy_BS_tuned, &b_dxy_BS_tuned);
   fChain->SetBranchAddress("dxy_PV_tuned", &dxy_PV_tuned, &b_dxy_PV_tuned);
   fChain->SetBranchAddress("charge_tuned", &charge_tuned, &b_charge_tuned);
   fChain->SetBranchAddress("d0_tuned", &d0_tuned, &b_d0_tuned);
   fChain->SetBranchAddress("pt_glb_trk", &pt_glb_trk, &b_pt_glb_trk);
   fChain->SetBranchAddress("eta_glb_trk", &eta_glb_trk, &b_eta_glb_trk);
   fChain->SetBranchAddress("phi_glb_trk", &phi_glb_trk, &b_phi_glb_trk);
   fChain->SetBranchAddress("mass_glb_trk", &mass_glb_trk, &b_mass_glb_trk);
   fChain->SetBranchAddress("dxy_BS_glb_trk", &dxy_BS_glb_trk, &b_dxy_BS_glb_trk);
   fChain->SetBranchAddress("dxy_PV_glb_trk", &dxy_PV_glb_trk, &b_dxy_PV_glb_trk);
   fChain->SetBranchAddress("charge_glb_trk", &charge_glb_trk, &b_charge_glb_trk);
   fChain->SetBranchAddress("pt_stdAlone_trk", &pt_stdAlone_trk, &b_pt_stdAlone_trk);
   fChain->SetBranchAddress("eta_stdAlone_trk", &eta_stdAlone_trk, &b_eta_stdAlone_trk);
   fChain->SetBranchAddress("phi_stdAlone_trk", &phi_stdAlone_trk, &b_phi_stdAlone_trk);
   fChain->SetBranchAddress("mass_stdAlone_trk", &mass_stdAlone_trk, &b_mass_stdAlone_trk);
   fChain->SetBranchAddress("dxy_BS_stdAlone_trk", &dxy_BS_stdAlone_trk, &b_dxy_BS_stdAlone_trk);
   fChain->SetBranchAddress("charge_stdAlone_trk", &charge_stdAlone_trk, &b_charge_stdAlone_trk);
   fChain->SetBranchAddress("pt_global_not_tracker", &pt_global_not_tracker, &b_pt_global_not_tracker);
   fChain->SetBranchAddress("pt_standAlone_not_tracker", &pt_standAlone_not_tracker, &b_pt_standAlone_not_tracker);
   fChain->SetBranchAddress("dxy_PV_trk", &dxy_PV_trk, &b_dxy_PV_trk);
   fChain->SetBranchAddress("d0_BS_trk", &d0_BS_trk, &b_d0_BS_trk);
   fChain->SetBranchAddress("beam_x", &beam_x, &b_beam_x);
   fChain->SetBranchAddress("beam_y", &beam_y, &b_beam_y);
   fChain->SetBranchAddress("beam_z", &beam_z, &b_beam_z);
   fChain->SetBranchAddress("beam_x_err", &beam_x_err, &b_beam_x_err);
   fChain->SetBranchAddress("beam_y_err", &beam_y_err, &b_beam_y_err);
   fChain->SetBranchAddress("beam_z_err", &beam_z_err, &b_beam_z_err);
   fChain->SetBranchAddress("beam_width_x", &beam_width_x, &b_beam_width_x);
   fChain->SetBranchAddress("beam_width_y", &beam_width_y, &b_beam_width_y);
   fChain->SetBranchAddress("beam_width_x_err", &beam_width_x_err, &b_beam_width_x_err);
   fChain->SetBranchAddress("beam_width_y_err", &beam_width_y_err, &b_beam_width_y_err);
   fChain->SetBranchAddress("pv_x", &pv_x, &b_pv_x);
   fChain->SetBranchAddress("pv_y", &pv_y, &b_pv_y);
   fChain->SetBranchAddress("pv_z", &pv_z, &b_pv_z);
   fChain->SetBranchAddress("pv_x_err", &pv_x_err, &b_pv_x_err);
   fChain->SetBranchAddress("pv_y_err", &pv_y_err, &b_pv_y_err);
   fChain->SetBranchAddress("pv_z_err", &pv_z_err, &b_pv_z_err);
   fChain->SetBranchAddress("v_x", &v_x, &b_v_x);
   fChain->SetBranchAddress("v_y", &v_y, &b_v_y);
   fChain->SetBranchAddress("v_z", &v_z, &b_v_z);
   fChain->SetBranchAddress("dxy_thebeamspot_one", &dxy_thebeamspot_one, &b_dxy_thebeamspot_one);
   fChain->SetBranchAddress("dxy_thebeamspot_second", &dxy_thebeamspot_second, &b_dxy_thebeamspot_second);
   fChain->SetBranchAddress("dxy_primaryvertex_one", &dxy_primaryvertex_one, &b_dxy_primaryvertex_one);
   fChain->SetBranchAddress("dxy_without_argument", &dxy_without_argument, &b_dxy_without_argument);
   fChain->SetBranchAddress("pt_FLO_vtx", &pt_FLO_vtx, &b_pt_FLO_vtx);
   fChain->SetBranchAddress("eta_FLO_vtx", &eta_FLO_vtx, &b_eta_FLO_vtx);
   fChain->SetBranchAddress("phi_FLO_vtx", &phi_FLO_vtx, &b_phi_FLO_vtx);
   fChain->SetBranchAddress("dxy_BS_FLO_vtx", &dxy_BS_FLO_vtx, &b_dxy_BS_FLO_vtx);
   fChain->SetBranchAddress("dxy_PV_FLO_vtx", &dxy_PV_FLO_vtx, &b_dxy_PV_FLO_vtx);
   fChain->SetBranchAddress("dxy_BS_FLO_vtx_second_test", &dxy_BS_FLO_vtx_second_test, &b_dxy_BS_FLO_vtx_second_test);
   fChain->SetBranchAddress("pt_FLO", &pt_FLO, &b_pt_FLO);
   fChain->SetBranchAddress("eta_FLO", &eta_FLO, &b_eta_FLO);
   fChain->SetBranchAddress("phi_FLO", &phi_FLO, &b_phi_FLO);
   fChain->SetBranchAddress("dxy_BS_FLO", &dxy_BS_FLO, &b_dxy_BS_FLO);
   fChain->SetBranchAddress("dxy_PV_FLO", &dxy_PV_FLO, &b_dxy_PV_FLO);
   fChain->SetBranchAddress("charge_FLO", &charge_FLO, &b_charge_FLO);
   fChain->SetBranchAddress("bs_x_error_base", &bs_x_error_base, &b_bs_x_error_base);
   fChain->SetBranchAddress("bs_y_error_base", &bs_y_error_base, &b_bs_y_error_base);
   fChain->SetBranchAddress("bs_x_error_set", &bs_x_error_set, &b_bs_x_error_set);
   fChain->SetBranchAddress("bs_y_error_set", &bs_y_error_set, &b_bs_y_error_set);
   Notify();
}

Bool_t macro::Notify()
{
   // The Notify() function is called when a new file is opened. This
   // can be either for a new TTree in a TChain or when when a new TTree
   // is started when using PROOF. It is normally not necessary to make changes
   // to the generated code, but the routine can be extended by the
   // user if needed. The return value is currently not used.

   return kTRUE;
}

void macro::Show(Long64_t entry)
{
// Print contents of entry.
// If entry is not specified, print current entry
   if (!fChain) return;
   fChain->Show(entry);
}
Int_t macro::Cut(Long64_t entry)
{
// This function may be called from Loop.
// returns  1 if entry is accepted.
// returns -1 otherwise.
   return 1;
}

void macro::giveAxisTitle(){

    // giving titles to axes
   pt_gen->GetXaxis()->SetTitle("GeV");
   pt_reco->GetXaxis()->SetTitle("GeV");
   pt_flo->GetXaxis()->SetTitle("GeV");
   pt_reco_tune->GetXaxis()->SetTitle("GeV");
   pt_reco_inner_BS->GetXaxis()->SetTitle("GeV");
   pt_reco_glb->GetXaxis()->SetTitle("GeV");
   dxy_reco_BS_glb->GetXaxis()->SetTitle("cm");
   dxy_reco_PV_glb->GetXaxis()->SetTitle("cm");
   dxy_reco_inner_BS->GetXaxis()->SetTitle("cm");
   dxy_reco_inner_PV->GetXaxis()->SetTitle("cm");
   dxy_reco_BS->GetXaxis()->SetTitle("cm");
   dxy_reco_PV->GetXaxis()->SetTitle("cm");
   dxy_reco_BS_tune->GetXaxis()->SetTitle("cm");
   dxy_reco_PV_tune->GetXaxis()->SetTitle("cm");
   dxy_BS_flo->GetXaxis()->SetTitle("cm");
   dxy_PV_flo->GetXaxis()->SetTitle("cm");
   dxy_BS_flo_scale->GetXaxis()->SetTitle("cm");
   dxy_PV_flo_scale->GetXaxis()->SetTitle("cm");
   beamspot_xy->GetXaxis()->SetTitle("cm");
   beamspot_xy->GetYaxis()->SetTitle("cm");
   primaryvertex_xy->GetXaxis()->SetTitle("cm");
   primaryvertex_xy->GetYaxis()->SetTitle("cm");

}

void macro::getInputFile(std::string filename){
	input_file = filename;

}

void macro::changeDeltaPtHist(double min, double max){
	delta_pT = new TH1F("delta_pT","delta pT/pT inner tracker",100,min,max);
}

/*
void changeSaveDir(std::string dir){
	save_dir = dir;
}
*/
#endif // #ifdef macro_cxx

