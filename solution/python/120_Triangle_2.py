from typing import List
from utils import *


class Solution_120_Triangle_2:
    def minimumTotal(self, triangle: List[List[int]]) -> int:
        prev_row = triangle[0]
        for row in range(1, len(triangle)):
            curr_row = []
            for col in range(row + 1):
                smallest_above = math.inf
                if col > 0:
                    smallest_above = prev_row[col - 1]
                if col < row:
                    smallest_above = min(smallest_above, prev_row[col])
                curr_row.append(triangle[row][col] + smallest_above)
            prev_row = curr_row
        return min(prev_row)


if __name__ == "__main__":
    nums = [
        [2],
        [3, 4],
        [6, 5, 7],
        # [4, 1, 8, 3],
        [4, 2, 8, 1],
    ]

    so = Solution_120_Triangle_2()
    res = so.minimumTotal(nums)
    print(res)
