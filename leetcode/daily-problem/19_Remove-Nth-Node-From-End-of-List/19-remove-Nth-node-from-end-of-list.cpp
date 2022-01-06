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

ListNode* buildListNode( std::vector<int> list ){
  ListNode* output = new ListNode( list.at(0) );
  ListNode* next = output;

  for( size_t i = 1; i < list.size(); i++) {
    next->next = new ListNode( list.at(i) );
    next = next->next;
  }
  return output;
}

void showListNode( ListNode* head, std::string label = "List" ){
  std::cout << label <<": { ";
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

class Solution {
public:

//----------------------------------------------------------- Challenge Solution
  ListNode* removeNthFromEnd(ListNode* head, int n) {
    if( head->next == nullptr ) return nullptr;

    vector<ListNode*> list = {};

    ListNode* next = head;
    while ( next != nullptr )
    {
      list.push_back( next );
      next = next->next;
    }

    if( n==1 ){
      list.at(list.size()-n-1)->next = nullptr;
    } else if ( n == list.size() ) {
      head = head->next;
    } else {
      list.at(list.size()-n-1)->next = list.at(list.size()-n+1);
    }

    
    return head;
  }
//------------------------------------------------------------------------------

  void showRemoveNthFromEnd( vector<int> vec, int n){
    ListNode* list = buildListNode(vec);
    showListNode( list, "Original" );
    list = removeNthFromEnd( list, n);
    showListNode( list, "Result" );

  }
};

int main(){

  std::cout <<"<<<<  LeetCode - 19. Remove Nth Node From End of List  >>>>" << std::endl;
  Solution solution;

  solution.showRemoveNthFromEnd( {1,2,3,4},1);
  solution.showRemoveNthFromEnd( {1,2,3,4},2);
  solution.showRemoveNthFromEnd( {1,2,3,4},3);
  solution.showRemoveNthFromEnd( {1,2,3,4},4);

  return 0;
}