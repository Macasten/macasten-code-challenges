#include <bits/stdc++.h>

using namespace std;

class Solution {
public:

//----------------------------------------------------------- Challenge Solution
  int countSegments(string s) {
    size_t size = s.length();
    if(size == 0 ) return 0;
    if(size == 1 ) return ( s == " " ? 0 : 1);
    int count = 0;
    for( size_t i = 1; i < size; i++){
        if( s.at(i-1) != ' ' && s.at(i) == ' ' ) count++;
    }
    if(s.back() != ' ')count++;
    return count;
  }
//------------------------------------------------------------------------------
  void showCountSegments(string s){
    std::cout << "("<< countSegments(s)<<")"<<s<< std::endl;
  }
};

int main(){

  std::cout <<"<<<<  LeetCode - 434. Number of Segments in a String >>>>" << std::endl;
  Solution solution;
  solution.showCountSegments("asda asd asd");

  return 0;
}