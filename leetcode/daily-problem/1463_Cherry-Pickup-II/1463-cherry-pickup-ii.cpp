#include <bits/stdc++.h>

using namespace std;

struct Robot
{
  uint row;
  uint column;

  Robot( uint iRow = 0 , uint iColumn = 0 ) : row(iRow), column(iColumn){};
};



class Solution {
public:

//----------------------------------------------------------- Challenge Solution
  int maxCherry{0};

  int cherryPickup(vector<vector<int>>& grid) {
    Robot* master = new Robot();
    Robot* slave = new Robot( 0 , (grid.front().size() - 1));
    return 0;
  }
//------------------------------------------------------------------------------
  void showCherryPickup(vector<vector<int>> grid) {

  }
};

int main(){

  std::cout <<"<<<<  LeetCode - 1463. Cherry Pickup II  >>>>" << std::endl;
  Solution solution;

  return 0;
}