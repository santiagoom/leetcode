
from typing import List  
from utils import *
import collections
                    
class Solution_171_ExcelSheetColumnNumber_1:
    def titleToNumber(self, s: str) -> int:
        result = 0
        
        # Decimal 65 in ASCII corresponds to char 'A'
        alpha_map = {chr(i + 65): i + 1 for i in range(26)}

        n = len(s)
        for i in range(n):
            cur_char = s[n - 1 - i]
            result += (alpha_map[cur_char] * (26 ** i))
        return result

if __name__ == "__main__":
    nums = [2, 7, 11, 15]
    target = 26
    so = Solution_171_ExcelSheetColumnNumber_1()
    s = "aa"
    arrays = [[1, 2, 3], [4, 5, 6]]
    print(arrays)
                    