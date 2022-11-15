
from typing import List  
from utils import *
import collections
                    
class Solution_189_RotateArray_1:
    def rotate(self, nums: List[int], k: int) -> None:
        # speed up the rotation
        k %= len(nums)

        for i in range(k):
            previous = nums[-1]
            for j in range(len(nums)):
                nums[j], previous = previous, nums[j]

if __name__ == "__main__":
    nums = [2, 7, 11, 15]
    target = 26
    so = Solution_189_RotateArray_1()
    s = "aa"
    arrays = [[1, 2, 3], [4, 5, 6]]
    print(arrays)
                    