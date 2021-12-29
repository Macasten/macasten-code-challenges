#include <iostream>     // std::cout
#include <algorithm>    // std::find
#include <vector>       // std::vector

class Solution {
public:
//----------------------------------------------------------- Challenge Solution

  int search(std::vector<int>& nums, int target) {
    auto index = std::find( nums.begin(), nums.end(), target );
    return index == nums.end() ? -1 : (index - nums.begin());
  }
//------------------------------------------------------------------------------
};

int main()
{
  Solution solution;
  std::cout << "704. Binary Search" << std::endl;
  std::vector<int> test{1};
  std::cout << solution.search( test , 1 ) << std::endl;
  return 0;
}
