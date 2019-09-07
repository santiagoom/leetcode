#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int backPackIV(vector<int> &nums, int target) {
        // Write your code here
        vector<int> dp(target + 1);
        dp[0] = 1;
        for (auto x:dp) {
            cout << x << endl;
        }
        for (auto a : nums) {
            for (int i = a; i <= target; ++i) {
                dp[i] += dp[i - a];
                cout << "i:" << i << " dp[i]:" << dp[i] << endl;
            }
        }
        return dp.back();
    }
};

int main() {
    auto *so = new Solution();
//    vector<int> nums{2, 3, 6, 7};
//    int target = 7;
    vector<int> nums{1, 2, 4};
    int target = 4;
    int res = so->backPackIV(nums, target);
    cout << res << endl;
    delete so;
    return 0;
}

