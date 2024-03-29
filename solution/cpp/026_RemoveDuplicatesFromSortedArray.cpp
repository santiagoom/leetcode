#include <iostream>
#include <vector>
#include <cppUtils.h>

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int> &nums) {
        if (nums.empty())
            return 0;
        int i = 0;
        for (int j = 1; j < nums.size(); j++) {
            if (nums[j - 1] != nums[j]) {
                i++;
                nums[i] = nums[j];
            }
        }
        return i + 1;
    }
};

int main() {
    auto *so = new Solution();
    vector<int> nums{0, 0, 1, 1, 1, 2, 2, 3, 3, 4, 5};
    int len = so->removeDuplicates(nums);
    CppUtils::print_1d_vector(nums);
    return 0;
}
