//Code originally written by Debabrata Bhowmik

#define something_v8_cxx
#include "something_v8.h"
#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>

#include <utility>

void something_v8::Loop()
{
//   In a ROOT session, you can do:
//      Root > .L HGCalpromptReco.C
//      Root > HGCalpromptReco t
//      Root > t.GetEntry(12); // Fill t data members with entry number 12
//      Root > t.Show();       // Show values of entry 12
//      Root > t.Show(16);     // Read and show values of entry 16
//      Root > t.Loop();       // Loop on all entries
//

//     This is the loop skeleton where:
//    jentry is the global entry number in the chain
//    ientry is the entry number in the current Tree
//  Note that the argument to GetEntry must be:
//    jentry for TChain::GetEntry
//    ientry for TTree::GetEntry and TBranch::GetEntry
//
//       To read only selected branches, Insert statements like:
// METHOD1:
//    fChain->SetBranchStatus("*",0);  // disable all branches
//    fChain->SetBranchStatus("branchname",1);  // activate branchname
// METHOD2: replace line
//    fChain->GetEntry(jentry);       //read all branches
//by  b_branchname->GetEntry(ientry); //read only this branch
   if (fChain == 0) return;

   Long64_t nentries = fChain->GetEntriesFast();
   
   vector<TH1F*> vecE1_currLayer;
   vector<TH1F*> vecE6_currLayer;
   vector<TH1F*> vecE18_currLayer;
   vector<TH1F*> vecE7_currLayer;
   vector<TH1F*> vecE19_currLayer;
   vector<TH1F*> vecE1byE7_currLayer;
   vector<TH1F*> vecE1byE19_currLayer;
   vector<TH1F*> vecE7byE19_currLayer;
   vector<TH1F*> vecSumE_currLayer;
   vector<TH2F*> vecE1iuiv_currLayer;
   vector<TH2F*> vecE1xy_currLayer;

   TFile * myFile=new TFile("data_v8_1MIP.root","RECREATE");
   //TFile * myFile=new TFile("filexy.root","NEW");
   const int max_Layer = 28;

      char name[100], Title[100], name2[100], Title2[100];
      
      for(int k = 0; k<max_Layer; k++){
	sprintf(name,"hE1_Layer%d",k+1);
	sprintf(Title,"distribution of E1 at layer%d",k+1);
	vecE1_currLayer.push_back(new TH1F(name,Title,1500,0,1500 ));	
	
	sprintf(name2,"hE6_Layer%d",k+1);
	sprintf(Title2,"distribution of E6 at layer%d",k+1);
	vecE6_currLayer.push_back( new TH1F(name2,Title2, 1500,0,1500));
	
	sprintf(name2,"hE18_Layer%d",k+1);
	sprintf(Title2,"distribution of E18 at layer%d",k+1);
	vecE18_currLayer.push_back( new TH1F(name2,Title2, 1500,0,1500));
	
	sprintf(name,"hE7_Layer%d",k+1);
        sprintf(Title,"distribution of E7 at layer%d",k+1);
        vecE7_currLayer.push_back(new TH1F(name,Title, 1500,0,1500 ));
	
	sprintf(name,"hE19_Layer%d",k+1);
        sprintf(Title,"distribution of E19 at layer%d",k+1);
        vecE19_currLayer.push_back(new TH1F(name,Title, 1500,0,1500 ));
		
        sprintf(name,"hE1byE7_Layer%d",k+1);
        sprintf(Title,"distribution of E1/E7 at layer%d",k+1);
        vecE1byE7_currLayer.push_back(new TH1F(name,Title, 1200,0,1.2 ));	
	
        sprintf(name,"hE1byE19_Layer%d",k+1);
        sprintf(Title,"distribution of E1/E19 at layer%d",k+1);
        vecE1byE19_currLayer.push_back(new TH1F(name,Title, 1200,0,1.2 ));	

        sprintf(name,"hE7byE19_Layer%d",k+1);
        sprintf(Title,"distribution of E7/E19 at layer%d",k+1);
        vecE7byE19_currLayer.push_back(new TH1F(name,Title, 1200,0,1.2 ));	
		
	sprintf(name,"hSumE_Layer%d",k+1);
        sprintf(Title,"distribution of Energy Sum at layer%d",k+1);
        vecSumE_currLayer.push_back(new TH1F(name,Title, 1500,0,1500 ));

	sprintf(name,"hE1iuiv_Layer%d",k+1);
        sprintf(Title,"Positions of maximum Energy hit at layer%d",k+1);
        vecE1iuiv_currLayer.push_back(new TH2F(name,Title, 40,-10,10, 40, -10, 10 ));

	sprintf(name,"hE1xy_Layer%d",k+1);
        sprintf(Title,"Positions of maximum Energy hit at layer%d",k+1);
        vecE1xy_currLayer.push_back(new TH2F(name,Title, 80, -10, 10, 80, -10, 10 ));
      }

   Long64_t nbytes = 0, nb = 0;
   for (Long64_t jentry=0; jentry<nentries;jentry++) {
     //for (Long64_t jentry=0; jentry<5000;jentry++) {
      Long64_t ientry = LoadTree(jentry);
      if (ientry < 0) break;
      nb = fChain->GetEntry(jentry);   nbytes += nb;
      // if (Cut(ientry) < 0) continue;
      double rechit_energyPerEvent = 0.;

      if(jentry == 0){
	string particle_name = "my particle";
	if (pdgID == 211)  particle_name = "pi+";
	if (pdgID == -211) particle_name = "pi-";
	if (pdgID == 11)   particle_name = "e-" ;
	if (pdgID == -11)  particle_name = "e+";
	if (pdgID == 13)   particle_name = "mu-";
	if (pdgID == -13)  particle_name = "mu+";
	//if ( !abs(pdgID) == (211 || 11 ||13)) particle_name = "UNKNOWN";
	if (!(abs(pdgID)==211 || abs(pdgID)==11 || abs(pdgID)==13)) particle_name = "UNKNOWN";
	cout<<"beam particle "<<particle_name<<"  pdgId "<<pdgID<<"  with energy "<<beamEnergy<<"GeV"<<endl; 
      }
      if (! (abs(pdgID)==11) ) {
	cout<< "Not electron";
      }
      if(!(beamEnergy == 100)){
	cout<<"not 100 GeV electron"<<endl;
      }
      double SumE_layer[max_Layer] ={0.};

      double E1_layer[max_Layer] = {0.};
      double  detID_E1_layer[max_Layer] = {0.};

      double iu_E1_layer[max_Layer] ={0.};
      double iv_E1_layer[max_Layer] = {0.};

      double x_E1_layer[max_Layer] ={0.};
      double y_E1_layer[max_Layer] = {0.};

      for(int i =0; i<NRechits; i++){
	if(rechit_layer->at(i) > max_Layer) continue;

	int curr_layerNo = rechit_layer->at(i);
	double curr_rechitEn=rechit_energy->at(i);
	bool curr_noiseflag=rechit_noise_flag->at(i);
	if(curr_rechitEn < 1.0) continue;

	if(curr_noiseflag) continue;

	//SumE_layer[curr_layerNo-1] += curr_rechitEn;
	SumE_layer[curr_layerNo-1] +=rechit_energy->at(i);

	double curr_xpos = rechit_x->at(i);
	double curr_ypos = rechit_y->at(i);

	double dis = sqrt(curr_xpos*curr_xpos + curr_ypos*curr_ypos);

	if (dis>5.) continue;

	if (curr_rechitEn > E1_layer[curr_layerNo -1]){
	  E1_layer[curr_layerNo -1] = curr_rechitEn;

	  detID_E1_layer[curr_layerNo] = rechit_detid->at(i);
	  iu_E1_layer[curr_layerNo -1] = rechit_iu->at(i);
	  iv_E1_layer[curr_layerNo -1] = rechit_iv->at(i);

	  x_E1_layer[curr_layerNo -1] = rechit_x->at(i);
	  y_E1_layer[curr_layerNo -1] = rechit_y->at(i);
	}

      }

      double E7_layer[max_Layer]={0.};
      double E19_layer[max_Layer]={0.};
      
      for(int i =0; i<NRechits; i++){

	if(rechit_layer->at(i) > max_Layer) continue;
	if(rechit_energy->at(i) < 1.0) continue;
	if(rechit_noise_flag->at(i)) continue;

	int curr_layerNo = rechit_layer->at(i);
	
	int curr_iu = rechit_iu->at(i);
	int curr_iv = rechit_iv->at(i);

	double curr_x = rechit_x->at(i);
	double curr_y = rechit_y->at(i);

	pair<int, int> curr_iuiv;
	curr_iuiv=make_pair(curr_iu, curr_iv);
	
	int iu_E1_currlayer = iu_E1_layer[curr_layerNo -1];
	int iv_E1_currlayer = iv_E1_layer[curr_layerNo -1];

	double x_E1_currlayer = x_E1_layer[curr_layerNo -1];
	double y_E1_currlayer = y_E1_layer[curr_layerNo -1];

	pair<int, int> det2_iuiv, det3_iuiv, det4_iuiv, det5_iuiv, det6_iuiv, det7_iuiv;
	
	det2_iuiv=make_pair(iu_E1_currlayer +1 , iv_E1_currlayer);
	det3_iuiv=make_pair(iu_E1_currlayer -1 , iv_E1_currlayer);	
	det4_iuiv=make_pair(iu_E1_currlayer, iv_E1_currlayer+1);
	det5_iuiv=make_pair(iu_E1_currlayer, iv_E1_currlayer-1);
	det6_iuiv=make_pair(iu_E1_currlayer+1, iv_E1_currlayer+1);
	det7_iuiv=make_pair(iu_E1_currlayer-1, iv_E1_currlayer-1);
	
	double Xdist = curr_x - x_E1_currlayer;
	double Ydist = curr_y - y_E1_currlayer;

	double R = sqrt(Xdist*Xdist + Ydist*Ydist);

	  /*
	  if (curr_iuiv==det2_iuiv || curr_iuiv==det3_iuiv ||curr_iuiv==det4_iuiv ||curr_iuiv==det5_iuiv ||curr_iuiv==det6_iuiv ||curr_iuiv==det7_iuiv ){
	  E6_layer[curr_layerNo -1] += rechit_energy->at(i);
	    }
	  */
	
	if(R<1.13){
	  E7_layer[curr_layerNo -1] += rechit_energy->at(i);
	}
	
	if(R<2.26){
	  E19_layer[curr_layerNo -1] += rechit_energy->at(i);
	}
	
      }
      
      for(int k = 0; k<max_Layer; k++){
	double E1_currLayer = E1_layer[k];
	vecE1_currLayer[k]->Fill(E1_currLayer);
	
	double E6_currLayer = E7_layer[k] - E1_layer[k];
	vecE6_currLayer[k]->Fill(E6_currLayer);
	
	double E18_currLayer = E19_layer[k] - E1_layer[k];
	vecE18_currLayer[k]->Fill(E18_currLayer);
	
	double E7_currLayer = E7_layer[k];
	vecE7_currLayer[k]->Fill(E7_currLayer);
	
	double E19_currLayer = E19_layer[k];
	vecE19_currLayer[k]->Fill(E19_currLayer);
		
	if(!(E1_currLayer==0.) && !(E7_currLayer==0.)){
	  double E1byE7_currLayer = E1_currLayer/E7_currLayer;
	  vecE1byE7_currLayer[k]->Fill(E1byE7_currLayer);
	}
	
	if(!(E1_currLayer==0.) && !(E19_currLayer==0.)){
	  double E1byE19_currLayer = E1_currLayer/E19_currLayer;
	  vecE1byE19_currLayer[k]->Fill(E1byE19_currLayer);
	}

	if(!(E7_currLayer==0.) && !(E19_currLayer==0.)){
	  double E7byE19_currLayer = E7_currLayer/E19_currLayer;
	  vecE7byE19_currLayer[k]->Fill(E7byE19_currLayer);
	}
		
	double SumE_currLayer = SumE_layer[k];
	vecSumE_currLayer[k]->Fill(SumE_currLayer);

	double E1iu_currLayer = iu_E1_layer[k];
	double E1iv_currLayer = iv_E1_layer[k];
	vecE1iuiv_currLayer[k]->Fill(E1iu_currLayer,E1iv_currLayer);

	double E1x_currLayer = x_E1_layer[k];
	double E1y_currLayer = y_E1_layer[k];
	vecE1xy_currLayer[k]->Fill(E1x_currLayer,E1y_currLayer);
      }

   }


   char hisname[100];
   for(int k = 0; k<max_Layer; k++){
     sprintf(hisname,"hE1_layer%d",k+1);
     TH1F* hist = (TH1F*)vecE1_currLayer[k]->Clone();
     hist->SetName(hisname);
     hist->SetMarkerStyle(kFullCircle);
     hist->Draw();
     hist->SetOption("PE");
     hist->Write();

     sprintf(hisname,"hE6_layer%d",k+1);
     TH1F* hist2 = (TH1F*)vecE6_currLayer[k]->Clone();
     hist2->SetName(hisname);
     hist2->SetMarkerStyle(kFullCircle);
     hist2->Draw();
     hist2->SetOption("PE");
     hist2->Write();
     
     sprintf(hisname,"hE18_layer%d",k+1);
     TH1F* hist8 = (TH1F*)vecE18_currLayer[k]->Clone();
     hist8->SetName(hisname);
     hist8->SetMarkerStyle(kFullCircle);
     hist8->Draw();
     hist8->SetOption("PE");
     hist8->Write();
          
     sprintf(hisname,"hE7_layer%d",k+1);
     TH1F* hist3 = (TH1F*)vecE7_currLayer[k]->Clone();
     hist3->SetName(hisname);
     hist3->SetMarkerStyle(kFullCircle);
     hist3->Draw();
     hist3->SetOption("PE");
     hist3->Write();
     
     sprintf(hisname,"hE19_layer%d",k+1);
     TH1F* hist9 = (TH1F*)vecE19_currLayer[k]->Clone();
     hist9->SetName(hisname);
     hist9->SetMarkerStyle(kFullCircle);
     hist9->Draw();
     hist9->SetOption("PE");
     hist9->Write();
     
     sprintf(hisname,"hE1byE7_layer%d",k+1);
     TH1F* hist4 = (TH1F*)vecE1byE7_currLayer[k]->Clone();
     hist4->SetName(hisname);
     hist4->SetMarkerStyle(kFullCircle);
     hist4->Draw();
     hist4->SetOption("PE");
     hist4->Write();
     
     sprintf(hisname,"hE1byE19_layer%d",k+1);
     TH1F* hist10 = (TH1F*)vecE1byE19_currLayer[k]->Clone();
     hist10->SetName(hisname);
     hist10->SetMarkerStyle(kFullCircle);
     hist10->Draw();
     hist10->SetOption("PE");
     hist10->Write();

     sprintf(hisname,"hE7byE19_layer%d",k+1);
     TH1F* hist11 = (TH1F*)vecE7byE19_currLayer[k]->Clone();
     hist11->SetName(hisname);
     hist11->SetMarkerStyle(kFullCircle);
     hist11->Draw();
     hist11->SetOption("PE");
     hist11->Write();
     
     sprintf(hisname,"hSumE_layer%d",k+1);
     TH1F* hist5 = (TH1F*)vecSumE_currLayer[k]->Clone();
     hist5->SetName(hisname);
     hist5->SetMarkerStyle(kFullCircle);
     hist5->Draw();
     hist5->SetOption("PE");
     hist5->Write();

     sprintf(hisname,"hE1hitPosition_layer%d",k+1);
     TH2F* hist6 = (TH2F*)vecE1iuiv_currLayer[k]->Clone();
     hist6->SetName(hisname);
     hist6->SetMarkerStyle(kFullCircle);
     hist6->GetXaxis()->SetTitle("iu");
     hist6->GetYaxis()->SetTitle("iv");
     hist6->Draw();
     hist6->SetOption("colz");
     hist6->Write();

     sprintf(hisname,"hE1hitPositionXY_layer%d",k+1);
     TH2F* hist7 = (TH2F*)vecE1xy_currLayer[k]->Clone();
     hist7->SetName(hisname);
     hist7->SetMarkerStyle(kFullCircle);
     hist7->GetXaxis()->SetTitle("x");
     hist7->GetYaxis()->SetTitle("y");
     hist7->Draw();
     hist7->SetOption("colz");
     hist7->Write();
   }
   
   //myFile->Close();
   
   /*
   TCanvas *c1 = new TCanvas("c1","RecHit Energy Distribution",1000,900);
   gPad-> SetLogy();
   hrechit_energy->GetXaxis()->SetTitle("Energy(GeV)");
   hrechit_energy->GetYaxis()->SetTitle("Counts/2GeV");
   hrechit_energy->SetMarkerStyle(kFullCircle);
   hrechit_energy->Draw("PE");
   c1->Draw();
   c1->SaveAs("RecHitEenergy.png");
   */

}
