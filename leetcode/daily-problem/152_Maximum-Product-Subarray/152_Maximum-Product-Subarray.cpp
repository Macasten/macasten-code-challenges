#include <iostream>
#include <vector>
#include <functional>

class Solution {
public:
  Solution(){}
  inline void update( int &prodMax, const int &prodAll, const int& prodLeft ){
    if( prodAll != prodLeft && prodAll < 0 ){
      // std::cout << "prodAll:  "<< prodAll << std::endl;
      // std::cout << "prodLeft:  "<< prodLeft << std::endl;

      int result = prodAll/prodLeft;
      // std::cout << "result:  "<< result << std::endl;
      if( prodMax < result ){
        prodMax = result;
      }
    }
  }

  int maxProduct(std::vector<int>& nums) {

    int output = INT32_MIN;
    int subLProd = 1;
    int subProd = 1;
    bool start = true;
    for(auto element : nums ){

      if( element > output){
        output = element;
      }

      if ( element == 0 ){
        update( output, subProd, subLProd );
        subProd = 1;
        subLProd = 1;
        start = true;
      } else {

        subProd *= element;
        if( subProd > output){
          output = subProd;
        }

        if( start && element < 0 ){
          start = false;
          subLProd = subProd;
          // std::cout << "New SubLProd: "<< subLProd << std::endl;
        }

      }
      // std::cout << "-> : "<< output  << std::endl;
    }
    update( output, subProd, subLProd );
    return output;

  }

  int maxProductTest(std::vector<int>&& nums) {
    return maxProduct( nums );
  }

};


int main(int argc, char const *argv[])
{
  Solution mySolution;
  std::cout << mySolution.maxProductTest({1,2})             << " = " << 2 <<std::endl;
  std::cout << mySolution.maxProductTest({-2})              << " = " << - 2 <<std::endl;
  std::cout << mySolution.maxProductTest({2,3,-2,4})        << " = " << 6 <<std::endl;
  std::cout << mySolution.maxProductTest({-2,0,-1})         << " = " << 0 <<std::endl;
  std::cout << mySolution.maxProductTest({-2,1,2,2,0,-1})   << " = " << 4 <<std::endl;
  std::cout << mySolution.maxProductTest({-2,1,2,2,-1,0,-1})<< " = " << 8 <<std::endl;
  std::cout << mySolution.maxProductTest({2,-5,-2,-4,3})    << " = " << 24 <<std::endl;
  std::cout << mySolution.maxProductTest({2,-5,-2,-4,3,0,3,-5,-2,-4,3,})    << " = " << 30 <<std::endl;
  return 0;
}
