
from typing import List  
from utils import *
import collections
                    
class Solution_459_RepeatedSubstringPattern_2:
    def repeatedSubstringPattern(self, s: str) -> bool:
        t = s + s
        if s in t[1:-1]:
            return True
        return False

if __name__ == "__main__":
    nums = [2, 7, 11, 15]
    target = 26
    arrays = [[1, 2, 3], [4, 5, 6]]
    print(arrays)
    so = Solution_459_RepeatedSubstringPattern_2()
    s = "aa"
    res = 1
    print(res)
                    