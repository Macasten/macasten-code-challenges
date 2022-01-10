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
  vector<int> plusOne(vector<int>& digits) {
    vector<int> output = {};

    bool carry = true;
    size_t index { digits.size() - 1 };
    while( carry ){
      int sum = digits.at(index) + 1;
      if( sum > 9 ){
        sum = 0;
      } else {
        carry = false;
      }
      output.push_back(sum);
      if( index == 0 || !carry )break;
      index--;
    }


    if( carry ) {
      output.push_back(1);
    } else {
      while ( index != 0 ){
        index--;
        output.push_back( digits.at(index) );
      }
    }

    std::reverse(output.begin(), output.end() );
    return output;
  }
//------------------------------------------------------------------------------
  void ShowPlusOne(vector<int> digits) {
    coutVector( digits, "Original");
    coutVector( plusOne(digits), "Result" );
  }
};

int main(){

  std::cout <<"<<<<  LeetCode - 66. Plus One  >>>>" << std::endl;
  Solution solution;
  solution.ShowPlusOne({9,9,5,6,3});
  solution.ShowPlusOne({9});
  solution.ShowPlusOne({1,1,5,9,9});

  return 0;
}