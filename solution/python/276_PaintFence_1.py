
from typing import List  
from utils import *
import collections
                    
class Solution_276_PaintFence_1:
    def numWays(self, n: int, k: int) -> int:
        def total_ways(i):
            if i == 1:
                return k
            if i == 2:
                return k * k
            
            # Check if we have already calculated totalWays(i)
            if i in memo:
                return memo[i]
            
            # Use the recurrence relation to calculate total_ways(i)
            memo[i] = (k - 1) * (total_ways(i - 1) + total_ways(i - 2))
            return memo[i]

        memo = {}
        return total_ways(n)

if __name__ == "__main__":
    nums = [2, 7, 11, 15]
    target = 26
    so = Solution_276_PaintFence_1()
    s = "aa"
    arrays = [[1, 2, 3], [4, 5, 6]]
    print(arrays)
                    