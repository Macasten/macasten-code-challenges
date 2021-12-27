#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
// Maximum number of digits in output
#define MAX 200
 
// This function multiplies x with the number
// represented by res[].
// res_size is size of res[] or number of digits in the
// number represented by res[]. This function uses simple
// school mathematics for multiplication.
// This function may value of res_size and returns the
// new value of res_size
int multiply(int x, int res[], int res_size)
{
  int carry = 0;  // Initialize carry

  // One by one multiply n with individual digits of res[]
  for (int i=0; i<res_size; i++)
  {
    int prod = res[i] * x + carry;

    // Store last digit of 'prod' in res[]
    res[i] = prod % 10;

    // Put rest in carry
    carry  = prod/10;
  }

  // Put carry in res and increase result size
  while (carry) {
    res[res_size] = carry%10;
    carry = carry/10;
    res_size++;
  }
  return res_size;
}

/*
 * Complete the 'extraLongFactorials' function below.
 *
 * The function accepts INTEGER n as parameter.
 */

void extraLongFactorials(int n) {
  int res[MAX];

  // Initialize result
  res[0] = 1;
  int res_size = 1;

  // Apply simple factorial formula n! = 1 * 2 * 3 * 4...*n
  for (int x=2; x<=n; x++)
    res_size = multiply(x, res, res_size);


  for (int i=res_size-1; i>=0; i--)
    cout << res[i];
  cout<< endl;
}

int main(){

  extraLongFactorials(100);

  return 0;
}

int hackerRankmain()
{
    string n_temp;
    getline(cin, n_temp);

    int n = stoi(ltrim(rtrim(n_temp)));

    extraLongFactorials(n);

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
