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
  int min;

  inline void updateMin( vector<int>& data , int num ){
    for( auto elem : data ){
      int dif = std::abs( (elem - num ) );
      if( dif < min ) min = dif;
      if( min == 0) return;
    }
    data.push_back( num );
  }
  bool nextDifference(TreeNode* node , vector<int>& data ) {
    if( node == nullptr ) return true;
    updateMin( data, node->val );
    //std::cout << "Min: "<< min << std::endl;
    if( min == 0 ) return false;
    if( nextDifference(node->left, data ) ){
      return nextDifference(node->right, data );
    }
    return false;
  }

  int getMinimumDifference(TreeNode* root) {
    min = INT32_MAX;
    std::vector<int> data = {};
    nextDifference( root, data);
    return min;
  }
//------------------------------------------------------------------------------
  void showGetMinimumDifference( ){
    TreeNode* root = new TreeNode( 1 , new TreeNode(2), new TreeNode(3) );
    std::cout << "Minimun Difference = "<< getMinimumDifference(root) << std::endl;
  }
};

int main(){

  std::cout <<"<<<<  LeetCode - 530. Minimum Absolute Difference in BST >>>>" << std::endl;
  Solution solution;
  solution.showGetMinimumDifference();


  return 0;
}