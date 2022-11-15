from typing import List
from utils import *


class Solution_169_MajorityElement_1:
    def majorityElement(self, nums):
        majority_count = len(nums) // 2
        for num in nums:
            count = sum(1 for elem in nums if elem == num)
            if count > majority_count:
                return num


if __name__ == "__main__":
    so = Solution_169_MajorityElement_1()
    nums = [2, 2, 1, 1, 1, 2, 2]
    res = so.majorityElement(nums)
    print(res)
