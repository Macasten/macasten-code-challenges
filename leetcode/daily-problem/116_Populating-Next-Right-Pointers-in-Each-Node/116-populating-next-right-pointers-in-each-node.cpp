#include <bits/stdc++.h>

// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};




class Solution {
public:

  Node* insert(Node* root, int val) {
    if(root == NULL) {
      return new Node(val);
    } else {
      Node* cur;
      if(val <= root->val) {
        cur = insert(root->left, val);
        root->left = cur;
      } else {
        cur = insert(root->right, val);
        root->right = cur;
      }

      return root;
    }
  }

//----------------------------------------------------------- Challenge Solution
  inline void setNext( std::map<uint, Node*> &map, Node* node, uint level ){
    if( map.find(level) != map.end() ){
      map[level]->next = node;
    }
    map[level] = node;
  }

  inline void nextLevel( std::map<uint, Node*> &map, Node* node, uint level ){
    if(node == NULL){
      return;
    }
    setNext( map, node, level );
    level++;
    nextLevel(map, node->left, level );
    nextLevel(map, node->right, level );
  }

  Node* connect(Node* root) {
    std::map<uint,Node*> nextMap;
    nextLevel( nextMap, root, 0);
    return root;
  }
//------------------------------------------------------------------------------
};

int main(){
  std::cout << "116. Populating Next Right Pointers in Each Node" << std::endl;
  return 0;
}