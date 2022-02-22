#include <bits/stdc++.h>

using namespace std;

class Solution {
public:

//----------------------------------------------------------- Challenge Solution
  int titleToNumber(string columnTitle) {
    int output{ static_cast<int>(columnTitle.at(0)) - 64 };
    for( int i = 1 ; i < columnTitle.size(); i++){
      output = output*26 + static_cast<int>(columnTitle.at(i)) - 64;
    }
    return output;
  }
//------------------------------------------------------------------------------
  void showTitleToNumber(string columnTitle){
    std::cout << "----- New Test -----" << std::endl;
    std::cout << columnTitle << " -> " << titleToNumber(columnTitle) << std::endl;
  }
};

int main(){

  std::cout <<"<<<<  LeetCode - 171. Excel Sheet Column Number >>>>" << std::endl;
  Solution solution;
  solution.showTitleToNumber("ZZ");
  solution.showTitleToNumber("AAA");
  solution.showTitleToNumber("FXSHRXW");

  return 0;
}