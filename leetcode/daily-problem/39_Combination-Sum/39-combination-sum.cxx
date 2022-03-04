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

  class Next {
  private:
    int* _target;
    std::vector<int> _seq{};
    int _amout{0};
  public:
    Next(){};
    Next(int* target):_target(target) {}
    Next( Next* next ){
      _target = next->_target;
      _seq = next->_seq;
      _amout = next->_amout;
    }

    ~Next() {}

    bool add( int num ){
      _amout += num;
      if( _amout > *_target )
        return false;
      // std::cout << "Add: " << _amout <<" - Target: "<< *_target << std::endl;
      _seq.push_back(num);
      //copy(_seq.begin(), _seq.end(), ostream_iterator<int>(std::cout, " "));
      //std::cout << std::endl;
        return true;
    }

    bool isFinal( ){ return _amout == *_target; }
    std::vector<int> getSequence( ){
      return _seq;
    }
    int getAmout(){return _amout; }
  };

  class CombinationSums {
  private:
    std::vector<std::vector<int>> _combi;
  public:
    CombinationSums(/* args */) {}
    ~CombinationSums() {}

    void add( std::vector<int> newCobin ){
      _combi.push_back(newCobin);
    }

    std::vector<std::vector<int>> getCombinaton(){
      return _combi;
    };

    int size() { return _combi.size(); }

  };


public:
  void getAlldifferect(
    CombinationSums& output,
    vector<int>& candidates,
    vector<int>::iterator top,
    Next* next ){

    Next* nextNext = next;
    for( auto it = top ; it >= candidates.begin(); it--){
      //std::cout << "Para " << *it << " "<< nextNext->getAmout() << std::endl;
      
      nextNext = new Next( next );
      if( nextNext->add(*it) ){
        if( nextNext->isFinal() ){
          output.add( nextNext->getSequence());
        } else {
          getAlldifferect( output, candidates, it , nextNext );
        }
      }
    }
  }

  /**
   * Remove todos os numeros maiores que o Target.
   */
  void eraseBiggerThan( vector<int>& candidates, int target){
    vector<int> :: iterator it;
    candidates.erase(
      remove_if( candidates.begin(), candidates.end(), bind2nd(greater<int>(), target )),
      candidates.end() );
  }

  vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    CombinationSums output;
    // Remover numeros maiores que oo target
    eraseBiggerThan( candidates, target );
    getAlldifferect( output, candidates , (candidates.end() -1), new Next(&target) );

    return output.getCombinaton();
  }

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