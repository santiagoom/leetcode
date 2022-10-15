
#include <iostream>
#include <cppUtils.h>

using namespace std;


class Solution_035_SearchInsertPosition_1 {
public:
    int searchInsert(vector<int> &nums, int target) {
        int pivot, left = 0, right = nums.size() - 1;
        while (left <= right) {
            pivot = left + (right - left) / 2;
            if (nums[pivot] == target) return pivot;
            if (target < nums[pivot]) right = pivot - 1;
            else left = pivot + 1;
        }
        return left;
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
                    