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
  inline int countSetBits(int n) {
    unsigned int count = 0;
    while (n) {
      count += n & 1;
      n >>= 1;
    }
    return count;
  }
  vector<int> countBits(int n){
    vector<int> output;
    for(int i = 0 ; i <= n; i++){
      output.push_back( countSetBits(i) );
    }
    return output;
  }
//------------------------------------------------------------------------------
  void showCountBits(int n){
    std::cout << "----- New Test -----" << std::endl;
    std::cout << n << " -> : " << std::endl;
    coutVector( countBits(n), "bits" );
  }
};

int main(){

  std::cout <<"<<<<  LeetCode - 338. Counting Bits >>>>" << std::endl;
  Solution solution;
  solution.showCountBits(0);
  solution.showCountBits(100);
  return 0;
}