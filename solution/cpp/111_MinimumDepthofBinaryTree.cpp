#include <iostream>
#include <vector>
#include <cppUtils.h>

using namespace std;

class Solution {
public:
    int minDepth(TreeNode *root) {
        if (root == nullptr)
            return 0;
//        if (root->left == nullptr && root->right == nullptr)
//            return 1;

//        int left = INT_MAX, right = INT_MAX;
//        if (root->left)
            int left = minDepth(root->left);
//        if (root->right)
            int right = minDepth(root->right);

        return min(left, right) + 1;
//        return max(left, right) + 1;
    }
};

int main() {
//       1
//     /  \
//    2   3
//  /  \
// 4   5
    auto *so = new Solution();
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    int res = so->minDepth(root);
    CppUtils::print(res);
    delete so;
    return 0;
}


