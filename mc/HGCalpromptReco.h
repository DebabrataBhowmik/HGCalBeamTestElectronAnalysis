//////////////////////////////////////////////////////////
// This class has been automatically generated on
// Wed Nov 14 03:05:56 2018 by ROOT version 6.12/07
// from TTree hits/HGC rechits
// found on file: ntuple_sim_config22_pdgID11_beamMomentum100.0_listFTFP_BERT_EMM.root
//////////////////////////////////////////////////////////

#ifndef HGCalpromptReco_h
#define HGCalpromptReco_h

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>

// Header file for the classes stored in the TTree if any.
#include "vector"
#include "vector"
#include "vector"
#include "vector"
#include "vector"

class HGCalpromptReco {
public :
   TTree          *fChain;   //!pointer to the analyzed TTree or TChain
   Int_t           fCurrent; //!current Tree number in a TChain

// Fixed size dimensions of array or collections stored in the TTree if any.

   // Declaration of leaf types
   UInt_t          event;
   ULong64_t       trigger_timestamp;
   UInt_t          run;
   Int_t           pdgID;
   Float_t         beamEnergy;
   Float_t         trueBeamEnergy;
   UInt_t          NRechits;
   vector<unsigned int> *rechit_detid;
   vector<unsigned int> *rechit_module;
   vector<unsigned int> *rechit_layer;
   vector<unsigned int> *rechit_chip;
   vector<unsigned int> *rechit_channel;
   vector<unsigned int> *rechit_type;
   vector<float>   *rechit_x;
   vector<float>   *rechit_y;
   vector<float>   *rechit_z;
   vector<short>   *rechit_iu;
   vector<short>   *rechit_iv;
   vector<short>   *rechit_iU;
   vector<short>   *rechit_iV;
   vector<float>   *rechit_energy;
   vector<float>   *rechit_energy_noHG;
   vector<float>   *rechit_amplitudeHigh;
   vector<float>   *rechit_amplitudeLow;
   vector<bool>    *rechit_hg_goodFit;
   vector<bool>    *rechit_lg_goodFit;
   vector<bool>    *rechit_hg_saturated;
   vector<bool>    *rechit_lg_saturated;
   vector<bool>    *rechit_fully_calibrated;
   vector<bool>    *rechit_noise_flag;
   vector<float>   *rechit_TS2High;
   vector<float>   *rechit_TS2Low;
   vector<float>   *rechit_TS3High;
   vector<float>   *rechit_TS3Low;
   vector<unsigned short> *rechit_Tot;
   vector<float>   *rechit_time;
   vector<float>   *rechit_timeMaxHG;
   vector<float>   *rechit_timeMaxLG;
   vector<unsigned short> *rechit_toaRise;
   vector<unsigned short> *rechit_toaFall;

   // List of branches
   TBranch        *b_event;   //!
   TBranch        *b_trigger_timestamp;   //!
   TBranch        *b_run;   //!
   TBranch        *b_pdgID;   //!
   TBranch        *b_beamEnergy;   //!
   TBranch        *b_trueBeamEnergy;   //!
   TBranch        *b_NRechits;   //!
   TBranch        *b_rechit_detid;   //!
   TBranch        *b_rechit_module;   //!
   TBranch        *b_rechit_layer;   //!
   TBranch        *b_rechit_chip;   //!
   TBranch        *b_rechit_channel;   //!
   TBranch        *b_rechit_type;   //!
   TBranch        *b_rechit_x;   //!
   TBranch        *b_rechit_y;   //!
   TBranch        *b_rechit_z;   //!
   TBranch        *b_rechit_iu;   //!
   TBranch        *b_rechit_iv;   //!
   TBranch        *b_rechit_iU;   //!
   TBranch        *b_rechit_iV;   //!
   TBranch        *b_rechit_energy;   //!
   TBranch        *b_rechit_energy_noHG;   //!
   TBranch        *b_rechit_amplitudeHigh;   //!
   TBranch        *b_rechit_amplitudeLow;   //!
   TBranch        *b_rechit_hg_goodFit;   //!
   TBranch        *b_rechit_lg_goodFit;   //!
   TBranch        *b_rechit_hg_saturated;   //!
   TBranch        *b_rechit_lg_saturated;   //!
   TBranch        *b_rechit_fully_calibrated;   //!
   TBranch        *b_rechit_noise_flag;   //!
   TBranch        *b_rechit_TS2High;   //!
   TBranch        *b_rechit_TS2Low;   //!
   TBranch        *b_rechit_TS3High;   //!
   TBranch        *b_rechit_TS3Low;   //!
   TBranch        *b_rechit_Tot;   //!
   TBranch        *b_rechit_time;   //!
   TBranch        *b_rechit_timeMaxHG;   //!
   TBranch        *b_rechit_timeMaxLG;   //!
   TBranch        *b_rechit_toaRise;   //!
   TBranch        *b_rechit_toaFall;   //!

   HGCalpromptReco(TTree *tree=0);
   virtual ~HGCalpromptReco();
   virtual Int_t    Cut(Long64_t entry);
   virtual Int_t    GetEntry(Long64_t entry);
   virtual Long64_t LoadTree(Long64_t entry);
   virtual void     Init(TTree *tree);
   virtual void     Loop();
   virtual Bool_t   Notify();
   virtual void     Show(Long64_t entry = -1);
};

#endif

#ifdef HGCalpromptReco_cxx
HGCalpromptReco::HGCalpromptReco(TTree *tree) : fChain(0) 
{
// if parameter tree is not specified (or zero), connect the file
// used to generate this class and read the Tree.
   if (tree == 0) {
     //TFile *f = (TFile*)gROOT->GetListOfFiles()->FindObject("ntuple_sim_config22_pdgID11_beamMomentum100.0_listFTFP_BERT_EMM.root");
     //TFile *f = (TFile*)gROOT->GetListOfFiles()->FindObject("/eos/cms/store/group/dpg_hgcal/tb_hgcal/2018/cern_h2_october/offline_analysis/sim_ntuples/v2/with1p1mmPCB/ntuple_sim_config22_pdgID11_beamMomentum100_listFTFP_BERT_EMM.root");
     //TFile *f = (TFile*)gROOT->GetListOfFiles()->FindObject("/eos/cms/store/group/dpg_hgcal/tb_hgcal/2018/cern_h2_october/offline_analysis/sim_ntuples/v2/ntuple_sim_config22_pdgID11_beamMomentum100_listFTFP_BERT_EMM.root");
      TFile *f = (TFile*)gROOT->GetListOfFiles()->FindObject("/eos/cms/store/group/dpg_hgcal/tb_hgcal/2018/cern_h2_october/offline_analysis/sim_ntuples/v1/ntuple_sim_config22_pdgID11_beamMomentum100.0_listFTFP_BERT_EMM.root");
      if (!f || !f->IsOpen()) {
	//f = new TFile("ntuple_sim_config22_pdgID11_beamMomentum100.0_listFTFP_BERT_EMM.root");
	//f = new TFile("/eos/cms/store/group/dpg_hgcal/tb_hgcal/2018/cern_h2_october/offline_analysis/sim_ntuples/v2/with1p1mmPCB/ntuple_sim_config22_pdgID11_beamMomentum100_listFTFP_BERT_EMM.root");
	//f = new TFile("/eos/cms/store/group/dpg_hgcal/tb_hgcal/2018/cern_h2_october/offline_analysis/sim_ntuples/v2/ntuple_sim_config22_pdgID11_beamMomentum100_listFTFP_BERT_EMM.root");
	f = new TFile("/eos/cms/store/group/dpg_hgcal/tb_hgcal/2018/cern_h2_october/offline_analysis/sim_ntuples/v1/ntuple_sim_config22_pdgID11_beamMomentum100.0_listFTFP_BERT_EMM.root");       
      }
      //TDirectory * dir = (TDirectory*)f->Get("ntuple_sim_config22_pdgID11_beamMomentum100.0_listFTFP_BERT_EMM.root:/rechitntupler");
      //TDirectory * dir = (TDirectory*)f->Get("/eos/cms/store/group/dpg_hgcal/tb_hgcal/2018/cern_h2_october/offline_analysis/sim_ntuples/v2/with1p1mmPCB/ntuple_sim_config22_pdgID11_beamMomentum100_listFTFP_BERT_EMM.root:/rechitntupler");
      //TDirectory * dir = (TDirectory*)f->Get("/eos/cms/store/group/dpg_hgcal/tb_hgcal/2018/cern_h2_october/offline_analysis/sim_ntuples/v2/ntuple_sim_config22_pdgID11_beamMomentum100_listFTFP_BERT_EMM.root:/rechitntupler");
      TDirectory * dir = (TDirectory*)f->Get("/eos/cms/store/group/dpg_hgcal/tb_hgcal/2018/cern_h2_october/offline_analysis/sim_ntuples/v1/ntuple_sim_config22_pdgID11_beamMomentum100.0_listFTFP_BERT_EMM.root:/rechitntupler");
      dir->GetObject("hits",tree);
   }
   Init(tree);
}

HGCalpromptReco::~HGCalpromptReco()
{
   if (!fChain) return;
   delete fChain->GetCurrentFile();
}

Int_t HGCalpromptReco::GetEntry(Long64_t entry)
{
// Read contents of entry.
   if (!fChain) return 0;
   return fChain->GetEntry(entry);
}
Long64_t HGCalpromptReco::LoadTree(Long64_t entry)
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

void HGCalpromptReco::Init(TTree *tree)
{
   // The Init() function is called when the selector needs to initialize
   // a new tree or chain. Typically here the branch addresses and branch
   // pointers of the tree will be set.
   // It is normally not necessary to make changes to the generated
   // code, but the routine can be extended by the user if needed.
   // Init() will be called many times when running on PROOF
   // (once per file to be processed).

   // Set object pointer
   rechit_detid = 0;
   rechit_module = 0;
   rechit_layer = 0;
   rechit_chip = 0;
   rechit_channel = 0;
   rechit_type = 0;
   rechit_x = 0;
   rechit_y = 0;
   rechit_z = 0;
   rechit_iu = 0;
   rechit_iv = 0;
   rechit_iU = 0;
   rechit_iV = 0;
   rechit_energy = 0;
   rechit_energy_noHG = 0;
   rechit_amplitudeHigh = 0;
   rechit_amplitudeLow = 0;
   rechit_hg_goodFit = 0;
   rechit_lg_goodFit = 0;
   rechit_hg_saturated = 0;
   rechit_lg_saturated = 0;
   rechit_fully_calibrated = 0;
   rechit_noise_flag = 0;
   rechit_TS2High = 0;
   rechit_TS2Low = 0;
   rechit_TS3High = 0;
   rechit_TS3Low = 0;
   rechit_Tot = 0;
   rechit_time = 0;
   rechit_timeMaxHG = 0;
   rechit_timeMaxLG = 0;
   rechit_toaRise = 0;
   rechit_toaFall = 0;
   // Set branch addresses and branch pointers
   if (!tree) return;
   fChain = tree;
   fCurrent = -1;
   fChain->SetMakeClass(1);

   fChain->SetBranchAddress("event", &event, &b_event);
   fChain->SetBranchAddress("trigger_timestamp", &trigger_timestamp, &b_trigger_timestamp);
   fChain->SetBranchAddress("run", &run, &b_run);
   fChain->SetBranchAddress("pdgID", &pdgID, &b_pdgID);
   fChain->SetBranchAddress("beamEnergy", &beamEnergy, &b_beamEnergy);
   fChain->SetBranchAddress("trueBeamEnergy", &trueBeamEnergy, &b_trueBeamEnergy);
   fChain->SetBranchAddress("NRechits", &NRechits, &b_NRechits);
   fChain->SetBranchAddress("rechit_detid", &rechit_detid, &b_rechit_detid);
   fChain->SetBranchAddress("rechit_module", &rechit_module, &b_rechit_module);
   fChain->SetBranchAddress("rechit_layer", &rechit_layer, &b_rechit_layer);
   fChain->SetBranchAddress("rechit_chip", &rechit_chip, &b_rechit_chip);
   fChain->SetBranchAddress("rechit_channel", &rechit_channel, &b_rechit_channel);
   fChain->SetBranchAddress("rechit_type", &rechit_type, &b_rechit_type);
   fChain->SetBranchAddress("rechit_x", &rechit_x, &b_rechit_x);
   fChain->SetBranchAddress("rechit_y", &rechit_y, &b_rechit_y);
   fChain->SetBranchAddress("rechit_z", &rechit_z, &b_rechit_z);
   fChain->SetBranchAddress("rechit_iu", &rechit_iu, &b_rechit_iu);
   fChain->SetBranchAddress("rechit_iv", &rechit_iv, &b_rechit_iv);
   fChain->SetBranchAddress("rechit_iU", &rechit_iU, &b_rechit_iU);
   fChain->SetBranchAddress("rechit_iV", &rechit_iV, &b_rechit_iV);
   fChain->SetBranchAddress("rechit_energy", &rechit_energy, &b_rechit_energy);
   fChain->SetBranchAddress("rechit_energy_noHG", &rechit_energy_noHG, &b_rechit_energy_noHG);
   fChain->SetBranchAddress("rechit_amplitudeHigh", &rechit_amplitudeHigh, &b_rechit_amplitudeHigh);
   fChain->SetBranchAddress("rechit_amplitudeLow", &rechit_amplitudeLow, &b_rechit_amplitudeLow);
   fChain->SetBranchAddress("rechit_hg_goodFit", &rechit_hg_goodFit, &b_rechit_hg_goodFit);
   fChain->SetBranchAddress("rechit_lg_goodFit", &rechit_lg_goodFit, &b_rechit_lg_goodFit);
   fChain->SetBranchAddress("rechit_hg_saturated", &rechit_hg_saturated, &b_rechit_hg_saturated);
   fChain->SetBranchAddress("rechit_lg_saturated", &rechit_lg_saturated, &b_rechit_lg_saturated);
   fChain->SetBranchAddress("rechit_fully_calibrated", &rechit_fully_calibrated, &b_rechit_fully_calibrated);
   fChain->SetBranchAddress("rechit_noise_flag", &rechit_noise_flag, &b_rechit_noise_flag);
   fChain->SetBranchAddress("rechit_TS2High", &rechit_TS2High, &b_rechit_TS2High);
   fChain->SetBranchAddress("rechit_TS2Low", &rechit_TS2Low, &b_rechit_TS2Low);
   fChain->SetBranchAddress("rechit_TS3High", &rechit_TS3High, &b_rechit_TS3High);
   fChain->SetBranchAddress("rechit_TS3Low", &rechit_TS3Low, &b_rechit_TS3Low);
   fChain->SetBranchAddress("rechit_Tot", &rechit_Tot, &b_rechit_Tot);
   fChain->SetBranchAddress("rechit_time", &rechit_time, &b_rechit_time);
   fChain->SetBranchAddress("rechit_timeMaxHG", &rechit_timeMaxHG, &b_rechit_timeMaxHG);
   fChain->SetBranchAddress("rechit_timeMaxLG", &rechit_timeMaxLG, &b_rechit_timeMaxLG);
   fChain->SetBranchAddress("rechit_toaRise", &rechit_toaRise, &b_rechit_toaRise);
   fChain->SetBranchAddress("rechit_toaFall", &rechit_toaFall, &b_rechit_toaFall);
   Notify();
}

Bool_t HGCalpromptReco::Notify()
{
   // The Notify() function is called when a new file is opened. This
   // can be either for a new TTree in a TChain or when when a new TTree
   // is started when using PROOF. It is normally not necessary to make changes
   // to the generated code, but the routine can be extended by the
   // user if needed. The return value is currently not used.

   return kTRUE;
}

void HGCalpromptReco::Show(Long64_t entry)
{
// Print contents of entry.
// If entry is not specified, print current entry
   if (!fChain) return;
   fChain->Show(entry);
}
Int_t HGCalpromptReco::Cut(Long64_t entry)
{
// This function may be called from Loop.
// returns  1 if entry is accepted.
// returns -1 otherwise.
   return 1;
}
#endif // #ifdef HGCalpromptReco_cxx
