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

  void multiplyByOneDigit( vector<int>& num, const int& digit, vector<int>& result ){
    int carry {0};
    int sum{0};
    for( auto& elem : num ){
      sum = (elem * digit + carry);
      updateCarry( sum, carry );
      result.push_back(sum);
    }
    if( carry ) result.push_back(carry);
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

  std::vector<int> multiplyTwoVectors( std::vector<int>& num1 , std::vector<int>& num2 ){
    std::vector<vector<int>> multipliesDigits;

    size_t calls = num2.size();
    multipliesDigits.reserve(num2.size());

    for( size_t i = 0; i < calls; i++ ){
      multipliesDigits.push_back( vector<int>(i) );
      multiplyByOneDigit(num1, num2.at(i), multipliesDigits.at(i) );
    }

    for( size_t i = 0 ; i < (calls -1 ); i++ ){
      sumTwoVectors( multipliesDigits.back(), multipliesDigits.at(i) );
    }

    return multipliesDigits.back();
  }



  string multiply(string num1, string num2) {
    if( num1 == "0" || num2 == "0" ){
      return "0";
    }

    if( num1 == "1" ) return num2;
    if( num2 == "1" ) return num1;

    vector<int> num1Int = stringToIntInverted(num1);
    vector<int> num2Int = stringToIntInverted(num2);

    std::vector<int> result;
    if( num1Int.size() > num2Int.size() ){
      result = multiplyTwoVectors(num1Int, num2Int);
    } else if( num1Int.size() < num2Int.size() ) {
      result = multiplyTwoVectors(num2Int, num1Int);
    } else {
      result = ( num1Int.back() > num2Int.back() ?
        multiplyTwoVectors(num2Int, num1Int) :
        multiplyTwoVectors(num1Int, num2Int) );
    }

    return intToSringInverted( result );
  }
//------------------------------------------------------------------------------

  void showMultiply( std::string num1, std::string num2 ){
    std::cout << num1 << " x " << num2 << " = " << multiply(num1, num2) << std::endl;
  }
};

int main(){

  std::cout <<"<<<<  LeetCode - 43. Multiply Strings >>>>" << std::endl;
  Solution solution;
  //solution.showMultiply( "2", "3" );
  //solution.showMultiply( "123", "321" );
  //solution.showMultiply( "123", "456" );
  solution.showMultiply( "123456789", "987654321" );
  solution.showMultiply( "987654321", "123456789" );
  solution.showMultiply( "140", "721" );
  solution.showMultiply( "721", "140" );


  return 0;
}