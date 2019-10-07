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

//假设一共有 n 天, 那么这 n 天最多能够完成 n / 2 比交易, 也就是说, 当 k * 2 >= n 时, 就变成了 买卖股票的最佳时机 II, 反之, 我们可以作为动态规划问题解决:
//
//定义:
//
//globalbest[i][j] 表示前i天，至多进行j次交易时的最大获益
//        mustsell[i][j] 表示前i天，至多进行j次交易，并且第i天卖出手中的股票时的最大获益
//        状态转移:
//
//mustsell[i][j] = max(globalbest[i - 1][j - 1], mustsell[i - 1][j]) + prices[i] - prices[i - 1]
//globalbest[i][j] = max(globalbest[i - 1][j], mustsell[i][j])
//边界: mustsell[0][i] = globalbest[0][i] = 0
//
//优化: 滚动数组优化两个状态的空间至一维数组.

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
