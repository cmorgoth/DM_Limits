{

  TFile* f = new TFile("graphs.root");

  TGraph* Ld = (TGraph*)f->Get("g0_05_SD");
  TGraph* Lu = (TGraph*)f->Get("g1_05_SD");
  TGraph* Lmono = (TGraph*)f->Get("g_mono_SI");
   
  TCanvas* C = new TCanvas("C", "C", 640, 640);
  C->cd();
  TString labelX = "M_{#chi} (GeV)";
  TString labelY = "#sigma_{N-#chi} (cm^{2})";
  
  TPad *pad1 = new TPad("pad1","pad1",.0,0.,1,1);
  //pad1->SetBottomMargin(0);
  pad1->SetLeftMargin(0.12);
  pad1->Draw();
  pad1->cd();

  Ld->SetLineColor(kBlue);
  Ld->SetLineWidth(3);
  Ld->SetLineStyle(9);
  
  Lu->SetLineColor(kRed);
  Lu->SetLineWidth(3);
  Lu->SetLineStyle(9);
  Lmono->SetLineColor(kGreen);
  Lmono->SetLineWidth(3);
  Lmono->SetLineStyle(9);
  
  Ld->GetYaxis()->SetTitle(labelY);
  Ld->GetXaxis()->SetTitleOffset(1.1);
  Ld->GetXaxis()-> CenterTitle();
  Ld->GetYaxis()->SetTitleOffset(1.3);
  Ld->GetYaxis()-> CenterTitle();
  
  TFile* f1 = new TFile("SD_Graphs.root");
  
  TGraph* cdf = (TGraph*)f1->Get("CDF_SD");
  TGraph* CDMSII = (TGraph*)f1->Get("CDMSII_limits_right_formt_SD");
  TGraph* COUPP = (TGraph*)f1->Get("COUPP_2008");
  TGraph* Ice_Cub = (TGraph*)f1->Get("Ice_Cub_proton_2009");
  TGraph* SIMPLE_N = (TGraph*)f1->Get("SIMPLE_right_Neutron");
  TGraph* SIMPLE_P = (TGraph*)f1->Get("SIMPLE_right_Proton");
  TGraph* SuperK_P = (TGraph*)f1->Get("SuperK_proton_2004");
  TGraph* monojet = (TGraph*)f1->Get("Monojet_8TeV");

  cdf->SetLineColor(kMagenta-4);
  cdf->SetLineWidth(3);
  cdf->SetLineStyle(1);

  CDMSII->SetLineColor(kOrange-2);
  CDMSII->SetLineWidth(3);
  CDMSII->SetLineStyle(1);
  
  COUPP->SetLineColor(kBlue-1);
  COUPP->SetLineWidth(3);
  COUPP->SetLineStyle(1);

  Ice_Cub->SetLineColor(kCyan+1);
  Ice_Cub->SetLineWidth(3);
  Ice_Cub->SetLineStyle(1);
  
  SIMPLE_N->SetLineColor(kViolet-4);
  SIMPLE_N->SetLineWidth(3);
  SIMPLE_N->SetLineStyle(1);

  SIMPLE_P->SetLineColor(kGreen+2);
  SIMPLE_P->SetLineWidth(3);
  SIMPLE_P->SetLineStyle(1);

  SuperK_P->SetLineColor(kAzure-9);
  SuperK_P->SetLineWidth(3);
  SuperK_P->SetLineStyle(1);
  
  monojet->SetLineColor(8);
  monojet->SetLineWidth(3);
  monojet->SetLineStyle(9);
  
  TMultiGraph *mg = new TMultiGraph();
  
  mg->Add(monojet,"L");
  mg->Add(Ld,"L");
  mg->Add(Lu,"L");
  mg->Add(cdf,"L");
  mg->Add(CDMSII,"L");
  mg->Add(COUPP,"L");
  mg->Add(Ice_Cub,"L");
  mg->Add(SIMPLE_N,"L");
  mg->Add(SIMPLE_P,"L");
  mg->Add(SuperK_P,"L");
  mg->Draw("A");
  mg->GetXaxis()->SetTitle(labelX);
  mg->GetYaxis()->SetTitle(labelY);
  mg->GetXaxis()->SetTitleOffset(1.1);
  mg->GetXaxis()-> CenterTitle();
  mg->GetYaxis()->SetTitleOffset(1.7);
  mg->GetYaxis()-> CenterTitle();
  //mg->GetXaxis()->SetRangeUser(1.0, 1000.0);
  mg->GetXaxis()->SetLimits(1.0, 1000.0);
  mg->GetYaxis()->SetRangeUser(1e-48, 1e-26);
  
  TLatex *t = new TLatex();
  t->SetNDC();
  t->SetTextAlign(22);
  t->SetTextSize(0.03);
  //t->DrawLatex(0.25,0.87,"CMS Preliminary");
  t->DrawLatex(0.29,0.87,"Caltech-CMS Internal");   
  t->DrawLatex(0.29,0.825,"#sqrt{s} = 8 TeV");
  t->DrawLatex(0.29,0.745,"#int L dt = 5 fb^{-1}");
  
  TLegend* leg = new TLegend(0.45, 0.65, 0.89, 0.89);//(xmin, ymin, xmax, ymax)
  leg->AddEntry(Ld, "Razor SD u-quark (5 fb^{-1})" ,"l");
  leg->AddEntry(Lu, "Razor SD d-quark (5 fb^{-1})" ,"l");
  leg->AddEntry(monojet, "Monojet SD combined limit (19.5 fb^{-1})" ,"l");
  leg->AddEntry(cdf, "CDF 2012" ,"l");
  leg->AddEntry(CDMSII, "CDMSII 2010" ,"l");
  leg->AddEntry(COUPP, "COUPP" ,"l");
  leg->AddEntry(Ice_Cub, "IceCube W^{+}W^{-}" ,"l");
  leg->AddEntry(SIMPLE_N, "SIMPLE 2005 Neutron" ,"l");
  leg->AddEntry(SIMPLE_P, "SIMPLE 2005 Proton" ,"l");
  leg->AddEntry(SuperK_P, "SuperK-W^{+}W^{-}" ,"l");
  leg->SetFillColor(0);
  leg->SetBorderSize(0);
  leg->SetTextSize(0.03);
  leg->SetTextSize(.022);
  leg->SetFillColor(0);
  leg->Draw();

  pad1->SetLogy();
  pad1->SetLogx();
  pad1->Update();
  C->SaveAs("SD_SigmaLimit_test.pdf");
  C->SaveAs("SD_SigmaLimit_test.png");


}
