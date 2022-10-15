
from typing import List  
from utils import *
                    
class Solution_115_DistinctSubsequences_1:
    def numDistinct(self, s: str, t: str) -> int:
        
        # Dictionary for memoization
        memo = {}
        
        def uniqueSubsequences(i, j):
            
            M, N = len(s), len(t)
            
            # Base case
            if i == M or j == N or M - i < N - j:
                return int(j == len(t))
            
            # Check if the result is already cached
            if (i, j) in memo:
                return memo[i,j]
            
            # Always make this recursive call
            ans = uniqueSubsequences(i + 1, j)
            
            # If the characters match, make the other
            # one and add the result to "ans"
            if s[i] == t[j]:
                ans += uniqueSubsequences(i + 1, j + 1)
            
            # Cache the answer and return
            memo[i, j] = ans
            return ans                
        
        return uniqueSubsequences(0, 0)

if __name__ == "__main__":
    nums = [2, 7, 11, 15]
    target = 26
    s = "aa"
    arrays = [[1, 2, 3], [4, 5, 6]]
    print(arrays)
                    