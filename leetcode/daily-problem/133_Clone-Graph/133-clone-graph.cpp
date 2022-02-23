#include <bits/stdc++.h>

using namespace std;


// Definition for a Node.
class Node {
public:
  int val;
  vector<Node*> neighbors;
  Node() {
    val = 0;
    neighbors = vector<Node*>();
  }
  Node(int _val) {
    val = _val;
    neighbors = vector<Node*>();
  }
  Node(int _val, vector<Node*> _neighbors) {
    val = _val;
    neighbors = _neighbors;
  }
};


class Solution {
public:

//----------------------------------------------------------- Challenge Solution
  unordered_map<Node* , Node*> mp;
  
  Node* cloneGraph(Node* node) {
    if(node == nullptr ) {
      return nullptr;
    }

    if(mp.find(node) == mp.end()) {
      mp[node] = new Node(node -> val, {});
      for(auto adj: node -> neighbors) {
        mp[node] -> neighbors.push_back(cloneGraph(adj));
      }
    }
    return mp[node];
  }
//------------------------------------------------------------------------------
  void showCloneGraph( std::vector<std::vector<int>> node ){
    std::cout << "----- New Test -----" << std::endl;
  }
};

int main(){

  std::cout <<"<<<<  LeetCode - 133. Clone Graph >>>>" << std::endl;
  Solution solution;
  return 0;
}