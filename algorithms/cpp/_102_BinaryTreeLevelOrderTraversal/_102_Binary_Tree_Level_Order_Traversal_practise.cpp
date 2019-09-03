#include <iostream>
#include <vector>
#include <queue>


using namespace std;

//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    explicit TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    vector<int> levelOrder(TreeNode *root) {
        vector<int> res;
        queue<TreeNode *> q;
        q.push(root);
        while (!q.empty()) {
            TreeNode *curr = q.front();
            res.push_back(curr->val);
            q.pop();

            if (curr->left)
                q.push(curr->left);
            if (curr->right)
                q.push(curr->right);
        }
        return res;
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
    vector<int> res = so->levelOrder(root);
    for (int &x:res)
        cout << x << " ";
    delete so;
    return 0;
}