
#include <iostream>
#include <cppUtils.h>
using namespace std;

                    
class Solution_098_ValidateBinarySearchTree_2 {
private:
    stack<TreeNode*> stk, lower_limits, upper_limits;

public:
    void update(TreeNode* root, TreeNode* low, TreeNode* high) {
        stk.push(root);
        lower_limits.push(low);
        upper_limits.push(high);
    }
    bool isValidBST(TreeNode* root) {
        TreeNode* low = nullptr;
        TreeNode* high = nullptr;
        update(root, low, high);

        while (!stk.empty()) {
            root = stk.top();
            stk.pop();
            low = lower_limits.top();
            lower_limits.pop();
            high = upper_limits.top();
            upper_limits.pop();

            if (root == nullptr) {
                continue;
            }

            TreeNode* val_node = root;
            if (low != nullptr and val_node->val <= low->val) {
                return false;
            }
            if (high != nullptr and val_node->val >= high->val) {
                return false;
            }
            update(root->right, val_node, high);
            update(root->left, low, val_node);
        }
        return true;
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
                    