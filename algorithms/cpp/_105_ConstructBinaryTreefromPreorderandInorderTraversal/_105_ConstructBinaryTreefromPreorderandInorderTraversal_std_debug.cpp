#include <iostream>
#include <vector>
#include <myTreeNode.h>
#include <myutils.h>

using namespace std;

class Solution {

public:
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        if (preorder.size() == 0 || inorder.size() == 0) return NULL;
        TreeNode *root = new TreeNode(preorder[0]);

        int index = 0;
        for (unsigned int i = 0; i < inorder.size(); i++) {
            if (inorder[i] == preorder[0]) {
                index = i;
                break;
            }
        }

        if (index == 0 && inorder[0] != preorder[0]) return NULL;

        vector<int> PreLeft(preorder.begin() + 1, preorder.begin() + 1 + index);
        vector<int> PreRight(preorder.begin() + 1 + index, preorder.end());
        vector<int> InLeft(inorder.begin(), inorder.begin() + index);
        vector<int> InRight(inorder.begin() + index + 1, inorder.end());

        root->left = buildTree(PreLeft, InLeft);
        root->right = buildTree(PreRight, InRight);
        return root;
    }

};

int main() {
    auto *so = new Solution();

    vector<int> pre{1, 2, 4, 7, 3, 5, 6, 8};
    vector<int> vin{4, 7, 2, 1, 5, 3, 8, 6};

    auto res = so->buildTree(pre, vin);
    preorderTraversal(res);
    cout << endl;
    inorderTraversal(res);
    delete so;
    return 0;
}
