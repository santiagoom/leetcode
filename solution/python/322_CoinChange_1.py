
from typing import List  
from utils import *
import collections
                    
class Solution_322_CoinChange_1:
    def coinChange(self, coins: List[int], amount: int) -> int:
        n = len(coins)

        def dfs(idx, amount):
            if amount == 0:
                return 0
            if idx < n and amount > 0:
                min_cost = float('inf')
                for x in range(0, amount // coins[idx] + 1):
                    res = dfs(idx + 1, amount-x * coins[idx])
                    if res != -1:
                        min_cost = min(min_cost, res + x)
                return -1 if min_cost == float('inf') else min_cost
            return -1

        return dfs(0, amount)

    # Time Limit Exceeded

if __name__ == "__main__":
    nums = [2, 7, 11, 15]
    target = 26
    so = Solution_322_CoinChange_1()
    s = "aa"
    arrays = [[1, 2, 3], [4, 5, 6]]
    print(arrays)
                    