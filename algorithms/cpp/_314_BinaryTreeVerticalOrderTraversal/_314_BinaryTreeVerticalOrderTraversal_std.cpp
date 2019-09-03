#include <iostream>
#include <vector>
#include <map>
#include <queue>

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
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> verticalOrder(TreeNode *root) {
        map<int, vector<int>> mp;
        queue<pair<TreeNode *, int> > q;
        if (root != NULL) {
            q.push(make_pair(root, 0));
        }
        while (!q.empty()) {
            pair<TreeNode *, int> now = q.front();
            q.pop();
            mp[now.second].push_back(now.first->val);
            if (now.first->left != NULL) {
                q.push(make_pair(now.first->left, now.second - 1));
            }
            if (now.first->right != NULL) {
                q.push(make_pair(now.first->right, now.second + 1));
            }
        }
        vector<vector<int>> ans;
        for (map<int, vector<int>>::iterator it = mp.begin(); it != mp.end(); it++) {
            ans.push_back(it->second);
        }
        return ans;
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
    vector<vector<int>> res = so->verticalOrder(root);
    for (auto &level:res) {
        for (int &ele:level)
            cout << ele << " ";
        cout << endl;
    }
    delete so;
    return 0;
}