//////////////////////////////////////////////////////////
//Code originally written by Debabrata Bhowmik
//////////////////////////////////////////////////////////

#include <TROOT.h>
#include <TFile.h>

using namespace std;

void MakeClassProducer(){
  string   line;
  ifstream myfile;
  ofstream file2;
  char name[200];
  if(!myfile.is_open()){
    myfile.open("ntuples_v8.txt");
  }
  TChain chain("/rechitntupler/hits"); 
  int lineno =1;
  while (getline(myfile,line)){
    stringstream s_in(line);
    s_in>>name;
    TFile *f = new TFile(name);
    cout<<name<<endl;  
    TTree *tree;
    f->GetObject("/rechitntupler/hits",tree);
    
    //TBranch *pdgID = (TBranch*)tree->GetBranch("pdgID");
    Int_t pdgiD;
    tree->SetBranchAddress("pdgID",&pdgiD);
    float beamEn;
    tree->SetBranchAddress("beamEnergy",&beamEn);
    UInt_t Run;
    tree->SetBranchAddress("run",&Run);

    //TH1I *h1 =new TH1I("","",100,1,50000);
    for(int i=0;i<1;i++){
      tree->GetEntry(i);
      //h1->Fill(pdgiD);
      if(Run<389 || Run>722) continue;      
      if(pdgiD==11 && beamEn == 100){
	if(!file2.is_open()){
	  file2.open("files_v8.txt");
	  }
	file2<<name<<endl;
	
	chain.Add(name); 
      }
      
    }

  }
  chain.MakeClass("something_v8");
}
