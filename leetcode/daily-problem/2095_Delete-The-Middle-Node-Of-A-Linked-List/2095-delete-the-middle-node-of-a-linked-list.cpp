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

  void showListNode( ListNode* head ){
    std::cout << "List: { ";
    if( head == nullptr ){
      std::cout<<"EMPTY }" <<std::endl;
      return;
    }

    while( head != nullptr ) {
      std::cout << head->val;
      head = head->next;
      if(head != nullptr ){
        std::cout << " -> ";
      }
    }
    std::cout<<" }" <<std::endl;
  }


  void showDeleteMiddle( std::vector<int> list ){
    showListNode( deleteMiddle( buildListNode( list ) ) );
  }
//----------------------------------------------------------- Challenge Solution
  inline size_t listNodeCount( ListNode* head ){
    size_t count{0};
    while( head != nullptr ){
      count++;
      head = head->next;
    }
    return count;
  }

  ListNode* deleteMiddle(ListNode* head) {
    if( head == nullptr ){
      return head;
    }

    size_t middle{ listNodeCount(head)/2 };

    if(middle == 0 ){
      return nullptr;
    }

    ListNode* prev = head;
    ListNode* next = head;
    while ( middle > 0)
    {
      prev = next;
      next = next->next;
      middle--;
    }

    if( next != nullptr ){
      prev->next = next->next;
    } else {
      prev->next = nullptr;
    }

    return head;
  }
//------------------------------------------------------------------------------
};

int main(){
  std::cout << "2095. Delete the Middle Node of a Linked List" << std::endl;
  Solution solution;
  solution.showDeleteMiddle({1});
  solution.showDeleteMiddle({1,2});
  solution.showDeleteMiddle({1,2,3});
  solution.showDeleteMiddle({1,2,3,4});
  solution.showDeleteMiddle({1,2,3,4,5});
  solution.showDeleteMiddle({1,2,3,4,5,6});

  return 0;
}