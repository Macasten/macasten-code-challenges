#include <bits/stdc++.h>

using namespace std;

template<typename T>
void coutGrid( vector<vector<T>> grid , std::string label = "Grid" ){
  if( grid.size() == 0 ){
    std::cout << label<< ": { EMPTY }" << std::endl;
    return;
  }
  std::cout << label<< ": {" << std::endl;
  for( auto &row : grid ){
    for( size_t i = 0 ; i < (row.size()-1); i++ ){
      std::cout << row.at(i) << " " ;
    }
    std::cout<< row.back()<< std::endl;
  }
  std::cout << "}" << std::endl;
}

constexpr char islandArea = '1';
class Solution {
public:

//----------------------------------------------------------- Challenge Solution

  int rowSize{0};
  int columnSize{0};

  void markIsland( vector<vector<char>>& grid, const int& sr, const int& sc ){
    //std::cout << "( "<< sr << " , " << sc << " ) => "<< image.at(sr).at(sc) <<" => ";
    grid.at(sr).at(sc) = 'c';
    if( sc > 0 && grid.at(sr).at(sc-1) == islandArea ){
      markIsland( grid, sr, (sc-1));
    }

    if( sc < columnSize && grid.at(sr).at(sc+1) == islandArea){
      markIsland( grid, sr, (sc+1));
    }

    if( sr > 0  && grid.at(sr-1).at(sc) == islandArea){
      markIsland( grid, (sr-1), sc);
    }

    if( sr < rowSize && grid.at(sr+1).at(sc) == islandArea ){
      markIsland( grid, (sr+1), sc);
    }
  }

  int numIslands(vector<vector<char>>& grid) {
    uint output{0};
    rowSize = grid.size() - 1;
    columnSize = grid.front().size() - 1 ;

    for( size_t row = 0 ;  row <= rowSize; row++ ){
      for( size_t column = 0; column <= columnSize; column++ ){
        if( grid.at(row).at(column) == islandArea ){
          markIsland( grid , row, column );
          output++;
        }
      }
    }
    return output;
  }
//------------------------------------------------------------------------------
  void ShowNumIslands(vector<vector<char>> grid) {
    coutGrid( grid );
    std::cout << "Number of Islands: "<< numIslands( grid ) << std::endl;
  }
};

int main(){

  std::cout <<"<<<<  LeetCode - 200. Number of Islands  >>>>" << std::endl;
  Solution solution;
  solution.ShowNumIslands({
    {'1','1','0','0','0'},
    {'1','1','0','0','0'},
    {'0','0','1','0','0'},
    {'0','0','0','1','1'}
  });

  return 0;
}