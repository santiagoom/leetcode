
from typing import List  
from utils import *
import collections
                    
class Solution_172_FactorialTrailingZeroes_2:
    def trailingZeroes(self, n: int) -> int:

        zero_count = 0
        for i in range(5, n + 1, 5):
            current = i
            while current % 5 == 0:
                zero_count += 1
                current //= 5

        return zero_count

if __name__ == "__main__":
    nums = [2, 7, 11, 15]
    target = 26
    so = Solution_172_FactorialTrailingZeroes_2()
    s = "aa"
    arrays = [[1, 2, 3], [4, 5, 6]]
    print(arrays)
                    