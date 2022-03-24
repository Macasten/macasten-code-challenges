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
  int numRescueBoats(vector<int> &people, int limit)
  {
    int boats{0};
    if (people.empty())
      return boats;

    std::sort(people.begin(), people.end());
    int i{0};
    int f = people.size() - 1;
    int newLimit;
    while (i <= f)
    {
      newLimit = people.at(f) + people.at(i);
      if (newLimit > limit)
      {
        f--;
      }
      else
      {
        f--;
        i++;
      }
      boats++;
    }
    return boats;
  }
  //------------------------------------------------------------------------------
  void showNumRescueBoats(vector<int> people, int limit)
  {
    std::cout << "----- New Test -----" << std::endl;
    std::cout << "Number of Rescue Boats" << std::endl;
  }
};

int main()
{

  std::cout << "<<<<  LeetCode - 881. Boats to Save People >>>>" << std::endl;
  Solution solution;

  return 0;
}