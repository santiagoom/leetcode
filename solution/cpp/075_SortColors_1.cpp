
#include <iostream>
#include <cppUtils.h>

using namespace std;


class Solution_075_SortColors_1 {
public:
    /*
    Dutch National Flag problem solution.
    */
    void sortColors(vector<int> &nums) {
        // for all idx < p0 : nums[idx < p0] = 0
        // curr is an index of element under consideration
        int p0 = 0, curr = 0;
        // for all idx > p2 : nums[idx > p2] = 2
        int p2 = nums.size() - 1;

        while (curr <= p2) {
            if (nums[curr] == 0) {
                swap(nums[curr++], nums[p0++]);
            } else if (nums[curr] == 2) {
                swap(nums[curr], nums[p2--]);
            } else curr++;
        }
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
                    