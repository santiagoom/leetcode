#include <iostream>
#include <vector>
#include <myutils.h>

using namespace std;

class Solution {
};

class Solution1 {
//    Time Limit Exceeded
public:
    /**
     * @param k: An integer
     * @param prices: Given an integer array
     * @return: Maximum profit
     */
    int maxProfit(int k, vector<int> &prices) {
        if (prices.size() <= 1 || k <= 0) return 0;

        int n = prices.size();
        // k >= prices.length / 2 ==> multiple transactions Stock II
        if (k >= n / 2) {
            int profit_max = 0;
            for (int i = 1; i < n; ++i) {
                int diff = prices[i] - prices[i - 1];
                if (diff > 0) {
                    profit_max += diff;
                }
            }
            return profit_max;
        }

        vector<vector<int> > f = vector<vector<int> >(n + 1, vector<int>(k + 1, 0));
        for (int j = 1; j <= k; ++j) {
            for (int i = 1; i <= n; ++i) {
                for (int x = 0; x <= i; ++x) {
                    f[i][j] = max(f[i][j], f[x][j - 1] + profit(prices, x + 1, i));
                }
            }
        }

        return f[n][k];
    }

private:
    int profit(vector<int> &prices, int l, int u) {
        if (l >= u) return 0;

        int valley = INT_MAX;
        int profit_max = 0;
        for (int i = l - 1; i < u; ++i) {
            profit_max = max(profit_max, prices[i] - valley);
            valley = min(valley, prices[i]);
        }

        return profit_max;
    }
};

/**
* This reference program is provided by @jiuzhang.com
* Copyright is reserved. Please indicate the source for forwarding
*/

class Solution2 {
public:
    int maxProfit(int k, vector<int> &prices) {
        if (prices.empty())
            return 0;

        int ans = 0;
        if (k >= prices.size() / 2) {
            for (int i = 1; i < prices.size(); ++i) {
                if (prices[i] - prices[i - 1] > 0) {
                    ans += prices[i] - prices[i - 1];
                }
            }
        } else {
            vector<int> local(k + 1);
            vector<int> global(k + 1);

            for (int i = 0; i < prices.size() - 1; ++i) {
                int increase = prices[i + 1] - prices[i];

                for (int j = k; j >= 1; --j) {
                    local[j] = max(global[j - 1] + max(increase, 0), local[j] + increase);
                    global[j] = max(global[j], local[j]);
                }
            }
            ans = global[k];
        }
        return ans;
    }
};

int main() {
    auto *so = new Solution();
    print(8);
    vector<int> nums{};
    delete so;
    return 0;
}
