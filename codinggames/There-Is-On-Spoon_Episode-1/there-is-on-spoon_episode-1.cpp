#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * Don't let the machines win. You are humanity's last hope...
 **/

inline void printNoNeighbor(string end = ""){
  cout << "-1 -1" << end;
}

inline void printNode( size_t x, size_t y ){
  cout<< x << " " << y << " ";
}

inline void  printRigthNeighbor( vector<string> &grid, const size_t &x, const size_t &y){
  for( size_t r = x+1; r < grid.at(y).size(); r++){
    if( grid.at(y).at(r) == '0' ){
      cout << r << " " << y << " ";
      return;
    }
  }
  printNoNeighbor(" ");
}

inline void printBottomNeighbor( vector<string> &grid, const size_t &x, const size_t &y){
  for( size_t b = y+1; b < grid.size(); b++){
    if( grid.at(b).at(x) == '0' ){
      cout << x << " " << b;
      return;
    }
  }
  printNoNeighbor();
}

void solution( vector<string> grid ){

  for( size_t y = 0 ; y < grid.size(); y++ ){
    for( size_t x = 0; x < grid.at(0).size(); x++ ){
      if( grid.at(y).at(x) == '0' ){
        printNode( x, y );
        printRigthNeighbor( grid, x, y);
        printBottomNeighbor( grid, x, y);
        cout << endl;
      }
    }
  }
}

int main(){
  solution( {"00", "0."});
  return 0;
}

int condingGameMain()
{
    int width; // the number of cells on the X axis
    cin >> width; cin.ignore();
    int height; // the number of cells on the Y axis
    cin >> height; cin.ignore();
    vector<string> grid = {};
    for (int i = 0; i < height; i++) {
        string line;
        getline(cin, line); // width characters, each either 0 or .
        grid.push_back(line);
        cerr << line << endl;
    }

    // Write an action using cout. DON'T FORGET THE "<< endl"
    // To debug: cerr << "Debug messages..." << endl;
    for( size_t y = 0; y < height; y++ ){
        for( size_t x = 0; x < width ; x++ ){
            if( grid.at(y).at(x) == '0' ){
                cout << x << " " << y << " ";
                if(  x == (width - 1) || y == (height -1) ){
                    cout << "-1 -1 -1 -1";
                } else {
                    cout << (x+1) << " "<< y << " "<< x << " "<< (y+1); 
                }

                cout<<endl;
            }
        }
    } 


    // Three coordinates: a node, its right neighbor, its bottom neighbor
    //cout << "0 0 1 0 0 1" << endl;
}