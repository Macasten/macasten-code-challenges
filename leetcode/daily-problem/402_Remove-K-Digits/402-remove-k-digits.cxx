#include <bits/stdc++.h>

using namespace std;

class Solution {
public:

//----------------------------------------------------------- Challenge Solution
  string removeKdigits(string num, int k) {
    if( num.length() <= k ) return "0";

    for( int i = 0; i<k; i++ ){
      int size = num.length();
      for( int index = 1; index< num.length(); index++ ){
        if( num.at(index-1) > num.at(index) ){
          num.erase( num.begin() + index -1 );
          break;
        }
      }
      if( size == num.length() ) num.pop_back();
    }

    if( num.at(0) == '0' && num.size() > 1 ){
      int count = 1;
      while( count < num.size() - 1 && num.at(count) == '0' ){
        count++;
      }
      num = num.substr(count, num.size() - count);
    }
    return num;
  }
//------------------------------------------------------------------------------
  void showRemovekdigits(string num, int k){
    std::cout << "----- New Test -----" << std::endl;
    std::cout << "Original: "<< num << std::endl;
    std::cout << "Result: "<< removeKdigits(num, k) << std::endl;
  }
};

int main(){

  std::cout <<"<<<<  LeetCode - 402. Remove K Digits >>>>" << std::endl;
  Solution solution;
  solution.showRemovekdigits("1", 2);
  solution.showRemovekdigits("123456", 2);
  solution.showRemovekdigits("654321", 2);
  solution.showRemovekdigits("10200", 2);

  return 0;
}