
from typing import List  
from utils import *
import collections
                    
class Solution_322_CoinChange_3:
    def coinChange(self, coins: List[int], amount: int) -> int:
        dp = [float('inf')] * (amount + 1)
        dp[0] = 0
        
        for coin in coins:
            for x in range(coin, amount + 1):
                dp[x] = min(dp[x], dp[x - coin] + 1)
        return dp[amount] if dp[amount] != float('inf') else -1 

if __name__ == "__main__":
    nums = [2, 7, 11, 15]
    target = 26
    so = Solution_322_CoinChange_3()
    s = "aa"
    arrays = [[1, 2, 3], [4, 5, 6]]
    print(arrays)
                    