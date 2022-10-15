
from typing import List  
from utils import *
                    
class Solution_246_StrobogrammaticNumber_1:
    def isStrobogrammatic(self, num: str) -> bool:
        
        # In Python, we use a list as a string builder.
        rotated_string_builder = []
        
        # Remember that we want to loop backward through the string.
        for c in reversed(num):
            if c in {'0', '1', '8'}:
                rotated_string_builder.append(c)
            elif c == '6':
                rotated_string_builder.append('9')
            elif c == '9':
                rotated_string_builder.append('6')
            else: # This must be an invalid digit.
                return False
        
        # In Python, we convert a list of characters to
        # a string using join.
        rotated_string = "".join(rotated_string_builder)
        return rotated_string == num

if __name__ == "__main__":
    nums = [2, 7, 11, 15]
    target = 26
    s = "aa"
    arrays = [[1, 2, 3], [4, 5, 6]]
    print(arrays)
                    