#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int> &prices) {
        if (prices.size() == 0) {
            return 0;
        }

        vector<int> profit(prices.size());
        int buy = 0;
        buy = prices[0];
        profit[0] = 0;
        for (int i = 1; i < prices.size(); i++) {
            profit[i] = max(profit[i - 1], prices[i] - buy);
            buy = min(buy, prices[i]);
        }

        int sell = prices[prices.size() - 1];
        int best = 0;
        for (int i = prices.size() - 2; i >= 0; i--) {
            best = max(best, sell - prices[i] + profit[i]);
            sell = max(sell, prices[i]);
        }

        return best;
    }
};

//class Solution2 {
//public:
//    int maxProfit(vector<int> &prices) {
//        if (prices.empty()) return 0;
//        int n = prices.size(), g[n][3] = {0}, l[n][3] = {0};
//        for (int i = 1; i < prices.size(); ++i) {
//            int diff = prices[i] - prices[i - 1];
//            for (int j = 1; j <= 2; ++j) {
//                l[i][j] = max(g[i - 1][j - 1] + max(diff, 0), l[i - 1][j] + diff);
//                g[i][j] = max(l[i][j], g[i - 1][j]);
//            }
//        }
//        return g[n - 1][2];
//    }
//};
class Solution1 {
public:
    int maxProfit(vector<int> &prices) {
        if (prices.empty()) return 0;
        int g[3] = {0};
        int l[3] = {0};
        for (int i = 0; i < prices.size() - 1; ++i) {
            int diff = prices[i + 1] - prices[i];
            for (int j = 2; j >= 1; --j) {
                l[j] = max(g[j - 1] + max(diff, 0), l[j] + diff);
                g[j] = max(l[j], g[j]);
            }
        }
        return g[2];
    }
};

class Solution3 {
public:
    /**
     * @param prices: Given an integer array
     * @return: Maximum profit
     */
    int maxProfit(vector<int> &prices) {
        if (prices.size() <= 1) return 0;

        int n = prices.size();
        // get profit in the front of prices
        vector<int> profit_front = vector<int>(n, 0);
        for (int i = 1, valley = prices[0]; i < n; ++i) {
            profit_front[i] = max(profit_front[i - 1], prices[i] - valley);
            valley = min(valley, prices[i]);
        }
        // get profit in the back of prices, (i, n)
        vector<int> profit_back = vector<int>(n, 0);
        for (int i = n - 2, peak = prices[n - 1]; i >= 0; --i) {
            profit_back[i] = max(profit_back[i + 1], peak - prices[i]);
            peak = max(peak, prices[i]);
        }
        // add the profit front and back
        int profit = 0;
        for (int i = 0; i < n; ++i) {
            profit = max(profit, profit_front[i] + profit_back[i]);
        }

        return profit;
    }
};

int main() {
    auto *so = new Solution3();
    auto *so1 = new Solution1();
    vector<int> prices{7, 1, 5, 3, 6, 4};
    int res = so->maxProfit(prices);
    int res1 = so1->maxProfit(prices);
    cout << res << endl;
    cout << res1 << endl;
    delete so;
    return 0;
}
