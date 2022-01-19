#include <bits/stdc++.h>

using namespace std;


/**
 * Definition for singly-linked list.
 */
class ListNode {
  public:
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {};

  static ListNode* buildListNode( std::vector<int> list ){
    ListNode* output = new ListNode( list.at(0) );
    ListNode* next = output;

    for( size_t i = 1; i < list.size(); i++) {
      next->next = new ListNode( list.at(i) );
      next = next->next;
    }
    return output;
  };

  static ListNode* getLast( ListNode* head ){
    if( head == nullptr ) return head;
    ListNode* output = head;
    while ( output->next ) {
      output = output->next;
    }
    
    return output;
  };
};


class Solution {
public:

//----------------------------------------------------------- Challenge Solution
  bool hasCycle(ListNode *head) {
    if( head == nullptr ) return false;

    ListNode* output = head;
    // std::set<int> setValue;
    head->val = INT32_MIN;
    while (output->next) {
      output = output->next;
      if( output->val != INT32_MIN ){
        output->val = INT32_MIN;
      } else {
        return true;
      }
    }

    return false;
  }
//------------------------------------------------------------------------------
  void ShowDetectCycle( ListNode *head ){
    if( hasCycle( head) ){
      std::cout << "Cycle" << std::endl;
    } else {
      std::cout << "No Cycle" << std::endl;
    }
  }

  void testI(){
  }
};

int main(){

  std::cout <<"<<<<  LeetCode - 141. Linked List Cycle >>>>" << std::endl;
  Solution solution;

  return 0;
}