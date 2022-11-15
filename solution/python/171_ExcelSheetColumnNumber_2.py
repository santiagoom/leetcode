
from typing import List  
from utils import *
import collections
                    
class Solution_171_ExcelSheetColumnNumber_2:
    def titleToNumber(self, s: str) -> int:
        result = 0
        n = len(s)
        for i in range(n):
            result = result * 26
            result += (ord(s[i]) - ord('A') + 1)
        return result

if __name__ == "__main__":
    nums = [2, 7, 11, 15]
    target = 26
    so = Solution_171_ExcelSheetColumnNumber_2()
    s = "aa"
    arrays = [[1, 2, 3], [4, 5, 6]]
    print(arrays)
                    