#include <bits/stdc++.h>

// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
private:
  std::vector<bool> versionBad = {};
public:

  Solution( uint versionCount , uint firstVersionBad ){
    for( uint i = 1 ; i <= versionCount ; i ++){
      versionBad.push_back( (i >= firstVersionBad) );
    }

  }

  bool isBadVersion( int index ){
    return versionBad.at( static_cast<uint>( index - 1 ) );
  }

//----------------------------------------------------------- Challenge Solution

  int firstBadVersion(int n) {
      int version{n};
      if( !isBadVersion((version-1)) ) return version;
      version /= 2;
      int minLast{n};
      while(true){

          if( isBadVersion(version) ){
              if( !isBadVersion((version-1)) ) return version;
              minLast = version;
              version /= 2;
          } else {
              version += ((minLast-version)/2);
          }
      }
    }
//------------------------------------------------------------------------------
};

int main(){
  Solution solution( 10, 7 );
  std::cout << solution.firstBadVersion(10) << std::endl;
  return 0;
}