#include <iostream>
#include <vector>
#include <myutils.h>

using namespace std;


/**
* This reference program is provided by @jiuzhang.com
* Copyright is reserved. Please indicate the source for forwarding
*/

class Solution {
public:
    /**
     * @param nums: The integer array
     * @return: The length of LIS (longest increasing subsequence)
     */
    int longestIncreasingSubsequence(vector<int> nums) {
        int f[nums.size()];
        int max = 0;
        for (int i = 0; i < nums.size(); i++) {
            f[i] = 1;
            for (int j = 0; j < i; j++) {
                if (nums[j] < nums[i]) {
                    f[i] = f[i] > f[j] + 1 ? f[i] : f[j] + 1;
                }
            }
            if (f[i] > max) {
                max = f[i];
            }
        }
        return max;
    }
};

int main() {
//    2019-09-08 14:38:36
//2019-09-08 14:46:15
    auto *so = new Solution();
//    vector<int> nums{10, 9, 2, 5, 3, 7, 101, 18};
    vector<int> nums{0};
    int res = so->longestIncreasingSubsequence(nums);
    print(res);
    delete so;
    return 0;
}
