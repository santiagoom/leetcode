
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
    so = Solution_171_ExcelSheetColumnNumber_2()
    s = "AD"
    res = so.titleToNumber(s)
    print(res)
                    