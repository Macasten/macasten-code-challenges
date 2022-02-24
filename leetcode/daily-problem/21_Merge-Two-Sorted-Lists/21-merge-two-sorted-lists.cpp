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
  void mergeToList( ListNode* baseList, ListNode* newList ){
    ListNode* nextNode = baseList;
    while ( newList != nullptr ) {
      if( nextNode->next == nullptr ){
        nextNode->next = newList;
        return;
      }

      if( nextNode->next->val >= newList->val ){
        ListNode* bAux = nextNode->next;
        ListNode* nAux = newList->next;
        nextNode->next = newList;
        nextNode->next->next = bAux;
        newList = nAux;
      }else{
        nextNode = nextNode->next;
      }
    }
  }
  ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
    if(list1 == nullptr ) return list2;
    if(list2 == nullptr ) return list1;


    if(list1->val < list2->val){
      mergeToList(list1, list2);
      return list1;
    } else {
      mergeToList(list2, list1);
      return list2;
    }
  }
//------------------------------------------------------------------------------
  void showMergeTwoLists(std::vector<int> vec1, std::vector<int> vec2){
    std::cout << "----- New Test -----" << std::endl;
    ListNode* list1 = ListNode::buildListNode(vec1);
    ListNode* list2 = ListNode::buildListNode(vec2);

    ListNode::showListNode(list1, "List 1");
    ListNode::showListNode(list2, "List 2");

    ListNode::showListNode( mergeTwoLists(list1,list2), "Merge List" );
  }
};

int main(){

  std::cout <<"<<<<  LeetCode - 21. Merge Two Sorted Lists >>>>" << std::endl;
  Solution solution;
  solution.showMergeTwoLists(
    {4,5,6,7,8}
    {1,2,3,4,5,6},
  );

  return 0;
}