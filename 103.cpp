#include <algorithm>
#include <iostream>

using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
};

class Solution {
 public:
  void search(TreeNode *node, int depth) {
    if (node == nullptr) return;

    m_depth = max(++depth, m_depth);

    search(node->left, depth);
    search(node->right, depth);
  }

  int maxDepth(TreeNode *root) {
    search(root, 0);
    return m_depth;
  }

 private:
  int m_depth{0};
};

int main() {
  Solution s;
  cout << s.maxDepth(nullptr) << endl;
  return 0;
}