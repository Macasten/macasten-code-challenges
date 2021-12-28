#include <iostream>
#include <iomanip> 
using namespace std;



//----------------------------------------------------------- Challenge Solution
void showValues( const double& A, const double& B, const double& C){
  cout << setiosflags(ios::uppercase);
  cout << setw(0xf) << internal;

  cout << std::nouppercase << std::setw (0) << "0x" << std::hex << ((long int)A) << endl;
  cout << std::right << std::setfill('_') << std::setw (15) << std::fixed << std::showpos << std::setprecision(2) << B << endl;
  cout << std::noshowpos << std::uppercase << std::scientific << std::setprecision(9) << C << endl;
}
//------------------------------------------------------------------------------

int main(){
  #include "test-input9.txt";
  return 0;
}

int hackerRanckMain() {
  int T; cin >> T;
  cout << setiosflags(ios::uppercase);
  cout << setw(0xf) << internal;
  while(T--) {
    double A; cin >> A;
    double B; cin >> B;
    double C; cin >> C;

    /* Enter your code here */
    cout << "0x" << std::hex << ((int)A) << endl;
    cout << std::setfill('_')<< std::setw (15) << (B>=0 ? "+" : "-") << std::setprecision(2) << B << endl;
    cout << C << endl;
  }
  return 0;
}