#include <bits/stdc++.h>

using namespace std;

class Solution {
public:

//----------------------------------------------------------- Challenge Solution
  bool isSubsequence(string s, string t) {
    if( s.empty() ) return true;
    if( t.empty() ) return false;

    int indexS{0};
    int indexT{0};
    while( indexS < s.size() && indexT < t.size() ){
      if( s.at(indexS) == t.at(indexT) ){
        indexS++;
      }
      indexT++;
    }
    return (indexS == s.size());
  }
//------------------------------------------------------------------------------
  void showIsSubsequence(string s, string t){
    std::cout << "----- New Test -----" << std::endl;
    std::cout << s << ( isSubsequence(s,t) ? " is " : " is NOT " ) << "subsequence of: "<< t << std::endl;
  }
};

int main(){

  std::cout <<"<<<<  LeetCode - 392. Is Subsequence >>>>" << std::endl;
  Solution solution;
  solution.showIsSubsequence("a", "b");
  solution.showIsSubsequence("a", "bsdfsdfsdfa");
  solution.showIsSubsequence("as", "bsdfsdfsdfa");
  solution.showIsSubsequence("as", "bsdfsdfsdfas");

  return 0;
}