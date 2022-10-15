
#include <iostream>
#include <cppUtils.h>
using namespace std;

                    
class Solution_104_MaximumDepthofBinaryTree_1 {
  public:
    int maxDepth(TreeNode *root) {
      if (root == NULL) {
        return 0;
      }
      return max(1 + maxDepth(root -> left), 1 + maxDepth(root -> right));
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
                    