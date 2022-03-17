#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
  //----------------------------------------------------------- Challenge Solution
  int scoreOfParentheses(string s)
  {
    int depth = 0, res = 0;
    char prev = '(';

    for (const char &ch : s)
    {
      if (ch == '(')
        depth++;
      else
      {
        depth--;
        if (prev == '(')
          res += pow(2, depth);
      }

      prev = ch;
    }

    return res;
  }
  //------------------------------------------------------------------------------
  void showScoreOfParentheses(string s)
  {
    std::cout << "----- New Test -----" << std::endl;
    std::cout << s << " = " << scoreOfParentheses(s) << std::endl;
  }
};

int main()
{

  std::cout << "<<<<  LeetCode - 856. Score of Parentheses >>>>" << std::endl;
  Solution solution;
  solution.showScoreOfParentheses("()");
  solution.showScoreOfParentheses("(())");
  solution.showScoreOfParentheses("()()");
  solution.showScoreOfParentheses("(())(())((((((()))))))");
  solution.showScoreOfParentheses("(((())))()()()");
  return 0;
}