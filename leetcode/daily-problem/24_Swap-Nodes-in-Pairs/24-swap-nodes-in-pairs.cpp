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
  ListNode* swapPairs(ListNode* head) {
    if( head == nullptr || head->next == nullptr ) return head;

    // first two elements
    ListNode* prev = head;
    ListNode* now = head->next;
    ListNode* next = now->next;
    prev->next = next;
    now->next = prev;
    head = now;
    ListNode* base = head->next;


    // if( next == nullptr || next->next == nullptr ) return head;

    // prev = head->next->next;
    // now = prev->next;
    // next = now->next;
    while ( !( base == nullptr || base->next == nullptr || base->next->next == nullptr ) ){
      // std::cout << base->val << " - " ;
      prev = base->next;
      now = prev->next;
      next = now->next;
      // std::cout << prev->val << " - " << now->val << " - ";

      prev->next = next;
      now->next = prev;
      base->next = now;

      base = prev;

      // std::cout << ( next ? next->val : -1 ) << std::endl;
      // //ListNode::showListNode( swapPairs(head) , "changes");
      // std::string name;
      // std::getline (std::cin,name);
    }

    return head;
  }
//------------------------------------------------------------------------------
  void showSwapPairs( std::vector<int> vec ) {
    std::cout << std::endl << "----- New Test -----" << std::endl;
    ListNode* head = ListNode::buildListNode( vec );
    ListNode::showListNode(head, "Original");
    ListNode::showListNode( swapPairs(head) , "Result");
  }
};

int main(){

  std::cout <<"<<<<  LeetCode - 24. Swap Nodes in Pairs >>>>" << std::endl;
  Solution solution;

  solution.showSwapPairs({1});
  solution.showSwapPairs({1,2});
  solution.showSwapPairs({1,2,3});
  solution.showSwapPairs({1,2,3,4});
  solution.showSwapPairs({1,2,3,4,5,6,7});
  solution.showSwapPairs({1,2,3,4,5,6,7,8});
  //solution.showSwapPairs({1,2,3,4,5});

  return 0;
}