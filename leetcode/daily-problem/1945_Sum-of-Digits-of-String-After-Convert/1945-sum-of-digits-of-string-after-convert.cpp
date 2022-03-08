#include <bits/stdc++.h>

using namespace std;

class Solution {
public:

//----------------------------------------------------------- Challenge Solution

  inline int sum(int n) {
    int sum=0;
    while(n){
      sum+=n%10;
      n/=10;
    }
    return sum;
  }

  int getLucky(string s, int k) {
    int output=0;
    for(int i=0;i<s.length();i++) {
      int ans=s[i]-96;
      output+=sum(ans);
    }

    while ( k > 1 && output > 9) {
      output=sum(output);
      k--;
    }

    return output;
  }
//------------------------------------------------------------------------------
  void showGetLucky(string s, int k){
    std::cout << "----- New Test -----" << std::endl;
    std::cout << "'"<< s << "' with "<< k << " transformations = "<< getLucky(s,k) << std::endl;
  }
};

int main(){

  std::cout <<"<<<<  LeetCode - 1945. Sum of Digits of String After Convert >>>>" << std::endl;
  Solution solution;
  //solution.showGetLucky("zbax", 2);
  //solution.showGetLucky("iiii", 1);
  //solution.showGetLucky("leetcode", 2);
  solution.showGetLucky("vbyytoijnbgtyrjlsc",2);
  //solution.showGetLucky("zzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzz",1);

  return 0;
}