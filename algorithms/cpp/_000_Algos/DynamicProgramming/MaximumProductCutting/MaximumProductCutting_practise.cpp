#include <iostream>
#include <vector>
#include <myutils.h>

using namespace std;

class Solution {
public:
    int maxProd(int n) {
        vector<int> dp(n + 1, 0);
        for (int i = 1; i <= n; i++) {
            int max_value = 0;
            for (int j = 1; j <= i / 2; j++) {
                max_value = max(max_value, (i - j) * j, dp[i - j] * j);
//                print(max_value);
            }
            print();
            dp[i] = max_value;
        }
        print_1d_vector(dp);
        return dp[n];
    }

    int max(int a, int b) { return (a > b) ? a : b; }

    int max(int a, int b, int c) { return max(a, max(b, c)); }
};

int main() {
    auto *so = new Solution();
    int res = so->maxProd(10);
    print(res);
    delete so;
    return 0;
}
