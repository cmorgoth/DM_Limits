#include "create_TGraph.hh"
#include <string>

TGraph* CreateTGraph(const char* filename){
  
  double mass[10000], xsec[10000];
  std::string buff;
  double weight;
  int ctr = 0;
  std::ifstream myfile(filename);
  if (myfile.is_open()){
    while ( myfile.good() ){
      if(ctr == 0){
	myfile >> buff >> weight;
	std::cout << buff <<  " "  << weight << std::endl;
      }else{
	myfile >> mass[ctr-1] >> xsec[ctr-1];
	xsec[ctr-1] = xsec[ctr-1]*weight;
	if(myfile.eof())break;
	std::cout << mass[ctr-1] <<  " "  << xsec[ctr-1] << std::endl;
      }
      ctr++;
    }
    myfile.close();
  }else std::cout << "Unable to open file";
  
  std::cout << "ctr: " << ctr << std::endl;
  TGraph* gr = new TGraph(ctr-1,mass,xsec);
  return gr;
  
}
