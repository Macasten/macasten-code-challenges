#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the 'timeConversion' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts STRING s as parameter.
 */

inline std::string format_account_number(int acct_no) {
  ostringstream out;
  out << std::internal << std::setfill('0') << std::setw(2) << acct_no;
  return out.str();
}
string timeConversion(string s) {
  // hh:mm:ssAM
  std::string timeTag = s.substr(8,2);
  int hours = std::stoi( s.substr(0,2) );

  std::string output ="";

  if( timeTag == "AM" && hours < 11){
    return s.substr(0,8);
  } else if ( timeTag == "AM" && hours > 11) {
    return ( format_account_number(hours-12) + s.substr( 2, (s.size() - 4 )) );
  } else if ( timeTag == "PM" && hours > 11 ){
    return s.substr(0,8);
  } else {
    return format_account_number(hours+12) + s.substr( 2, (s.size() - 4 ));
  }

}

int main()
{

  std::cout << timeConversion("04:05:05AM") << std::endl;
  std::cout << timeConversion("04:05:05PM") << std::endl;
  std::cout << timeConversion("01:05:05PM") << std::endl;
  std::cout << timeConversion("11:00:10PM") << std::endl;
  std::cout << timeConversion("13:05:05AM") << std::endl;
  std::cout << timeConversion("12:05:05PM") << std::endl;
    // ofstream fout(getenv("OUTPUT_PATH"));

    // string s;
    // getline(cin, s);

    // string result = timeConversion(s);

    // fout << result << "\n";

    // fout.close();

    // return 0;
}
