
from typing import List  
from utils import *
import collections
                    
class Solution_265_PaintHouseII_2:
    def minCostII(self, costs: List[List[int]]) -> int:

        n = len(costs)
        if n == 0: return 0
        k = len(costs[0])

        for house in range(1, n):
            for color in range(k):
                best = math.inf
                for previous_color in range(k):
                    if color == previous_color: continue
                    best = min(best, costs[house - 1][previous_color])
                costs[house][color] += best

        return min(costs[-1])

if __name__ == "__main__":
    nums = [2, 7, 11, 15]
    target = 26
    so = Solution_265_PaintHouseII_2()
    s = "aa"
    arrays = [[1, 2, 3], [4, 5, 6]]
    print(arrays)
                    