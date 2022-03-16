#include <bits/stdc++.h>

using namespace std;

template <typename T>
inline void coutVector(std::vector<T> vec, std::string label = "Vector")
{
  std::cout << label << " : { ";
  if (vec.empty())
  {
    std::cout << "EMPTY }" << std::endl;
    return;
  }
  for (size_t i = 0; i < (vec.size() - 1); i++)
  {
    std::cout << vec.at(i) << "; ";
  }
  std::cout << vec.back() << " }" << std::endl;
}

class Solution
{
public:
  //----------------------------------------------------------- Challenge Solution
  bool validateStackSequences(vector<int> &pushed, vector<int> &popped)
  {
    if (pushed.empty())
      return true;

    std::vector<int> temp;
    int indxPop{0};
    int indxPus{0};

    while (indxPus < pushed.size())
    {
      if (temp.empty() || temp.back() != popped.at(indxPop))
      {
        temp.push_back(pushed.at(indxPus));
        indxPus++;
        continue;
      }

      if (temp.back() == popped.at(indxPop))
      {
        temp.pop_back();
        indxPop++;
      }
    }

    while (indxPop < popped.size() && temp.back() == popped.at(indxPop))
    {
      temp.pop_back();
      indxPop++;
    }

    return temp.empty();
  }
  //------------------------------------------------------------------------------
  void showValidateStackSequences(vector<int> pushed, vector<int> popped)
  {
    std::cout << "----- New Test -----" << std::endl;
    coutVector(pushed, "puched");
    coutVector(popped, "popped");
    std::cout << (validateStackSequences(pushed, popped) ? "VALID" : "INVALID") << " Stack Sequences" << std::endl;
  }
};

int main()
{

  std::cout << "<<<<  LeetCode - 946. Validate Stack Sequences >>>>" << std::endl;
  Solution solution;
  solution.showValidateStackSequences({1, 2, 3, 4, 5}, {1, 2, 3, 4, 5});
  solution.showValidateStackSequences({1, 2, 3, 4, 5}, {5, 4, 3, 2, 1});
  solution.showValidateStackSequences({1, 2, 3, 4, 5}, {4, 3, 5, 1, 2});

  return 0;
}