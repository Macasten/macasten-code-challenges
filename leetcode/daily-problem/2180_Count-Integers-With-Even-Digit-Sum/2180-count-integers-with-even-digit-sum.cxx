#include <bits/stdc++.h>

using namespace std;

class Solution {
public:

//----------------------------------------------------------- Challenge Solution
  inline int sumDiggits( int num ){
    int output {0};
    while (num > 9){
      output += num%10;
      num /= 10;
    }

    return (output + num);
  }
  int countEven(int num) {
    int countEven{0};
    while( num ){
      if( sumDiggits(num) % 2  == 0) countEven++;
      num--;
    }
    return countEven;
  }
//------------------------------------------------------------------------------
  void showCountEven(int num){
    std::cout << "----- New Test -----" << std::endl;
    std::cout << num << " as "<< countEven(num) << " even numbers" << std::endl;
  }
};

int main(){

  std::cout <<"<<<<  LeetCode - 2180. Count Integers With Even Digit Sum >>>>" << std::endl;
  Solution solution;
  solution.showCountEven(1);
  solution.showCountEven(4);
  solution.showCountEven(10);
  solution.showCountEven(15);
  solution.showCountEven(20);
  solution.showCountEven(30);
  solution.showCountEven(1000);
  solution.showCountEven(999);
  solution.showCountEven(998);

  return 0;
}