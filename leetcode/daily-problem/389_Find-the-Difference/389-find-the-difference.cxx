#include <bits/stdc++.h>

using namespace std;

class Solution {
public:

//----------------------------------------------------------- Challenge Solution
  inline void incriseAlfa( int* alfa, char letter ){
    alfa[(int)letter-97]++;
    return;
  }

  char findTheDifference(string s, string t) {
    int alfa_s[31] = {0};
    int alfa_t[31] = {0};
    int i=0;
    for( ; i< s.size(); i++){
      incriseAlfa( alfa_s, s[i] );
      incriseAlfa( alfa_t, t[i] );
    }
    incriseAlfa( alfa_t, t[i] );

    i=0;
    for( ; i< 31; i++){
      if( alfa_s[i] != alfa_t[i]){
        return (char)(i+97);
      }

    }
    return (char)(i+97);
  }
//------------------------------------------------------------------------------
  void showFindTheDifference(string s, string t) {
    std::cout << "Difference: "<< findTheDifference( s, t) << std::endl;
  }
};

int main(){

  std::cout <<"<<<<  LeetCode - 389. Find the Difference >>>>" << std::endl;
  Solution solution;
  solution.showFindTheDifference( "a", "ab");
  return 0;
}