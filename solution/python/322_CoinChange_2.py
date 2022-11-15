
from typing import List  
from utils import *
import collections
                    
from functools import lru_cache


class Solution_322_CoinChange_2:
    def coinChange(self, coins: List[int], amount: int) -> int:

        @lru_cache(None)
        def dfs(rem):
            if rem < 0:
                return -1
            if rem == 0:
                return 0
            min_cost = float('inf')
            for coin in coins:
                res = dfs(rem - coin)
                if res != -1:
                    min_cost = min(min_cost, res + 1)
            return min_cost if min_cost != float('inf') else -1

        return dfs(amount)

if __name__ == "__main__":
    nums = [2, 7, 11, 15]
    target = 26
    so = Solution_322_CoinChange_2()
    s = "aa"
    arrays = [[1, 2, 3], [4, 5, 6]]
    print(arrays)
                    