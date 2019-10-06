#include <iostream>
#include <vector>
#include <myutils.h>

using namespace std;

class Solution {
//    vector<int> prices{7, 1, 5, 3, 6, 4};
//  统计卖一次的最高利润，然后从后向前减在加上前边的利润
public:
    int maxProfit(vector<int> &prices) {
        if (prices.empty()) {
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

        print_1d_vector(profit);

        int sell = prices[prices.size() - 1];
        int best = 0;
        for (int i = prices.size() - 2; i >= 0; i--) {
            best = max(best, sell - prices[i] + profit[i]);
            print(best);
            sell = max(sell, prices[i]);
            print(sell);
            print();
        }
        return best;
    }
};

class Solution3 {
//    vector<int> prices{7, 1, 5, 3, 6, 4};
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

        print_1d_vector(profit_front);

        // get profit in the back of prices, (i, n)
        vector<int> profit_back = vector<int>(n, 0);
        for (int i = n - 2, peak = prices[n - 1]; i >= 0; --i) {
            profit_back[i] = max(profit_back[i + 1], peak - prices[i]);
            peak = max(peak, prices[i]);
        }

        print_1d_vector(profit_back);


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
    vector<int> prices{7, 1, 5, 3, 6, 4};
    int res = so->maxProfit(prices);
    cout << res << endl;
    delete so;
    return 0;
}
