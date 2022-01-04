#include <bits/stdc++.h>

using namespace std;

class Solution {
public:

//----------------------------------------------------------- Challenge Solution
  inline string reverseWord( string s ){
    size_t runs{s.size()/2};
    size_t i = 0;
    size_t f = s.size() - 1;
    while( runs ){
      char temp = s.at(i);
      s.at(i) = s.at(f);
      s.at(f) = temp;
      i++;
      f--;
      runs--;
    }
    return s;
  }

  inline void reverseSubWord(string& s, size_t iIndex , size_t fIndex) {
    size_t subLength = (fIndex - iIndex);
    s.replace(
      iIndex,
      subLength,
      reverseWord( s.substr( iIndex, subLength) ) );
  }

  string reverseWords(string s) {
    size_t iIndex{0};
    size_t fIndex{0};
    while (fIndex < s.length()) {
      if( s.at(fIndex) == ' ' ){
        reverseSubWord( s, iIndex, fIndex);
        fIndex ++;
        iIndex = fIndex;

      }
      fIndex++;
    }

    reverseSubWord( s, iIndex, fIndex);

    return s;
  }
//------------------------------------------------------------------------------
  void showReverseWords( string s ){
    std::cout << "Original: >"<< s <<"< ("<< s.length() <<")"<< std::endl;
    std::cout << "Result: >"<< reverseWords(s)<<"<" << std::endl;
  }
};

int main(){

  Solution solution;
  solution.showReverseWords("cenas");
  solution.showReverseWords("cenas coisa outra");
  return 0;
}