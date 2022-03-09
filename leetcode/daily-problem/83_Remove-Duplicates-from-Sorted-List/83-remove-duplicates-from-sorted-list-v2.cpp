#include <bits/stdc++.h>

using namespace std;

//-------------------------------------------------- Definition for a List node.
struct ListNode {
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

    static inline size_t listNodeCount( ListNode* head ){
      size_t count{0};
      while( head != nullptr ){
        count++;
        head = head->next;
      }
      return count;
    }

    static void showListNode( ListNode* head , std::string label = "List" ){
      std::cout << label << ": { ";
    if( head == nullptr ){
      std::cout<<"EMPTY }" <<std::endl;
      return;
    }
      while( head != nullptr )
      {
        std::cout << head->val ;
        head = head->next;
        if(head != nullptr ){
          std::cout << " -> ";
        }
      }
      std::cout<< " }" <<std::endl;
    }
  };
//------------------------------------------------------------------------------

class Solution {
public:

//----------------------------------------------------------- Challenge Solution
  ListNode* deleteDuplicates(ListNode* head) {
    if( head == nullptr || head->next == nullptr ) return head;
    ListNode* prev = head;
    while( prev ) {
      while( prev->next && prev->val == prev->next->val ) {
        prev->next = prev->next->next;
      }
      if( prev->next == nullptr ) break;
      prev = prev->next;
    }
    return head;
  }
//------------------------------------------------------------------------------
  void showDeleteDuplicates( std::vector<int> list ) {
    std::cout << "----- New Test -----" << std::endl;
    ListNode* head = ListNode::buildListNode(list);
    ListNode::showListNode(head, "Original" );
    ListNode::showListNode( deleteDuplicates(head), "Result" );
  }
};

int main(){

  std::cout <<"<<<<  LeetCode - 83. Remove Duplicates from Sorted List >>>>" << std::endl;
  Solution solution;
  solution.showDeleteDuplicates({1,2,3,3,4,4,5});
  solution.showDeleteDuplicates({1,1,1,2,3});
  solution.showDeleteDuplicates({1,2,3,3,4,4,5,5,5});

  return 0;
}