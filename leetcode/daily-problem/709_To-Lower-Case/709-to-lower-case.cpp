#include <bits/stdc++.h>

using namespace std;

class Solution {
public:

//----------------------------------------------------------- Challenge Solution
  string toLowerCase(string s) {
    for (auto& l : s) {
      if( l >= 'A' && l <= 'Z'){
        l = tolower(l);
      }
    }
    return s;
  }
//------------------------------------------------------------------------------
  void showToLowerCase( string s ){
    std::cout << "---------- NEW CASE ----------" << std::endl;
    std::cout <<"Original : " << s << std::endl;
    std::cout <<"Result   : " << toLowerCase( s )<< std::endl;
  }
};

int main(){

  std::cout <<"<<<<  LeetCode - 709. To Lower Case >>>>" << std::endl;
  Solution solution;
  solution.showToLowerCase("asdSDfasdfadfaSDFasds");

  return 0;
}