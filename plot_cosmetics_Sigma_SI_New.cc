{

  TFile* f = new TFile("graphs.root");

  TGraph* Ld = (TGraph*)f->Get("g2_05_SI");
  TGraph* Lu = (TGraph*)f->Get("g3_05_SI");
  TGraph* Lmono = (TGraph*)f->Get("g_mono_SD");
   
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
  
  TFile* f1 = new TFile("SI_Graphs.root");
  
  TGraph* cdf = (TGraph*)f1->Get("CDF_SI");
  TGraph* CDMSII = (TGraph*)f1->Get("cdms_edelweiss_right_format");
  TGraph* pMSSM = (TGraph*)f1->Get("pMSSM_right_format");
  TGraph* Xenon10s2 = (TGraph*)f1->Get("xenon_10s2_right_format");
  TGraph* Xenon1T = (TGraph*)f1->Get("xenon_1T_right_format");
  TGraph* monojet = (TGraph*)f1->Get("Monojet_8TeV");

  cdf->SetLineColor(kMagenta-4);
  cdf->SetLineWidth(3);
  cdf->SetLineStyle(1);

  CDMSII->SetLineColor(kOrange-2);
  CDMSII->SetLineWidth(3);
  CDMSII->SetLineStyle(1);
  
  pMSSM->SetLineColor(kBlue-9);
  pMSSM->SetFillColor(kBlue-9);
  pMSSM->SetLineWidth(3);
  pMSSM->SetLineStyle(1);

  Xenon10s2->SetLineColor(kCyan+1);
  Xenon10s2->SetLineWidth(3);
  Xenon10s2->SetLineStyle(1);
  
  Xenon1T->SetLineColor(kViolet-4);
  Xenon1T->SetLineWidth(3);
  Xenon1T->SetLineStyle(1);

  monojet->SetLineColor(8);
  monojet->SetLineWidth(3);
  monojet->SetLineStyle(9);
  
  TMultiGraph *mg = new TMultiGraph();
  
  mg->Add(pMSSM,"F");
  mg->Add(monojet,"L");
  mg->Add(Ld,"L");
  mg->Add(Lu,"L");
  mg->Add(cdf,"L");
  mg->Add(CDMSII,"L");
  mg->Add(Xenon10s2,"L");
  mg->Add(Xenon1T,"L");
  mg->Draw("A");
  mg->GetXaxis()->SetTitle(labelX);
  mg->GetYaxis()->SetTitle(labelY);
  mg->GetXaxis()->SetTitleOffset(1.1);
  mg->GetXaxis()-> CenterTitle();
  mg->GetYaxis()->SetTitleOffset(1.7);
  mg->GetYaxis()-> CenterTitle();
  //mg->GetXaxis()->SetRangeUser(1.0, 1000.0);
  mg->GetXaxis()->SetLimits(1.0, 1000.0);
  mg->GetYaxis()->SetRangeUser(1e-51, 1e-26);
  
  TLatex *t = new TLatex();
  t->SetNDC();
  t->SetTextAlign(22);
  t->SetTextSize(0.03);
  //t->DrawLatex(0.25,0.87,"CMS Preliminary");
  t->DrawLatex(0.29,0.87,"Caltech-CMS Internal");   
  t->DrawLatex(0.29,0.825,"#sqrt{s} = 8 TeV");
  t->DrawLatex(0.29,0.745,"#int L dt = 5 fb^{-1}");
  
  TLegend* leg = new TLegend(0.45, 0.65, 0.89, 0.89);//(xmin, ymin, xmax, ymax)
  leg->AddEntry(Ld, "Razor SI u-quark (5 fb^{-1})" ,"l");
  leg->AddEntry(Lu, "Razor SI d-quark (5 fb^{-1})" ,"l");
  leg->AddEntry(monojet, "Monojet SD combined limit (19.5 fb^{-1})" ,"l");
  leg->AddEntry(cdf, "CDF 2012" ,"l");
  leg->AddEntry(CDMSII, "CDMS-Edelweiss Combined Limit" ,"l");
  leg->AddEntry(pMSSM, "pMSSM, 2013, 99.5% C.L" ,"l");
  leg->AddEntry(Xenon10s2, "XENON 10, S2 only (2011)" ,"l");
  leg->AddEntry(Xenon1T, "XENON 1T (projected 2017)" ,"l");
  
  leg->SetFillColor(0);
  leg->SetBorderSize(0);
  leg->SetTextSize(0.03);
  leg->SetTextSize(.022);
  leg->SetFillColor(0);
  leg->Draw();

  pad1->SetLogy();
  pad1->SetLogx();
  pad1->Update();
  C->SaveAs("SI_SigmaLimit_test.pdf");
  C->SaveAs("SI_SigmaLimit_test.png");


}
