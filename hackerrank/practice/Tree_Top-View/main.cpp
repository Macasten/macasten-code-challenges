#include<bits/stdc++.h>

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


class TopViewNode
{
private:
  uint deepLevel {0};
  int *pValue {0};
public:
  TopViewNode(){};
  TopViewNode( uint level, int *value ):deepLevel(level), pValue(value) {} ;
  ~TopViewNode(){};

  void Update( uint level, int* value ){
    if( level < deepLevel ){
      deepLevel = level;
      pValue = value;
    }
  }
public:
  int getValue(){ return *pValue; }
};

class TopView
{
private:
  std::map<int, TopViewNode> listNodes;
public:
  TopView(){};
  ~TopView(){};

  void insertNode( int horizontalLevel, uint deepLevel, int* value){
    if( listNodes.count(horizontalLevel) == 0 ){
      listNodes.insert( std::pair<int,TopViewNode>( horizontalLevel, TopViewNode(deepLevel, value) ) );
    } else {
      listNodes[horizontalLevel].Update( deepLevel, value);
    }
  }
public:
  void print( ){
    for (auto itr = listNodes.begin(); itr != listNodes.end(); ++itr) {
      std::cout << itr->second.getValue() << " ";
    }
  }
};


class Solution {
public:
  Node* insert( Node* root, std::vector<int> && values ){
    for( auto value : values ){
      root = insert( root , value );
    }

    return root;
  }

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


  void topView(Node * root) {

    TopView topView;
    buildTopView( topView, root, 0, 0 );
    topView.print();
  }

  void buildTopView( TopView &topView, Node *root, int horiLevel, uint deep ){
    // std::cout << "(" <<horiLevel <<"," << deep << ")"  << std::endl;

    if( root == NULL )
      return;
    
    topView.insertNode( horiLevel, deep, &root->data );
    if(root->left != NULL){
      // std::cout << "GO Left" << std::endl;
      buildTopView( topView, root->left, (horiLevel -1), ( deep + 1) );
    }

    if( root->right != NULL ){
      buildTopView( topView, root->right, (horiLevel +1), ( deep + 1) );
    }
  }

}; //End of Solution

int main() {

  Solution myTree;
  Node* root = NULL;
  // int t;
  // int data;

  // std::cin >> t;

  // while(t-- > 0) {
  //     std::cin >> data;
  //     root = myTree.insert(root, data);
  // }



  root = myTree.insert( root, {1,2,5,3,6,4} );
  myTree.topView( root );

  return 0;
}
