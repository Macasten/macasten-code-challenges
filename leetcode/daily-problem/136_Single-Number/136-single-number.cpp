#include <bits/stdc++.h>

using namespace std;

class Solution {
public:

//----------------------------------------------------------- Challenge Solution
  int singleNumber(vector<int>& nums) {
    if(nums.size() == 1 )
      return nums.at(0);

    int output {0};
    for( auto num: nums ){
      output ^= num;
    }
    return output;
  }
//------------------------------------------------------------------------------
  void showSingleNumber(vector<int> nums) {
    std::cout << "Single Number: "<< singleNumber(nums) << std::endl;
  }
};

int main(){

  std::cout <<"<<<<  LeetCode - 136. Single Number >>>>" << std::endl;
  Solution solution;
  solution.showSingleNumber({1,1,2,2,3,3,5,8,8});

  return 0;
}