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
  int dominantIndex(vector<int>& nums) {
    if( nums.size() == 1 ) return 0;

    int Max = nums.at(0);
    int iMax = 0;
    int max = -1;
    int imax = -1;
    for( int i = 1; i < nums.size() ; i++ ){
      if( nums.at(i) > Max ){
        max = Max;
        imax = iMax;
        Max = nums.at(i);
        iMax = i;
      } else {
        if( nums.at(i) > max ){
          max = nums.at(i);
          imax = i;
        }
      }
    }
    return ( max*2 <= Max ? iMax : -1 );
  }
//------------------------------------------------------------------------------
  void showDominantIndex(vector<int> nums){
    std::cout << "----- New Test -----" << std::endl;
    std::cout << "Index: "<< dominantIndex(nums) << std::endl;
  }
};

int main(){

  std::cout <<"<<<<  LeetCode - 747. Largest Number At Least Twice of Others >>>>" << std::endl;
  Solution solution;
  solution.showDominantIndex( {3,6,1,0} );

  return 0;
}