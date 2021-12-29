#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class Difference {
    private:
    vector<int> elements;
  
  	public:
  	int maximumDifference;

    // Add your code here
	Difference( vector<int> elem ): elements(elem){
        maximumDifference = -1;
    };
    
    inline int absolute( const int &a , const int& b ){
        // int output{a-b};
        // if( output < 0 ) output *= -1;
        // return output;
        return std::abs( (a-b) );
    }
    
    void computeDifference(){
        
        for( size_t i = 0; i < (elements.size() - 1); i++ ){
            for (size_t j = (i+1); j < elements.size() ; j++) {
                int result = absolute(elements.at(i),elements.at(j) );
                if( result > maximumDifference) maximumDifference = result;
            }
        }
    }

}; // End of Difference class

int main() {
    int N;
    cin >> N;
    
    vector<int> a;
    
    for (int i = 0; i < N; i++) {
        int e;
        cin >> e;
        
        a.push_back(e);
    }
    
    Difference d(a);
    
    d.computeDifference();
    
    cout << d.maximumDifference;
    
    return 0;
}