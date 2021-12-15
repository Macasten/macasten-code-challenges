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

  inline void insertNode( ListNode* positionNode, ListNode* node ){
    ListNode* next = positionNode->next;
    positionNode->next = node;
    node->next = next;
  }

  inline ListNode* shortListNode( ListNode* list ){
    std::vector<int> listVect = {};
    while( list != nullptr ){
      listVect.push_back(list->val);
      list = list->next;
    }
    std::sort(listVect.begin(), listVect.end());
    return buildListNode( listVect );
  }


  ListNode* insertionSortList(ListNode* head) {

    if(head == nullptr || head->next == nullptr ){
      return head;
    }

    return shortListNode(head);
  }

  ListNode* buildListNode( std::vector<int> list ){
    ListNode* output = new ListNode( list.at(0) );
    ListNode* next = output;

    for( size_t i = 1; i < list.size(); i++) {
      next->next = new ListNode( list.at(i) );
      next = next->next;
    }
    return output;
  }

  ListNode* insertionSortList(std::vector<int> list) {
    return insertionSortList( buildListNode(list) );
  }

  void printList( ListNode* head ){
    while( head != nullptr ){
      std::cout << head->val << " -> ";
      head = head->next;
    }
    std::cout << std::endl;
  }
};


int main()
{
  Solution solution;

  solution.printList( solution.insertionSortList({4,1,2,3}) );
  return 0;
}
