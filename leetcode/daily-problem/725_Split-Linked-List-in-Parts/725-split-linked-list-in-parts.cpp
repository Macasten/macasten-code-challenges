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

template<typename T>
inline void coutVector( std::vector<T> vec, std::string label = "Vector" ){
  std::cout << label << " : { ";
  if( vec.empty() ){
    std::cout << "EMPTY }" << std::endl;
    return;
  }
  for( size_t i = 0 ; i < (vec.size()-1); i++ ){
    std::cout << vec.at(i) << "; " ;
  }
  std::cout<< vec.back() << " }"<< std::endl;
}

class Solution {
public:

//----------------------------------------------------------- Challenge Solution
  inline ListNode* chopListNode(ListNode* & head, int size){
    ListNode* output = head;
    while( size ){
      head = head->next;
      size--;
    }
    if( head ){
      ListNode* temp = head;
      head = head->next;
      temp->next = nullptr;
    }
    return output;
  }

  vector<ListNode*> splitListToParts(ListNode* head, int k) {

    // count list Nodes
    ListNode* aux = head;
    int count{0};
    while(aux) {
      count++;
      aux=aux->next;
    }

    std::vector<ListNode*> output;
    aux=head;

    // split bigger than list size
    if( k >= count ){
      while(aux){
        output.push_back(aux);
        aux = aux->next;
        output.back()->next = nullptr;
        k--;
      }

      while (k){
        output.push_back(nullptr);
        k--;
      }
    }
    // split less than list size
    else {
      ListNode* temp;
      int overSize = count%k;
      count /= k;
      while (overSize){
        output.push_back(chopListNode( head , count ) );
        overSize--;
      }

      while (head){
        output.push_back(chopListNode( head , count-1) );
      }
    }

    return output;
  }
//------------------------------------------------------------------------------
  void showSplitListToParts( std::vector<int> vec, int k){
    std::cout << "----- New Test -----" << std::endl;
    coutVector( vec , "Original");
    ListNode* head = ListNode::buildListNode(vec);
    auto result = splitListToParts( head, k );
    std::cout << "Results of split in to "<< k <<" :" << std::endl;
    for( size_t i = 0 ; i < result.size(); i++ ){
      ListNode::showListNode( result.at(i), std::to_string(i) );
    }
  }
};

int main(){

  std::cout <<"<<<<  LeetCode - 725. Split Linked List in Parts >>>>" << std::endl;
  Solution solution;
  solution.showSplitListToParts({1,2,3}, 5);
  solution.showSplitListToParts({1,2,3,4,5,6,7,8,9,10}, 3);
  solution.showSplitListToParts({1,2,3,4,5,6,7,8,9,10}, 1);

  return 0;
}