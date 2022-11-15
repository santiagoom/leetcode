
from typing import List  
from utils import *
import collections
                    
class Solution_246_StrobogrammaticNumber_2:
    def isStrobogrammatic(self, num: str) -> bool:
        
        rotated_digits = {'0': '0', '1': '1', '8': '8', '6': '9', '9': '6'}
        
        rotated_string_builder = []
        
        for c in reversed(num):
            if c not in rotated_digits:
                return False
            rotated_string_builder.append(rotated_digits[c])
        
        rotated_string = "".join(rotated_string_builder)
        return rotated_string == num

if __name__ == "__main__":
    nums = [2, 7, 11, 15]
    target = 26
    so = Solution_246_StrobogrammaticNumber_2()
    s = "aa"
    arrays = [[1, 2, 3], [4, 5, 6]]
    print(arrays)
                    