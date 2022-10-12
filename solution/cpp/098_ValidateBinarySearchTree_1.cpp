
#include <iostream>
#include <cppUtils.h>

using namespace std;

                    
class Solution {
public:
    bool validate(TreeNode* root, TreeNode* low, TreeNode* high) {
        // Empty trees are valid BSTs.
        if (root == nullptr) {
            return true;
        }

        // The current node's value must be between low and high.
        if ((low != nullptr and root->val <= low->val) or
            (high != nullptr and root->val >= high->val)) {
            return false;
        }

        // The left and right subtree must also be valid.
        return validate(root->right, root, high) and
               validate(root->left, low, root);
    }

    bool isValidBST(TreeNode* root) {
        return validate(root, nullptr, nullptr);
    }
};

                    
int main() {
    vector<int> nums{2, 7, 11, 15};
    int target = 26;
    string s = "aa";
    auto *so = new Solution();
    vector<vector<int>> arrays;
    CppUtils::print(s);
    CppUtils::print_1d_vector(nums);
    CppUtils::print_2d_vector(arrays);
    delete so;
    return 0;
}
                    