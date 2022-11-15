
from typing import List  
from utils import *
import collections
                    
class Solution_309_BestTimetoBuyandSellStockwithCooldown_1:
    def maxProfit(self, prices):
        """
        :type prices: List[int]
        :rtype: int
        """
        sold, held, reset = float('-inf'), float('-inf'), 0

        for price in prices:
            # Alternative: the calculation is done in parallel.
            # Therefore no need to keep temporary variables
            #sold, held, reset = held + price, max(held, reset-price), max(reset, sold)

            pre_sold = sold
            sold = held + price
            held = max(held, reset - price)
            reset = max(reset, pre_sold)

        return max(sold, reset)

if __name__ == "__main__":
    nums = [2, 7, 11, 15]
    target = 26
    so = Solution_309_BestTimetoBuyandSellStockwithCooldown_1()
    s = "aa"
    arrays = [[1, 2, 3], [4, 5, 6]]
    print(arrays)
                    