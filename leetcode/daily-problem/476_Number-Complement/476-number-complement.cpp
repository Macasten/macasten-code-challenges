#include <bits/stdc++.h>

class Solution {
public:
  //--------------------------------------------------------- Challenge Solution
  inline int set_bit(int num, int position) {
    int mask = 1 << position;
    return num | mask;
  }

  inline bool get_bit(int num, int position) {
    bool bit = num & (1 << position);
    return bit;
  }

  int findComplement(int num) {
    bool convert{false};
    bool bit{false};
    int output{0};
    for( int p = 31; p>= 0; p--){
      bit = get_bit(num, p);
      if( !convert && bit) convert = true;
      if( convert ){
        if( !bit ){
          output = set_bit(output,p);
        }
      }
    }
    std::cout << std::endl;
    return output;
  }
  //---------------------------------------------------------------------------
  void showComplement( int num ){
    std::cout << num << " -> complement -> " << findComplement(num) << std::endl;
  }
};

int main(){
  
  Solution solution;
  solution.showComplement(9);
  solution.showComplement(5);
  solution.showComplement(3);
  return 0;
}