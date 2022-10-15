
#include <iostream>
#include <cppUtils.h>
using namespace std;

                    
class Solution_098_ValidateBinarySearchTree_3 {
private:
    TreeNode* prev = nullptr;

public:
    bool isValidBST(TreeNode* root) {
        return inorder(root);
    }

    bool inorder(TreeNode* root) {
        if (root == nullptr) {
            return true;
        }
        if (!inorder(root->left)) {
            return false;
        }
        if (prev != nullptr && root->val <= prev->val) {
            return false;
        }
        prev = root;
        return inorder(root->right);
    }
};

int main() {
vector<int> nums{2, 7, 11, 15};
int target = 26;
string s = "aa";
vector<vector<int>> arrays;
CppUtils::print(s);
CppUtils::print_1d_vector(nums);
CppUtils::print_2d_vector(arrays);
return 0;
}
                    