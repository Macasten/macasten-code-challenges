#include <bits/stdc++.h>

using namespace std;

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

void showListNode( ListNode* head , std::string label = "List" ){
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

ListNode* buildListNode( std::vector<int> list ){
  ListNode* output = new ListNode( list.at(0) );
  ListNode* next = output;

  for( size_t i = 1; i < list.size(); i++) {
    next->next = new ListNode( list.at(i) );
    next = next->next;
  }
  return output;
}

class Solution {
public:

//----------------------------------------------------------- Challenge Solution
  ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode* nextL1 = l1;
    ListNode* nextL2 = l2;

    bool carry {false};
    int sum{0};
    while ( l1 != nullptr && l2 != nullptr )
    {
      sum = (carry ? 1 : 0) + nextL1->val + nextL2->val;

      if( sum > 9 ){
        sum = sum%10;
        carry = true;
      } else {
        carry = false;
      }

      nextL1->val = sum;
    std::cout << sum << std::endl;
      if( nextL1->next == nullptr && nextL2->next == nullptr) break;

      if( nextL1->next == nullptr ){
        nextL1->next = new ListNode(0);
      }

      nextL1 = nextL1->next;

      if( nextL2->next == nullptr ){
        nextL2->val = 0;
      } else {
        nextL2 = nextL2->next;
      }
    }

    if(carry){
      nextL1->next = new ListNode(1);
    }

    return l1;
  }
//------------------------------------------------------------------------------
  void ShowAddTwoNumbers( std::vector<int> l1 , std::vector<int> l2 ){
    ListNode *newL1 = buildListNode(l1);
    ListNode *newL2 = buildListNode(l2);

    showListNode(newL1, "L1");
    showListNode(newL2, "L2");

    showListNode( addTwoNumbers( newL1 , newL2) , "Result");
  }
};

int main(){

  std::cout <<"<<<<  LeetCode - 2. Add Two Numbers >>>>" << std::endl;

  Solution solution;
  solution.ShowAddTwoNumbers( {1,2} , {9,7} );
  solution.ShowAddTwoNumbers( {1,2} , {9,7,1} );
  solution.ShowAddTwoNumbers( {1} , {9,7,1} );
   solution.ShowAddTwoNumbers( {9,9,9,9,9,9,9} , {9,9,9,9} );

  return 0;
}