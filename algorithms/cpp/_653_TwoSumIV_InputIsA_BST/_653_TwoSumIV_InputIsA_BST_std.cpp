
# include <iostream>
#include <vector>

using namespace std;

int main() {
    cout << "new file!" << endl;
    return 0;
}

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    explicit TreeNode(int val) {
        this->val = val;
        this->left = NULL;
        this->right = NULL;
    }
};

class Solution1 {
public:
    /*
     * @param : the root of tree
     * @param : the target sum
     * @return: two number from tree witch sum is n
     */
    vector<int> twoSum(TreeNode *root, int n) {
        // write your code here
        root_node = root;
        return dfs(root, n);
    }

private:
    TreeNode *root_node = NULL;

    vector<int> dfs(TreeNode *root, int n) {
        vector<int> ret;
        if (!root)
            return ret;

        ret = dfs(root->left, n);
        if (!ret.empty())
            return ret;

        if (helper(root_node, n - root->val, root)) {
            ret.push_back(root->val);
            ret.push_back(n - root->val);
            return ret;
        }

        ret = dfs(root->right, n);
        return ret;
    }

    bool helper(TreeNode *root, int val, TreeNode *node) {
        if (!root)
            return false;

        if (root->val == val) {
            if (root != node)
                return true;
            else {
                return helper(root->left, val, node) || helper(root->right, val, node);
            }
        } else if (root->val < val)
            return helper(root->right, val, node);
        else
            return helper(root->left, val, node);
    }
    // vector<int> twoSum(TreeNode* root, int k) {
    //     vector<int> ret;
    //     if (!root) return ret;
    //     unordered_set<int> s;
    //     queue<TreeNode*> q{{root}};
    //     while (!q.empty()) {
    //       auto t = q.front(); q.pop();
    //       if (s.count(k - t->val)) {
    //           ret.push_back(t->val);
    //           ret.push_back(k - t->val);
    //           return ret;
    //       }
    //       s.insert(t->val);
    //       if (t->left) q.push(t->left);
    //       if (t->right) q.push(t->right);
    //     }
    //     return ret;
    // }
};

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

class Solution2 {
public:
    /*
     * @param : the root of tree
     * @param : the target sum
     * @return: two number from tree witch sum is n
     */
    vector<int> res;
    vector<int> twoSum(TreeNode * root, int n) {
        // write your code here
        if(root == NULL)
            return res;
        collect(root);
        // for(int i = 0; i < res.size(); i++)
        // {
        //     cout << res[i] << " ";
        // }
        //collect(root);
        return find(n);
        //return res;
    }

    void collect(TreeNode *root)
    {
        if(root != NULL)
        {
            collect(root->left);
            res.push_back(root->val);
            collect(root->right);
        }
    }
    vector<int> find(int target)
    {
        int start = 0;
        int end = res.size() - 1;
        vector<int> answer;
        while(start < end)
        {
            if(res[start] + res[end] < target)
            {
                start++;
            }
            else if(res[start] + res[end] > target)
            {
                end--;
            }
            else
            {
                answer.push_back(res[start]);
                answer.push_back(res[end]);
                return answer;
            }
        }
        return {};
    }
};