#include <bits/stdc++.h>

using namespace std;

class Solution {
public:

//----------------------------------------------------------- Challenge Solution


  inline void updateCarry( int& sum, int& carry ){
    if( sum > 9 ){
      carry = sum/10;
      sum = sum%10;
    } else {
      carry = 0;
    }
  }

  inline int sumChar( const char& a , const char& b){
    return (int)( a - '0') + (int)( b - '0');
  }

  std::string addStringToBig( const string& bigger, const string& smaller ){
    int indexB = bigger.length()-1;
    int indexS = smaller.length()-1;

    std::string output = "";
    int carry{0};
    while ( indexS >= 0) {
      int sum = sumChar( bigger.at(indexB), smaller.at(indexS) ) + carry;
      updateCarry(sum, carry );
      output += std::to_string( sum );
      indexS--;
      indexB--;
    }

    while ( carry )
    {
      if( indexB >= 0 ){
        int sum = carry + (int)(bigger.at(indexB) - '0');
        updateCarry( sum , carry );
        output += std::to_string( sum );
      } else{
        output += std::to_string( carry );
        break;
      }
      indexB--;
    }

    while (indexB >=0 ) {
      output += bigger.at(indexB);
      indexB--;
    }
    return output;
  }

  string addStrings(string num1, string num2) {
    if( num1 == "0" ) return num2;
    if( num2 == "0" ) return num1;


    std::string output = ( num1.length() >= num2.length() ?
      addStringToBig(num1, num2) :
      addStringToBig(num2, num1) );

    std::reverse(output.begin(), output.end());
    return output;
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
  solution.showAddString("11111111" , "9" );
  solution.showAddString("9", "11111111" );
  solution.showAddString("11111111" , "999999999" );
  solution.showAddString("999999999", "11111111" );
  return 0;
}