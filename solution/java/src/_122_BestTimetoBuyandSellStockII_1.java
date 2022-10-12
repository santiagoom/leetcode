
                        
                    import java.util.*;
                    import utils.TreeNode;
                    import utils.ListNode;
                                            
                                                
class Solution_122_BestTimetoBuyandSellStockII_1 {
    public int maxProfit(int[] prices) {
        return calculate(prices, 0);
    }

    public int calculate(int prices[], int s) {
        if (s >= prices.length)
            return 0;
        int max = 0;
        for (int start = s; start < prices.length; start++) {
            int maxprofit = 0;
            for (int i = start + 1; i < prices.length; i++) {
                if (prices[start] < prices[i]) {
                    int profit = calculate(prices, i + 1) + prices[i] - prices[start];
                    if (profit > maxprofit)
                        maxprofit = profit;
                }
            }
            if (maxprofit > max)
                max = maxprofit;
        }
        return max;
    }
}

                                                public class _122_BestTimetoBuyandSellStockII_1 {
                                                    public static void main(String[] args) {
                                                        Solution_122_BestTimetoBuyandSellStockII_1 so = new Solution_122_BestTimetoBuyandSellStockII_1();
                                                    }
                                                }
                                                