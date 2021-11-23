#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'sockMerchant' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER n
 *  2. INTEGER_ARRAY ar
 */

int sockMerchant(int n, vector<int> ar) {

  int output{0};

  std::map<int,bool> oldSocks;
  std::map<int,bool>::iterator it;

  for( int i=0 ; i < n ; i++ ){
    int color = ar.at(i);
    it = oldSocks.find( color );
    if( it == oldSocks.end() ){
      oldSocks.insert( std::pair<int,bool>( color, false) );
      //std::cout << "add Color Sock: "<< it->first << std::endl;
    } else if( it->second == true ){
      it->second = false;
      //std::cout << it->first<< " turn to old" << std::endl;
    } else {
      it->second = true;
      output++;
      //std::cout << "Pairs: " <<output<< " - " << it->first<< " turn to even" << std::endl;
    }
  }
  return output;
}


int sockMerchantWithList( vector<int> ar) {
  return sockMerchant( static_cast<int>(ar.size()), ar );
}
void macastenStartPoint(){

  std::cout << sockMerchantWithList({1,1} ) << std::endl;
  std::cout << sockMerchantWithList({1,1,1,1} ) << std::endl;
  std::cout << sockMerchantWithList({1,1,2,2} ) << std::endl;
  std::cout << sockMerchantWithList({1,1,2,3} ) << std::endl;
  // std::cout << "Macasten start Point" << std::endl;
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

void hackerRankStartPoint()
{
  ofstream fout(getenv("OUTPUT_PATH"));

  string n_temp;
  getline(cin, n_temp);

  int n = stoi(ltrim(rtrim(n_temp)));

  string ar_temp_temp;
  getline(cin, ar_temp_temp);

  vector<string> ar_temp = split(rtrim(ar_temp_temp));

  vector<int> ar(n);

  for (int i = 0; i < n; i++) {
    int ar_item = stoi(ar_temp[i]);

    ar[i] = ar_item;
  }

  int result = sockMerchant(n, ar);

  fout << result << "\n";

  fout.close();

}

int main()
{
  //hackerRankStartPoint();
  macastenStartPoint();
  return 0;
}