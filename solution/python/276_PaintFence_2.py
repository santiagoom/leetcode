
from typing import List  
from utils import *
import collections
                    
class Solution_276_PaintFence_2:
    def numWays(self, n: int, k: int) -> int:
        @lru_cache(None)
        def total_ways(i):
            if i == 1: 
                return k
            if i == 2: 
                return k * k
            
            return (k - 1) * (total_ways(i - 1) + total_ways(i - 2))
        
        return total_ways(n)

if __name__ == "__main__":
    nums = [2, 7, 11, 15]
    target = 26
    so = Solution_276_PaintFence_2()
    s = "aa"
    arrays = [[1, 2, 3], [4, 5, 6]]
    print(arrays)
                    