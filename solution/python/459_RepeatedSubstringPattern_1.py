
from typing import List  
from utils import *
import collections
                    
class Solution_459_RepeatedSubstringPattern_1:
    def repeatedSubstringPattern(self, s: str) -> bool:
        n = len(s)
        for i in range(1, n // 2 + 1):
            if n % i == 0:
                pattern = s[:i] * (n // i)
                if s == pattern:
                    return True
        return False

if __name__ == "__main__":
    nums = [2, 7, 11, 15]
    target = 26
    arrays = [[1, 2, 3], [4, 5, 6]]
    print(arrays)
    so = Solution_459_RepeatedSubstringPattern_1()
    s = "aa"
    res = 1
    print(res)
                    