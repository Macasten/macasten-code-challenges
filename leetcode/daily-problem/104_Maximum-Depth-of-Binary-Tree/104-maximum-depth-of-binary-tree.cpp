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
  int maxDepthCount(TreeNode* root, int depth) {
    if( root == nullptr ) return depth;
    depth++;
    return std::max(
      maxDepthCount(root->left, depth),
      maxDepthCount(root->right, depth)
    );
  }

  int maxDepth(TreeNode* root) {
    if( root == nullptr ) return 0;

    return std::max(
      maxDepthCount(root->left, 1),
      maxDepthCount(root->right, 1)
    );
  }
//------------------------------------------------------------------------------

  void showMaxDepthCount( std::vector<int> tree ){
    TreeNode* root = TreeNode::insert( tree );
    TreeNode::print(root);
    std::cout << "Max Depth: "<< maxDepth( root ) << std::endl;
  }
};

int main(){

  std::cout <<"<<<<  LeetCode - 104. Maximum Depth of Binary Tree >>>>" << std::endl;
  Solution solution;
  solution.showMaxDepthCount( {1,2,3,4,5,6});

  return 0;
}