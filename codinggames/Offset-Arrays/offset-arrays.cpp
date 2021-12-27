#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <bits/stdc++.h>

using namespace std;

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/



class OffsetArray
{
private:
  string pAssignment;
  int pFirstIndex;
  vector<string> pValues = {};

public:

  inline void initValues( string &assignment , vector<string> &values ){
    string valuesList = assignment.substr( assignment.find("= ") + 2, assignment.size() );
    stringstream ss(valuesList);
    string value;
    while (ss >> value) {
      values.push_back(value);
    }
  }

  inline static string getArrayName( string &assignment ){
    return assignment.substr( 0 , assignment.find("[") );
  }

  inline static int getOffset( string &assignment ){
    return std::stoi( assignment.substr( assignment.find("[")+1, assignment.find("..")-(assignment.find("[")+1) ) );
  }

  OffsetArray( string assignment ){
    pAssignment = getArrayName(assignment);
    pFirstIndex = getOffset(assignment);
    initValues( assignment, pValues );

  }
  ~OffsetArray(){};

  string getValue( int index ){
    return pValues.at( (index-pFirstIndex) );
  };

  bool isArrayAssignment( const string &id ){
    return pAssignment == id;
  }

  friend std::ostream & operator<<(std::ostream & os , const OffsetArray& theArray);

};

std::ostream & operator<<(std::ostream & os , const OffsetArray& theArray) {
  os << "Offset  : " << theArray.pFirstIndex << "\n";
  os << "Array Id: " << theArray.pAssignment << "\n";
  os << "Values  : ";
  for(auto elem : theArray.pValues ) {
    os<<elem<< "; ";
  }
  os <<"\n";
  return os;
};

bool is_integer( const std::string& testString ){
  auto start = testString.begin();
  if( testString[0] == '-' ){
    start++;
  }

  return !testString.empty() && std::find_if(start,
    testString.end(), [](unsigned char c) { return !std::isdigit(c); }) == testString.end();
}

class OffserArrays
{
private:
  /* data */
  vector<OffsetArray> pOffsetArray = {};
public:
  OffserArrays(/* args */){};
  ~OffserArrays(){};

  void addAssignment( string assignment ){
    pOffsetArray.push_back( OffsetArray( assignment ) );
  }

  inline int getIndex( string request ){
    std::cout << "request "<< request << std::endl;
    return std::stoi( request );
  }
  inline string getBetweenBracktes( const string& request ){
    return request.substr(
      request.find("[") + 1,
      (request.find_last_of("]") - request.find("[") - 1)
    );
  }

  inline string getValue( const string& arrayID, const int& valueIndex ){
    for( auto ar : pOffsetArray ){
      if( ar.isArrayAssignment(arrayID) ){
        cout << ar ;
        return ar.getValue( valueIndex );
      }
    }
    return "";
  }

  string newRequest( string request ){
    string arrarID = OffsetArray::getArrayName( request );
    string betweenBracktes = getBetweenBracktes( request );
    std::cout << betweenBracktes << std::endl;
    //return "";
    int requestIndex {0};
    if( is_integer(betweenBracktes) ){
      requestIndex = getIndex( betweenBracktes );
    } else {
      requestIndex = getIndex( newRequest( betweenBracktes ) );
    }
    std::cout << requestIndex << std::endl;
    return getValue( arrarID, requestIndex );
  }
};



int main(){
  //solution( {"00", "0."});
  OffserArrays arrays;
  std::cout << "Main" << std::endl;
  std::cout << "Assinment 1" << std::endl;
  arrays.addAssignment( "ARR1[-1..2] = 1 2 3 4" );
  std::cout << "Assinment 2" << std::endl;
  arrays.addAssignment( "ARR2[5..9] = 5 6 7 8 9" );
  std::cout << "Assinment 3" << std::endl;
  arrays.addAssignment( "ARR3[0..3] = 1 3 3 7" );

  std::cout << "Request 1" << std::endl;
  //cout << arrays.newRequest("ARR2[5]") << endl;
  cout << arrays.newRequest("ARR1[0]") << endl;
  cout << arrays.newRequest("ARR3[ARR3[2]]") << endl;
  return 0;
}

int condingGameMain()
{
    int n;
    cin >> n; cin.ignore();
    for (int i = 0; i < n; i++) {
        string assignment;
        getline(cin, assignment);
        cerr << assignment << endl;
    }
    string x;
    getline(cin, x);

    // Write an answer using cout. DON'T FORGET THE "<< endl"
    // To debug: cerr << "Debug messages..." << endl;

    cout << "0" << endl;
  return 0;
}