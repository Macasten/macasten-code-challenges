#include <bits/stdc++.h>

using namespace std;

class Solution {
public:

//----------------------------------------------------------- Challenge Solution
  int missingNumber(vector<int>& nums) {
    std::vector<bool> test( nums.size()+1, true );
    for( auto num: nums){
      test.at(num) = false;
    }

    for( auto i = 0; i < test.size(); i++ ){
      if( test.at(i) ) return i;
    }
    return 0;
  }
//------------------------------------------------------------------------------
  void showMissingNumber(vector<int> nums) {
    std::cout << "Missin Number: " << missingNumber(nums) << std::endl;
  }
};

int main(){

  std::cout <<"<<<<  LeetCode - 268. Missing Number >>>>" << std::endl;
  Solution solution;
  solution.showMissingNumber({0,1,3});

  return 0;
}