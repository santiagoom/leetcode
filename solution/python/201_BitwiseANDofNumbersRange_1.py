
from typing import List  
from utils import *
                    
class Solution_201_BitwiseANDofNumbersRange_1:
    def rangeBitwiseAnd(self, m: int, n: int) -> int:
        shift = 0   
        # find the common 1-bits
        while m < n:
            m = m >> 1
            n = n >> 1
            shift += 1
        return m << shift

if __name__ == "__main__":
    nums = [2, 7, 11, 15]
    target = 26
    s = "aa"
    arrays = [[1, 2, 3], [4, 5, 6]]
    print(arrays)
                    