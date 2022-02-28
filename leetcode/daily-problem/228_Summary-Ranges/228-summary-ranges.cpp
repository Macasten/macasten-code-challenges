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
  vector<string> summaryRanges(vector<int>& nums) {
    vector<string> ans;
    if (!nums.size()) return ans;
    int f = nums[0], s = nums[0], len = nums.size();
    for (int i = 1; i < len; i++){
      if (s + 1 == nums[i]){
        s = nums[i];
      } else {
        f == s ? ans.push_back(to_string(f)) : ans.push_back(to_string(f) + "->" + to_string(s)), f = s = nums[i];
      }
    }
    f == s ? ans.push_back(to_string(f)) : ans.push_back(to_string(f) + "->" + to_string(s));
    return ans;
  }
//------------------------------------------------------------------------------
  void showSummaryRanges(vector<int> nums){
    std::cout << "----- New Test -----" << std::endl;
    coutVector(nums, "nums");
    coutVector( summaryRanges(nums), "string" );
  }
};

int main(){

  std::cout <<"<<<<  LeetCode - 228. Summary Ranges >>>>" << std::endl;
  Solution solution;
  solution.showSummaryRanges({0,2,3,5,7,8,9});

  return 0;
}