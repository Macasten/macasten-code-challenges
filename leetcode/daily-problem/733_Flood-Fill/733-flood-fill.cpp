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

  void fill( vector<vector<int>>& image, const int& sr, const int& sc, const int& newColor, const int& oldColor){
    //std::cout << "( "<< sr << " , " << sc << " ) => "<< image.at(sr).at(sc) <<" => ";
    image.at(sr).at(sc) = newColor;
    std::cout << image.at(sr).at(sc) << std::endl;
    if( sc > 0 && image.at(sr).at(sc-1) == oldColor ){
      fill( image, sr, (sc-1), newColor , oldColor);
    }

    if( sc < (image.at(0).size() - 1) && image.at(sr).at(sc+1) == oldColor){
      fill( image, sr, (sc+1), newColor , oldColor);
    }

    if( sr > 0  && image.at(sr-1).at(sc) == oldColor){
      fill( image, (sr-1), sc, newColor , oldColor);
    }

    if( sr < ( image.size() - 1 ) && image.at(sr+1).at(sc) == oldColor ){
      fill( image, (sr+1), sc, newColor , oldColor);
    }
  }
  vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
    int old_color = image.at(sr).at(sc);
    if( old_color != newColor ){
      fill(image, sr, sc, newColor, old_color);
    }
    return image;
  }
//------------------------------------------------------------------------------

  void showFloodFill( vector<vector<int>> image, int sr, int sc, int newColor){
    coutGrid( image , "Original");
    coutGrid( floodFill(image, sr, sc, newColor ), "Result" );
  }
};

int main(){

  std::cout <<"<<<<  LeetCode - 733. Flood Fills  >>>>" << std::endl;
  Solution solution;
  //solution.showFloodFill( {{1,4},{3,3}} , 1,1,0);
  solution.showFloodFill({{1,1,1},{1,1,0},{1,0,1}}, 1,1,2);
  solution.showFloodFill({{0,0,0},{0,1,1}}, 1,1,1);
  return 0;
}