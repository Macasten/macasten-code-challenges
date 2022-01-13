#include <bits/stdc++.h>

using namespace std;


void printBalloons( vector<vector<int>>& points ){
  for( auto& point : points ){
    cout << setw(point.at(1) +1 ) << right << std::string( std::abs( point.at(0) - point.at(1) ) + 1 , 'X' ) << endl;
  }
}

class Solution {
public:

//----------------------------------------------------------- Challenge Solution
  static bool sortPoint( std::vector<int> a, std::vector<int> b ){
    return a.at(1) < b.at(1);
  }
  int findMinArrowShots(vector<vector<int>>& points) {
    int minArrows = points.size();
    if( minArrows < 2 ) return minArrows;

    std::sort( points.begin(), points.end(), sortPoint);

    int* first = &points.at(0).at(1);
    int arrows = 1;
    for( size_t i=1; i < points.size(); i++ ){

      if(points.at(i).at(0) > *first) {
        arrows++;
        first = &points.at(i).at(1);
      }
    }

    return arrows;
  }
//------------------------------------------------------------------------------

  void showFindMinArrowShots( std::vector<std::vector<int>> points ){
    printBalloons( points );
    std::cout << "Min Arrow Shots: " << findMinArrowShots(points) << std::endl;

  }
};

int main(){

  std::cout <<"<<<<  LeetCode - 452. Minimum Number of Arrows to Burst Balloons >>>>" << std::endl;
  Solution solution;
  //solution.showFindMinArrowShots({{10,16},{2,8},{1,6},{7,12}});
  solution.showFindMinArrowShots({{3,9},{7,12},{3,8},{6,8},{9,10},{2,9},{0,9},{3,9},{0,6},{2,8}});
  return 0;
}