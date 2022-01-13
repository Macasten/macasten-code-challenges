#include <bits/stdc++.h>

using namespace std;

void getLine(){
  std::string name;
  std::getline(std::cin,name);
  std::cout << name << " Restar " << std::endl;
}

class Solution {
public:

  int newData{0};

  void newGuessNumber( int n ){
    newData = std::rand()%n + 1;
  }
  int guess(int num){
    if( num < newData ) return 1;
    else if( num == newData ) return 0;
    else return -1;
  }


//----------------------------------------------------------- Challenge Solution
  int guessNumber(int n) {
    if( n == 1 ) return 1;
    int result = 1;
    int lower = 1;
    int higher = n;
    int test = n ;

    while ( true ){
      result = guess( test );
      if( result == 0 ) break;
      else if ( result == -1 ){
        higher = test;
      } else {
        lower = test;
      }
      test = lower + (higher - lower)/2;
    }

    return test;
  }
//------------------------------------------------------------------------------

  void showGuessNumber( int n ){
    newGuessNumber(n);
    std::cout << "GUESS: " << newData<< " == " << guessNumber( n ) << std::endl;
  }
};

int main(){

  std::cout <<"<<<<  LeetCode - 374. Guess Number Higher or Lower >>>>" << std::endl;
  srand (time(NULL));
  Solution solution;
  solution.showGuessNumber( 15000 );

  return 0;
}