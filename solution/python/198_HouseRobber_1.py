
from typing import List  
from utils import *
import collections
                    
class Solution_198_HouseRobber_1:
    
    def __init__(self):
        self.memo = {}
    
    def rob(self, nums: List[int]) -> int:
        
        self.memo = {}
        
        return self.robFrom(0, nums)
    
    def robFrom(self, i, nums):
        
        
        # No more houses left to examine.
        if i >= len(nums):
            return 0
        
        # Return cached value.
        if i in self.memo:
            return self.memo[i]
        
        # Recursive relation evaluation to get the optimal answer.
        ans = max(self.robFrom(i + 1, nums), self.robFrom(i + 2, nums) + nums[i])
        
        # Cache for future use.
        self.memo[i] = ans
        return ans

if __name__ == "__main__":
    nums = [2, 7, 11, 15]
    target = 26
    so = Solution_198_HouseRobber_1()
    s = "aa"
    arrays = [[1, 2, 3], [4, 5, 6]]
    print(arrays)
                    