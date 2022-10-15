
from typing import List  
from utils import *
                    
class Solution_120_Triangle_3:
    def minimumTotal(self, triangle: List[List[int]]) -> int:
        below_row = triangle[-1] 
        n = len(triangle)
        for row in reversed(range(n - 1)):     
            curr_row = []
            for col in range(row + 1):
                smallest_below = min(below_row[col], below_row[col + 1])
                curr_row.append(triangle[row][col] + smallest_below)
            below_row = curr_row
        return below_row[0]

if __name__ == "__main__":
    nums = [2, 7, 11, 15]
    target = 26
    s = "aa"
    arrays = [[1, 2, 3], [4, 5, 6]]
    print(arrays)
                    