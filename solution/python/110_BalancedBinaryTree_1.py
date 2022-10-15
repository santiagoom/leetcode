
from typing import List  
from utils import *
                    
class Solution {
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

if __name__ == "__main__":
    nums = [2, 7, 11, 15]
    target = 26
    s = "aa"
    arrays = [[1, 2, 3], [4, 5, 6]]
    print(arrays)
                    