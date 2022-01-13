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
  int findMinArrowShots(vector<vector<int>>& points) {
    vector<pair<int,int>> k;
    for(int i=0;i<points.size();i++) {
      k.push_back({points[i][0],points[i][1]});
    }

    int cnt=1;
    sort(k.begin(),k.end());
    int end=k[0].second;
    for(int i=1;i<k.size();i++) {
      if(k[i].first>end) {
        cnt++;
        end=k[i].second;
      }
      end=std::min(end,k[i].second);
    }
    return cnt;
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