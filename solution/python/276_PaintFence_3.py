
from typing import List  
from utils import *
import collections
                    
class Solution_276_PaintFence_3:
    def numWays(self, n: int, k: int) -> int:
        # Base cases for the problem to avoid index out of bound issues
        if n == 1:
            return k
        if n == 2:
            return k * k

        total_ways = [0] * (n + 1)
        total_ways[1] = k
        total_ways[2] = k * k
        
        for i in range(3, n + 1):
            total_ways[i] = (k - 1) * (total_ways[i - 1] + total_ways[i - 2])
        
        return total_ways[n]

if __name__ == "__main__":
    nums = [2, 7, 11, 15]
    target = 26
    so = Solution_276_PaintFence_3()
    s = "aa"
    arrays = [[1, 2, 3], [4, 5, 6]]
    print(arrays)
                    