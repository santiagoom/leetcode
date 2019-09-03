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
    vector<vector<int>> zigzagLevelOrder(TreeNode *root) {
        vector<vector<int>> res;
        if (!root)
            return res;

        queue<TreeNode *> q;
        q.push(root);
        bool flag = true;
        while (!q.empty()) {
            int level_length = q.size();
            vector<int> level;
            flag = !flag;
            for (int i = 0; i < level_length; i++) {
                TreeNode *curr = q.front();
                level.push_back(curr->val);
                q.pop();
                if (curr->left)
                    q.push(curr->left);
                if (curr->right)
                    q.push(curr->right);
            }
            if (flag)
                reverse(level.begin(), level.end());
            res.push_back(level);
        }
        return res;
    }
};

int main() {
    //        1
    //     /    \
    //    2     3
    //  /  \   / \
    // 4   5  6  7
    auto *so = new Solution();
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);
    vector<vector<int>> res = so->zigzagLevelOrder(root);
    for (auto &level:res) {
        for (int &ele:level)
            cout << ele << " ";
        cout << endl;
    }
    delete so;
    return 0;
}