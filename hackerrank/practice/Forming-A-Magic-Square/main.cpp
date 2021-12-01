#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'formingMagicSquare' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts 2D_INTEGER_ARRAY s as parameter.
 */

bool isMagicSquare( std::vector<std::vector<int>> ms ){

  if( ms[0][0]+ms[0][1]+ms[0][2] != 15 ) return false;
  if( ms[1][0]+ms[1][1]+ms[1][2] != 15 ) return false;
  if( ms[2][0]+ms[2][1]+ms[2][2] != 15 ) return false;

  if( ms[0][0]+ms[1][0]+ms[2][0] != 15 ) return false;
  if( ms[0][1]+ms[1][1]+ms[2][1] != 15 ) return false;
  if( ms[0][2]+ms[1][2]+ms[2][2] != 15 ) return false;

  if( ms[0][0]+ms[1][1]+ms[2][2] != 15 ) return false;
  if( ms[0][2]+ms[1][1]+ms[2][0] != 15 ) return false;

  return true;
}

const std::vector<std::vector<std::vector<int>>> MAGIC_SQUARES = {
  { {8,1,6},{3,5,7},{4,9,2} },
  { {6,1,8},{7,5,3},{2,9,4} },
  { {4,9,2},{3,5,7},{8,1,6} },
  { {2,9,4},{7,5,3},{6,1,8} },
  { {8,3,4},{1,5,9},{6,7,2} },
  { {4,3,8},{9,5,1},{2,7,6} },
  { {6,7,2},{1,5,9},{8,3,4} },
  { {2,7,6},{9,5,1},{4,3,8} }
};

inline uint calculateDistance( const int & x , const int & y){
  return x < y ? y-x : x-y ;
}

uint calculateDifferenceIfLessThanMax( const std::vector<std::vector<int>> &test , const std::vector<std::vector<int>> &ms , const uint &max ){
  uint result = 0;
  for(uint r = 0; r < 3; r++ ){
    for( uint c = 0 ; c < 3; c++ ){
      result += calculateDistance( test.at(r).at(c), ms.at(r).at(c) );
      if(result > max ) return max;
    }
  }
  return result;
}

int formingMagicSquare(vector<vector<int>> s) {
  uint output = UINT_MAX;
  for( size_t m = 0 ; m < MAGIC_SQUARES.size(); m++ ){
    uint result = calculateDifferenceIfLessThanMax( s , MAGIC_SQUARES.at(m), output );
    if( output > result ){
      output = result;
    }
  }
  return static_cast<int>(output);
}

void developing()
{
  std::cout << UINT_MAX << std::endl;

}
int main()
{
  //developing();
    ofstream fout(getenv("OUTPUT_PATH"));

    vector<vector<int>> s(3);

    for (int i = 0; i < 3; i++) {
        s[i].resize(3);

        string s_row_temp_temp;
        getline(cin, s_row_temp_temp);

        vector<string> s_row_temp = split(rtrim(s_row_temp_temp));

        for (int j = 0; j < 3; j++) {
            int s_row_item = stoi(s_row_temp[j]);

            s[i][j] = s_row_item;
        }
    }

    int result = formingMagicSquare(s);

    fout << result << "\n";

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}
