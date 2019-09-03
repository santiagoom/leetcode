#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    explicit TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

/**
* This reference program is provided by @jiuzhang.com
* Copyright is reserved. Please indicate the source for forwarding
*/

/**
 * Definition of TreeNode:
 * class TreeNode {
 * public:
 *     int val;
 *     TreeNode *left, *right;
 *     TreeNode(int val) {
 *         this->val = val;
 *         this->left = this->right = NULL;
 *     }
 * }
 */
class Solution {
public:
    /**
     * @param root: The root of binary tree.
     * @return: An integer
     */
    int ans;

    int solve_dp(TreeNode *root) {
        if (root == NULL)
            return 0;

        if (root->left == NULL && root->right == NULL)
            return 1;

        int lf = 0x7fffffff, rt = 0x7fffffff;
        if (root->left)
            lf = solve_dp(root->left);

        if (root->right)
            rt = solve_dp(root->right);

        return min(lf, rt) + 1;
    }

    int minDepth(TreeNode *root) {
        // write your code here
        if (!root) return 0;
        return solve_dp(root);
    }

private:
    int min(int a, int b) {
        return a > b ? b : a;

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
    cout << res << " ";
    delete so;
    return 0;
}
