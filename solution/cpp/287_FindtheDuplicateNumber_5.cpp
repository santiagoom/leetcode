
#include <iostream>
#include <cppUtils.h>
using namespace std;

                    
class Solution_287_FindtheDuplicateNumber_5 {
public:
    int findDuplicate(vector<int>& nums) {
        while (nums[0] != nums[nums[0]])
            swap(nums[0], nums[nums[0]]);
        return nums[0];
    }
};

int main() {
auto *so = new Solution_287_FindtheDuplicateNumber_5();
vector<int> nums{2, 7, 11, 15};
int target = 26;
string s = "aa";
vector<vector<int>> arrays;
CppUtils::print(s);
CppUtils::print_1d_vector(nums);
CppUtils::print_2d_vector(arrays);
return 0;
}
                    