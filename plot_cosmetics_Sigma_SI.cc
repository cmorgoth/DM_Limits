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
  Ld->SetLineWidth(2);
  Ld->SetLineStyle(2);
  
  
  Lu->SetLineColor(kRed);
  Lu->SetLineWidth(2);
  Lu->SetLineStyle(2);
  Lmono->SetLineColor(kGreen);
  Lmono->SetLineWidth(2);
  Lmono->SetLineStyle(2);
  
  Ld->GetYaxis()->SetTitle(labelY);
  Ld->GetXaxis()->SetTitleOffset(1.1);
  Ld->GetXaxis()-> CenterTitle();
  Ld->GetYaxis()->SetTitleOffset(1.3);
  Ld->GetYaxis()-> CenterTitle();
  

  TMultiGraph *mg = new TMultiGraph();
  mg->Add(Lmono);
  mg->Add(Ld);
  mg->Add(Lu);
  mg->Draw("ALP");
  mg->GetXaxis()->SetTitle(labelX);
  mg->GetYaxis()->SetTitle(labelY);
  mg->GetXaxis()->SetTitleOffset(1.1);
  mg->GetXaxis()-> CenterTitle();
  mg->GetYaxis()->SetTitleOffset(1.7);
  mg->GetYaxis()-> CenterTitle();
  mg->GetYaxis()->SetRangeUser(0.9e-42, 3e-38);
  
  TLatex *t = new TLatex();
  t->SetNDC();
  t->SetTextAlign(22);
  t->SetTextSize(0.03);
  t->DrawLatex(0.25,0.87,"CMS Preliminary");
  t->DrawLatex(0.25,0.83,"#sqrt{s} = 8 TeV");
  
  TLegend* leg = new TLegend(0.45, 0.75, 0.89, 0.89);//(xmin, ymin, xmax, ymax)
  leg->AddEntry(Ld, "Razor SI u-quark (5 fb^{-1})" ,"l");
  leg->AddEntry(Lu, "Razor SI d-quark (5 fb^{-1})" ,"l");
  leg->AddEntry(Lmono, "Monojer SI combined limit (19.5 fb^{-1})" ,"l");
  leg->SetFillColor(0);
  leg->SetBorderSize(0);
  leg->SetTextSize(0.03);
  leg->SetTextSize(.022);
  leg->SetFillColor(0);
  leg->Draw();

  pad1->SetLogy();
  pad1->SetLogx();
  pad1->Update();
  C->SaveAs("SI_SigmaLimit.pdf");
  C->SaveAs("SI_SigmaLimit.png");


}
