#include <bits/stdc++.h>

using namespace std;

template<typename T>
inline void coutVector( std::vector<T> vec){
  for( size_t i = 0 ; i < vec.size(); i++ ){
    std::cout << vec.at(i) << ";";
  }
}

class Solution {
public:

//----------------------------------------------------------- Challenge Solution
  vector<int> intToVector( int& k ){
    vector<int> output = {};
    while( k ) {
      output.push_back(k%10);
      k /= 10;
    }
    return output;
  }

  vector<int> addToArrayForm(vector<int>& num, int k) {
    int index = num.size();
    vector<int> kVector = intToVector( k );
    if( index == 1 && num.at(0) == 0 ){
      std::reverse( kVector.begin(), kVector.end() );
      return kVector;
    }

    size_t numLength{ num.size() };
    size_t kLength{ kVector.size() };
    size_t calls{ std::max( numLength , kLength ) };
    bool carry = false;

    int sum{0};
    vector<int> output = {};
    std::reverse( num.begin(), num.end() );
    for( size_t index = 0; index < calls ; index++){
      sum = (carry ? 1 : 0);
      if( index < numLength ) sum += num.at(index);
      if( index < kLength ) sum += kVector.at(index);

      if( sum > 9 ){
        sum = sum%10;
        carry = true;
      } else {
        carry = false;
      }
      output.push_back(sum);
    }
    if(carry) output.push_back(1);

    reverse(output.begin(), output.end());
    return output;
  }
//------------------------------------------------------------------------------
  void ShowAddToArrayForm( vector<int> num, int k) {
    coutVector(num);
    std::cout << " + " << k << " = " ;
    coutVector( addToArrayForm(num, k) );
    std::cout << std::endl;
  }

};

int main(){

  std::cout <<"<<<<  LeetCode - 989. Add to Array-Form of Integer  >>>>" << std::endl;
  Solution solution;
  solution.ShowAddToArrayForm( {0} , 9000 );
  solution.ShowAddToArrayForm( {9,9,0,0,0,0} , 9 );
  solution.ShowAddToArrayForm( {6,5,6} , 6 );
  solution.ShowAddToArrayForm( {1,1,0,5,6} , 50 );
  solution.ShowAddToArrayForm( {9,9,1,2,3,5} , 9000 );
  solution.ShowAddToArrayForm( {9,9,0,0,0,0} , 9000 );
  solution.ShowAddToArrayForm( {1,2,0,0} , 34 );
  solution.ShowAddToArrayForm( {1,0} , 94 );
  solution.ShowAddToArrayForm( {9,9,9} , 1 );

  return 0;
}