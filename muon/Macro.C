#define macro_cxx
#include "macro.h"
#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>
#include<TF1.h>
#include<TH1.h>


void Macro(std::string filename, double min, double max, std::string savedir){
	// create an object
	macro obj;
	// mention the root file
	obj.getInputFile(filename);
	obj.initialization();
	obj.giveAxisTitle();
	// change the delta pTover pT histogram range
	//obj.changeDeltaPtHist(-0.03, 0.03);
	obj.changeDeltaPtHist(min, max);
	// where do you want to save the output files
	//obj.changeSavingDirectory("tmp/"); // don't forget to create this folder first
	obj.changeSavingDirectory(savedir); // don't forget to create this folder first
	// release the dragon; let it go 
	obj.Loop();

}


void macro::Loop()
{
gROOT->SetBatch(kTRUE);
   
// defining variables for plotting graph between deltapT/pT vs qd0

     if (fChain == 0) return;

     Long64_t nentries = fChain->GetEntriesFast();
    // Long64_t nentries = 1000;
     Long64_t nbytes = 0, nb = 0;
     

     int number_muons,number_reco, number_flo_muons, number_reco_tune, number_reco_glb, number_reco_inner_BS;
     int count_flo = 0;

     // To know number of events in root file
     std::cout<<"number of events"<<nentries<<std::endl;

     //  for (Long64_t jentry=0; jentry<4000;jentry++){
     for (Long64_t jentry=0; jentry<nentries;jentry++) {
        Long64_t ientry = LoadTree(jentry);
        cout<<" event loop "<<jentry<<endl; 
        //  if (ientry < 0) break;
        nb = fChain->GetEntry(jentry);   nbytes += nb;
        // if (Cut(ientry) < 0) continue;

        GetEntry(jentry);

        cout<<"check for loading entry : jentry :   "<<jentry<<endl;

        Float_t delta_pt = 0, delta_pt_FLO = 0 , delta_pt_glb = 0  , delta_pt_tuned = 0, delta_pt_inner = 0;
        Float_t delta_pt_inverse = 0,delta_pt_inverse_inner_BS = 0, delta_pt_inverse_tuned = 0 , delta_pt_inverse_glb =0,
                delta_pt_inverse_FLO = 0;     
           number_muons = pt_GEN->size();
           number_reco = pt_trk->size();
           number_reco_inner_BS = pt_trk_BS->size();
           number_reco_glb = pt_glb_trk->size();
           number_reco_tune = pt_tuned->size(); 
           
           number_flo_muons = pt_FLO->size(); 
            
           cout<<"number of gen tracks :   "<<number_muons<<endl;
           cout<<"number of reco tracks  :  "<<number_reco<<endl;
           cout<<"number of inner tracks with BS:   "<<number_reco_inner_BS<<endl;
           cout<<"number of reco tracks  :  "<<number_reco<<endl;
           cout<<"number of flo tracks  :  "<<number_reco_tune<<endl;


           for(int i = 0 ; i < number_muons; i++){

              pt_gen->Fill(pt_GEN->at(i));
              eta_gen->Fill(eta_GEN->at(i));
              phi_gen->Fill(phi_GEN->at(i));
              charge_gen->Fill(charge_GEN->at(i));
            }    

            cout<<"beamspot details time"<<endl;
            beamspot_x->Fill(beam_x->at(0));
            beamspot_y->Fill(beam_y->at(0));
            beamspot_z->Fill(beam_z->at(0));
            beamspot_x_err->Fill(beam_x_err->at(0));
            beamspot_y_err->Fill(beam_y_err->at(0));
            beamspot_z_err->Fill(beam_z_err->at(0));
            beamspot_width_x->Fill(beam_width_x->at(0));
            beamspot_width_y->Fill(beam_width_y->at(0));
            beamspot_width_x_err->Fill(beam_width_x_err->at(0));
            beamspot_width_y_err->Fill(beam_width_y_err->at(0));
            beamspot_xy->Fill(beam_width_x->at(0),beam_width_y->at(0));
            cout<<"primary vertex "<<endl;
            primary_vertex_x->Fill(pv_x->at(0));
            primary_vertex_y->Fill(pv_y->at(0));
            primary_vertex_z->Fill(pv_z->at(0));
            primaryvertex_xy->Fill(pv_x->at(0),pv_y->at(0));
            primary_vertex_x_err->Fill(pv_x_err->at(0));
            primary_vertex_y_err->Fill(pv_y_err->at(0));
            primary_vertex_z_err->Fill(pv_z_err->at(0));


            for(int i =0 ; i< number_reco; i++){
               pt_reco->Fill(pt_trk->at(i));
               phi_reco->Fill(phi_trk->at(i));
               eta_reco->Fill(eta_trk->at(i));
               dxy_reco_BS->Fill(dxy_thebeamspot_second->at(i));
               dxy_reco_PV->Fill(dxy_primaryvertex_one->at(i));
               charge_reco->Fill(charge_trk->at(i));
            
            }
          
            for(int i =0 ; i< number_reco_inner_BS; i++){
               pt_reco_inner_BS->Fill(pt_trk_BS->at(i));
               phi_reco_inner_BS->Fill(phi_trk_BS->at(i));
               eta_reco_inner_BS->Fill(eta_trk_BS->at(i));
               dxy_reco_inner_BS->Fill(dxy_trk_BS_const->at(i));
               dxy_reco_inner_PV->Fill(dxy_trk_PV_const->at(i));
            }
            for(int i =0 ; i< number_reco_tune; i++){

            //    d0_reco->Fill(d0_trk->at(i));
                pt_reco_tune->Fill(pt_tuned->at(i));
                phi_reco_tune->Fill(phi_tuned->at(i));
                eta_reco_tune->Fill(eta_tuned->at(i));
                dxy_reco_BS_tune->Fill(dxy_BS_tuned->at(i));
                dxy_reco_PV_tune->Fill(dxy_PV_tuned->at(i));
                charge_reco_tune->Fill(charge_tuned->at(i));
             }

            for(int i =0 ; i< number_reco_glb; i++){
                cout<<"entering into global "<<endl;
                pt_reco_glb->Fill(pt_glb_trk->at(i));
                phi_reco_glb->Fill(phi_glb_trk->at(i));
                eta_reco_glb->Fill(eta_glb_trk->at(i));
                dxy_reco_BS_glb->Fill(dxy_BS_glb_trk->at(i));
                dxy_reco_PV_glb->Fill(dxy_PV_glb_trk->at(i));
                charge_reco_glb->Fill(charge_glb_trk->at(i));
             }

           for(int i =0 ; i< number_flo_muons; i++){
                pt_flo->Fill(pt_FLO->at(i));
                phi_flo->Fill(phi_FLO->at(i));
                eta_flo->Fill(eta_FLO->at(i));
                dxy_BS_flo->Fill(dxy_BS_FLO->at(i));
                dxy_PV_flo->Fill(dxy_PV_FLO->at(i));
                dxy_BS_flo_scale->Fill(dxy_BS_FLO->at(i));
                dxy_PV_flo_scale->Fill(dxy_PV_FLO->at(i));
                charge_flo->Fill(charge_FLO->at(i));
             }

            int k;
              // it would select those events with gen charge and reco charge with same charge

           for(int i=0; i < pt_trk->size();i++){
              if(charge_trk->at(i) == charge_GEN->at(0))
               {  
                delta_pt = (pt_GEN->at(0) - pt_trk->at(i))/(pt_GEN->at(0));
                delta_pt_inverse = ((1/pt_GEN->at(0) - 1/pt_trk->at(i))/(1/pt_GEN->at(0)));
                delta_pT->Fill(delta_pt);
                delta_pT_inverse->Fill(delta_pt_inverse);
               } 
              else break;
            }
    
           for(int i=0; i < pt_trk_BS->size();i++){
              if(charge_trk->at(i) == charge_GEN->at(0))
               {  
                delta_pt_inner = (pt_GEN->at(0) - pt_trk_BS->at(i))/(pt_GEN->at(0));
                delta_pT_inner_BS->Fill(delta_pt_inner);
                delta_pt_inverse_inner_BS = ((1/pt_GEN->at(0) - 1/pt_trk_BS->at(i))/(1/pt_GEN->at(0)));
                delta_pT_inverse_inner_BS->Fill(delta_pt_inverse_inner_BS);
               } 
              else break;
            }
        
            for(int i = 0 ; i < pt_tuned->size(); i++)     
             {  // it would select those events with gen charge and reco charge with same charge
              if(charge_tuned->at(i) == charge_GEN->at(0))
               { 
                delta_pt_tuned = (pt_GEN->at(0) - pt_tuned->at(i))/(pt_GEN->at(0));
                delta_pT_reco_tune->Fill(delta_pt_tuned);
                delta_pt_inverse_tuned = ((1/pt_GEN->at(0) - 1/pt_tuned->at(i))/(1/pt_GEN->at(0)));
                delta_pT_inverse_tune->Fill(delta_pt_inverse_tuned);
               } 
              else break;
             }
                   
            for(int i = 0 ; i < number_reco_glb; i++)     
            {
              // it would select those events with gen charge and reco charge with same charge
              if(charge_glb_trk->at(i) == charge_GEN->at(0)) 
               {
                  cout<<" number of glb  "<<pt_glb_trk->size()<<endl;
                  delta_pt_glb = (pt_GEN->at(0) - pt_glb_trk->at(i))/(pt_GEN->at(0));
                  delta_pT_reco_glb->Fill(delta_pt_glb);
                  delta_pt_inverse_glb = ((1/pt_GEN->at(0) - 1/pt_glb_trk->at(i))/(1/pt_GEN->at(0)));
                  delta_pT_inverse_glb->Fill(delta_pt_inverse_glb);
               }
               else break;
             } 
       

            for(int i =0 ; i< number_flo_muons; i++)
            {   
              if(charge_FLO->at(i) == charge_GEN->at(0))
              {
                delta_pt_FLO = (pt_GEN->at(0) - pt_FLO->at(i))/(pt_GEN->at(0));
                delta_pT_flo->Fill(delta_pt_FLO); 
                delta_pt_inverse_FLO = ((1/pt_GEN->at(0) - 1/pt_FLO->at(i))/(1/pt_GEN->at(0)));
            delta_pT_inverse_FLO->Fill(delta_pt_inverse_FLO);
              }
              else break;
            } 
       
            // end of entry loop
       
          
      }

  // Plotting graphs


          cout<<"plotting canvases now"<<endl;
          TCanvas *gen_info = new TCanvas("gen_info"," gen info ");
          gen_info->Divide(2,2);
          gen_info->cd(1);
          pt_gen->Draw();
          gen_info->cd(2);
          eta_gen->Draw();
          gen_info->cd(3);
          phi_gen->Draw();
          gen_info->cd(4);
          charge_gen->Draw();
          gen_info->SaveAs((save_dir_path +"gen_info.pdf").c_str());


          TCanvas *reco_info = new TCanvas("reco_info"," reco info ");
          reco_info->Divide(2,2);
          reco_info->cd(1);
          pt_reco->Draw();
          reco_info->cd(2);
          eta_reco->Draw();
          reco_info->cd(3);
          phi_reco->Draw();
          reco_info->cd(4);
          charge_reco->Draw();
          reco_info->SaveAs((save_dir_path +"reco_info.pdf").c_str());
 
          TCanvas *reco_info_inner_BS = new TCanvas("reco_info_inner_BS"," reco info _inner_BS");
          reco_info_inner_BS->Divide(2,2);
          reco_info_inner_BS->cd(1);
          pt_reco_inner_BS->Draw();
          reco_info_inner_BS->cd(2);
          eta_reco_inner_BS->Draw();
          reco_info_inner_BS->cd(3);
          phi_reco_inner_BS->Draw();
          reco_info_inner_BS->SaveAs((save_dir_path +"reco_info_inner_BS.pdf").c_str());
          
          TCanvas *reco_glb_info = new TCanvas("reco_glb_info"," reco glb_info ");
          reco_glb_info->Divide(2,2);
          reco_glb_info->cd(1);
          pt_reco_glb->Draw();
          reco_glb_info->cd(2);
          eta_reco_glb->Draw();
          reco_glb_info->cd(3);
          phi_reco_glb->Draw();
          reco_glb_info->SaveAs((save_dir_path +"reco_glb_info.pdf").c_str());


           TCanvas *reco_tuneP_info = new TCanvas("reco_tuneP_info"," reco tuneP info ");
           reco_tuneP_info->Divide(2,2);
           reco_tuneP_info->cd(1);
           pt_reco_tune->Draw();
           reco_tuneP_info->cd(2);
           eta_reco_tune->Draw();
           reco_tuneP_info->cd(3);
           phi_reco_tune->Draw();
           reco_tuneP_info->cd(4);
           charge_reco_tune->Draw();
           reco_tuneP_info->SaveAs((save_dir_path +"reco_tune_info.pdf").c_str());


          TCanvas *dxy_info = new TCanvas("dxy_info"," dxy reco vs FLO ");
          dxy_info->Divide(2,2);
          dxy_info->cd(1);
          dxy_reco_BS->Draw();
          dxy_info->cd(2);
          dxy_reco_PV->Draw(); 
          dxy_info->cd(3);
          dxy_BS_flo->Draw();
          dxy_info->cd(4);
          dxy_PV_flo->Draw();    
          dxy_info->SaveAs((save_dir_path +"dxy_info.pdf").c_str());

          TCanvas *dxy_info_inner_BS = new TCanvas("dxy_info_inner_BS"," dxy reco INNER BS vs FLO ");
          dxy_info_inner_BS->Divide(2,2);
          dxy_info_inner_BS->cd(1);
          dxy_reco_inner_BS->Draw();
          dxy_info_inner_BS->cd(2);
          dxy_reco_inner_PV->Draw(); 
          dxy_info_inner_BS->cd(3);
          dxy_BS_flo->Draw();
          dxy_info_inner_BS->cd(4);
          dxy_PV_flo->Draw();    
          dxy_info_inner_BS->SaveAs((save_dir_path +"dxy_info_inner_BS.pdf").c_str());

          TCanvas *dxy_info_cmp_inner_BS = new TCanvas("dxy_info_cmp_inner_BS"," dxy tracker vs INNER BS  ");
          dxy_info_cmp_inner_BS->Divide(2,2);
          dxy_info_cmp_inner_BS->cd(1);
          dxy_reco_BS->Draw();
          dxy_info_cmp_inner_BS->cd(2);
          dxy_reco_PV->Draw();    
          dxy_info_cmp_inner_BS->cd(3);
          dxy_reco_inner_BS->Draw();
          dxy_info_cmp_inner_BS->cd(4);
          dxy_reco_inner_PV->Draw(); 
  dxy_info_cmp_inner_BS->SaveAs((save_dir_path +"dxy_info_cmp_inner_BS.pdf").c_str());


          TCanvas *dxy_glb_info = new TCanvas("dxy_glb_info"," dxy reco global vs FLO ");
          dxy_glb_info->Divide(2,2);
          dxy_glb_info->cd(1);
          dxy_reco_BS_glb->Draw();
          dxy_glb_info->cd(2);
          dxy_reco_PV_glb->Draw(); 
          dxy_glb_info->cd(3);
          dxy_BS_flo->Draw();
          dxy_glb_info->cd(4);
          dxy_PV_flo->Draw();    
          dxy_glb_info->SaveAs((save_dir_path +"dxy_info_glb.pdf").c_str());
        
          TCanvas *dxy_info_tune = new TCanvas("dxy_info_tune"," dxy reco tune vs FLO  ");
          dxy_info_tune->Divide(2,2);
          dxy_info_tune->cd(1);
          dxy_reco_BS_tune->Draw();
          dxy_info_tune->cd(2);
          dxy_reco_PV_tune->Draw(); 
          dxy_info_tune->cd(3);
          dxy_BS_flo->Draw();
          dxy_info_tune->cd(4);
          dxy_PV_flo->Draw();    
          dxy_info_tune->SaveAs((save_dir_path +"dxy_info_tune.pdf").c_str());



         TCanvas *dxy_info_scale = new TCanvas("dxy_info_scale"," dxy reco vs FLO different axes range");
         dxy_info_scale->Divide(2,2);
         dxy_info_scale->cd(1);
         dxy_reco_BS->Draw();
         dxy_info_scale->cd(2);
         dxy_reco_PV->Draw(); 
         dxy_info_scale->cd(3);
         dxy_BS_flo_scale->Draw();
         dxy_info_scale->cd(4);
         dxy_PV_flo_scale->Draw();    
         dxy_info_scale->SaveAs((save_dir_path +"dxy_info_scale.pdf").c_str());

        TF1 *f1 = new TF1("f1","gaus",-0.12,0.12);
        TF1 *f2 = new TF1("f2","gaus",-0.12,0.12);

TCanvas *delta_pt_cmp_inner_BS = new TCanvas("delta_pt_cmp_inner_BS"," delta pT reco tracker vs tracker with BS ");
delta_pt_cmp_inner_BS->Divide(2,1);
delta_pt_cmp_inner_BS->cd(1);
delta_pT->Fit("f1","R");
gStyle->SetOptFit(1111);
delta_pT->Draw();
delta_pt_cmp_inner_BS->cd(2);
delta_pT_inner_BS->Fit("f2","R");
gStyle->SetOptFit(1111);
delta_pT_inner_BS->Draw();
delta_pt_cmp_inner_BS->SaveAs((save_dir_path +"delta_pT_cmp_inner_BS.pdf").c_str());


TCanvas *delta_pt_inverse_cmp_inner_BS = new TCanvas("delta_pt_inverse_cmp_inner_BS"," delta pT inverse reco tracker vs tracker with BS ");
delta_pt_inverse_cmp_inner_BS->Divide(2,1);
delta_pt_inverse_cmp_inner_BS->cd(1);
delta_pT_inverse->Fit("f1","R");
gStyle->SetOptFit(1111);
delta_pT_inverse->Draw();
delta_pt_inverse_cmp_inner_BS->cd(2);
delta_pT_inverse_inner_BS->Fit("f2","R");
gStyle->SetOptFit(1111);
delta_pT_inverse_inner_BS->Draw();
delta_pt_inverse_cmp_inner_BS->SaveAs((save_dir_path +"delta_pT_inverse_cmp_inner_BS.pdf").c_str());
      
      
      
          TCanvas *delta_pt_info = new TCanvas("delta_pt_info"," delta pT reco tracker vs FLO ");
          delta_pt_info->Divide(2,1);
          delta_pt_info->cd(1);
          delta_pT->Fit("f1","R"); 
          gStyle->SetOptFit(1111);
          delta_pT->Draw();
          delta_pt_info->cd(2);
          delta_pT_flo->Fit("f2","R");
          gStyle->SetOptFit(1111);
          delta_pT_flo->Draw();          
          delta_pt_info->SaveAs((save_dir_path +"delta_pT.pdf").c_str());

          TCanvas *delta_pt_inner_BS_info = new TCanvas("delta_pt_inner_BS_info"," delta pT reco inner Track with BS vs FLO ");
          delta_pt_inner_BS_info->Divide(2,1);
          delta_pt_inner_BS_info->cd(1);
          delta_pT_inner_BS->Fit("f1","R"); 
          gStyle->SetOptFit(1111);
          delta_pT_inner_BS->Draw();
          delta_pt_inner_BS_info->cd(2);
          delta_pT_flo->Fit("f2","R");
          gStyle->SetOptFit(1111);
          delta_pT_flo->Draw();          
          delta_pt_inner_BS_info->SaveAs((save_dir_path +"delta_pT_inner_BS.pdf").c_str());


          TCanvas *delta_pt_inverse_info = new TCanvas("delta_pt_inverse_info"," delta pT inverse_reco vs FLO ");
          delta_pt_inverse_info->Divide(2,1);
          delta_pt_inverse_info->cd(1);
          delta_pT_inverse->Fit("f1","R"); 
          gStyle->SetOptFit(1111);
          delta_pT_inverse->Draw();
          delta_pt_inverse_info->cd(2);
          delta_pT_inverse_FLO->Fit("f2","R");
          gStyle->SetOptFit(1111);
           delta_pT_inverse_FLO->Draw();          
          delta_pt_inverse_info->SaveAs((save_dir_path +"delta_pT_inverse.pdf").c_str());

          TCanvas *delta_pt_inverse_tune_info = new TCanvas("delta_pt_inverse_tune_info","1/(#Delta pT/pT) inverse tune vs FLO ");
          delta_pt_inverse_tune_info->Divide(2,1);
          delta_pt_inverse_tune_info->cd(1);
          delta_pT_inverse_tune->Fit("f1","R"); 
          gStyle->SetOptFit(1111);
          delta_pT_inverse_tune->Draw();
          delta_pt_inverse_tune_info->cd(2);
          delta_pT_inverse_FLO->Fit("f2","R");
          gStyle->SetOptFit(1111);
           delta_pT_inverse_FLO->Draw();          
          delta_pt_inverse_tune_info->SaveAs((save_dir_path +"delta_pT_inverse_tune.pdf").c_str());

          TCanvas *delta_pt_inverse_inner_BS_info = new TCanvas("delta_pt_inverse_inner_BS_info"," delta pT inverse inner BS vs FLO ");
          delta_pt_inverse_inner_BS_info->Divide(2,1);
          delta_pt_inverse_inner_BS_info->cd(1);
          delta_pT_inverse_inner_BS->Fit("f1","R"); 
          gStyle->SetOptFit(1111);
          delta_pT_inverse_inner_BS->Draw();
          delta_pt_inverse_inner_BS_info->cd(2);
          delta_pT_inverse_FLO->Fit("f2","R");
          gStyle->SetOptFit(1111);
           delta_pT_inverse_FLO->Draw();          
          delta_pt_inverse_inner_BS_info->SaveAs((save_dir_path +"delta_pT_inverse_inner_BS_.pdf").c_str());


          TCanvas *delta_pt_inverse_glb_info = new TCanvas("delta_pt_inverse_glb_info"," delta pT inverse reco glb vs FLO ");
          delta_pt_inverse_glb_info->Divide(2,1);
          delta_pt_inverse_glb_info->cd(1);
          delta_pT_inverse_glb->Fit("f1","R"); 
          gStyle->SetOptFit(1111);
          delta_pT_inverse_glb->Draw();
          delta_pt_inverse_glb_info->cd(2);
          delta_pT_inverse_FLO->Fit("f2","R");
          gStyle->SetOptFit(1111);
          delta_pT_inverse_FLO->Draw();          
          delta_pt_inverse_glb_info->SaveAs((save_dir_path +"delta_pT_inverse_glb.pdf").c_str());

          TCanvas *delta_pt_glb_info = new TCanvas("delta_pt_glb_info"," delta pT reco global vs FLO ");
          delta_pt_glb_info->Divide(2,1);
          delta_pt_glb_info->cd(1);
          delta_pT_reco_glb->Fit("f1","R"); 
          gStyle->SetOptFit(1111);
          delta_pT_reco_glb->Draw();
          delta_pt_glb_info->cd(2);
          delta_pT_flo->Fit("f2","R");
          gStyle->SetOptFit(1111);
          delta_pT_flo->Draw();          
          delta_pt_glb_info->SaveAs((save_dir_path +"delta_pT_glb.pdf").c_str());

/*
     TF1 *g1 = new TF1("g1","gaus",-0.02,0.02);
     TF1 *g2 = new TF1("g2","gaus",-0.02,0.02);
         
          TCanvas *delta_pt_info_fit_1 = new TCanvas("delta_pt_info_fit_1"," delta pT reco vs FLO ");
          delta_pt_info_fit_1->cd();
          delta_pT->Fit("g1","R");
          gStyle->SetOptFit(1111);
          delta_pT->Draw();
          delta_pt_info_fit_1->SaveAs("/afs/cern.ch/user/n/nrawal/eos/analyze_programs/SingleMuPt5_local/1stbin_new/delta_pT_fit_1.pdf");

          TCanvas *delta_pt_info_fit_2 = new TCanvas("delta_pt_info_fit_2"," delta pT reco vs FLO ");
          delta_pt_info_fit_2->cd();
          delta_pT_flo->Fit("g2","R"); 
          gStyle->SetOptFit(1111);
          delta_pT_flo->Draw();
  
         //  gStyle->SetOptStat(1101);       
          delta_pt_info_fit_2->SaveAs("/afs/cern.ch/user/n/nrawal/eos/analyze_programs/SingleMuPt5_local/1stbin_new/delta_pT_fit_2.pdf");
*/
          TCanvas *dxy_info_tune_scale = new TCanvas("dxy_info_tune_scale"," dxy reco tune vs FLO different axes range");
          dxy_info_tune_scale->Divide(2,2);
          dxy_info_tune_scale->cd(1);
          dxy_reco_BS_tune->Draw();
          dxy_info_tune_scale->cd(2);
          dxy_reco_PV_tune->Draw(); 
          dxy_info_tune_scale->cd(3);
          dxy_BS_flo_scale->Draw();
          dxy_info_tune_scale->cd(4);
          dxy_PV_flo_scale->Draw();    
          dxy_info_tune_scale->SaveAs((save_dir_path +"dxy_info_tune_scale.pdf").c_str());


          TCanvas *delta_pt_info_tune = new TCanvas("delta_pt_info_tune"," delta pT reco tune vs FLO ");
          delta_pt_info_tune->Divide(2,1);
          delta_pt_info_tune->cd(1);
          delta_pT_reco_tune->Fit("f1","R"); 
          gStyle->SetOptFit(1111);
          delta_pT_reco_tune->Draw();
          delta_pt_info_tune->cd(2);
          delta_pT_flo->Fit("f2","R");
          gStyle->SetOptFit(1111);
          delta_pT_flo->Draw();          
          delta_pt_info_tune->SaveAs((save_dir_path +"delta_pT_tune.pdf").c_str());



          TCanvas *flo_info = new TCanvas("flo_info"," flo info ");
          flo_info->Divide(2,2);
          flo_info->cd(1);
          pt_flo->Draw();
          flo_info->cd(2);
          eta_flo->Draw();
          flo_info->cd(3);
          phi_flo->Draw();
          flo_info->cd(4);
          charge_flo->Draw();
   
    flo_info->SaveAs((save_dir_path +"flo_info.pdf").c_str());

  TF1 *line_fit_hist= new TF1("line_fit_hist","[1]*x+[0]",-5,5);
  cout<<"line definition "<<endl;
  line_fit_hist->SetParName(0,"intercept");  
  line_fit_hist->SetParName(1,"slope");  


          TCanvas *Beamspot_canvas= new TCanvas("Beamspot_canvas"," beamspot position");
          Beamspot_canvas->Divide(3,2);
          Beamspot_canvas->cd(1);
          beamspot_x->Draw();
          Beamspot_canvas->cd(2);
          beamspot_y->Draw();
          Beamspot_canvas->cd(3);
          beamspot_z->Draw(); 
          Beamspot_canvas->cd(4);
          beamspot_width_x->Draw();           
          Beamspot_canvas->cd(5);
          beamspot_width_y->Draw();    
          Beamspot_canvas->SaveAs((save_dir_path +"beamposition.pdf").c_str());


          TCanvas *Beamspot_err_canvas= new TCanvas("Beamspot_err_canvas"," beamspot error");
          Beamspot_err_canvas->Divide(3,2);
          Beamspot_err_canvas->cd(1);
          beamspot_x_err->Draw();
          Beamspot_err_canvas->cd(2);
          beamspot_y_err->Draw();
          Beamspot_err_canvas->cd(3);
          beamspot_z_err->Draw(); 
          Beamspot_err_canvas->cd(4);
          beamspot_width_x_err->Draw();           
          Beamspot_err_canvas->cd(5);
          beamspot_width_y_err->Draw();    
          Beamspot_err_canvas->SaveAs((save_dir_path +"beamspot_err.pdf").c_str());



          TCanvas *primary_vertex_canvas= new TCanvas("primary_vertex_canvas"," primary vertex ");
          primary_vertex_canvas->Divide(3,2);
          primary_vertex_canvas->cd(1);
          primary_vertex_x->Draw();
          primary_vertex_canvas->cd(2);
          primary_vertex_y->Draw();
          primary_vertex_canvas->cd(3);
          primary_vertex_z->Draw(); 
          primary_vertex_canvas->cd(4);
          primary_vertex_x_err->Draw();
          primary_vertex_canvas->cd(5);
          primary_vertex_y_err->Draw();
          primary_vertex_canvas->cd(6);
          primary_vertex_z_err->Draw();
          //primary_vertex_canvas->SaveAs("/afs/cern.ch/user/n/nrawal/eos/analyze_programs/SingleMuPt5_local/1stbin_new/primary_vertex_position.pdf");
          primary_vertex_canvas->SaveAs((save_dir_path +"primary_vertex_position.pdf").c_str());


       

/*1. draw h1
2. take its stat box [stat1 = TPaveStats (hdt.GetListOfFunctions().FindObject("stats"))]
3. draw h2.
4. take its stat box
5. draw h1
6. draw h2 [with "SAME" option]
7. draw both stat boxes*/
 
// Program ending here          
  }
