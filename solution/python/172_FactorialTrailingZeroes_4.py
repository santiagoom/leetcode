
from typing import List  
from utils import *
import collections
                    
def trailingZeroes(self, n: int) -> int:
    zero_count = 0
    current_multiple = 5
    while n >= current_multiple:
        zero_count += n // current_multiple
        current_multiple *= 5
    return zero_count

if __name__ == "__main__":
    nums = [2, 7, 11, 15]
    target = 26
    so = Solution_172_FactorialTrailingZeroes_4()
    s = "aa"
    arrays = [[1, 2, 3], [4, 5, 6]]
    print(arrays)
                    