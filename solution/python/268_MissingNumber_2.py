
from typing import List  
from utils import *
import collections
                    
class Solution_268_MissingNumber_2:
    def missingNumber(self, nums):
        num_set = set(nums)
        n = len(nums) + 1
        for number in range(n):
            if number not in num_set:
                return number

if __name__ == "__main__":
    nums = [2, 7, 11, 15]
    target = 26
    so = Solution_268_MissingNumber_2()
    s = "aa"
    arrays = [[1, 2, 3], [4, 5, 6]]
    print(arrays)
                    