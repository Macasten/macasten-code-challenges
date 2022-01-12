#include <bits/stdc++.h>

using namespace std;

//------------------------------------------- Definition for a binary tree node.
class TreeNode {
public:
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}

  static TreeNode* insert( std::vector<int>& values, TreeNode* root = nullptr ){
    for( auto value : values ){
      root = insert( root , value );
    }
    return root;
  }

  static TreeNode* insert(TreeNode* root, int val) {
    if(root == nullptr) {
      return new TreeNode(val);
    } else {
      TreeNode* cur;
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

  static void print(const TreeNode* node, const std::string& prefix = "", bool isLeft = false) {
    if( node != nullptr ) {
      std::cout << prefix;
      std::cout << (isLeft ? "├──" : "└──" );
      // print the value of the node
      std::cout << node->val << std::endl;
      // enter the next tree level - left and right branch
      TreeNode::print( node->left, prefix + (isLeft ? "│   " : "    "), true);
      TreeNode::print( node->right, prefix + (isLeft ? "│   " : "    "), false);
    }
  }
};
//------------------------------------------------------------------------------
class Solution {
public:

//----------------------------------------------------------- Challenge Solution
  TreeNode* insertIntoBST(TreeNode* root, int val) {
    if( root == nullptr ){
      return new TreeNode(val);
    }
    TreeNode* prev = root;
    while( true ){
      if( prev->val > val ){
        if( prev->left == nullptr ){
          prev->left = new TreeNode(val);
          break;
        }
        prev = prev->left;
      } else {
        if( prev->right == nullptr ){
          prev->right = new TreeNode(val);
          break;
        }
        prev = prev->right;
      }
    }
    return root;
  }
//------------------------------------------------------------------------------
  void showInsertIntoBST( vector<int> vec, int val){
    TreeNode* root = TreeNode::insert( vec );
    TreeNode::print(root);
    insertIntoBST( root , val );
    TreeNode::print(root);
  }
};

int main(){

  std::cout <<"<<<<  LeetCode - 701. Insert into a Binary Search Tree >>>>" << std::endl;
  Solution solution;
  solution.showInsertIntoBST( {4,2,7,1,3},5);

  return 0;
}