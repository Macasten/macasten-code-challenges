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
  ListNode* sortList(ListNode* head) {
    if(head == nullptr) return nullptr;
    ListNode* base = head;
    std::vector<int> list;
    while (base) {
      list.push_back(base->val);
      base = base->next;
    }
    std::sort( list.begin(), list.end() );
    base=head;
    for( auto& num : list){
      base->val = num;
      base = base->next;
    }

    return head;
  }
//------------------------------------------------------------------------------
  void showSortList( std::vector<int> vec ) {
    std::cout << "----- New Test -----" << std::endl;
    ListNode* head = ListNode::buildListNode(vec);
    ListNode::showListNode(head, "Original");
    ListNode::showListNode( sortList(head) , "Result");
  }
};

int main(){

  std::cout <<"<<<<  LeetCode - 148. Sort List >>>>" << std::endl;
  Solution solution;
  solution.showSortList({9,8,7,6,5,4,3,2,1,5});

  return 0;
}