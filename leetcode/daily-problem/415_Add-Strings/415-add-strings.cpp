#include <bits/stdc++.h>

using namespace std;

class Solution {
public:

//----------------------------------------------------------- Challenge Solution
  vector<int> stringToIntInverted( const string& num ){
    vector<int> output = {};
    for( int i = num.size() -1 ; i >= 0; i-- ){
      output.push_back( static_cast<int>( num.at(i) - '0') );
    }
    return output;
  }

  inline string intToSringInverted( const std::vector<int>& vec){
    std::string output = "";
    for( int i = vec.size() -1 ; i >= 0; i-- ){
      output += std::to_string(vec.at(i));
    }
    return output;
  }


  inline void updateCarry( int& sum, int& carry ){
    if( sum > 9 ){
      carry = sum/10;
      sum = sum%10;
    } else {
      carry = 0;
    }
  }

  void sumTwoVectors( std::vector<int>& result, const std::vector<int>& add ){
    int carry{0};
    size_t resultSize{ result.size() };
    size_t i = 0;
    for( ; i < add.size() ; i++){
      if( i < resultSize ){
        result.at(i) += add.at(i) + carry;
      } else{
        result.push_back( add.at(i) + carry );
      }
      updateCarry( result.at(i) , carry );
    }

    while ( carry )
    {
      if( i < resultSize ){
        result.at(i) += carry;
      } else{
        result.push_back( carry );
        break;
      }
      updateCarry( result.at(i) , carry );
      i++;
    }
  }

  string addStrings(string num1, string num2) {
    if( num1 == "0" ) return num2;
    if( num2 == "0" ) return num1;

    vector<int> num1Int = stringToIntInverted(num1);
    vector<int> num2Int = stringToIntInverted(num2);

    sumTwoVectors( num1Int, num2Int );
    return intToSringInverted( num1Int );

  }
//------------------------------------------------------------------------------
  void showAddString( std::string num1, std::string num2 ){
    std::cout << num1 << " + " << num2 << " = " << addStrings(num1, num2) << std::endl;

  }
};

int main(){

  std::cout <<"<<<<  LeetCode - 415. Add Strings >>>>" << std::endl;
  Solution solution;
  solution.showAddString("1" , "2" );
  return 0;
}