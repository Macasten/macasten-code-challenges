#include <bits/stdc++.h>

using namespace std;

class Solution {
public:

//----------------------------------------------------------- Challenge Solution
  void stringToVectorInt( std::vector<int>& ver, string& verS ){
    size_t pos = 0;
    while ((pos = verS.find(".")) != string::npos) {
      ver.push_back( std::stoi(verS.substr(0, pos)) );
      verS.erase(0, pos + 1);
    }
    ver.push_back( std::stoi(verS) );
  }

  inline bool hasNoZeroDigit( std::vector<int>& ver, int& startIndex ){
    while (startIndex < ver.size()) {
      if(ver.at(startIndex) > 0 ) return true;
      startIndex++;
    }
    return false;
  }

  int compareVersion(string version1, string version2) {
    
    std::vector<int> vec1;
    stringToVectorInt(vec1, version1);
    std::vector<int> vec2;
    stringToVectorInt(vec2, version2);

    int i = 0;
    int minSize = std::min( vec1.size(), vec2.size() );
    while (i < minSize ) {
      if( vec1.at(i) > vec2.at(i) ) return 1;
      else if( vec1.at(i) < vec2.at(i) ) return -1;
      else i++;
    }

    if( vec1.size() == vec2.size() ) return 0;
    else if( vec1.size() > vec2.size() ) return hasNoZeroDigit( vec1, i ) ? 1 : 0;
    else return hasNoZeroDigit( vec2, i ) ? -1 : 0;

  }
//------------------------------------------------------------------------------
  void showCompareVersion(string version1, string version2){
    std::cout << "----- New Test -----" << std::endl;
    switch ( compareVersion(version1, version2) ) {
      case -1:
        std::cout << version1 << " < " << version2 << std::endl;
        break;
      case 0:
        std::cout << version1 << " = " << version2 << std::endl;
        break;
      case 1:
      std::cout << version1 << " > " << version2 << std::endl;
        break;
      default:
        std::cout << "Unknown value" << std::endl;
        break;
    }
  }
};

int main(){

  std::cout <<"<<<<  LeetCode - 165. Compare Version Numbers >>>>" << std::endl;
  Solution solution;
  solution.showCompareVersion("1", "2");
  solution.showCompareVersion("1", "1.0");
  solution.showCompareVersion("1.0.1", "1.0.1.0.0.2");
  solution.showCompareVersion("1.0.1", "1.0.1.0.0.0");

  return 0;
}