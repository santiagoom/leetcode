
from typing import List  
from utils import *
import collections
                    
class Solution_172_FactorialTrailingZeroes_5:    
    def trailingZeroes(self, n: int) -> int:
        zero_count = 0
        while n > 0:
            n //= 5
            zero_count += n
        return zero_count

if __name__ == "__main__":
    nums = [2, 7, 11, 15]
    target = 26
    so = Solution_172_FactorialTrailingZeroes_5()
    s = "aa"
    arrays = [[1, 2, 3], [4, 5, 6]]
    print(arrays)
                    