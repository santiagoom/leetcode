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

class Solution_p1 {
public:
    TreeNode *buildTree(vector<int> pre, vector<int> vin) {
        if (pre.empty() || pre.size() != vin.size())
            return nullptr;
        int length = pre.size();
        return constructHelper(pre, 0, length - 1, vin, 0, length - 1);
    }

    TreeNode *constructHelper(vector<int> pre, int preStart, int preEnd, vector<int> vin, int vinStart, int vinEnd) {
//        int rootVal = pre[preStart];
        int rootVal = pre[preEnd];
        TreeNode *root = new TreeNode(rootVal);

        if (pre[preStart] == pre[preEnd]) {
            if (vin[vinStart] == vin[vinEnd] && pre[preStart] == vin[vinStart])
                return root;
            else
                throw invalid_argument("invalid input");
        }

        int rootPos = vinStart;
//        wrong
//        for (int i = 0; i <= vin.size(); ++i) {
//            if (vin[i] == rootVal) {
//                break;
//            }
//            rootPos++;
//        }

        for (int i = vinStart; i <= vinEnd; ++i) {
            if (vin[i] == rootVal) {
                break;
            }
            rootPos++;
        }

//        while (vinStart <= vinEnd && rootVal != vin[rootPos])
//            rootPos++;
        if (rootPos == vinEnd && rootVal != vin[rootPos])
            throw invalid_argument("invalid_argument");

        CppUtils::print(rootPos);
//        if (vinStart == vinEnd && vin[rootPos] != rootVal)
//            throw invalid_argument("invalid input");

        int leftLength = rootPos - vinStart;
//        int leftEnd = preStart + leftLength;
        if (leftLength > 0)
            root->left = constructHelper(pre, preStart, preStart + leftLength - 1, vin, vinStart,
                                         rootPos - 1);
        if (leftLength < preEnd - preStart)
            root->right = constructHelper(pre, preStart + leftLength, preEnd - 1, vin, rootPos + 1,
                                          vinEnd);
        return root;
    }
};


int main() {
//    auto *so = new Solution();
    auto *so = new Solution_p1();

    vector<int> post{9, 15, 7, 20, 3};
    vector<int> vin{9, 3, 15, 20, 7};

    auto res = so->buildTree(post, vin);
    CppUtils::postorderTraversal(res);
    cout << endl;
    CppUtils::inorderTraversal(res);
    delete so;
    return 0;
}