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
  int minimumDeviation(vector<int>& nums) {
    int n = nums.size();
    int mx = INT_MIN, mn = INT_MAX;

    for(int i = 0; i<n; ++i) {
      if((nums[i]%2) != 0)    // multiplication by 2 if nums[i] is odd
        nums[i] *= 2;   // maximising all odd numbers

      mx = max(mx,nums[i]);
      mn = min(mn,nums[i]);
    }

    int min_deviation = mx - mn;

    priority_queue<int> pq;
    // Inserting into Priority queue (Max Heap) and try to decrease as much we can
    for(int i = 0; i<n; ++i) {
      pq.push(nums[i]);
    }

    while((pq.top()) % 2 == 0){
      int top = pq.top();
      pq.pop(); // popped the top element
      min_deviation = min(min_deviation, top - mn);
      top /= 2;
      mn = min(mn, top);  // updating min
      pq.push(top);   // pushing again the top as we have to minimize the max
    }

    min_deviation = min(min_deviation, pq.top() - mn);

    return min_deviation;
  }
//------------------------------------------------------------------------------
  void showMinimumDeviation(vector<int> nums) {
    std::cout << "----- New Test -----" << std::endl;
    coutVector(nums);
    std::cout << "Minimum Deviation: "<< minimumDeviation( nums ) << std::endl;
  }
};

int main(){

  std::cout <<"<<<<  LeetCode - 1675. Minimize Deviation in Array >>>>" << std::endl;
  Solution solution;
  solution.showMinimumDeviation( {1,2,3,4} );
  solution.showMinimumDeviation( {4,1,5,20,3});
  return 0;
}