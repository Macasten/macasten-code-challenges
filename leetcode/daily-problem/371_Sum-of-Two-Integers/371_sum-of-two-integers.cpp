#include <bits/stdc++.h>

using namespace std;

class Solution {
public:

//----------------------------------------------------------- Challenge Solution
  int getSum(int a, int b) {
    if( b < 0 ){
      while (b!=0){
        a--;
        b++;
      }
      
    } else {
      while (b!=0){
        a++;
        b--;
      }
    }
    return a;
  }
//------------------------------------------------------------------------------
  void showGetSum( int a, int b){
    std::cout << a << " + " << b << " = " << getSum(a,b) << std::endl;
  }
};

int main(){

  std::cout <<"<<<<  LeetCode - 371. Sum of Two Integers >>>>" << std::endl;
  Solution solution;
  solution.showGetSum( 5 , 5);
  solution.showGetSum( 5 , -5);

  return 0;
}