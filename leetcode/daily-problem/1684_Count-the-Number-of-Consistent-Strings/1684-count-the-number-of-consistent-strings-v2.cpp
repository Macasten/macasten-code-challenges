#include <bits/stdc++.h>

using namespace std;

template<typename T>
inline void coutVector( std::vector<T> vec, std::string label = "Vector" ){
  std::cout << label << " : { ";
  for( size_t i = 0 ; i < (vec.size()-1); i++ ){
    std::cout << vec.at(i) << "; " ;
  }
  std::cout<< vec.back() << " }"<< std::endl;
}

class Solution {
public:

//----------------------------------------------------------- Challenge Solution
  inline bool isConsistentString( string& allow, string word ){
    while (!word.empty())
    {
      char letter = word.front();
      if( allow.find( letter ) == std::string::npos ) return false;
      word.erase(std::remove(word.begin(), word.end(), letter ), word.end());
    }
    return word.empty();
  }

  int countConsistentStrings(string allowed, vector<string>& words) {

    int count{0};
    for (auto &&i : words )
    {
      if( isConsistentString( allowed , i ) ) count++;
    }

    return count;
  }
//------------------------------------------------------------------------------
  void showCountConsistentStrings(string allowed, vector<string> words) {
    std::cout << "----- NEW TEST -----" << std::endl;
    std::cout << "Allowed: " << allowed << std::endl;
    coutVector( words , "Words");
    int result = countConsistentStrings( allowed, words);
    std::cout << "Number of allowed words: "<< result << std::endl;
  }
};

int main(){

  std::cout <<"<<<<  LeetCode - 1684. Count the Number of Consistent Strings >>>>" << std::endl;
  Solution solution;

  solution.showCountConsistentStrings( "ab", {"ad","bd","aaab","baa","badab"});

  return 0;
}