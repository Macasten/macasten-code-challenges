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

class Solution {
public:

//----------------------------------------------------------- Challenge Solution
  bool isPalindrome(ListNode* head) {
    if(head == nullptr ) return false;

    std::vector<int> aux = {};
    while(head){
      aux.push_back(head->val);
      head = head->next;
    }
    if( aux.size() == 1) return true;
    for( size_t i = 0; i < aux.size()/2; i++ ){
      if( aux.at(i) != aux.at(aux.size()-1-i) ) return false;
    }
    return true;
  }
//------------------------------------------------------------------------------
};

int main(){

  std::cout <<"<<<<  LeetCode - 234. Palindrome Linked List >>>>" << std::endl;
  Solution solution;

  return 0;
}