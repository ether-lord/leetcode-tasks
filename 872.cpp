#include <algorithm>
#include <iostream>
#include <vector>

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
  vector<int> leaves;

  void search(TreeNode *node) {
    if (node == nullptr) return;
    if (node->left == nullptr && node->right == nullptr)
      leaves.push_back(node->val);

    search(node->left);
    search(node->right);
  }

  bool leafSimilar(TreeNode *root1, TreeNode *root2) {
    search(root1);
    auto leaves1 = leaves;
    leaves.clear();
    search(root2);

    return equal(leaves.begin(), leaves.end(), leaves1.begin(), leaves1.end());
  }
};

int main() {
  Solution s;
  cout << s.leafSimilar(nullptr, nullptr) << endl;
  return 0;
}