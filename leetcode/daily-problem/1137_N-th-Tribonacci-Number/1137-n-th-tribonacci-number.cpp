#include <bits/stdc++.h>

using namespace std;

class Solution {
public:

//----------------------------------------------------------- Challenge Solution
  int tribonacci(int n) {
    int output {0};
    std::vector<int> last = {0,1,1};
    if( n < 3 ) return last.at(n);

    while ( n > 2 ) {
      int sum = last.at(0) + last.at(1) + last.at(2);
      last.at(0) = last.at(1);
      last.at(1) = last.at(2);
      last.at(2) = sum;
      n--;
    }

    return last.back();
  }
//------------------------------------------------------------------------------
  void showTribonacci(int n){
    std::cout << "----- New Test -----" << std::endl;
    std::cout << n << "-th Tribonacci Number: "<< tribonacci(n) << std::endl;
  }
};

int main(){

  std::cout <<"<<<<  LeetCode - 1137. N-th Tribonacci Number >>>>" << std::endl;
  Solution solution;
  solution.showTribonacci(0);
  solution.showTribonacci(3);
  solution.showTribonacci(4);
  solution.showTribonacci(37);

  return 0;
}