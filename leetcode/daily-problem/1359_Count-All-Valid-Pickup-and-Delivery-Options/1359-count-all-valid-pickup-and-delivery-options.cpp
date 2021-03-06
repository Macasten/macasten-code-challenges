#include <bits/stdc++.h>

using namespace std;

class Solution {
public:

//----------------------------------------------------------- Challenge Solution
  int countOrders(int n) {
    long res = 1, mod = 1000000007;
    for(int i = 1; i <=n; ++i) {
      // calulating n!
       res *= i;
      // to avoid overflow
      res %= mod;

      // (2*i-1) are the vacant places which we can choose
      // later we have n! permutation of pickup task
      // therefore we have to multiply with n! that we calculated as res.
      res *= (2*i-1);

      // to avoid overflow
      res %= mod;
    }

    // to avoid overflow
    return res % mod;
  }
//------------------------------------------------------------------------------
  void showCountOrders(int n) {
    std::cout << "----- New Test -----" << std::endl;
    std::cout << n << " - Orders -> "<< countOrders(n) << std::endl;
  }
};

int main(){

  std::cout <<"<<<<  LeetCode - 1359. Count All Valid Pickup and Delivery Options >>>>" << std::endl;
  Solution solution;
  solution.showCountOrders(90);

  return 0;
}