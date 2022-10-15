
from typing import List  
from utils import *
                    
class Solution_058_LengthofLastWord_3:
    def lengthOfLastWord(self, s: str) -> int:
        return 0 if not s or s.isspace() else len(s.split()[-1])

if __name__ == "__main__":
    nums = [2, 7, 11, 15]
    target = 26
    s = "aa"
    arrays = [[1, 2, 3], [4, 5, 6]]
    print(arrays)
                    