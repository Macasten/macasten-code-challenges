#include <bits/stdc++.h>

using namespace std;

class Solution {
public:

//----------------------------------------------------------- Challenge Solution
  string minRemoveToMakeValid(string s) {
    int n = s.length();
    string res = "";

    int cnt {0};
    // iterating from beginnning
    for (int i = 0; i < s.length(); ++i){
      // if we find and open parenthesis increase the cnt
      if (s[i] == '(')
        ++cnt;
      // if we found an close parenthisis
      // check if cnt == 0 , that means we have no earlier open parenthesis,
      // therefore replace that index by '#'
      else if (s[i] == ')') {
        if (cnt == 0)
          s[i] = '#';
        // else decrease the cnt beacuse a valid pair is found
        else
          --cnt;
      }
    }

    cnt = 0;
    // iterating from the end
    for (int i = n - 1; i >= 0; --i) {
      // if we find and close parenthesis increase the cnt
      if (s[i] == ')')
        ++cnt;
      // if we found an open parenthisis
      // check if cnt == 0 , that means we have no earlier close parenthesis,
      // therefore replace that index by '#'
      else if (s[i] == '(') {
        if (cnt == 0)
          s[i] = '#';
        // else decrease the cnt beacuse a valid pair is found
        else
          --cnt;
      }
    }

    // making the resultant string by excluding '#'
    for (int i = 0; i < s.length(); ++i) {
      if (s[i] != '#')
        res.push_back(s[i]);
    }

    return res;
  }
//------------------------------------------------------------------------------
  void showMinRemoveToMakeValid(string s) {
    std::cout << "----- New Test -----" << std::endl;
    std::cout << s << " -> " << minRemoveToMakeValid(s) << std::endl;
  }
};

int main(){

  std::cout <<"<<<<  LeetCode - 1249. Minimum Remove to Make Valid Parentheses >>>>" << std::endl;
  Solution solution;
  solution.showMinRemoveToMakeValid("lee(t(c)o)de)");
  solution.showMinRemoveToMakeValid("a)b(c)d");
  solution.showMinRemoveToMakeValid("))((");
  return 0;
}