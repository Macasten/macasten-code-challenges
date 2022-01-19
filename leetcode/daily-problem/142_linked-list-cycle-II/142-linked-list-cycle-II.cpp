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
  ListNode *detectCycle(ListNode *head) {
    if( head == nullptr ) return nullptr;

    ListNode* output = head;
    // std::set<int> setValue;
    head->val = INT32_MIN;
    while (output->next) {
      output = output->next;
      if( output->val != INT32_MIN ){
        output->val = INT32_MIN;
      } else {
        return output;
      }
    }

    return nullptr;
  }
//------------------------------------------------------------------------------
  void ShowDetectCycle( ListNode *head ){
    ListNode * startNode = detectCycle( head );
    if( startNode ){
      std::cout << "Start Node : "<< startNode->val << std::endl;
    } else {
      std::cout << "No Cycle" << std::endl;
    }
  }

  void testI(){
  }
};

int main(){

  std::cout <<"<<<<  LeetCode - 142. Linked List Cycle II >>>>" << std::endl;
  Solution solution;

  return 0;
}