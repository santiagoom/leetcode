
from typing import List  
from utils import *
                    
class Solution_058_LengthofLastWord_1:
    def lengthOfLastWord(self, s: str) -> int:
        # trim the trailing spaces
        p = len(s) - 1
        while p >= 0 and s[p] == ' ':
            p -= 1

        # compute the length of last word
        length = 0
        while p >= 0 and s[p] != ' ':
            p -= 1
            length += 1
        return length

if __name__ == "__main__":
    nums = [2, 7, 11, 15]
    target = 26
    s = "aa"
    arrays = [[1, 2, 3], [4, 5, 6]]
    print(arrays)
                    