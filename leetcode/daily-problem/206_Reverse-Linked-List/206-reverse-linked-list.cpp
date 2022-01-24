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
  ListNode* reverseList(ListNode* head) {
    if( head == nullptr || head->next == nullptr) return head;

    ListNode* prev = nullptr;
    ListNode* next = nullptr;
    while (head->next)
    {
      next = head->next;
      head->next = prev;
      prev = head;
      head = next;
    }
    head->next = prev;

    return head;
  }
//------------------------------------------------------------------------------
  void showReverseList( std::vector<int> vec ){
    ListNode* orig = ListNode::buildListNode(vec);
    ListNode::showListNode(orig, "Origin");
    ListNode::showListNode(reverseList(orig) , "Result");
  }
};

int main(){

  std::cout <<"<<<<  LeetCode - 206. Reverse Linked List >>>>" << std::endl;
  Solution solution;
  solution.showReverseList({1,2,3,4,5,6});

  return 0;
}