
                        
                    import java.util.*;
                    import utils.TreeNode;
                    import utils.ListNode;
                                            
                                                
class Solution_122_BestTimetoBuyandSellStockII_3 {
    public int maxProfit(int[] prices) {
        int maxprofit = 0;
        for (int i = 1; i < prices.length; i++) {
            if (prices[i] > prices[i - 1])
                maxprofit += prices[i] - prices[i - 1];
        }
        return maxprofit;
    }
}

                                                public class _122_BestTimetoBuyandSellStockII_3 {
                                                    public static void main(String[] args) {
                                                        Solution_122_BestTimetoBuyandSellStockII_3 so = new Solution_122_BestTimetoBuyandSellStockII_3();
                                                    }
                                                }
                                                