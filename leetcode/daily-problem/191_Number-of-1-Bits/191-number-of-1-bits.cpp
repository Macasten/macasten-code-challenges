#include <bits/stdc++.h>

using namespace std;

class Solution {
public:

//----------------------------------------------------------- Challenge Solution
  int hammingWeight(uint32_t n) {
    unsigned int count = 0;
    while (n) {
      count += n & 1;
      n >>= 1;
    }
    return count;
  }
//------------------------------------------------------------------------------
  void showhammingWeight(uint32_t n){
    std::cout << "----- New Test -----" << std::endl;
    std::cout << n << " -> "<< hammingWeight(n)<< " bits" << std::endl;
  }
};

int main(){

  std::cout <<"<<<<  LeetCode - 191. Number of 1 Bits >>>>" << std::endl;
  Solution solution;

  return 0;
}