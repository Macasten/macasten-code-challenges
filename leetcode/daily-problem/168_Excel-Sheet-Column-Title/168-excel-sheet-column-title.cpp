#include <bits/stdc++.h>

using namespace std;

class Solution {
public:

//----------------------------------------------------------- Challenge Solution
  string convertToTitle(int columnNumber) {
    std::string output = "";
    while (columnNumber >= 1){
      int next = columnNumber%26;
      columnNumber /= 26;
      if(next == 0){
        columnNumber--;
        output.insert(0,1, static_cast<char>( 90 ));
      } else {
        output.insert(0,1,static_cast<char>( next + 64 ));
      }

    }
    return output;
    
  }
//------------------------------------------------------------------------------
  void showConvertToTitle(int columnNumber){
    std::cout << "----- New Test -----" << std::endl;
    std::cout << columnNumber << " -> " << convertToTitle(columnNumber) << std::endl;
  }
};

int main(){

  std::cout <<"<<<<  LeetCode - 168. Excel Sheet Column Title >>>>" << std::endl;
  Solution solution;
  solution.showConvertToTitle(1);
  solution.showConvertToTitle(26);
  solution.showConvertToTitle(27);
  solution.showConvertToTitle(703);

  return 0;
}