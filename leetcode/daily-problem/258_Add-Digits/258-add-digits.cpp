#include <bits/stdc++.h>

using namespace std;

class Solution {
public:

//----------------------------------------------------------- Challenge Solution
  int addDigits(int num) {
    if( num < 10 ) return num;

    int output{num};
    do{
      num = output;
      output = 0;
      while ( num ){
        output += num%10;
        num = num/10;
      }
    }while (output > 9 );

    return output;
  }
//------------------------------------------------------------------------------
  void showAddDigits(int num) {
    std::cout << "Number: "<< num << " digits sum: "<< addDigits(num) << std::endl;
  }
};

int main(){

  std::cout <<"<<<<  LeetCode - 258. Add Digits >>>>" << std::endl;
  Solution solution;
  solution.showAddDigits(123456789);
  solution.showAddDigits(38);

  return 0;
}