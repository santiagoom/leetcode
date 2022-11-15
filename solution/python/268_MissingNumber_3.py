
from typing import List  
from utils import *
import collections
                    
class Solution_268_MissingNumber_3:
    def missingNumber(self, nums):
        missing = len(nums)
        for i, num in enumerate(nums):
            missing ^= i ^ num
        return missing

if __name__ == "__main__":
    nums = [2, 7, 11, 15]
    target = 26
    so = Solution_268_MissingNumber_3()
    s = "aa"
    arrays = [[1, 2, 3], [4, 5, 6]]
    print(arrays)
                    