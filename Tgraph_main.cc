#include <iostream>
#include "create_TGraph.hh"
#include <fstream>
#include "TFile.h"
#include "TROOT.h"
#include "TGraph.h"

int main(){
  
  gROOT->Reset();
  
  
  std::ifstream mfile("ListOfFilesSD.txt");
  std::string fname;
  std::string name_graph[50];
  int ctr = 0;
  TGraph* g[50];
  if (mfile.is_open()){
    while ( mfile.good() ){
      mfile >> fname;
      if(mfile.eof())break;
      std::cout << fname << std::endl;
      std::cout<< "POS1: " << fname.find("SD/") << std::endl;
      std::cout<< "POS2: " << fname.find(".txt") << std::endl;
      std::cout<< "SUBSTR: " << fname.substr(fname.find("SD/")+3, fname.find(".txt")-fname.find("SD/")) << std::endl;
      name_graph[ctr] = fname.substr(fname.find("SD/")+3, fname.find(".txt")-fname.find("SD/")-3);
      g[ctr] = CreateTGraph(fname.c_str());
      ctr++;
    }
    mfile.close();
  }else std::cout << "Unable to open file";
  
  TFile* file = new TFile("SD_Graphs.root", "RECREATE");

  std::cout << "here 0" << std::endl;
  for(int i = 0; i < ctr; i++){
    g[i]->Write(name_graph[i].c_str());
  }
  std::cout << "here 1"<< std::endl;
  file->Close();
  std::cout << "here 2"<< std::endl;

  return 0;
}
