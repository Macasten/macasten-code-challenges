#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
  //----------------------------------------------------------- Challenge Solution
  string removeDuplicateLetters(string s)
  {
    int len = s.size();
    string res = "";
    unordered_map<char, int> M;
    unordered_map<char, bool> V;
    stack<int> S;

    for (auto c : s)
    {
      if (M.find(c) == M.end())
        M[c] = 1;
      else
        M[c]++;
    }
    for (unordered_map<char, int>::iterator iter = M.begin(); iter != M.end(); iter++)
      V[iter->first] = false;

    for (int i = 0; i < len; i++)
    {
      M[s[i]]--;
      if (V[s[i]] == true)
        continue;

      while (!S.empty() and s[i] < s[S.top()] and M[s[S.top()]] > 0)
      {
        V[s[S.top()]] = false;
        S.pop();
      }
      S.push(i);
      V[s[i]] = true;
    }
    while (!S.empty())
    {
      res = s[S.top()] + res;
      S.pop();
    }
    return res;
  }
  //------------------------------------------------------------------------------
  void showRemoveDuplicateLetters(string s)
  {
    std::cout << "----- New Test -----" << std::endl;
  }
};

int main()
{

  std::cout << "<<<<  LeetCode - 316. Remove Duplicate Letters >>>>" << std::endl;
  Solution solution;
  solution.showRemoveDuplicateLetters("bcabc");
  solution.showRemoveDuplicateLetters("cbacdcbc");

  return 0;
}