#include <iostream>
#include <vector>
#include <myutils.h>

using namespace std;

class Solution {
public:
    int cutRod(vector<int> &price, int n) {
        vector<int> dp(n + 1, 0);
        for (int i = 1; i <= n; i++) {
            int max_value = INT_MIN;
            for (int j = 0; j < i; j++) {
                max_value = max(max_value, price[j] + dp[i - j - 1]);
            }
            dp[i] = max_value;
        }
        print_1d_vector(dp);
        return dp[n];
    }
};

int main() {
    auto *so = new Solution();
    vector<int> nums{1, 5, 8, 9, 10, 17, 17, 20};
    int size = nums.size();
    int res = so->cutRod(nums, size);
    print(res);
    delete so;
    return 0;
}
