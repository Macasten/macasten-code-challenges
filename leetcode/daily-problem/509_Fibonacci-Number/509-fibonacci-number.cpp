#include <bits/stdc++.h>

using namespace std;

class Solution {
public:

//----------------------------------------------------------- Challenge Solution
  int fib(int n) {
    int output {0};
    std::vector<int> last = {0,1};
    if( n < 2 ) return last.at(n);

    while ( n > 1 ) {
      int sum = last.at(0) + last.at(1);
      last.at(0) = last.at(1);
      last.at(1) = sum;
      n--;
    }

    return last.back();
  }
//------------------------------------------------------------------------------
  void showFib(int n){
    std::cout << "----- New Test -----" << std::endl;
    std::cout << n << "-th Fibonacci Number: "<< fib(n) << std::endl;
  }
};

int main(){

  std::cout <<"<<<<  LeetCode - 509. Fibonacci Number >>>>" << std::endl;
  Solution solution;
  solution.showFib(0);
  solution.showFib(3);
  solution.showFib(30);

  return 0;
}