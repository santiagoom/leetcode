package _122_BestTimetoBuyandSellStockII;

public class _122_BestTimetoBuyandSellStockII_std {
    public static void main(String[] args) {
        _122_BestTimetoBuyandSellStockII_std_ so = new _122_BestTimetoBuyandSellStockII_std_();

    }
}

class _122_BestTimetoBuyandSellStockII_std_ {

}

class Solution1 {
    public int maxProfit(int[] prices) {
        int i = 0;
        int valley = prices[0];
        int peak = prices[0];
        int maxprofit = 0;
        while (i < prices.length - 1) {
            while (i < prices.length - 1 && prices[i] >= prices[i + 1])
                i++;
            valley = prices[i];
            while (i < prices.length - 1 && prices[i] <= prices[i + 1])
                i++;
            peak = prices[i];
            maxprofit += peak - valley;
        }
        return maxprofit;
    }
}

class Solution2 {
    public int maxProfit(int[] prices) {
        int maxprofit = 0;
        for (int i = 1; i < prices.length; i++) {
            if (prices[i] > prices[i - 1])
                maxprofit += prices[i] - prices[i - 1];
        }
        return maxprofit;
    }
}