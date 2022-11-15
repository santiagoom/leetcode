
from typing import List  
from utils import *
import collections
                    
class Ugly:
    def __init__(self):
        self.nums = nums = [1, ]
        i2 = i3 = i5 = 0

        for i in range(1, 1690):
            ugly = min(nums[i2] * 2, nums[i3] * 3, nums[i5] * 5)
            nums.append(ugly)

            if ugly == nums[i2] * 2: 
                i2 += 1
            if ugly == nums[i3] * 3:
                i3 += 1
            if ugly == nums[i5] * 5:
                i5 += 1
            
class Solution_264_UglyNumberII_2:
    u = Ugly()
    def nthUglyNumber(self, n):
        return self.u.nums[n - 1]

if __name__ == "__main__":
    nums = [2, 7, 11, 15]
    target = 26
    so = Solution_264_UglyNumberII_2()
    s = "aa"
    arrays = [[1, 2, 3], [4, 5, 6]]
    print(arrays)
                    