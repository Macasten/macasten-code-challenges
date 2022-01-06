#include <bits/stdc++.h>

using namespace std;

class Solution {
public:

//----------------------------------------------------------- Challenge Solution
  int lengthOfLongestSubstring(string s) {
    int sSize = s.size();
    if( sSize < 2 ) return sSize;
    int left{0};
    int right{0};
    int ans{0};
    unordered_set<char> st;
    while(left<sSize && right<sSize){
      if(st.find(s[right]) == st.end()){
        st.insert(s[right++]);
        ans = max(ans,right-left);
      }
      else{
        st.erase(s[left++]);
      }
    }
    return ans;

  }
//------------------------------------------------------------------------------
  void showLengthOfLongestSubstring( string s ){
    std::cout << "Result: "<< lengthOfLongestSubstring(s) << std::endl;
  }
};

int main(){

  std::cout <<"<<<<  LeetCode - 3. Longest Substring Without Repeating Characters >>>>" << std::endl;
  Solution solution;
  solution.showLengthOfLongestSubstring("BBBB");
  solution.showLengthOfLongestSubstring("pwwkew");
  solution.showLengthOfLongestSubstring("abcabcbb");

  return 0;
}