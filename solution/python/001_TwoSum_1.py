import collections
from typing import List


class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        for i in range(len(nums)):
            for j in range(i + 1, len(nums)):
                if nums[j] == target - nums[i]:
                    return [i, j]


if __name__ == "__main__":
    nums = [2, 7, 11, 15]
    target = 26

    so = Solution()
    res = so.twoSum(nums, target)
    print(res)
