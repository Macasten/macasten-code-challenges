#include <bits/stdc++.h>

using namespace std;

class Solution {
public:

//----------------------------------------------------------- Challenge Solution
  bool checkInclusion(string s1, string s2) {
    size_t s1Size = s1.length();
    if( s1.length() > s2.length()) return false;
    if( s1Size == 1 ) return ( s2.find(s1) != std::string::npos);

    do {
      if( s2.find(s1) != std::string::npos ) return true;
    }while(std::next_permutation(s1.begin(),s1.end()));
    return false;
  }
//------------------------------------------------------------------------------
  void showCheckInclusion( string s1, string s2 ){
    std::cout << "<"<<s2 << ( checkInclusion(s1,s2) ? "> HAS <" : "> NOT HAS <" ) << s1 <<">"<< std::endl;
  }
};

int main(){

  std::cout <<"<<<<  LeetCode - 567. Permutation in String  >>>>" << std::endl;
  Solution solution;
  solution.showCheckInclusion("asd","a");
  solution.showCheckInclusion("a","afdf");
  solution.showCheckInclusion("e","afdf");
  solution.showCheckInclusion("ab","eidbaooo");
  solution.showCheckInclusion("ab","eidboaoo");


  return 0;
}