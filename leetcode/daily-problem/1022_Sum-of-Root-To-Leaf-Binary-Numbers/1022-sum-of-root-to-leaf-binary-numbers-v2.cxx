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
};
//------------------------------------------------------------------------------
void printBT(const std::string& prefix, const TreeNode* node, bool isLeft)
{
    if( node != nullptr )
    {
        std::cout << prefix;

        std::cout << (isLeft ? "├──" : "└──" );

        // print the value of the node
        std::cout << node->val << std::endl;

        // enter the next tree level - left and right branch
        printBT( prefix + (isLeft ? "│   " : "    "), node->left, true);
        printBT( prefix + (isLeft ? "│   " : "    "), node->right, false);
    }
}

void printBT(const TreeNode* node)
{
  printBT("", node, false);
}

class Solution {
public:

//----------------------------------------------------------- Challenge Solution
  int sum{0};

  void nextLevel( TreeNode* leaf, int number, int level ){
    //std::cout << "NUMBER: "<< number << "("<<std::bitset<8>(number) << ") LEVEL :" << level << std::endl;
    number = number << 1 | leaf->val;
    if( leaf->right == nullptr && leaf->left == nullptr ){
      sum += number ;
      //std::cout <<"number: " << number << "("<<std::bitset<8>(number) << ") -> sum -> " << sum << std::endl;
      return;
    }
    if( leaf->left != nullptr){
      nextLevel( leaf->left, number, level );
    }
    if( leaf->right){
      nextLevel( leaf->right, number, level );
    }
  }

  int sumRootToLeaf(TreeNode* root) {
    if(root == nullptr ) return 0;
    sum = 0;
    nextLevel( root, 0 , 0);
    return sum;
  }
//------------------------------------------------------------------------------
  void showSumRootToLeaf( vector<int> vec ){
    //TreeNode* root = TreeNode::insert( vec );
    TreeNode* root = new TreeNode(1,
      new TreeNode(0, new TreeNode(0), new TreeNode(1) ),
      new TreeNode(1, new TreeNode(0), new TreeNode(1) ));
    printBT(root);
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
