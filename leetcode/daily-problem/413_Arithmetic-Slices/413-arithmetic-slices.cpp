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
  int numberOfArithmeticSlices(vector<int>& nums) {
    // if nums size is less than 3 return false
    if(nums.size() < 3)
      return 0;

    int cnt = 0, diff;
    for(int i = 0; i< nums.size()-2 ; ++i) {
      // storing diff of first 2 elements
      diff = nums[i+1] - nums[i];

      // checking for consecutive elements with same difference.
      for(int j = i+2; j<nums.size(); ++j) {
      // if we find the same diff of next 2 elements
      // this means we  find consecutive elements
      // increase the Count
      if(nums[j] - nums[j-1] == diff)
        ++cnt;
      else
        // break as we need to cnt for consecutive diff elements
        break;
      }
    }
    // return cnt
    return cnt;
  }
//------------------------------------------------------------------------------
  void showNumberOfArithmeticSlices(vector<int> nums){
    std::cout << "----- New Test -----" << std::endl;
    coutVector( nums );
    std::cout << "Number os Arithmetis slices: "<< numberOfArithmeticSlices(nums) << std::endl;
  }
};

int main(){

  std::cout <<"<<<<  LeetCode - 413. Arithmetic Slices >>>>" << std::endl;
  Solution solution;
  solution.showNumberOfArithmeticSlices({7,7,7,7,7,7});

  return 0;
}