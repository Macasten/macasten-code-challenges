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
      ListNode* aux = new ListNode( list.at(0) );
      ListNode* next = aux;

      for( size_t i = 1; i < list.size(); i++) {
        next->next = new ListNode( list.at(i) );
        next = next->next;
      }
      return aux;
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
  ListNode* rotateRight(ListNode* head, int k) {
    if( head == nullptr || head->next == nullptr ) return head;

    ListNode* aux = head;
    int count {1};
    while (aux->next){
      aux = aux->next;
      count++;
    }

    k %= count;

    if( k == 0 ) return head;
    aux->next = head;
    k = count-k;
    while(k){
      aux = aux->next;
      k--;
    }
    head = aux->next;
    aux->next = nullptr;

    return head;
  }
//------------------------------------------------------------------------------
  void showRotateRight(std::vector<int> vec, int k){
    std::cout << "----- New Test -----" << std::endl;
    ListNode* head = ListNode::buildListNode(vec);
    ListNode::showListNode(head, "Original");
    std::cout << "After "<< k <<" rotation" << std::endl;
    ListNode::showListNode( rotateRight( head, k ), "Result" );
  }
};

int main(){

  std::cout <<"<<<<  LeetCode - 61. Rotate List >>>>" << std::endl;
  Solution solution;
  solution.showRotateRight({0,1,2},1);
  solution.showRotateRight({0,1,2},4);
  solution.showRotateRight({1,2,3,4,5},2);
  solution.showRotateRight({1,2,3,4,5},3);

  return 0;
}