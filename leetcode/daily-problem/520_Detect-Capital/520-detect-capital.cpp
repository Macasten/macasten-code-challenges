#include <bits/stdc++.h>

using namespace std;

class Solution {
public:

//----------------------------------------------------------- Challenge Solution
  inline bool isUpperCase( char& letter ){
    return ( letter >='A'&& letter <='Z');
  }

  bool detectCapitalUse(string word) {
    if( word.length() < 2 ) return true;
    if( isUpperCase( word.at(0) )){
      if(isUpperCase( word.at(1) )){
        for( size_t i = 2; i <word.length(); i++){
          if( !isUpperCase(word.at(i)) ) return false;
        }
        return true;
      } else {
        for( size_t i = 2; i <word.length(); i++){
          if( isUpperCase(word.at(i)) ) return false;
        }
        return true;
      }

    } else {
      for( size_t i = 1; i <word.length(); i++){
        if( isUpperCase(word.at(i)) ) return false;
      }
      return true;
    }
  }
//------------------------------------------------------------------------------
  void showDetectCapitalUse(string word){
    std::cout << word << " : "<< ( detectCapitalUse(word) ? "Right" : "Wrong" )  << std::endl;
  }
};

int main(){

  std::cout <<"<<<<  LeetCode - 520. Detect Capital >>>>" << std::endl;
  Solution solution;
  solution.showDetectCapitalUse("WASDFADS");
  solution.showDetectCapitalUse("asdasd");
  solution.showDetectCapitalUse("Wasdasd");
  solution.showDetectCapitalUse("WasdasS");

  return 0;
}