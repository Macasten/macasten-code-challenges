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
  void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    for( int i = 0; i < n ; i++ ){
      nums1.at(m+i) = nums2.at(i);
    }
    std::sort(nums1.begin(), nums1.end() );
  }
//------------------------------------------------------------------------------
  void showMerge(vector<int> nums1, int m, vector<int> nums2, int n){
    std::cout << "----- New Test -----" << std::endl;
    coutVector( nums1, "num1" );
    std::cout << "new size: " << m << std::endl;
    coutVector( nums2, "num2" );
    std::cout << "new size: " << n << std::endl;
    merge(nums1, m, nums2, n);
    coutVector( nums1, "Result" );
  }
};

int main(){

  std::cout <<"<<<<  LeetCode - 88. Merge Sorted Array >>>>" << std::endl;
  Solution solution;

  solution.showMerge( {1,2,3,4,5,6}, 3, {9,1,0,12,} ,3 );

  return 0;
}