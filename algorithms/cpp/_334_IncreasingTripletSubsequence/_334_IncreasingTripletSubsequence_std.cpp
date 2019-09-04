#include <iostream>
#include <vector>

using namespace std;


/**
* This reference program is provided by @jiuzhang.com
* Copyright is reserved. Please indicate the source for forwarding
*/

class Solution {
//    直接遍历一遍数组，用一个维护一个最小值以及次小值，如果当前值小于最小值则更新最小值，若大于最小值小于次小值则更新次小值，若大于次小值则返回true。


public:
    bool increasingTriplet(vector<int> &nums) {
        if (nums.size() < 3)
            return false;
        vector<int> ans(2, INT_MAX);

        for (int now : nums) {
            if (now <= ans[0]) {
                ans[0] = now;
            } else if (now <= ans[1]) {
                ans[1] = now;
            } else {
                return true;
            }
        }
        return false;
    }
};

int main() {
    auto *so = new Solution();
    vector<int> nums{2147483646, 2147483647, 2147483647};
    bool res = so->increasingTriplet(nums);
    cout << res << endl;
    delete so;
    return 0;
}

