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
  int majorityElement(vector<int>& nums) {
    if(nums.size() ==1 ) return nums.at(0);

    std::map<int,int> counter;
    int max = -1;
    int output = -1;
    for(auto &num : nums ){
      if( counter.find(num) == counter.end() ){
        counter[num] = 0;
      } else {
        counter[num]++;
      }

      if( counter[num] > max ){
        max = counter[num];
        if( output != num) output = num;
      };
    }

    return output;
  }
//------------------------------------------------------------------------------
  void showMajorityElement(vector<int> nums){
    std::cout << "----- New Test -----" << std::endl;
    coutVector(nums);
    std::cout << "Majority Element: "<< majorityElement(nums) << std::endl;
  }
};

int main(){

  std::cout <<"<<<<  LeetCode - 169. Majority Element >>>>" << std::endl;
  Solution solution;
  solution.showMajorityElement({1,1,1,1,1,2});

  return 0;
}