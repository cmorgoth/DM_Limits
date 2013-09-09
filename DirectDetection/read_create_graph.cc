{
  gROOT->Reset();
  
  double mass[10000], xsec[10000];
  int ctr = 0;
  std::ifstream myfile("xenon_1T_right_format.txt");
  if (myfile.is_open()){
    while ( myfile.good() ){
      myfile >> mass[ctr] >> xsec[ctr];
      if(myfile.eof())break;
      std::cout << mass[ctr] <<  " "  << xsec[ctr] << std::endl;
      ctr++;
    }
    myfile.close();
  }else std::cout << "Unable to open file"; 
  
  std::cout << "ctr: " << ctr << std::endl;
  TCanvas* C = new TCanvas("C", "C", 640, 640);
  C->cd();
  TGraph* gr = new TGraph(ctr,mass,xsec);
  
  TColor *col26 = gROOT->GetColor(kBlue-10);
  col26->SetAlpha(0.0001);
  gr->SetLineColor(kBlue-10);
  gr->SetFillColor(kBlue-10);
  //gr->Draw("APL");

  double mass1[10000], xsec1[10000];
  int ctr1 = 0;
  std::ifstream myfile("cdms_edelweiss_right_format.txt");
  if (myfile.is_open()){
    while ( myfile.good() ){
      myfile >> mass1[ctr1] >> xsec1[ctr1];
      if(myfile.eof())break;
      std::cout << mass1[ctr1] <<  " "  << xsec1[ctr1] << std::endl;
      ctr1++;
    }
    myfile.close();
  }else std::cout << "Unable to open file"; 
  
  std::cout << "ctr: " << ctr1 << std::endl;
  TGraph* cdms = new TGraph(ctr1,mass1,xsec1);

  
  double mass2[10000], xsec2[10000];
  int ctr2 = 0;
  std::ifstream myfile("xenon_10s2_right_format.txt");
  if (myfile.is_open()){
    while ( myfile.good() ){
      myfile >> mass2[ctr2] >> xsec2[ctr2];
      if(myfile.eof())break;
      std::cout << mass2[ctr2] <<  " "  << xsec2[ctr2] << std::endl;
      ctr2++;
    }
    myfile.close();
  }else std::cout << "Unable to open file"; 
  
  std::cout << "ctr: " << ctr2 << std::endl;
  TGraph* xenon_10s2 = new TGraph(ctr2,mass2,xsec2);

  

  double mass3[10000], xsec3[10000];
  int ctr3 = 0;
  std::ifstream myfile("pMSSM_right_format.txt");
  if (myfile.is_open()){
    while ( myfile.good() ){
      myfile >> mass3[ctr3] >> xsec3[ctr3];
      xsec3[ctr3] = xsec3[ctr3]*1e-36;
      if(myfile.eof())break;
      std::cout << mass3[ctr3] <<  " "  << xsec3[ctr3] << std::endl;
      ctr3++;
    }
    myfile.close();
  }else std::cout << "Unable to open file"; 
  
  std::cout << "ctr: " << ctr3 << std::endl;
  TGraph* pmssm = new TGraph(ctr3,mass3,xsec3);
  
  double mass4[10000], xsec4[10000];
  int ctr4 = 0;
  std::ifstream myfile("bayes_fit_95_right_format.txt");
  if (myfile.is_open()){
    while ( myfile.good() ){
      myfile >> mass4[ctr4] >> xsec4[ctr4];
      if(myfile.eof())break;
      std::cout << mass4[ctr4] <<  " "  << xsec4[ctr4] << std::endl;
      ctr4++;
    }
    myfile.close();
  }else std::cout << "Unable to open file"; 
  
  std::cout << "ctr: " << ctr4 << std::endl;
  TGraph* bayes = new TGraph(ctr4,mass4,xsec4);
  
  
  TFile* f = new TFile("graph.root", "RECREATE");
  gr->Write("xenon1T");
  cdms->Write("cdms");
  xenon_10s2->Write("xenon_10s2");
  pmssm->Write("pMSSM");
  bayes->Write("Bayes");

  f->Close();
}
