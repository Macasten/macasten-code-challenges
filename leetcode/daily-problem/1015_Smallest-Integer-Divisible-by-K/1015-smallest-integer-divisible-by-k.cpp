#include <bits/stdc++.h>

class Solution {
public:
//----------------------------------------------------------- Challenge Solution

  static int smallestRepunitDivByK(int k) {
    if(k%2==0) return -1;

    int rest = 0;
    for(int i = 1; i<=k; i++){
      rest = (rest*10+1) % k;
      if(rest == 0){
        return i;
      }
    }
    return -1;

  }
//------------------------------------------------------------------------------
};

int main()
{
  std::cout << Solution::smallestRepunitDivByK(3) << std::endl;
  return 0;
}
