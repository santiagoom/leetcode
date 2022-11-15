
from typing import List  
from utils import *
import collections
                    
class Solution_268_MissingNumber_4:
    def missingNumber(self, nums):
        expected_sum = len(nums)*(len(nums)+1)//2
        actual_sum = sum(nums)
        return expected_sum - actual_sum

if __name__ == "__main__":
    nums = [2, 7, 11, 15]
    target = 26
    so = Solution_268_MissingNumber_4()
    s = "aa"
    arrays = [[1, 2, 3], [4, 5, 6]]
    print(arrays)
                    