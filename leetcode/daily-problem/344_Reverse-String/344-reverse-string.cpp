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
  void reverseString(vector<char>& s) {
    size_t runs{s.size()/2};
    size_t i = 0;
    size_t f = s.size() - 1;
    while( runs ){
      char temp = s.at(i);
      s.at(i) = s.at(f);
      s.at(f) = temp;
      i++;
      f--;
      runs--;
    }
  }
//------------------------------------------------------------------------------

  void showReverseString(std::string word ){
    std::vector<char> s(word.begin(), word.end());
    std::cout << "Original: "<< word << std::endl;
    reverseString( s );
    coutVector(s, "Result");

  }
};

int main(){

  Solution solution;
  solution.showReverseString( "test" );
  solution.showReverseString( "tests" );

  return 0;
}