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

  inline void moveSubArray( vector<int>& nums, size_t initIndex , size_t lastIndex ){
    // std::cout << "Moving" << std::endl;
    size_t i {initIndex};
    while (i < lastIndex )
    {
      nums.at(i) = nums.at(i+1);
      i++;
    }
    nums.at(i) = 0;
  }
  void moveZeroes(vector<int>& nums) {

    size_t lastIndex {nums.size()};
    size_t index {0};
    while(index < lastIndex){
      if( nums.at(index) == 0 ){
        lastIndex--;
        moveSubArray( nums, index, lastIndex );
      } else {
        index++;
      }
      std::cout << index << " - " << lastIndex << std::endl;
    }
  }
//------------------------------------------------------------------------------

  void showMoveZeroes( vector<int> nums ){
    coutVector(nums, "Original");
    moveZeroes(nums);
    coutVector(nums, "Moved");
  }
};

int main(){

  Solution solution;
  // solution.showMoveZeroes( { 1,2,3} );
  // solution.showMoveZeroes( {0,1,2,3} );
  // solution.showMoveZeroes( {0,1,2,3,0} );
  // solution.showMoveZeroes( {0,1,2,3,0,0,0} );
  solution.showMoveZeroes( {0,0,3,0,0,0,4} );
  // solution.showMoveZeroes( {0,0,0,3,4} );
  // solution.showMoveZeroes( {0,3,4} );
  // solution.showMoveZeroes( {0,0,3,4} );
  return 0;
}