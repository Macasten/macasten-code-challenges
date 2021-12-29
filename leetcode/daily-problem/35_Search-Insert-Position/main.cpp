#include <iostream>
#include <vector>

class Solution {
public:

  Solution(){}

  int searchInsert( std::vector<int>&& nums, int target) {
    return searchInsert( nums, target );
  }

  //----------------------------------------------------------- Challenge Solution
  int searchInsert( std::vector<int>& nums, int target) {
    if( nums[0] >= target )
      return 0;
    if( target > nums.back() )
      return nums.size();

    for( size_t i = 0; i < nums.size()-1; i++){
      if( nums.at(i) < target && nums.at(i+1) >= target ){
        return i+1 ;
      }
    }
    return nums.size() ;
  }
  //------------------------------------------------------------------------------
};


int main(int argc, char const *argv[])
{
  Solution mySolution;
  std::cout << mySolution.searchInsert( {1,3,5,6} , 2 ) << std::endl;
  std::cout << mySolution.searchInsert( {1,3,5,6} , 7 ) << std::endl;
  std::cout << mySolution.searchInsert( {1,3,5,6} , 6 ) << std::endl;
  std::cout << mySolution.searchInsert( {1,3,5,6} , 3 ) << std::endl;
  std::cout << mySolution.searchInsert( {1,3,5,6} , -1 ) << std::endl;
  std::cout << mySolution.searchInsert( {1,3} , 3 ) << std::endl;


  return 0;
}