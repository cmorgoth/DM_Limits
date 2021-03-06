#include <iostream>
#include "math.h"
#include "TROOT.h"
#include "TH1F.h"
#include "TH2F.h"
#include "TFile.h"
#include "TTree.h"
#include "TString.h"
#include <fstream>
#include "TEfficiency.h"
#include "TCanvas.h"
#include "TLorentzVector.h"
#include <map>

int main(){

  gROOT->Reset(); 
  
  std::map<int,double> AVd_map;
  std::map<int,double> AVu_map;
  std::map<int,double> Vd_map;
  std::map<int,double> Vu_map;

  std::map<int,double> AVd_map_exp;
  std::map<int,double> AVu_map_exp;
  std::map<int,double> Vd_map_exp;
  std::map<int,double> Vu_map_exp;
  
  std::map<int,double> AVd_limit_map;
  std::map<int,double> AVu_limit_map;
  std::map<int,double> Vd_limit_map;
  std::map<int,double> Vu_limit_map;

  std::map<int,double> AVd_limit_map_exp;
  std::map<int,double> AVu_limit_map_exp;
  std::map<int,double> Vd_limit_map_exp;
  std::map<int,double> Vu_limit_map_exp;

  int mass[6] = {1,10,100,400,700,1000};
  double AVd_xs[6] = {6.42E-8,6.4E-8,4.7E-8,9.74E-9,1.68E-9,2.4E-10};
  double AVu_xs[6] = {1.16E-7, 1.15E-7, 8.8E-8, 2.17E-8, 4.76E-9, 9.36E-10};
  double Vd_xs[6] = {6.43E-8, 6.44E-8, 5.76E-8, 2.06E-8, 5.3E-9, 1.06E-9};
  double Vu_xs[6] = {1.16E-7, 1.16E-7,  1.06E-7, 4.31E-8, 1.34E-8, 3.57E-9};
  for(int i = 0; i < 6; i++){
    AVd_map[mass[i]] = AVd_xs[i];
    AVu_map[mass[i]] = AVu_xs[i];
    Vd_map[mass[i]] = Vd_xs[i];
    Vu_map[mass[i]] = Vu_xs[i];
  }
  
  double xsec[24] = {2.4E-10,9.36E-10,1.06E-9,3.57E-9,4.7E-8,8.8E-8,5.76E-8,1.06E-7,6.4E-8,1.15E-7,6.44E-8,1.16E-7,6.42E-8,1.16E-7,6.43E-8,1.16E-7,9.74E-9,2.17E-8,2.06E-8,4.31E-8,1.68E-9,4.76E-9,5.3E-9,1.34E-8};
  
  //std::ifstream mfile0("output_combine_cls90_RunAB.txt");
  //std::ifstream mfile0("output_combine_cls90_btagcorr.txt");
  //std::ifstream mfile0("output_combine_cls90_Parked_RunBCD.txt");
  //std::ifstream mfile0("output_combine_cls90_1d_rsq_toys_10k_v2.txt");
  //std::ifstream mfile0("output_combine_cls90_Parked_2d_RunBCD.txt");
  //std::ifstream mfile0("output_combine_cls90_Parked_RunBCD_ParkedTriggers.txt");
  std::ifstream mfile0("output_combine_cls90_MR_Categories.txt");
  std::ofstream out1("DirectDetection/SD/RazorDM_AVd_8TeV.txt");
  std::ofstream out2("DirectDetection/SD/RazorDM_AVu_8TeV.txt");
  std::ofstream out3("DirectDetection/SI/RazorDM_Vd_8TeV.txt");
  std::ofstream out4("DirectDetection/SI/RazorDM_Vu_8TeV.txt");
  std::ofstream out5("DirectDetection/SD/RazorDM_AV_8TeV_Combined.txt");
  std::ofstream out6("DirectDetection/SI/RazorDM_V_8TeV_Combined.txt");
  std::ofstream out7("DirectDetection/SD/RazorDM_AV_8TeV_Combined_Expected.txt");
  std::ofstream out8("DirectDetection/SI/RazorDM_V_8TeV_Combined_Expected.txt");
  
  std::string dm_name;
  double limit_95, expected;
  int ctr_xs = 0;
  
  out1 << "weight 1.0\n";
  out2 << "weight 1.0\n";
  out3 << "weight 1.0\n";
  out4 << "weight 1.0\n";
  out5 << "weight 1.0\n";
  out6 << "weight 1.0\n";
  out7 << "weight 1.0\n";
  out8 << "weight 1.0\n";
  
  if (mfile0.is_open()){
    while ( mfile0.good() ){
      mfile0 >> dm_name >> limit_95 >> expected;
      if(mfile0.eof())break;
      
      if(dm_name.find("AVd") != std::string::npos){
	std::string sub = dm_name.substr(3,dm_name.find("AVd")-3);
	std::cout << "==============================AVd============================" << std::endl;
	int DM_mass = atoi(sub.c_str());
	AVd_limit_map[DM_mass] = pow(AVd_map[DM_mass]/limit_95, 0.250)*40000.;
	AVd_limit_map_exp[DM_mass] = pow(AVd_map[DM_mass]/expected, 0.250)*40000.;
	//std::cout << dm_name << " " << sub << " " << limit_95 << " " << expected_97p5 << " " <<pow(xsec[ctr_xs]/limit_95, 0.250)*40000. << std::endl; 
	//out1 << sub << "\t" << pow(xsec[ctr_xs]/limit_95, 0.250)*40000. << "\n";
      }
      
      if(dm_name.find("AVu") != std::string::npos){
	std::string sub = dm_name.substr(3,dm_name.find("AVu")-3);
	std::cout << "==============================AVu============================" << std::endl;
	int DM_mass = atoi(sub.c_str());
	AVu_limit_map[DM_mass] = pow(AVu_map[DM_mass]/limit_95, 0.250)*40000.;
	AVu_limit_map_exp[DM_mass] = pow(AVu_map[DM_mass]/expected, 0.250)*40000.;
	//std::cout << dm_name << " " << sub << " " << limit_95 << " " << expected_97p5 << " " <<pow(xsec[ctr_xs]/limit_95, 0.250)*40000. << std::endl; 
	//out2 << sub << "\t" << pow(xsec[ctr_xs]/limit_95, 0.250)*40000. << "\n";
      }
      
      if(dm_name.find("Vd") != std::string::npos && dm_name.find("AVd") == std::string::npos){
	std::string sub = dm_name.substr(3,dm_name.find("Vd")-3);
	int DM_mass = atoi(sub.c_str());
	Vd_limit_map[DM_mass] = pow(Vd_map[DM_mass]/limit_95, 0.250)*40000.;
	Vd_limit_map_exp[DM_mass] = pow(Vd_map[DM_mass]/expected, 0.250)*40000.;
	//out3 << sub << "\t" << pow(xsec[ctr_xs]/limit_95, 0.250)*40000. << "\n";
      }
     
      if(dm_name.find("Vu") != std::string::npos && dm_name.find("AVu") == std::string::npos){
	std::string sub = dm_name.substr(3,dm_name.find("Vu")-3);
	int DM_mass = atoi(sub.c_str());
	Vu_limit_map[DM_mass] = pow(Vu_map[DM_mass]/limit_95, 0.250)*40000.;
	Vu_limit_map_exp[DM_mass] = pow(Vu_map[DM_mass]/expected, 0.250)*40000.;
	//std::cout << dm_name << " " << sub << " " << limit_95 << " " << expected_97p5 << " " <<pow(xsec[ctr_xs]/limit_95, 0.250)*40000. << std::endl;
	
	//out4 << sub << "\t" << pow(xsec[ctr_xs]/limit_95, 0.250)*40000. << "\n";
      }

      ctr_xs++;
    }
    
  }else{
    std::cout << "Unable to open the file" << std::endl;
  }
  
  mfile0.close();
  std::cout << "size: " << Vu_limit_map.size() << std::endl;
  for(int j = 0; j < Vu_limit_map.size(); j++){
    out1 << mass[j] << "\t" << AVd_limit_map[mass[j]] << "\n"; 
    out2 << mass[j] << "\t" << AVu_limit_map[mass[j]] << "\n"; 
    out3 << mass[j] << "\t" << Vd_limit_map[mass[j]] << "\n"; 
    out4 << mass[j] << "\t" << Vu_limit_map[mass[j]] << "\n"; 
    double AV_com = pow( pow(AVd_limit_map[mass[j]],4) + pow(AVu_limit_map[mass[j]],4) , 0.250);
    double V_com = pow( pow(Vd_limit_map[mass[j]],4) + pow(Vu_limit_map[mass[j]],4) , 0.250);
    double AV_com_exp = pow( pow(AVd_limit_map_exp[mass[j]],4) + pow(AVu_limit_map_exp[mass[j]],4) , 0.250);
    double V_com_exp = pow( pow(Vd_limit_map_exp[mass[j]],4) + pow(Vu_limit_map_exp[mass[j]],4) , 0.250);
    out5 << mass[j] << "\t" << AV_com << "\n";
    out6 << mass[j] << "\t" << V_com << "\n";
    out7 << mass[j] << "\t" << AV_com_exp << "\n";
    out8 << mass[j] << "\t" << V_com_exp << "\n";
  }
  
  out1.close();
  out2.close();
  out3.close();
  out4.close();
  out5.close();
  out6.close();
  out7.close();
  out8.close();

  return 0;
}
