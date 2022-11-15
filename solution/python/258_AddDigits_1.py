
from typing import List  
from utils import *
import collections
                    
class Solution_258_AddDigits_1:
    def addDigits(self, num: int) -> int:
        if num == 0:
            return 0
        if num % 9 == 0:
            return 9
        return num % 9

if __name__ == "__main__":
    nums = [2, 7, 11, 15]
    target = 26
    so = Solution_258_AddDigits_1()
    s = "aa"
    arrays = [[1, 2, 3], [4, 5, 6]]
    print(arrays)
                    