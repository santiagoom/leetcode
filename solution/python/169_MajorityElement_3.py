from typing import List
from utils import *


class Solution_169_MajorityElement_3:
    def majorityElement(self, nums):
        nums.sort()
        return nums[len(nums) // 2]


if __name__ == "__main__":
    so = Solution_169_MajorityElement_3()
    nums = [2, 2, 1, 1, 1, 2, 2]
    res = so.majorityElement(nums)
    print(res)
