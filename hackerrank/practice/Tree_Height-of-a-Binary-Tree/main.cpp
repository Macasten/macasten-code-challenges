#include <bits/stdc++.h>

using namespace std;

class Node {
  public:
    int data;
    Node *left;
    Node *right;
    Node(int d) {
      data = d;
      left = NULL;
      right = NULL;
    }
};

class Solution {
  public:
  Node* insert(Node* root, int data) {
    if(root == NULL) {
      return new Node(data);
    } else {
      Node* cur;
      if(data <= root->data) {
        cur = insert(root->left, data);
        root->left = cur;
      } else {
        cur = insert(root->right, data);
        root->right = cur;
      }

      return root;
    }
  }
/*The tree node has data, left child and right child
class Node {
    int data;
    Node* left;
    Node* right;
};

*/
  // Macasten Solution Code Start ...
  int height(Node* root) {
    return root == NULL ? 0 : this->countLevel( root, 0 );
  }

  int countLevel( Node* node, int level){
    if( node->left == NULL && node->right == NULL ){
      return level;
    }

    int currentLevel{ level + 1  };
    //std::cout << "Current Level: "<< currentLevel << std::endl;
    int outputLeft{ currentLevel };
    int outputRight{ currentLevel };

    // Count continues through the left leaf
    if( node->left != NULL ){
      outputLeft = countLevel( node->left, currentLevel);
    }

    // Count continues through the rigth leaf
    if( node->right != NULL ){
      outputRight = countLevel( node->right, currentLevel);
    }

    return outputRight > outputLeft ? outputRight : outputLeft;
  }

  // ... End Macasten Solution.

}; //End of Solution

int main() {

  Solution myTree;
  Node* root = NULL;

  int t;
  int data;

  std::cin >> t;

  while(t-- > 0) {
    std::cin >> data;
    root = myTree.insert(root, data);
  }

  int height = myTree.height(root);

  std::cout << height << std::endl;

  return 0;
}
