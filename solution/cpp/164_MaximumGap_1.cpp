
#include <iostream>
#include <cppUtils.h>

using namespace std;


class Solution_164_MaximumGap_1 {
public:
    int maximumGap(vector<int> &nums) {
        if (nums.empty() || nums.size() < 2)            // check if array is empty or small sized
            return 0;

        sort(nums.begin(), nums.end());                 // sort the array

        int maxGap = 0;

        for (int i = 0; i < nums.size() - 1; i++)
            maxGap = max(nums[i + 1] - nums[i], maxGap);

        return maxGap;
    }
};

int main() {
    auto *so = new Solution_164_MaximumGap_1();
    vector<int> nums{2, 7, 11, 15};
    int target = 26;
    string s = "aa";
    vector<vector<int>> arrays;
    CppUtils::print(s);
    CppUtils::print_1d_vector(nums);
    CppUtils::print_2d_vector(arrays);
    return 0;
}
                    