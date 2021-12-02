#include <bits/stdc++.h>


using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'pickingNumbers' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts INTEGER_ARRAY a as parameter.
 */

int pickingNumbers(vector<int> a) {
  std::sort(a.begin(), a.end());
  int output {0};
  for( size_t i = 0 ; i < a.size(); i++ ){
    int count = 0;
    int element = a[i];
    for( size_t j = i; j< a.size(); j++ ){
      a[j] -= element;
      if( a[j] == 0 || a[j] == 1 ){
        count++;
      }
      if(a[j] == 0)
        i = j;
    }

    if( count > output ) output = count;

  }
  return output;
}

// int pickingNumbersI(vector<int> &a) {
//   return pickingNumbers(a);
// }
// int pickingNumbersII(vector<int> &&a) {
//   return pickingNumbers(a);
// }

int main()
{
  std::cout << pickingNumbers({2,2}) << std::endl;
  std::cout << pickingNumbers({2,3}) << std::endl;
  std::cout << pickingNumbers({2,3,4}) << std::endl;
  std::cout << pickingNumbers({2,3,4,5}) << std::endl;
  std::cout << pickingNumbers({2,3,4,5,2,2,2}) << std::endl;
    // ofstream fout(getenv("OUTPUT_PATH"));

    // string n_temp;
    // getline(cin, n_temp);

    // int n = stoi(ltrim(rtrim(n_temp)));

    // string a_temp_temp;
    // getline(cin, a_temp_temp);

    // vector<string> a_temp = split(rtrim(a_temp_temp));

    // vector<int> a(n);

    // for (int i = 0; i < n; i++) {
    //     int a_item = stoi(a_temp[i]);

    //     a[i] = a_item;
    // }

    // int result = pickingNumbers(a);

    // fout << result << "\n";

    // fout.close();

    // return 0;
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
