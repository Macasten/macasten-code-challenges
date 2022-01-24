#include <bits/stdc++.h>

using namespace std;

class Solution {
public:

//----------------------------------------------------------- Challenge Solution
  string capitalizeTitle(string title) {
    int first{0};
    int last{0};
    int count{0};

    for( size_t i = 0; i < title.length() ; i++ ){
      if( title.at( last ) == ' ' ){
        first = i;
      }

      if( title.at(i) == ' ' ){
        if( count > 2){
          title.at(first) = toupper(title.at( first ));
        }
        count = 0;
      } else {

        title.at(i) = tolower( title.at(i));
        count++;
      }
      last = i;
    }

    if( count > 2){
      title.at(first) = toupper(title.at( first ));
    }

    return title;
  }
//------------------------------------------------------------------------------

  void showCapitalizeTitle( string title ){
    std::cout << "---------- NEW CASE ----------" << std::endl;
    std::cout <<"Original : " << title << std::endl;
    std::cout <<"Result   : " << capitalizeTitle( title )<< std::endl;
  }
};

int main(){

  std::cout <<"<<<<  LeetCode - 2129. Capitalize the Title >>>>" << std::endl;
  Solution solution;
  solution.showCapitalizeTitle("capiTalIze tHe titLe");
  // solution.showCapitalizeTitle("First leTTeR of EACH Word");
  // solution.showCapitalizeTitle("i lOve leetcode");

  return 0;
}