
from typing import List  
from utils import *
import collections
                    
class Solution_309_BestTimetoBuyandSellStockwithCooldown_2:
    def maxProfit(self, prices):
        """
        :type prices: List[int]
        :rtype: int
        """
        L = len(prices)
        # padding the array with additional zero to simply the logic
        MP = [0] * (L + 2)

        for i in range(L-1, -1, -1):
            C1 = 0
            # Case 1). buy and sell the stock
            for sell in range(i + 1, L):
                profit = (prices[sell] - prices[i]) + MP[sell + 2]
                C1 = max(profit, C1)

            # Case 2). do no transaction with the stock p[i]
            C2 = MP[i + 1]

            # sum up two cases
            MP[i] = max(C1, C2)

        return MP[0]

if __name__ == "__main__":
    nums = [2, 7, 11, 15]
    target = 26
    so = Solution_309_BestTimetoBuyandSellStockwithCooldown_2()
    s = "aa"
    arrays = [[1, 2, 3], [4, 5, 6]]
    print(arrays)
                    