#include <bits/stdc++.h>

using namespace std;

template<typename T>
inline void coutVector( std::vector<T> vec, std::string label = "Vector" ){
  std::cout << label << " : { ";
  if( vec.empty() ){
    std::cout << "EMPTY }" << std::endl;
    return;
  }
  for( size_t i = 0 ; i < (vec.size()-1); i++ ){
    std::cout << vec.at(i) << "; " ;
  }
  std::cout<< vec.back() << " }"<< std::endl;
}

class Solution {
public:

//----------------------------------------------------------- Challenge Solution
  int arrayPairSum(vector<int>& nums) {
    if( nums.size() == 0 ) return 0;
    std::sort(nums.begin(), nums.end() );
    int output{0};
    for(int i = 0; i < nums.size(); i+=2 ){
      output += nums.at(i);
    }
    return output;
  }
//------------------------------------------------------------------------------
  void showArrayPairSum(vector<int> nums){
    std::cout << "----- New Test -----" << std::endl;
    coutVector( nums , "Numbers: " );
    std::cout << "Max sum of min pair: " << arrayPairSum(nums) << std::endl;
  }
};

int main(){

  std::cout <<"<<<<  LeetCode - 561. Array Partition I >>>>" << std::endl;
  Solution solution;
  solution.showArrayPairSum({6,2,6,5,1,2,-1,56,-8,-9,2,0});

  return 0;
}