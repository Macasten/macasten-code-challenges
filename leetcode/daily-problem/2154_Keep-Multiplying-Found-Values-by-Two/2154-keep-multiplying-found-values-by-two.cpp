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
  int findFinalValue(vector<int>& nums, int original) {
    std::sort(nums.begin(), nums.end() );

    for( int i = 0 ; i < nums.size() ; i++ ){
      if( nums.at(i) == original ){
        original *= 2;
      } else if ( nums.at(i) > original ){
        break;
      } else {
        
      }
    }

    return original;
  }
//------------------------------------------------------------------------------
  void showFindFinalValue(vector<int> nums, int original){
    std::cout << "----- New Test -----" << std::endl;
    coutVector( nums );
    std::cout<< original << " -> Final Values: "<< findFinalValue(nums, original ) << std::endl;
  }
};

int main(){

  std::cout <<"<<<<  LeetCode - 2154. Keep Multiplying Found Values by Two >>>>" << std::endl;
  Solution solution;
  solution.showFindFinalValue( {5,3,6,1,12}, 3 );

  return 0;
}