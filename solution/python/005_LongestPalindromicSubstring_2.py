
from typing import List  
from utils import *
import collections
                    
class Solution_005_LongestPalindromicSubstring_2:
    def longestPalindrome(self, s: str) -> str:
        def check(i, j):
            left = i
            right = j - 1
            
            while left < right:
                if s[left] != s[right]:
                    return False
                
                left += 1
                right -= 1
            
            return True
        
        for length in range(len(s), 0, -1):
            for start in range(len(s) - length + 1):
                if check(start, start + length):
                    return s[start:start + length]

        return ""

if __name__ == "__main__":
    nums = [2, 7, 11, 15]
    target = 26
    arrays = [[1, 2, 3], [4, 5, 6]]
    print(arrays)
    so = Solution_005_LongestPalindromicSubstring_2()
    s = "aa"
    res = 1
    print(res)
                    