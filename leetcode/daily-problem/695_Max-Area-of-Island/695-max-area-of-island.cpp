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

class Solution {
public:

//----------------------------------------------------------- Challenge Solution
  int rowSize{0};
  int columnSize{0};

  void calcuteAreaOfIstland( vector<vector<int>>& grid, const int& sr, const int& sc, uint& area ){
    //std::cout << "( "<< sr << " , " << sc << " ) => "<< image.at(sr).at(sc) <<" => ";
    grid.at(sr).at(sc) = 2;
    area++;
    if( sc > 0 && grid.at(sr).at(sc-1) == 1 ){
      calcuteAreaOfIstland( grid, sr, (sc-1), area);
    }

    if( sc < (columnSize - 1) && grid.at(sr).at(sc+1) == 1){
      calcuteAreaOfIstland( grid, sr, (sc+1), area);
    }

    if( sr > 0  && grid.at(sr-1).at(sc) == 1){
      calcuteAreaOfIstland( grid, (sr-1), sc, area);
    }

    if( sr < ( rowSize - 1 ) && grid.at(sr+1).at(sc) == 1 ){
      calcuteAreaOfIstland( grid, (sr+1), sc, area);
    }
  }
  int maxAreaOfIsland(vector<vector<int>>& grid) {
    uint output{0};
    uint istlandArea{0};
    rowSize = grid.size();
    columnSize = grid.front().size();

    for( size_t row = 0 ;  row < rowSize; row++ ){
      for( size_t column = 0; column < columnSize; column++ ){
        if( grid.at(row).at(column) == 1 ){
          calcuteAreaOfIstland( grid , row, column, istlandArea );
          if( istlandArea > output ) output = istlandArea;
          istlandArea = 0;
        }
      }
    }
    return output;
  }
//------------------------------------------------------------------------------
  void ShowMaxAreaOfIsland( vector<vector<int>> grid){
    coutGrid( grid );
    std::cout << "Max Island Size: "<< maxAreaOfIsland( grid ) << std::endl;
  }
};

int main(){

  std::cout <<"<<<<  LeetCode - 695. Max Area of Island  >>>>" << std::endl;
  Solution solution;
  solution.ShowMaxAreaOfIsland({
    {0,0,1,0,0,0,0,1,0,0,0,0,0},
    {0,0,0,0,0,0,0,1,1,1,0,0,0},
    {0,1,1,0,1,0,0,0,0,0,0,0,0},
    {0,1,0,0,1,1,0,0,1,0,1,0,0},
    {0,1,0,0,1,1,0,0,1,1,1,0,0},
    {0,0,0,0,0,0,0,0,0,0,1,0,0},
    {0,0,0,0,0,0,0,1,1,1,0,0,0},
    {0,0,0,0,0,0,0,1,1,0,0,0,0}
  });

  return 0;
}