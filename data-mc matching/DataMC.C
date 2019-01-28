#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>
#include <TFile.h>

void DataMC(){
  
  TFile *data = new TFile("../data/data_v8_1MIP.root");
  TFile *mc = new TFile("../mc/mc_v1_1MIP.root");

  const int max_Layer = 28;

  //************************************ E1 draw*******************************************
  char name[100],name2[100];

  const char *label1 = "data";
  const char *label2 = "mc";

  TH1F*h_data;
  TH1F*h_mc;

  for(int k = 0; k<max_Layer; k++){  
    sprintf(name,"hE1_layer%d",k+1);  
    
    data->GetObject(name,h_data); 
    mc->GetObject(name,h_mc);  
    
    TCanvas *cE1 = new TCanvas("E1","E1",1000,900);
    h_data->GetXaxis()->SetTitle("E1 in MIP");
    h_data->GetXaxis()->SetTitleSize(0.05);
    h_data->GetXaxis()->SetTitleOffset(1.0);
    //h_data->GetYaxis()->SetTitle("Events/GeV");
    h_data->GetYaxis()->SetTitleOffset(1.45);
    h_data->SetMarkerStyle(kFullCircle);

    h_mc->SetMarkerColor(kRed);

    TVirtualPad* p11;
    p11 = cE1->cd();
    p11 -> SetLogy();
    
    double I_mc = h_mc->Integral(); 
    double I = h_data->Integral(); 
    h_mc->Scale(I/I_mc);

    h_data->Draw("PE");
    h_mc->Draw("PE sames");
    
    TLegend *l = cE1->BuildLegend(0.60,0.83,0.70,0.93);
    TList *p = l->GetListOfPrimitives();
    TIter next(p);
    TObject *obj;
    TLegendEntry *le;
    int i = 0;
    while ((obj = next())) {
      le = (TLegendEntry*)obj;
      i++;
      if (i==1) le->SetLabel(label1);
      if (i==2) le->SetLabel(label2);
    }

    cE1->Update();
    TPaveStats *p1 = (TPaveStats*)h_data->FindObject("stats");

    TPaveStats *p2 = (TPaveStats*)h_mc->FindObject("stats");
    p2->SetY1NDC(0.55);
    p2->SetY2NDC(0.75);
    p2->SetTextColor(kRed); 
   
    sprintf(name2,"E1_Layer%d.png",k+1);  
    cE1->SaveAs(name2);
    delete h_data;
    delete h_mc;
    delete cE1;
  //*****************************************************************************************
    
  //*****************************Distribution of E7*********************************************
    sprintf(name,"hE7_layer%d",k+1);  

    data->GetObject(name,h_data); 
    mc->GetObject(name,h_mc);  
    
    cE1 = new TCanvas("E7","E7",1000,900);
    h_data->GetXaxis()->SetTitle("E7 in MIP");
    h_data->GetXaxis()->SetTitleSize(0.05);
    h_data->GetXaxis()->SetTitleOffset(1.0);
    //h_data->GetYaxis()->SetTitle("Events/GeV");
    h_data->GetYaxis()->SetTitleOffset(1.45);
    h_data->SetMarkerStyle(kFullCircle);
    
    h_mc->SetMarkerColor(kRed);

    p11 = cE1->cd();
    p11 -> SetLogy();
    
    I_mc = h_mc->Integral(); 
    I = h_data->Integral(); 
    h_mc->Scale(I/I_mc);

    h_data->Draw("PE");
    h_mc->Draw("PE sames");
    
    l = cE1->BuildLegend(0.60,0.83,0.70,0.93);
    p = l->GetListOfPrimitives();
    TIter next2(p);
    i = 0;
    while ((obj = next2())) {
      le = (TLegendEntry*)obj;
      i++;
      if (i==1) le->SetLabel(label1);
      if (i==2) le->SetLabel(label2);
    }

    cE1->Update();
    p1 = (TPaveStats*)h_data->FindObject("stats");

    p2 = (TPaveStats*)h_mc->FindObject("stats");
    p2->SetY1NDC(0.55);
    p2->SetY2NDC(0.75);
    p2->SetTextColor(kRed); 
    
    sprintf(name2,"E7_Layer%d.png",k+1);  
    cE1->SaveAs(name2);
    delete h_data;
    delete h_mc;
    delete cE1;    
  //*****************************************************************************************

  //*****************************Distribution of E19*********************************************
    sprintf(name,"hE19_layer%d",k+1);  

    data->GetObject(name,h_data); 
    mc->GetObject(name,h_mc);  
    
    cE1 = new TCanvas("E19","E19",1000,900);
    h_data->GetXaxis()->SetTitle("E19 in MIP");
    h_data->GetXaxis()->SetTitleSize(0.05);
    h_data->GetXaxis()->SetTitleOffset(1.0);
    //h_data->GetYaxis()->SetTitle("Events/GeV");
    h_data->GetYaxis()->SetTitleOffset(1.45);
    h_data->SetMarkerStyle(kFullCircle);
    
    h_mc->SetMarkerColor(kRed);

    p11 = cE1->cd();
    p11 -> SetLogy();
    
    I_mc = h_mc->Integral(); 
    I = h_data->Integral(); 
    h_mc->Scale(I/I_mc);

    h_data->Draw("PE");
    h_mc->Draw("PE sames");
    
    l = cE1->BuildLegend(0.60,0.83,0.70,0.93);
    p = l->GetListOfPrimitives();
    TIter next3(p);
    i = 0;
    while ((obj = next3())) {
      le = (TLegendEntry*)obj;
      i++;
      if (i==1) le->SetLabel(label1);
      if (i==2) le->SetLabel(label2);
    }

    cE1->Update();
    p1 = (TPaveStats*)h_data->FindObject("stats");

    p2 = (TPaveStats*)h_mc->FindObject("stats");
    p2->SetY1NDC(0.55);
    p2->SetY2NDC(0.75);
    p2->SetTextColor(kRed); 
    
    sprintf(name2,"E19_Layer%d.png",k+1);  
    cE1->SaveAs(name2);
    delete h_data;
    delete h_mc;
    delete cE1;
    //*******************************************************************************************

    //*****************************E1/E7 draw*********************************************
    sprintf(name,"hE1byE7_layer%d",k+1);

    data->GetObject(name,h_data); 
    mc->GetObject(name,h_mc);  
    
    cE1 = new TCanvas("E1byE7","E1byE7",1000,900);
    h_data->GetXaxis()->SetTitle("E1/E7");
    h_data->GetXaxis()->SetTitleSize(0.05);
    h_data->GetXaxis()->SetTitleOffset(1.0);
    //h_data->GetYaxis()->SetTitle("Events/GeV");
    h_data->GetYaxis()->SetTitleOffset(1.45);
    h_data->SetMarkerStyle(kFullCircle);
    
    h_mc->SetMarkerColor(kRed);

    //p11 = cE1->cd();
    //p11 -> SetLogy();
    
    I_mc = h_mc->Integral(); 
    I = h_data->Integral(); 
    h_mc->Scale(I/I_mc);

    h_data->Rebin(2);
    h_mc->Rebin(2);

    h_data->GetXaxis()->SetRangeUser(0.0, 0.99);
    //h_data->GetYaxis()->SetRangeUser(0.0, 1500);
    h_mc->GetXaxis()->SetRangeUser(0.0, 0.99);
    //h_mc->GetYaxis()->SetRangeUser(0.0, 1500);

    int bin5 = h_data->GetMaximumBin();
    int bin6 = h_mc->GetMaximumBin();

    int binC5 = h_data->GetBinContent(bin5);
    double Yrange17 = binC5;
    int binC6 = h_mc->GetBinContent(bin6);
    if (binC6>binC5) Yrange17 = binC6;
    Yrange17 = 1.2*Yrange17;

    h_data->GetYaxis()->SetRangeUser(0.0, Yrange17);

    h_data->Draw("PE");
    h_mc->Draw("PE sames");

    h_data->Draw("PE");
    h_mc->Draw("PE sames");
    
    l = cE1->BuildLegend(0.23,0.82,0.33,0.92);
    p = l->GetListOfPrimitives();
    TIter next4(p);
    i = 0;
    while ((obj = next4())) {
      le = (TLegendEntry*)obj;
      i++;
      if (i==1) le->SetLabel(label1);
      if (i==2) le->SetLabel(label2);
    }

    cE1->Update();
    p1 = (TPaveStats*)h_data->FindObject("stats");
    p1->SetX1NDC(0.12);
    p1->SetX2NDC(0.22);
    p1->SetY1NDC(0.82);
    p1->SetY2NDC(0.92);

    p2 = (TPaveStats*)h_mc->FindObject("stats");
    p2->SetX1NDC(0.12);
    p2->SetX2NDC(0.22);
    p2->SetY1NDC(0.7);
    p2->SetY2NDC(0.8);
    p2->SetTextColor(kRed); 
    
    sprintf(name2,"E1byE7_NonLog_Layer%d.png",k+1);  
    cE1->SaveAs(name2);
    delete h_data;
    delete h_mc;
    delete cE1;
    //**************************************************************************************

    //*****************************E1/E19 draw*********************************************
    sprintf(name,"hE1byE19_layer%d",k+1);

    data->GetObject(name,h_data); 
    mc->GetObject(name,h_mc);  
    
    cE1 = new TCanvas("E1byE19","E1byE19",1000,900);
    h_data->GetXaxis()->SetTitle("E1/E19");
    h_data->GetXaxis()->SetTitleSize(0.05);
    h_data->GetXaxis()->SetTitleOffset(1.0);
    //h_data->GetYaxis()->SetTitle("Events/GeV");
    h_data->GetYaxis()->SetTitleOffset(1.45);
    h_data->SetMarkerStyle(kFullCircle);
    
    h_mc->SetMarkerColor(kRed);

    //p11 = cE1->cd();
    //p11 -> SetLogy();
    
    I_mc = h_mc->Integral(); 
    I = h_data->Integral(); 
    h_mc->Scale(I/I_mc);

    h_data->Rebin(2);
    h_mc->Rebin(2);


    h_data->GetXaxis()->SetRangeUser(0.0, 0.99);
    //h_data->GetYaxis()->SetRangeUser(0.0, 1500);
    h_mc->GetXaxis()->SetRangeUser(0.0, 0.99);
    //h_mc->GetYaxis()->SetRangeUser(0.0, 1500);

    int bin3 = h_data->GetMaximumBin();
    int bin4 = h_mc->GetMaximumBin();

    int binC3 = h_data->GetBinContent(bin3);
    double Yrange119 = binC3;
    int binC4 = h_mc->GetBinContent(bin4);
    if (binC4>binC3) Yrange119 = binC4;
    Yrange119 = 1.2*Yrange119;

    h_data->GetYaxis()->SetRangeUser(0.0, Yrange119);
    h_data->Draw("PE");
    h_mc->Draw("PE sames");
    
    //l = cE1->BuildLegend(0.60,0.83,0.70,0.93);
    l = cE1->BuildLegend(0.23,0.82,0.33,0.92);
    p = l->GetListOfPrimitives();
    TIter next5(p);
    i = 0;
    while ((obj = next5())) {
      le = (TLegendEntry*)obj;
      i++;
      if (i==1) le->SetLabel(label1);
      if (i==2) le->SetLabel(label2);
    }

    cE1->Update();
    p1 = (TPaveStats*)h_data->FindObject("stats");
    p1->SetX1NDC(0.12);
    p1->SetX2NDC(0.22);
    p1->SetY1NDC(0.82);
    p1->SetY2NDC(0.92);

    p2 = (TPaveStats*)h_mc->FindObject("stats");
    p2->SetX1NDC(0.12);
    p2->SetX2NDC(0.22);
    p2->SetY1NDC(0.7);
    p2->SetY2NDC(0.8);
    p2->SetTextColor(kRed); 

    
    sprintf(name2,"E1byE19_NonLog_Layer%d.png",k+1);  
    cE1->SaveAs(name2);
    delete h_data;
    delete h_mc;
    delete cE1;
    //*************************************************************************************************

    //*****************************E7/E19 draw*********************************************
    sprintf(name,"hE7byE19_layer%d",k+1);

    data->GetObject(name,h_data); 
    mc->GetObject(name,h_mc);  
    
    cE1 = new TCanvas("E7byE19","E7byE19",1000,900);
    h_data->GetXaxis()->SetTitle("E7/E19");
    h_data->GetXaxis()->SetTitleSize(0.05);
    h_data->GetXaxis()->SetTitleOffset(1.0);
    //h_data->GetYaxis()->SetTitle("Events/GeV");
    h_data->GetYaxis()->SetTitleOffset(1.35);
    h_data->SetMarkerStyle(kFullCircle);
    
    h_mc->SetMarkerColor(kRed);

    //p11 = cE1->cd();
    //p11 -> SetLogy();
    
    I_mc = h_mc->Integral(); 
    I = h_data->Integral(); 
    h_mc->Scale(I/I_mc);

    h_data->Rebin(2);
    h_mc->Rebin(2);

    h_data->GetXaxis()->SetRangeUser(0.0, 0.99);

    h_mc->GetXaxis()->SetRangeUser(0.0, 0.99);
    //h_mc->GetYaxis()->SetRangeUser(0.0, 5000);

    int bin = h_data->GetMaximumBin();
    int bin2 = h_mc->GetMaximumBin();

    int binC = h_data->GetBinContent(bin);
    double Yrange = binC;
    int binC2 = h_mc->GetBinContent(bin2);
    if (binC2>binC) Yrange = binC2;
    Yrange = 1.2*Yrange;

    cout<< bin << " " <<binC<<endl;
    cout<< bin2 << " " <<binC2<<endl;

    h_data->GetYaxis()->SetRangeUser(0.0, Yrange);

    h_data->Draw("PE");
    h_mc->Draw("PE sames");
    
    //l = cE1->BuildLegend(0.60,0.83,0.70,0.93);
    l = cE1->BuildLegend(0.23,0.82,0.33,0.92);
    p = l->GetListOfPrimitives();
    TIter next7(p);
    i = 0;
    while ((obj = next7())) {
      le = (TLegendEntry*)obj;
      i++;
      if (i==1) le->SetLabel(label1);
      if (i==2) le->SetLabel(label2);
    }

    cE1->Update();
    p1 = (TPaveStats*)h_data->FindObject("stats");
    p1->SetX1NDC(0.12);
    p1->SetX2NDC(0.22);
    p1->SetY1NDC(0.82);
    p1->SetY2NDC(0.92);

    p2 = (TPaveStats*)h_mc->FindObject("stats");
    p2->SetX1NDC(0.12);
    p2->SetX2NDC(0.22);
    p2->SetY1NDC(0.7);
    p2->SetY2NDC(0.8);
    p2->SetTextColor(kRed); 
    
    sprintf(name2,"E7byE19_Layer%d.png",k+1);  
    cE1->SaveAs(name2);
    delete h_data;
    delete h_mc;
    delete cE1;
    //*************************************************************************************************

  //*****************************Distribution of SumE*********************************************
    sprintf(name,"hSumE_layer%d",k+1);  

    data->GetObject(name,h_data); 
    mc->GetObject(name,h_mc);  
    
    cE1 = new TCanvas("SumE","SumE",1000,900);
    h_data->GetXaxis()->SetTitle("SumE in MIP");
    h_data->GetXaxis()->SetTitleSize(0.05);
    h_data->GetXaxis()->SetTitleOffset(1.0);
    h_data->GetYaxis()->SetTitle("Events/GeV");
    h_data->GetYaxis()->SetTitleOffset(1.45);
    h_data->SetMarkerStyle(kFullCircle);
    
    h_mc->SetMarkerColor(kRed);

    p11 = cE1->cd();
    p11 -> SetLogy();
    
    I_mc = h_mc->Integral(); 
    I = h_data->Integral(); 
    h_mc->Scale(I/I_mc);

    h_data->Draw("PE");
    h_mc->Draw("PE sames");
    
    l = cE1->BuildLegend(0.60,0.83,0.70,0.93);
    p = l->GetListOfPrimitives();
    TIter next6(p);
    i = 0;
    while ((obj = next6())) {
      le = (TLegendEntry*)obj;
      i++;
      if (i==1) le->SetLabel(label1);
      if (i==2) le->SetLabel(label2);
    }

    cE1->Update();
    p1 = (TPaveStats*)h_data->FindObject("stats");

    p2 = (TPaveStats*)h_mc->FindObject("stats");
    p2->SetY1NDC(0.55);
    p2->SetY2NDC(0.75);
    p2->SetTextColor(kRed); 
    
    sprintf(name2,"SumE_Layer%d.png",k+1);  
    cE1->SaveAs(name2);
    delete h_data;
    delete h_mc;
    delete cE1;
    //*******************************************************************************************

    //********************************x-y position of max energy hit*****************************
    TH2F*h_dataXY;
    TH2F*h_mcXY;
    sprintf(name,"hE1hitPositionXY_layer%d",k+1);  

    data->GetObject(name,h_dataXY); 
    mc->GetObject(name,h_mcXY);  
    
    TCanvas*cEpos = new TCanvas("E1hitposXY","E1hitposXY",2000,900);
    h_dataXY->GetXaxis()->SetTitle("X in cm");
    h_dataXY->GetXaxis()->SetTitleSize(0.05);
    h_dataXY->GetXaxis()->SetTitleOffset(1.0);
    h_dataXY->GetYaxis()->SetTitle("Y in cm");
    h_dataXY->GetYaxis()->SetTitleOffset(1.45);

    h_mcXY->GetXaxis()->SetTitle("X in cm");
    h_mcXY->GetXaxis()->SetTitleSize(0.05);
    h_mcXY->GetXaxis()->SetTitleOffset(1.0);
    h_mcXY->GetYaxis()->SetTitle("Y in cm");
    h_mcXY->GetYaxis()->SetTitleOffset(1.45);

    cEpos->Divide(2,1);
    cEpos->cd(1);
    h_dataXY->Draw("colz");
    cEpos->cd(2);
    h_mcXY->Draw("colz");

    cEpos->Update();
    TPaveStats *pos = (TPaveStats*)h_mcXY->FindObject("stats");
    pos->SetX1NDC(0.66);
    pos->SetX2NDC(0.88);
    pos->SetY1NDC(0.77);
    pos->SetY2NDC(0.92);
    pos = (TPaveStats*)h_dataXY->FindObject("stats");
    pos->SetX1NDC(0.66);
    pos->SetX2NDC(0.88);
    pos->SetY1NDC(0.77);
    pos->SetY2NDC(0.92);
    
    TPaletteAxis *palette = (TPaletteAxis*)h_dataXY->GetListOfFunctions()->FindObject("palette");
    palette->SetX1NDC(0.88);
    palette->SetX2NDC(0.90);
    palette->SetY1NDC(0.1);
    palette->SetY2NDC(0.9);

    palette = (TPaletteAxis*)h_mcXY->GetListOfFunctions()->FindObject("palette");
    palette->SetX1NDC(0.88);
    palette->SetX2NDC(0.90);
    palette->SetY1NDC(0.1);
    palette->SetY2NDC(0.9);

    cEpos->Modified();

    sprintf(name2,"E1posXY_Layer%d.png",k+1);  
    cEpos->SaveAs(name2);
    delete cEpos;
    //*******************************************************************************************

    //********************************x-y position of max energy hit*****************************
    TH2F*h_dataiuiv;
    TH2F*h_mciuiv;
    sprintf(name,"hE1hitPosition_layer%d",k+1);  

    data->GetObject(name,h_dataiuiv); 
    mc->GetObject(name,h_mciuiv);  
    
    cEpos = new TCanvas("SumE","SumE",2000,900);
    h_dataiuiv->GetXaxis()->SetTitle("iu");
    h_dataiuiv->GetXaxis()->SetTitleSize(0.05);
    h_dataiuiv->GetXaxis()->SetTitleOffset(1.0);
    h_dataiuiv->GetYaxis()->SetTitle("iv");
    h_dataiuiv->GetYaxis()->SetTitleOffset(1.45);

    h_mciuiv->GetXaxis()->SetTitle("iu");
    h_mciuiv->GetXaxis()->SetTitleSize(0.05);
    h_mciuiv->GetXaxis()->SetTitleOffset(1.0);
    h_mciuiv->GetYaxis()->SetTitle("iv");
    h_mciuiv->GetYaxis()->SetTitleOffset(1.45);

    cEpos->Divide(2,1);
    cEpos->cd(1);
    h_dataiuiv->Draw("colz");
    cEpos->cd(2);
    h_mciuiv->Draw("colz");

    cEpos->Update();

    pos = (TPaveStats*)h_mciuiv->FindObject("stats");
    pos->SetX1NDC(0.66);
    pos->SetX2NDC(0.88);
    pos->SetY1NDC(0.77);
    pos->SetY2NDC(0.92);
    pos = (TPaveStats*)h_dataiuiv->FindObject("stats");
    pos->SetX1NDC(0.66);
    pos->SetX2NDC(0.88);
    pos->SetY1NDC(0.77);
    pos->SetY2NDC(0.92);
    
    palette = (TPaletteAxis*)h_dataiuiv->GetListOfFunctions()->FindObject("palette");
    palette->SetX1NDC(0.88);
    palette->SetX2NDC(0.90);
    palette->SetY1NDC(0.1);
    palette->SetY2NDC(0.9);

    palette = (TPaletteAxis*)h_mciuiv->GetListOfFunctions()->FindObject("palette");
    palette->SetX1NDC(0.88);
    palette->SetX2NDC(0.90);
    palette->SetY1NDC(0.1);
    palette->SetY2NDC(0.9);

    cEpos->Modified();
    
    sprintf(name2,"E1posiuiv_Layer%d.png",k+1);  
    cEpos->SaveAs(name2);
    delete cEpos;
    //******************************************************************************************

    }

}
