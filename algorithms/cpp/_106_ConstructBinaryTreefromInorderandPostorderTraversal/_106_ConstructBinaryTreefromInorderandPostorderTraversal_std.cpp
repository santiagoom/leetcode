#include <iostream>
#include <vector>
#include <myTreeNode.h>
#include <myutils.h>

using namespace std;

class Solution {
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

class Solution1 {
public:
    /**
     * @param inorder: A list of integers that inorder traversal of a tree
     * @param postorder: A list of integers that postorder traversal of a tree
     * @return: Root of a tree
     */

    TreeNode *buildTreeCore(vector<int> inorder, vector<int> postorder) {
        int len = inorder.size();
        TreeNode *root = new TreeNode(postorder[len - 1]);
        int pos = 0;
        while (pos < len) {
            if (inorder[pos] == postorder[len - 1]) {
                break;
            }
            ++pos;
        }
        if (pos > 0) {
            vector<int> ii(inorder.begin(), inorder.begin() + pos);
            vector<int> pp(postorder.begin(), postorder.begin() + pos);
            root->left = buildTreeCore(ii, pp);
        }
        if (pos < len - 1) {
            vector<int> ii(inorder.begin() + pos + 1, inorder.end());
            vector<int> pp(postorder.begin() + pos, postorder.end() - 1);
            root->right = buildTreeCore(ii, pp);
        }
        return root;
    }

    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
        // write your code here
        if (inorder.empty() || postorder.empty() || inorder.size() != postorder.size()) {
            return nullptr;
        }
        return buildTreeCore(inorder, postorder);
    }
};

class Solution2 {
    /**
     *@param inorder : A list of integers that inorder traversal of a tree
     *@param postorder : A list of integers that postorder traversal of a tree
     *@return : Root of a tree
     */
public:
    typedef vector<int>::iterator Iter;

    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
        // write your code here
        if (inorder.size() == 0)
            return NULL;
        return buildTreeRecur(inorder.begin(), inorder.end(), postorder.begin(),
                              postorder.end());
    }

    TreeNode *buildTreeRecur(Iter istart, Iter iend, Iter pstart, Iter pend) {
        if (istart == iend)return NULL;
        int rootval = *(pend - 1);
        Iter iterroot = find(istart, iend, rootval);
        TreeNode *res = new TreeNode(rootval);
        res->left = buildTreeRecur(istart, iterroot, pstart, pstart + (iterroot - istart));
        res->right = buildTreeRecur(iterroot + 1, iend, pstart + (iterroot - istart), pend - 1);
        return res;
    }
};

class Solution3 {
public:
    /**
     * @param inorder: A list of integers that inorder traversal of a tree
     * @param postorder: A list of integers that postorder traversal of a tree
     * @return: Root of a tree
     */
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
        // write your code here
        int n = inorder.size(), m = postorder.size();
//        if(n != m) return NULL;
        return helper(inorder, postorder, 0, n - 1, 0, n - 1);
    }

private:
    TreeNode *helper(vector<int> &inorder, vector<int> &postorder, int s1, int e1, int s2, int e2) {
        if (s1 > e1) return NULL;

        TreeNode *buff = new TreeNode(postorder[e2]);
        int i = s1;
        while (inorder[i] != postorder[e2]) i++;

        buff->left = helper(inorder, postorder, s1, i - 1, s2, s2 + i - 1 - s1);
        buff->right = helper(inorder, postorder, i + 1, e1, s2 + i - s1, e2 - 1);

        return buff;
    }
};

int main() {
    auto *so = new Solution();
    vector<int> nums{};
    delete so;
    return 0;
}
