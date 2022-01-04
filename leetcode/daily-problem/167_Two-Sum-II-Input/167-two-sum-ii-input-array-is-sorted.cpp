#include <bits/stdc++.h>

using namespace std;

template<typename T>
inline void coutVector( std::vector<T> vec, std::string label = "Vector" ){
  std::cout << label << " : { ";
  for( size_t i = 0 ; i < (vec.size()-1); i++ ){
    std::cout << vec.at(i) << "; " ;
  }
  std::cout<< vec.back() << " }"<< std::endl;
}

class Solution {
public:


//----------------------------------------------------------- Challenge Solution
  inline void nextIndex(vector<int>& numbers, size_t& index ){
    if( index >= (numbers.size() - 1)){
      index++;
      return;
    }

    if( numbers.at(index) == numbers.at(index+1) ){
      index++;
      for(; index < numbers.size() - 1; index++ ){
        if( numbers.at(index) != numbers.at(index+1) ){
          break;
        }
      }
    }
    index++;
  }

  vector<int> twoSum(vector<int>& numbers, int target) {
    vector<int> output = {-1,-1};

    size_t fIndex{0};
    size_t iIndex{0};
    while(iIndex < ( numbers.size() - 1 ) ){
      fIndex=(iIndex + 1);
      while (fIndex < numbers.size() ) {
        int sum = numbers.at(iIndex) + numbers.at(fIndex);
        std::cout << "i: "<< iIndex << " f: "<< fIndex << " sum: "<< sum << std::endl;
        if( sum == target){
          output.at(0) = iIndex;
          output.at(1) = fIndex;
          iIndex = numbers.size();
          break;
        } else if( sum > target ){
          break;
        }
        nextIndex(numbers, fIndex );
      }
      nextIndex(numbers, iIndex );
    }
    output.at(0) += 1;
    output.at(1) += 1;
    return output;
  }
//------------------------------------------------------------------------------

  void ShowTwoSum(vector<int> numbers, int target) {
    coutVector(numbers);
    std::cout << "Targe: " << target << std::endl;
    coutVector(twoSum(numbers, target), "Result");
  }

};

int main(){

  Solution solution;
  solution.ShowTwoSum( {1,2,3,4,4,9,56,90}, 8 );
  //solution.ShowTwoSum( {-20,-5,-3,-2,-1}, -4 );
  //solution.ShowTwoSum( {-20,-20,-20,-20,-5,-3,-2,-1,0,2,6}, 2 );
  return 0;
}


