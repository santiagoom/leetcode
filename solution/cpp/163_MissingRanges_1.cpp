
#include <iostream>
#include <cppUtils.h>

using namespace std;


class Solution_163_MissingRanges_1 {
public:
    vector<string> findMissingRanges(vector<int> &nums, int lower, int upper) {
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
    auto *so = new Solution_163_MissingRanges_1();
    vector<int> nums = {0, 1, 3, 50, 75};
    int lower = 0;
    int upper = 99;
    vector<string> res = so->findMissingRanges(nums, lower, upper);
    CppUtils::print_1d_vector(res);
    delete so;
    return 0;
}
                    