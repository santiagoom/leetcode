#include <iostream>
#include <vector>
#include <cppUtils.h>

using namespace std;

class Solution {
public:
    typedef vector<int>::iterator Iter;

    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
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

int main() {
    auto *so = new Solution();

    vector<int> post{9, 15, 7, 20, 3};
    vector<int> vin{9, 3, 15, 20, 7};

    auto res = so->buildTree(vin, post);
    CppUtils::preorderTraversal(res);
    cout << endl;
    CppUtils::inorderTraversal(res);
    delete so;
    return 0;
}