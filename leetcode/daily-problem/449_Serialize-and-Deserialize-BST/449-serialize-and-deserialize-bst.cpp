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

//----------------------------------------------------------- Challenge Solution
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:
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

  // Encodes a tree to a single string.
  string serialize(TreeNode* root) {
    string output = "";
    if( root == nullptr) return "";
    output += std::to_string(root->val) + ",";
    output += serialize(root->left);
    output += serialize(root->right);
    return output;
  }

  // Decodes your encoded data to tree.
  TreeNode* deserialize(string data) {
    TreeNode* output = nullptr;
    size_t pos = 0;
    while ((pos = data.find(",")) != string::npos && data.length() > 1 ) {
      output = Codec::insert( output, std::stoi(data.substr(0, pos)));
      data.erase(0, pos + 1 );
    }
    return output;
  }
};
//------------------------------------------------------------------------------

class Solution {
public:

  void showCodec( std::vector<int> nums ){
    std::cout << "----- New Test -----" << std::endl;
    TreeNode* root = TreeNode::insert(nums);
    TreeNode::print(root);
    Codec* ser = new Codec();
    Codec* deser = new Codec();
    string tree = ser->serialize(root);
    std::cout << "Serialize: "<< tree << std::endl;
    TreeNode* ans = deser->deserialize(tree);
    TreeNode::print(ans);
  }
};

int main(){

  std::cout <<"<<<<  LeetCode - 449. Serialize and Deserialize BST >>>>" << std::endl;
  Solution solution;
  solution.showCodec( {1,11,12,10,13,14,5,6,7,8,9} );

  return 0;
}