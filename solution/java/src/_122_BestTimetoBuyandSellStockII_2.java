
                        
                    import java.util.*;
                    import utils.TreeNode;
                    import utils.ListNode;
                                            
                                                
class Solution_122_BestTimetoBuyandSellStockII_2 {
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

                                                public class _122_BestTimetoBuyandSellStockII_2 {
                                                    public static void main(String[] args) {
                                                        Solution_122_BestTimetoBuyandSellStockII_2 so = new Solution_122_BestTimetoBuyandSellStockII_2();
                                                    }
                                                }
                                                