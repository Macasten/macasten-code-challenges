#include <bits/stdc++.h>

using namespace std;


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
  bool validMountainArray(vector<int>& arr) {
    if( arr.size() < 3 ) return false;

    std::vector <int>::iterator last = arr.begin();
    std::vector <int>::iterator next = arr.begin() + 1;
    for (; next != arr.end(); next++) {
      if( *last >= *next ) break;
      last++;
    }


    if( last == arr.begin() || next == arr.end() || *last == *next ) return false;

    last++;
    next++;

    for (; next != arr.end(); next++) {
      if( *last <= *next ) return false;
      last++;
    }
    return true;
  }
//------------------------------------------------------------------------------
  void showValidMountainArray(vector<int> arr) {
    std::cout << "----- NEW TEST -----" << std::endl;
    coutVector( arr , "Array");
    std::cout << ( validMountainArray(arr) ? "Valid Mountain" : "NOT Mountain") << std::endl;
  }
};

int main(){

  std::cout <<"<<<<  LeetCode - 941. Valid Mountain Array >>>>" << std::endl;
  Solution solution;
  solution.showValidMountainArray({1,2,3,2,1});
  solution.showValidMountainArray({1,2,3,3,2,1});
  solution.showValidMountainArray({1,2,3,3,5,2,1});
  solution.showValidMountainArray({1,2,3});
  solution.showValidMountainArray({3,2,1});
  solution.showValidMountainArray({});
  solution.showValidMountainArray({3,2,1,2,3});
  return 0;
}