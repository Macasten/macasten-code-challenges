#include <bits/stdc++.h>

using namespace std;

class Solution {
public:

//----------------------------------------------------------- Challenge Solution
  const int N = (1e5 + 1);
  int deleteAndEarn(vector<int>& nums) {
    vector<int> frequencyMap(N, 0);
    int dp[N];
    
    for(auto num : nums)
      frequencyMap[num]++;
    
    dp[0] = 0;
    dp[1] = frequencyMap[1];
    
    for(int i=2;i<N;i++)
      dp[i] = max(dp[i-2]+i*frequencyMap[i], dp[i-1]);

    return dp[N-1];
  }
//------------------------------------------------------------------------------
  void showDeleteAndEarn(vector<int> nums){
    std::cout << "----- New Test -----" << std::endl;
    std::cout << " Earn : "<< deleteAndEarn(nums) << std::endl;
  }
};

int main(){

  std::cout <<"<<<<  LeetCode - 740. Delete and Earn >>>>" << std::endl;
  Solution solution;
  solution.showDeleteAndEarn( {1,2,3,4,5,6,8});

  return 0;
}