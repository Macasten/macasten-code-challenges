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
      if(val == root->val) {
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

class Solution {
public:

//----------------------------------------------------------- Challenge Solution
	int sumAllLeaft( TreeNode* next , int numb ){
		if( next == nullptr ){
			std::cout << numb << endl;
			return numb;
		}
		
		numb = ( numb << 1 ) + next->val;

		if( next->right != nullptr && next->left != nullptr)
			return sumAllLeaft( next->right, numb ) + sumAllLeaft( next->left, numb );
		else if ( next->right != nullptr && next->left == nullptr )
			return sumAllLeaft( next->right, numb );
		else if ( next->right == nullptr && next->left != nullptr )
			return sumAllLeaft( next->left, numb );
		else
			return numb;
	}
	int sumRootToLeaf(TreeNode* root) {
		if( root == nullptr )
			return 0;
		
        int numb = root->val;
        if( root->right != nullptr && root->left != nullptr)
			return sumAllLeaft( root->right, numb ) + sumAllLeaft( root->left, numb );
		else if ( root->right != nullptr && root->left == nullptr )
			return sumAllLeaft( root->right, numb );
		else if ( root->right == nullptr && root->left != nullptr )
			return sumAllLeaft( root->left, numb );
		else
			return numb;
	}
//------------------------------------------------------------------------------
  void showSumRootToLeaf( vector<int> vec ){
    //TreeNode* root = TreeNode::insert( vec );
    TreeNode* root = new TreeNode(1,
      new TreeNode(0, new TreeNode(0), new TreeNode(1) ),
      new TreeNode(1, new TreeNode(0), new TreeNode(1) ));
    TreeNode::print(root);
    std::cout << "Sum = "<< sumRootToLeaf(root) << std::endl;
  }
};

int main(){

  std::cout <<"<<<<  LeetCode - 1022. Sum of Root To Leaf Binary Numbers >>>>" << std::endl;
  Solution solution;
  //solution.showSumRootToLeaf( {0} );
  //solution.showSumRootToLeaf( {1,1,1,1} );
  solution.showSumRootToLeaf( {1,0,1,0,1,0,1});

  return 0;
}
