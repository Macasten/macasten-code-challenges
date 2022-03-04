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

template<typename T>
inline void coutVector( std::vector<T> vec, std::string label = "Vector" ){
  std::cout << label << " : { ";
  if( vec.empty() ){
    std::cout << "EMPTY }" << std::endl;
    return;
  }
  for( size_t i = 0 ; i < (vec.size()-1); i++ ){
    std::cout << vec.at(i) << "; " ;
  }
  std::cout<< vec.back() << " }"<< std::endl;
}

class Solution {
public:

//----------------------------------------------------------- Challenge Solution
  void findCombinationSum(
    std::vector<int>& candidates,
    int target,
    std::vector<vector<int>>& res,
    std::vector<int>& r, int i)
  {
    if(target == 0) {
      res.push_back(r);
      return;
    }

    while(i < candidates.size() && target - candidates[i] >= 0){
      r.push_back(candidates[i]);
      findCombinationSum(candidates,target - candidates[i],res,r,i);
      ++i;
      r.pop_back();
    }
  }
  vector<vector<int>> combinationSum(vector<int>& candidates, int target) {

    // Ordenar, remover duplicados e remover numero maiores que o Target
    coutVector( candidates , "Original");
    std::set<int> s;
    auto size = candidates.size();
    for( auto i = 0u; i < size; ++i ){
      if( target >= candidates.at(i) )
        s.insert( candidates.at(i) );
    }
    candidates.assign( s.begin(), s.end() );

    if( candidates.size() == 0 ) return {};

    // Encontrar combinacao
    std::vector<int> aux;
    std::vector<vector<int> > output;
    findCombinationSum(candidates,target,output,aux,0);
    return output;
  }
//------------------------------------------------------------------------------
  void showCombinationSum( vector<int> candidates, int target){
    std::cout << std::endl << "----- New Test -----" << std::endl;
    coutGrid( combinationSum(candidates, target), "Result" );
  }
};

int main(){

  std::cout <<"<<<<  LeetCode - 39. Combination Sum >>>>" << std::endl;
  Solution solution;

  solution.showCombinationSum( {6,5,4,3,2,1,6,5,4,3,2,1}, 4 );
  solution.showCombinationSum( {6,5,4,3,2,1,6,5,4,3,2,1}, 0 );

  return 0;
}