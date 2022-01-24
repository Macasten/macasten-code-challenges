#include <bits/stdc++.h>

using namespace std;

class Solution {
public:

//----------------------------------------------------------- Challenge Solution
  inline bool valid( string s ){
    //cout<< s<< endl;
    size_t i = 0;
    size_t f = s.length() -1;

    if( f<2 ){
      return s.at(i) == s.at(f);
    }


    while (i<f) {
        if( s.at(i) != s.at(f)) return false;
        f--;
        i++;
    }
    return true;
  }

  bool validPalindrome(string s) {
    size_t i = 0;
    size_t f = s.length() -1;

    if(f<2){
      return true;
    }


    while (i<f) {
      if( s.at(i) != s.at(f)){
        //cout<< s.at(i) <<"-"<< s.at(f)<< endl;
        if( valid(s.substr(i, f-i ) ) ) return true;
        return valid(s.substr(i+1, f-i ) );
      }
      f--;
      i++;

    }
    return true;
  }
//------------------------------------------------------------------------------
  void showValidPalindrome( string s ){
    std::cout << s << (validPalindrome(s) ? " is " : " is not ")<< " palindrome" << std::endl;
  }
};

int main(){

  std::cout <<"<<<<  LeetCode - 680. Valid Palindrome II >>>>" << std::endl;
  Solution solution;
  solution.showValidPalindrome("aaaaa");

  return 0;
}