#include <bits/stdc++.h>

using namespace std;

class Solution {
public:

//----------------------------------------------------------- Challenge Solution
  inline int cubeDiggits( int n ){
    int output{0};
    while (n >= 10 ) {
      output += static_cast<int>( std::pow(n%10,2) );
      n /= 10;
    }
    output += std::pow(n,2);
    return output;
  }

  bool isHappy(int n) {
    std::set<int> nums;
    std::pair<std::set<int>::iterator,bool> it;
    do {
      it = nums.insert( cubeDiggits(n) );
      n = *it.first;
    }while (n != 1 && it.second );
    return n == 1;
  }
//------------------------------------------------------------------------------
  void showIsHappy(int n){
    std::cout << "----- New Test -----" << std::endl;
    std::cout << n << ( isHappy(n) ? " is " : " is not " )<< "Happy Number" << std::endl;
  }
};

int main(){

  std::cout <<"<<<<  LeetCode - 202. Happy Number >>>>" << std::endl;
  Solution solution;
  solution.showIsHappy(1);
  solution.showIsHappy(2);
  solution.showIsHappy(19);

  return 0;
}