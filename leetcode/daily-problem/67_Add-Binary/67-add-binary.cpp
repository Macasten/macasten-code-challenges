#include <bits/stdc++.h>

using namespace std;

class Solution {
public:

//----------------------------------------------------------- Challenge Solution
  string addBinary(string a, string b) {
    if( a == "0" ) return b;
    if( b == "0" ) return a;

    std::string output{""};

    size_t aLength{ a.length() };
    size_t bLength{ b.length() };
    size_t calls{ std::max( aLength , bLength ) };
    bool carry = false;

    int sum{0};
    std::reverse( a.begin(), a.end() );
    std::reverse( b.begin(), b.end() );
    for( size_t index = 0; index < calls ; index++)
    {
      sum = 0;
      if( carry ) sum++;
      if( index < aLength && a.at(index) == '1' ) sum++;
      if( index < bLength && b.at(index) == '1' ) sum++;

      switch (sum)
      {
      case 0:
        output.push_back('0');
        carry = false;
        break;
      case 1:
        output.push_back('1');
        carry = false;
        break;
      case 2:
        output.push_back('0');
        carry = true;
        break;
      case 3:
        output.push_back('1');
        carry = true;
        break;
      default:
        break;
      }
    }
    if(carry) output.push_back('1');

    reverse(output.begin(), output.end());
    return output;
  }
//------------------------------------------------------------------------------
  void showAddBinary(string a, string b) {
    std::cout << a << " + " << b << " = " << addBinary(a,b) << std::endl;
  }
};

int main(){

  std::cout <<"<<<<  LeetCode - 67. Add Binary  >>>>" << std::endl;
  Solution solution;
  solution.showAddBinary( "1", "1" );
  solution.showAddBinary( "111", "11" );

  return 0;
}