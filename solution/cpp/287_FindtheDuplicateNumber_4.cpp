
#include <iostream>
#include <cppUtils.h>
using namespace std;

                    
class Solution_287_FindtheDuplicateNumber_4 {
public:
    int store(vector<int>& nums, int cur) {
        if (cur == nums[cur])
            return cur;
        int nxt = nums[cur];
        nums[cur] = cur;
        return store(nums, nxt);
    }
    
    int findDuplicate(vector<int>& nums) {
        return store(nums, 0);
    }
};

int main() {
auto *so = new Solution_287_FindtheDuplicateNumber_4();
vector<int> nums{2, 7, 11, 15};
int target = 26;
string s = "aa";
vector<vector<int>> arrays;
CppUtils::print(s);
CppUtils::print_1d_vector(nums);
CppUtils::print_2d_vector(arrays);
return 0;
}
                    