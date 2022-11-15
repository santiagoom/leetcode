
from typing import List  
from utils import *
import collections
                    
class Solution_201_BitwiseANDofNumbersRange_2:
    def rangeBitwiseAnd(self, m: int, n: int) -> int:
        while m < n:
            # turn off rightmost 1-bit
            n = n & (n - 1)
        return m & n

if __name__ == "__main__":
    nums = [2, 7, 11, 15]
    target = 26
    so = Solution_201_BitwiseANDofNumbersRange_2()
    s = "aa"
    arrays = [[1, 2, 3], [4, 5, 6]]
    print(arrays)
                    