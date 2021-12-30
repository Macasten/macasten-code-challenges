#include <bits/stdc++.h>

using namespace std;

template<typename T>
inline void coutVector( std::vector<T> vec, std::string label = "Vector" ){
  std::cout << label << " : { ";
  for( size_t i = 0 ; i < (vec.size()-1); i++ ){
    std::cout << vec.at(i) << "; " ;
  }
  std::cout<< vec.back() << " }"<< std::endl;
}

class Solution {
public:
//----------------------------------------------------------- Challenge Solution
  static void rotate(vector<int>& nums, int k) {
    k = (k%nums.size());
    if( k == 0 ) return;

    std::vector<int> begin( nums.begin() + (nums.size() - k ), nums.end() );
    std::vector<int> tail( nums.begin(), nums.begin() + (nums.size() - k ) );

    nums.clear();
    nums.insert( nums.end(), begin.begin(), begin.end() );
    nums.insert( nums.end(), tail.begin(), tail.end() );
  }
//------------------------------------------------------------------------------
};

int main(){

  std:vector<int> vec = {1,2,3,4,5,6};
  Solution::rotate( vec, 7);
  coutVector(vec, "Result");
  return 0;
}