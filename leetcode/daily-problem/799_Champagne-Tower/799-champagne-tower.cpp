#include <bits/stdc++.h>

using namespace std;

class Solution {
public:

//----------------------------------------------------------- Challenge Solution
  double champagneTower(int poured, int query_row, int query_glass) {

    if(poured < query_row) return 0.0;

    double v[101][101] = {0.0};
    v[0][0] = poured;

    for (int i = 0; i < 100; i++) {
      for (int j = 0; j <= i; j++) {
        if (v[i][j] >= 1) {
          // split  (v[i][j] - 1) into next level
          v[i + 1][j]     += (v[i][j] - 1) / 2.0;
          v[i + 1][j + 1] += (v[i][j] - 1) / 2.0;
          v[i][j] = 1;
        }
        if(query_row == i && query_glass == j ) return v[query_row][query_glass] ;
      }
    }
    return v[query_row][query_glass];
  }
//------------------------------------------------------------------------------
  void showChampagneTower(int poured, int query_row, int query_glass){
    std::cout << "----- New Test -----" << std::endl;
    std::cout << "     Poured: "<< poured << std::endl;
    std::cout << "  Query Row: "<< query_row << std::endl;
    std::cout << "Query Glass: "<< query_glass << std::endl;
    std::cout << "     Amount: "<< champagneTower(poured, query_row, query_glass) << std::endl;
  }
};

int main(){

  std::cout <<"<<<<  LeetCode - 799. Champagne Tower >>>>" << std::endl;
  Solution solution;
  solution.showChampagneTower(0,1,1);
  solution.showChampagneTower(2,1,1);
  solution.showChampagneTower(100000009,33,17);
  return 0;
}