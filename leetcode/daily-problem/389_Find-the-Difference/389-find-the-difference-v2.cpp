#include <bits/stdc++.h>

using namespace std;

class Solution {
public:

//----------------------------------------------------------- Challenge Solution
  char findTheDifference(string s, string t) {
    if( s.length() == 0 ){
      return t.at(0);
    }
    sort(s.begin(), s.end());
    sort(t.begin(), t.end());
    for (size_t i = 0; i < s.length(); i++) {
      if( s.at(i) != t.at(i) ) return t.at(i);
    }
    return t.back();
  }
//------------------------------------------------------------------------------
  void showFindTheDifference(string s, string t) {
    std::cout << "Difference: "<< findTheDifference( s, t) << std::endl;
  }
};

int main(){

  std::cout <<"<<<<  LeetCode - 389. Find the Difference >>>>" << std::endl;
  Solution solution;
  solution.showFindTheDifference( "a", "ab");
  return 0;
}