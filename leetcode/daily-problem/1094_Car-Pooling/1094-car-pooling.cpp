#include <bits/stdc++.h>

using namespace std;

  bool mySort( vector<int> a, vector<int> b){
    return a.at(1) < b.at(1) ;
  }

class Solution {
public:

//----------------------------------------------------------- Challenge Solution

  inline void updateCapacityWithExits(  std::map<int,int>& stops, int& filled, int stop ){
    auto i = stops.begin();
    std::cout<< std::endl;
    while (i != stops.end() && i->first <= stop ){
      filled -= i->second;
      std::cout <<"\texit: "<< i->second << " removed: "<< i->first << std::endl;
      i = stops.erase(i);
    }
  }

  bool carPooling(vector<vector<int>>& trips, int capacity) {
    if( trips.size() == 1 ) return capacity >= trips.at(0).at(0);

    sort(trips.begin(), trips.end(), mySort );

    map<int,int> stops;
    int filled{0};

    for( auto trip : trips ){
      filled += trip.at(0);
      std::cout << "STOP: " << trip.at(1) << " ENTRY: " << trip.at(0);
      updateCapacityWithExits( stops, filled, trip.at(1) );
      std::cout << " FINAL: " << filled ;

      if( filled > capacity ) return false;

      std::map<int,int>::iterator nextStop = stops.find( trip.at(2) );
      if( nextStop != stops.end() ){
        nextStop->second += trip.at(0);
      } else {
        stops[trip.at(2)] = trip.at(0);
      }

      std::cout << " NEXT STOPS: "<< stops.size() << std::endl;
    }

    return true;
  }
//------------------------------------------------------------------------------
  void showCarPooling(vector<vector<int>> trips, int capacity) {
    std::cout << ( carPooling(trips, capacity) ? "True" : "False" ) << std::endl;
  }
};

int main(){
  std::cout <<"<<<<  LeetCode - 1094. Car Pooling  >>>>" << std::endl;
  Solution solution;
  solution.showCarPooling( {{4,3,4},{3,2,4},{1,8,9},{7,2,5}},14);

  return 0;
}