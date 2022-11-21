#include <iostream>
#include <cppUtils.h>

using namespace std;


class Solution_209_MinimumSizeSubarraySum_1 {
public:
    int minSubArrayLen(int s, vector<int> &nums) {
        int n = nums.size();
        int ans = INT_MAX;
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                int sum = 0;
                for (int k = i; k <= j; k++) {
                    sum += nums[k];
                }
                if (sum >= s) {
                    ans = min(ans, (j - i + 1));
                    break; //Found the smallest subarray with sum>=s starting with index i, hence move to next index
                }
            }
        }
        return (ans != INT_MAX) ? ans : 0;
    }
};

int main() {
    auto *so = new Solution_209_MinimumSizeSubarraySum_1();
    vector<int> nums{2, 7, 11, 15};
    int target = 26;
    string s = "aa";
    vector<vector<int>> arrays;
    CppUtils::print(s);
    CppUtils::print_1d_vector(nums);
    CppUtils::print_2d_vector(arrays);
    return 0;
}
                    