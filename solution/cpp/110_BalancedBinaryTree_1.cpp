
#include <iostream>
#include <cppUtils.h>
using namespace std;

                    
class Solution_110_BalancedBinaryTree_1 {
private:
  // Recursively obtain the height of a tree. An empty tree has -1 height
  int height(TreeNode* root) { 
    // An empty tree has height -1
    if (root == NULL) {
      return -1;
    }
    return 1 + max(height(root->left), height(root->right));
  }
public:
  bool isBalanced(TreeNode* root) {
    // An empty tree satisfies the definition of a balanced tree
    if (root == NULL) {
      return true;
    }

    // Check if subtrees have height within 1. If they do, check if the
    // subtrees are balanced
    return abs(height(root->left) - height(root->right)) < 2 &&
      isBalanced(root->left) &&
      isBalanced(root->right);
  }
};

int main() {
vector<int> nums{2, 7, 11, 15};
int target = 26;
string s = "aa";
vector<vector<int>> arrays;
CppUtils::print(s);
CppUtils::print_1d_vector(nums);
CppUtils::print_2d_vector(arrays);
return 0;
}
                    