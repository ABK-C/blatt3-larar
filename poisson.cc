#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>


double poisson(double mu, int k) { 
  return pow(mu,k)*exp(-mu)/tgamma(k+1);
}

int main() {
  using namespace std;
  
  ifstream fin("datensumme.txt");
  int n_i;
  vector<int> zaehler(11);

  for(int i = 0 ; i < 234 ; ++i) {        fin >> n_i;
    zaehler[n_i] += 1;
  }
  fin.close();
  for(int i = 0; i<11; ++i){
    std::cout<<zaehler[i]<<std::endl;
  }
  
  std::ofstream fout("hist.txt");
  for(int i = 0; i<11; ++i){
    fout<<i<<" "<<zaehler[i]<<std::endl;
  }
  fout.close();

  std::ofstream gout("histpoi.txt");
  for(int i = 0; i<11; ++i){
    gout<<i<<" "<<zaehler[i]<<" "<<234*poisson(3.1158,i)<<std::endl;
  }
  gout.close();

}