#include <iostream>
#include <vector>
#include <cppUtils.h>

using namespace std;


class Solution {
public:
    int maxSubArray(vector<int> &nums) {
        if (nums.empty())
            return 0;
        return helper(nums, 0, nums.size() - 1);

    }

    int helper(vector<int> &nums, int start, int end) {
        if (start == end)
            return nums[start];

        int mid = (end + start) / 2;

        int left = helper(nums, start, mid);
        int right = helper(nums, mid + 1, end);
        int crossingSum = maxCrossingSum(nums, start, end, mid);
        return max(left, right, crossingSum);
    }

    int maxCrossingSum(vector<int> &nums, int start, int end, int mid) {
        int sum = 0;
        int left_sum = INT_MIN;
        for (int i = mid; i >= start; i--) {
            sum = sum + nums[i];
            if (sum > left_sum)
                left_sum = sum;
        }
        sum = 0;
        int right_sum = INT_MIN;
        for (int i = mid + 1; i <= end; i++) {
            sum = sum + nums[i];
            if (sum > right_sum)
                right_sum = sum;
        }
        return left_sum + right_sum;
    }

    int max(int a, int b, int c) {
        return (a > b ? a : b) > c ? (a > b ? a : b) : c;
    }
};

class Solution_p1 {
public:
    int maxSubArray(vector<int> &nums) {
        if (nums.empty()) return 0;
        int maxValue = nums[0];
        int curr = nums[0];
        for (int i = 1; i < nums.size(); ++i) {
            if (curr < 0)
                curr = nums[i];
            else {
                curr += nums[i];
            }
            if (curr > maxValue)
                maxValue = curr;
        }
        return maxValue;
    }
};

int main() {
//    auto *so = new Solution();
    auto *so = new Solution_p1();
    vector<int> nums{-2, 1, -3, 4, -1, 2, 1, -5, 4};
    int res = so->maxSubArray(nums);
    CppUtils::print(res);
    delete so;
    return 0;
}

