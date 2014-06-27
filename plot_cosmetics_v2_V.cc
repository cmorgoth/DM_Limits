{

  TFile* f3 = new TFile("SI_Graphs.root");
  TGraph* Lmono = (TGraph*)f3->Get("Monojet_V_8TeV");
  TGraph* Ld = (TGraph*)f3->Get("RazorDM_Vd_8TeV");
  TGraph* Lu = (TGraph*)f3->Get("RazorDM_Vu_8TeV");
  TGraph* Lc = (TGraph*)f3->Get("RazorDM_V_8TeV_Combined_Toys");
  TGraph* Lcom = (TGraph*)f3->Get("RazorDM_V_8TeV_Combined_Expected");

  TGraph* Lup = (TGraph*)f3->Get("RazorDM_V_8TeV_Combined_Expected_up");
  TGraph* Ldown = (TGraph*)f3->Get("RazorDM_V_8TeV_Combined_Expected_down");

  TString labelX = "M_{#chi} (GeV)";
  TString labelY = "#Lambda (GeV)";
  int n = Lcom->GetN();
  double* x = Lup->GetX();
  double* yup = Lup->GetY();
  double* ydown = Ldown->GetY();
  TGraph *grshade = new TGraph(2*n);
  for(int i = 0; i < n; i++) {
    grshade->SetPoint(i,x[i],ydown[i]);
    grshade->SetPoint(n+i,x[n-i-1],yup[n-i-1]);
  }
  grshade->SetFillStyle(3013);
  //grshade->SetFillColor(kOrange+6);
  grshade->SetFillColor(kRed-10);
  grshade->SetTitle("");
  
  TCanvas* C = new TCanvas("C", "C", 640, 640);
  C->cd();
  
  TMultiGraph *mg0 = new TMultiGraph();
  mg0->Add(grshade);
  
  mg0->Draw("af");
  mg0->GetYaxis()->SetRangeUser(300, 1.7*1e3);
  mg0->GetXaxis()->SetTitle(labelX);
  mg0->GetYaxis()->SetTitle(labelY);
  mg0->GetXaxis()->SetTitleOffset(1.1);
  mg0->GetXaxis()-> CenterTitle();
  mg0->GetYaxis()->SetTitleOffset(1.1);
  mg0->GetYaxis()-> CenterTitle();

  Lc->SetLineWidth(2);
  Lc->SetLineStyle(1);
  //Lc->SetLineColor(kViolet-4);
  Lc->SetLineColor(kBlue);

  //Lcom->SetLineColor(kRed);
  Lcom->SetLineColor(kRed-7);
  Lcom->SetLineWidth(3);
  Lcom->SetLineStyle(2);

  //Lup->SetLineColor(kRed);
  Lup->SetLineColor(kRed-7);
  Lup->SetLineWidth(2);
  Lup->SetLineStyle(2);
  
  //Ldown->SetLineColor(kRed);
  Ldown->SetLineColor(kRed-7);
  Ldown->SetLineWidth(2);
  Ldown->SetLineStyle(2);
  
  //Lmono->SetLineColor(kBlack);
  Lmono->SetLineColor(kGreen-6);
  Lmono->SetLineWidth(2);
  Lmono->SetLineStyle(1);
  
  Ld->GetYaxis()->SetTitle(labelY);
  Ld->GetXaxis()->SetTitleOffset(1.1);
  Ld->GetXaxis()-> CenterTitle();
  Ld->GetYaxis()->SetTitleOffset(1.1);
  Ld->GetYaxis()-> CenterTitle();
  
  
  TMultiGraph *mg = new TMultiGraph();
  mg->Add(Lup);
  mg->Add(Lcom);
  mg->Add(Ldown); 
  mg->Add(Lc);
  mg->Add(Lmono);
  //mg->Draw("AF");
  mg->Draw("L");
    /*
    mg->GetXaxis()->SetTitle(labelX);
  mg->GetYaxis()->SetTitle(labelY);
  mg->GetXaxis()->SetTitleOffset(1.1);
  mg->GetXaxis()-> CenterTitle();
  mg->GetYaxis()->SetTitleOffset(1.1);
  mg->GetYaxis()-> CenterTitle();
  mg->GetYaxis()->SetRangeUser(300, 1.7*1e3);
  */
  
  //mg->GetYaxis()->SetRangeUser(450, 2.7*1e3);
  //C->RangeAxis(1,400,1000,5000);

  TLatex *t = new TLatex();
  t->SetNDC();
  t->SetTextAlign(22);
  t->SetTextSize(0.03);
  t->DrawLatex(0.23,0.92,"CMS Preliminary");
  t->DrawLatex(0.41,0.92,", #sqrt{s} = 8 TeV");
  
  TLegend* leg = new TLegend(0.50, 0.75, 0.90, 0.89);//(xmin, ymin, xmax, ymax)
  leg->AddEntry(Ldown, "Razor V Expected -1#sigma (18.5 fb^{-1})" ,"l");
  leg->AddEntry(Lcom, "Razor V Expected (18.5 fb^{-1})" ,"l");
  leg->AddEntry(Lup, "Razor V Expected +1#sigma (18.5 fb^{-1})" ,"l");
  leg->AddEntry(Lc, "Razor V Observed (18.5 fb^{-1})" ,"l");
  leg->AddEntry(Lmono, "Monojet combined limit (19.5 fb^{-1})" ,"l");
  leg->SetFillColor(0);
  leg->SetBorderSize(0);
  leg->SetTextSize(0.03);
  leg->SetTextSize(.022);
  leg->SetFillColor(0);
  leg->Draw();

  C->SetLogy();
  C->SetLogx();
  
  C->Update();
  C->SaveAs("V_LambdaLimit_v2_BtagCorr_FullData_1D_IE.pdf");
  C->SaveAs("V_LambdaLimit_v2_BtagCorr_FullData_1D_IE.png");
  C->SaveAs("V_LambdaLimit_v2_BtagCorr_FullData_1D_IE.C");
}
