#include <bits/stdc++.h>

using namespace std;

int main()
{
  string S;
  getline(cin, S);

//----------------------------------------------------------- Challenge Solution
  try
  {
    std::cout << std::stoi(S) << std::endl;
  }
  catch(const std::exception& e)
  {
    std::cout << "Bad String" << std::endl;
  }
//------------------------------------------------------------------------------
  

    return 0;
}
