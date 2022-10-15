
from typing import List  
from utils import *
                    
class Solution_120_Triangle_5:
    def minimumTotal(self, triangle: List[List[int]]) -> int:
        @lru_cache(maxsize=None)
        def min_path(row, col):
            path = triangle[row][col]
            if row < len(triangle) - 1:
                path += min(min_path(row + 1, col), min_path(row + 1, col + 1))
            return path
        return min_path(0, 0)

if __name__ == "__main__":
    nums = [2, 7, 11, 15]
    target = 26
    s = "aa"
    arrays = [[1, 2, 3], [4, 5, 6]]
    print(arrays)
                    