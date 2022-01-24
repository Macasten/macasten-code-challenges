#include <bits/stdc++.h>

using namespace std;

class Solution {
public:

//----------------------------------------------------------- Challenge Solution
  inline bool isletter( char& letter ){
    return ((letter >= 'A' && letter <= 'Z') || ( letter >= 'a' && letter <= 'z') || (letter >= '0' && letter <= '9'));
  }

  bool isPalindrome(string s) {
    size_t i = 0;
    size_t f = s.length() -1;

    if(!f){
      return isletter( s.front() );
    }

    while (i<f) {
      if( isletter( s.at(i) ) && isletter( s.at(f) ) ){
        if( tolower( s.at(i) ) != tolower(s.at(f)) ) return false;
        i++;
        f--;
      } else {
        if( !isletter( s.at(i) ) )i++;
        if( !isletter( s.at(f) ) )f--;
      }
    }
    return true;
  }
//------------------------------------------------------------------------------
  void showIsPalindrome( string s ){
    std::cout << s << (isPalindrome(s) ? " is " : " is not ")<< " palindrome" << std::endl;
  }
};

int main(){

  std::cout <<"<<<<  LeetCode - 125. Valid Palindrome >>>>" << std::endl;
  Solution solution;
  solution.showIsPalindrome("A man, a plan, a canal: Panama");

  return 0;
}