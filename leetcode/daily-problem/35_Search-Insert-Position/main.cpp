#include <iostream>
#include <vector>

class Solution {
public:

  Solution(){}

  int searchInsert( std::vector<int>&& nums, int target) {
    return searchInsert( nums, target );
  }

  int searchInsert( std::vector<int>& nums, int target) {
    if( nums[0] >= target )
      return 0;

    for( size_t i = 0; i < nums.size()-1; i++){
      std::cout << i << " - "<< nums.at(i) << std::endl;
      if( nums.at(i) < target && nums.at(i+1) >= target ){
        return i+1 ;
      }
    }
    return nums.size() ;
  }
};


int main(int argc, char const *argv[])
{
  Solution mySolution;
  std::cout << mySolution.searchInsert( {1,3,5,6} , 2 ) << std::endl;

  return 0;
}