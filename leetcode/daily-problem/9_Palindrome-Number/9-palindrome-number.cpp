#include <bits/stdc++.h>

using namespace std;

class Solution {
public:

//----------------------------------------------------------- Challenge Solution
  bool isPalindrome(int x) {
    if( x >= 0 && x < 10) return true;
    if( x < 0 ) return false;

    std::vector<int> digits = {};
    while(x){
      digits.push_back( x%10 );
      x /= 10;
    }

    size_t leng = digits.size();
    for(size_t i = 0; i <leng/2; i++ ){
      if( digits.at(i) != digits.at( leng-1-i) ) return false;
    }

    return true;
  }
//------------------------------------------------------------------------------
void showIsPalindrome( int x ){
  std::cout << x << ( isPalindrome(x) ? " is " : " is not " )<< "Palindrome" << std::endl;
}
};

int main(){

  std::cout <<"<<<<  LeetCode - 9. Palindrome Number >>>>" << std::endl;
  Solution solution;
  solution.showIsPalindrome(0);
  solution.showIsPalindrome(-1);
  solution.showIsPalindrome(121);

  return 0;
}