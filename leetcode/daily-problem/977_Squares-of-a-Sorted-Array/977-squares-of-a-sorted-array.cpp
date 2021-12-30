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
  static vector<int> sortedSquares(vector<int>& nums) {
    vector<int> output = {};
    for( auto num : nums ){
      output.push_back( (num*num) );
    }
    std::sort(output.begin(), output.end());
    return output;
  }
//------------------------------------------------------------------------------
  static std::vector<int> sortedSquaresInit( std::vector<int> nums ){
    return Solution::sortedSquares(nums);
  }
};



int main()
{
  coutVector( Solution::sortedSquaresInit({-7,-3,2,3,11}) );
  /* code */
  return 0;
}
