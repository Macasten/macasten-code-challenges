#include <bits/stdc++.h>

using namespace std;

/**
 * Definition for singly-linked list.
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* buildListNode( std::vector<int>& list ){
  ListNode* output = new ListNode( list.at(0) );
  ListNode* next = output;

  for( size_t i = 1; i < list.size(); i++) {
    next->next = new ListNode( list.at(i) );
    next = next->next;
  }
  return output;
}

class Solution {
public:
//----------------------------------------------------------- Challenge Solution
  std::vector<int*> access = {};
  Solution(ListNode* head) {
    while (head != nullptr)
    {
      access.push_back( &head->val );
      head = head->next;
    }
  }

  int getRandom() {
    return *access.at( static_cast<uint>( rand()%access.size() ) );
    //return vector.at( (size_t)( rand() );
  }
//------------------------------------------------------------------------------

  static void showSolution( std::vector<int> vec ){
    Solution solution( buildListNode( vec ) );
    for( size_t call = 0; call < 10 ; call++){
      std::cout << "Call "<< call <<"º: "<< solution.getRandom() << std::endl;
    }
  }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */

int main(){
  srand( (unsigned)time( NULL ) );

  std::cout <<"<<<<  LeetCode - 382. Linked List Random Node  >>>>" << std::endl;
  Solution::showSolution({-11,2,-63,4});

  return 0;
}