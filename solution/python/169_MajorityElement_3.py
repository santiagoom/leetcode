
from typing import List  
from utils import *
                    
class Solution_169_MajorityElement_3:
    def majorityElement(self, nums):
        nums.sort()
        return nums[len(nums)//2]

if __name__ == "__main__":
    nums = [2, 7, 11, 15]
    target = 26
    s = "aa"
    arrays = [[1, 2, 3], [4, 5, 6]]
    print(arrays)
                    