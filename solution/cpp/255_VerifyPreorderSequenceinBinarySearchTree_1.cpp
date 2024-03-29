
#include <iostream>
#include <cppUtils.h>
using namespace std;

                    
class Solution_255_VerifyPreorderSequenceinBinarySearchTree_1 {
public:
    bool verifyPreorder(vector<int>& preorder) {
        stack<int> stk;
        int lower_bound = INT_MIN;
        for(int i = 0; i < preorder.size(); i++){
            if(stk.empty() || preorder[i] < preorder[i - 1]){
                if(preorder[i] <= lower_bound) return false;
                stk.push(preorder[i]);
            }else{
                while(!stk.empty() && stk.top() < preorder[i]){
                    lower_bound = stk.top();
                    stk.pop();
                }
                stk.push(preorder[i]);
            }
        }
        
        return true;
    }
};

int main() {
auto *so = new Solution_255_VerifyPreorderSequenceinBinarySearchTree_1();
vector<int> nums{2, 7, 11, 15};
int target = 26;
string s = "aa";
vector<vector<int>> arrays;
CppUtils::print(s);
CppUtils::print_1d_vector(nums);
CppUtils::print_2d_vector(arrays);
return 0;
}
                    