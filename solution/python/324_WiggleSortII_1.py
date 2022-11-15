
from typing import List  
from utils import *
import collections
                    
class Solution_324_WiggleSortII_1:
    def wiggleSort(self, nums):
        nums.sort()
        half = len(nums[::2])
        nums[::2], nums[1::2] = nums[:half][::-1], nums[half:][::-1]


if __name__ == "__main__":
    nums = [2, 7, 11, 15]
    target = 26
    so = Solution_324_WiggleSortII_1()
    s = "aa"
    arrays = [[1, 2, 3], [4, 5, 6]]
    print(arrays)
                    