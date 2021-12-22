#include <bits/stdc++.h>

// Definition for singly-linked list.
class ListNode {
public:
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}

  static ListNode* buildListNode( std::vector<int> list ){
    ListNode* output = new ListNode( list.at(0) );
    ListNode* next = output;

    for( size_t i = 1; i < list.size(); i++) {
      next->next = new ListNode( list.at(i) );
      next = next->next;
    }
    return output;
  }

  static std::vector<int> toVector( ListNode* head ){
    std::vector<int> listVect = {};
    while( head != nullptr ){
      listVect.push_back(head->val);
      head = head->next;
    }
    return listVect;
  }

  static void printList( ListNode* head ){
    while( head != nullptr ){
      std::cout << head->val << " -> ";
      head = head->next;
    }
    std::cout << std::endl;
  }
};

class Solution {
public:



  //----------------------------------------------------------- Problem Solution
  inline std::vector<int> toVector( ListNode* head ){
    std::vector<int> listVect = {};
    while( head != nullptr ){
      listVect.push_back(head->val);
      head = head->next;
    }
    return listVect;
  }

  void reorderList(ListNode* head) {
    if( head == nullptr || head->next == nullptr || head->next->next == nullptr ) return;

    std::vector<int> auxList = toVector( head );

    size_t begin = 1;
    size_t end = ( auxList.size() - 1 );
    ListNode *next = head->next;
    while ( begin < end )
    {
      next->val = auxList.at(end);
      //std::cout << auxList.at(begin) << " <-> "<< next->next->val << std::endl;
      next->next->val = auxList.at(begin);
      //std::cout << auxList.at(begin) << " <-> "<< next->next->val << std::endl;

      begin++;
      end--;
      next = next->next->next;

    }
    if( begin == end ){
      next->val = auxList.at(begin);
    }

    //std::cout << begin << " !==! "<< end << std::endl;
  }
  //----------------------------------------------------------------------------

  ListNode* reorderList(std::vector<int> list) {
    ListNode* output = ListNode::buildListNode(list);
    reorderList( output );
    return output;
  }
};

int main()
{
  Solution solution;

  ListNode::printList( solution.reorderList({1}) );
  ListNode::printList( solution.reorderList({1,2}) );
  ListNode::printList( solution.reorderList({1,2,3}) );
  ListNode::printList( solution.reorderList({1,2,3,4}) );
  ListNode::printList( solution.reorderList({1,2,3,4,5}) );


  /* code */
  return 0;
}
