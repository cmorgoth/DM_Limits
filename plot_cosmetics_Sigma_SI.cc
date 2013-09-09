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
  pad1->SetRightMargin(0.04);
  pad1->Draw();
  pad1->cd();

  Ld->SetLineColor(kBlue);
  Ld->SetLineWidth(3);
  Ld->SetLineStyle(2);
  
  
  Lu->SetLineColor(kRed);
  Lu->SetLineWidth(3);
  Lu->SetLineStyle(2);
  Lmono->SetLineColor(kGreen);
  Lmono->SetLineWidth(3);
  Lmono->SetLineStyle(2);
  
  Ld->GetYaxis()->SetTitle(labelY);
  Ld->GetXaxis()->SetTitleOffset(1.1);
  Ld->GetXaxis()-> CenterTitle();
  Ld->GetYaxis()->SetTitleOffset(1.3);
  Ld->GetYaxis()-> CenterTitle();
  

  TFile* f1 = new TFile("DirectDetection/graph.root");
  
  TGraph* x1t = (TGraph*)f1->Get("xenon1T");
  TGraph* x2 = (TGraph*)f1->Get("xenon_10s2");
  TGraph* cdms = (TGraph*)f1->Get("cdms");
  TGraph* bayes = (TGraph*)f1->Get("Bayes");
  TGraph* pMSSM = (TGraph*)f1->Get("pMSSM");

  x1t->SetLineColor(kBlue+2);
  x1t->SetLineWidth(3);
  x1t->SetLineStyle(1);
  x2->SetLineColor(kGreen+2);
  x2->SetLineWidth(3);
  x2->SetLineStyle(1);
  cdms->SetLineColor(kViolet-2);
  cdms->SetLineWidth(3);
  cdms->SetLineStyle(1);
  pMSSM->SetLineColor(kBlue-10);
  pMSSM->SetLineWidth(3);
  pMSSM->SetFillColor(kBlue-10);
  pMSSM->SetLineStyle(1);
  
  TMultiGraph *mg = new TMultiGraph();
  mg->Add(pMSSM,"FL");
  mg->Add(Lmono,"L");
  mg->Add(Ld,"L");
  mg->Add(Lu,"L");
  mg->Add(x1t,"L");
  mg->Add(x2,"L");
  mg->Add(cdms,"L");
  //mg->Add(pMSSM,"FL");
  mg->Draw("A");
  mg->GetXaxis()->SetTitle(labelX);
  mg->GetYaxis()->SetTitle(labelY);
  mg->GetXaxis()->SetTitleOffset(1.1);
  mg->GetXaxis()-> CenterTitle();
  mg->GetYaxis()->SetTitleOffset(1.7);
  mg->GetYaxis()-> CenterTitle();
  mg->GetYaxis()->SetRangeUser(0.9e-50, 3e-35);
  mg->GetXaxis()->SetRangeUser(1e-4, 1000.);
  //pMSSM->Draw("AF");

  TLatex *t = new TLatex();
  t->SetNDC();
  t->SetTextAlign(22);
  t->SetTextSize(0.03);
  //t->DrawLatex(0.28,0.87,"CMS Preliminary");
  t->DrawLatex(0.29,0.87,"Caltech-CMS Internal");   
  t->DrawLatex(0.29,0.825,"#sqrt{s} = 8 TeV");
  t->DrawLatex(0.29,0.745,"#int L dt = 5 fb^{-1}");

  TLegend* leg = new TLegend(0.425, 0.75, 0.89, 0.89);//(xmin, ymin, xmax, ymax)
  leg->AddEntry(Ld, "Razor SI u-quark (5 fb^{-1}) 90% C.L" ,"l");
  leg->AddEntry(Lu, "Razor SI d-quark (5 fb^{-1}) 90% C.L" ,"l");
  leg->AddEntry(Lmono, "Monojet SI combined limit (19.5 fb^{-1}) 90% C.L" ,"l");
  leg->AddEntry(x1t, "XENON 1T (projected 2017)" ,"l");
  leg->AddEntry(x2, "XENON 10, S2 only (2011)" ,"l");
  leg->AddEntry(cdms, "CDMS-Edelweiss Combined Limit" ,"l");
  leg->AddEntry(pMSSM, "Phenomenological MSSM, 2013, 99.5% C.L " ,"l");
  leg->SetFillColor(0);
  leg->SetBorderSize(0);
  leg->SetTextSize(0.03);
  leg->SetTextSize(.022);
  leg->SetFillColor(0);
  leg->Draw();

  pad1->SetLogy();
  pad1->SetLogx();
  pad1->Update();
  C->SaveAs("SI_SigmaLimit_internal.pdf");
  C->SaveAs("SI_SigmaLimit_internal.png");


}
