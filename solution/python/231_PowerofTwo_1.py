
from typing import List  
from utils import *
import collections
                    
class Solution_231_PowerofTwo_1:
    def isPowerOfTwo(self, n):
        if n == 0:
            return False
        while n % 2 == 0:
            n /= 2
        return n == 1

if __name__ == "__main__":
    nums = [2, 7, 11, 15]
    target = 26
    so = Solution_231_PowerofTwo_1()
    s = "aa"
    arrays = [[1, 2, 3], [4, 5, 6]]
    print(arrays)
                    