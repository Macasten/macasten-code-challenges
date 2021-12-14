#include <iostream>
#include <vector>
#include <functional>

//Definition for a binary tree node.
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:

  TreeNode* insert(TreeNode* root, int data) {
    if(root == NULL) {
      return new TreeNode(data);
    } else {
      TreeNode* cur;
      if(data <= root->val) {
        cur = insert(root->left, data);
        root->left = cur;
      } else {
        cur = insert(root->right, data);
        root->right = cur;
      }

      return root;
    }
  }

  TreeNode buildTreeNode( std::vector<int> buffer ){
    TreeNode output;
    for( int data : buffer ){
      insert( &output, data );
    }
    return output;
  }

  int rangeSumBST(TreeNode* root, int low, int high) {
    int output{0};
    sumBST(root, low, high, output);
    return output;
  }

  inline void sumBST(TreeNode* root, const int& low, const int& high, int &sum ) {
    if( root == nullptr ){
      return;
    }

    if( root->val >= low && root->val <= high ){
      sum += root->val;
    }

    sumBST( root->right, low, high , sum );
    sumBST( root->left, low, high , sum );
  }


  int rangeSumBST(std::vector<int> buffer , int low, int high) {
    TreeNode tree = buildTreeNode( buffer );
    return rangeSumBST( &tree, low, high );
  }
};

int main()
{
  Solution solution;

  std::cout <<  solution.rangeSumBST( {1,2}, 1 , 2 ) << std::endl;
  std::cout <<  solution.rangeSumBST( {1,2,3,4,5}, 1 , 3 ) << std::endl;
  std::cout <<  solution.rangeSumBST( {1,2,3,4,5}, 1 , 3 ) << std::endl;
  std::cout <<  solution.rangeSumBST( {1,2,3,4,5}, 1 , 3 ) << std::endl;
  return 0;
}
