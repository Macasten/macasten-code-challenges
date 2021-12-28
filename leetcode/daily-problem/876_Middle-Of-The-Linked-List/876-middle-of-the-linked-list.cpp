#include <bits/stdc++.h>
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

class Solution {
public:
  ListNode* buildListNode( std::vector<int> list ){
    ListNode* output = new ListNode( list.at(0) );
    ListNode* next = output;

    for( size_t i = 1; i < list.size(); i++) {
      next->next = new ListNode( list.at(i) );
      next = next->next;
    }
    return output;
  }

  void showMiddleNode( std::vector<int> list ) {
    std::cout << middleNode( buildListNode(list) )->val << std::endl;
  }
//----------------------------------------------------------- Challenge Solution
  inline size_t nodeCount( ListNode* head ){
    size_t count{0};
    while( head != nullptr ){
      count++;
      head = head->next;
    }
    return count;
  }

  inline ListNode* getNode( ListNode* head, size_t index){
    while (index > 0)
    {
      if(head == nullptr ){
        break;
      }
      head = head->next;
      index--;
    }
    return head;
  }

  ListNode* middleNode(ListNode* head) {

    ListNode* next = head;

    if( next == nullptr || next->next == nullptr ){
      return next;
    }

    size_t count { nodeCount(head) };

    return getNode( head, (count/2) );

  }
//------------------------------------------------------------------------------
};

int main( ){
  Solution solution;
  solution.showMiddleNode( {1} );
  solution.showMiddleNode( {1,0} );
  solution.showMiddleNode( {1,2,3} );
  solution.showMiddleNode( {1,2,3,4} );
  return 0;
}