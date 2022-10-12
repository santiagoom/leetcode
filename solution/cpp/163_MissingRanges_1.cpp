
#include <iostream>
#include <cppUtils.h>

using namespace std;

                    
class Solution {
public:
    vector<string> findMissingRanges(vector<int>& nums, int lower, int upper) {
        vector<string> result;
        int prev = lower - 1;
        for (size_t i = 0; i <= nums.size(); i++) {
            int curr = (i < nums.size()) ? nums[i] : upper + 1;
            if (prev + 1 <= curr - 1) {
                result.push_back(formatRange(prev + 1, curr - 1));
            }
            prev = curr;
        }
        return result;
    }

    // formats range in the requested format
    string formatRange(int lower, int upper) {
        if (lower == upper) {
            return to_string(lower);
        }
        return to_string(lower) + "->" + to_string(upper);
    }
};

                    
int main() {
    vector<int> nums{2, 7, 11, 15};
    int target = 26;
    string s = "aa";
    auto *so = new Solution();
    vector<vector<int>> arrays;
    CppUtils::print(s);
    CppUtils::print_1d_vector(nums);
    CppUtils::print_2d_vector(arrays);
    delete so;
    return 0;
}
                    