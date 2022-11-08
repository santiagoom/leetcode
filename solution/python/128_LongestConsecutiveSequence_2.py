from typing import List
from utils import *


class Solution_128_LongestConsecutiveSequence_2:
    def longestConsecutive(self, nums):
        if not nums:
            return 0

        nums.sort()

        longest_streak = 1
        current_streak = 1

        for i in range(1, len(nums)):
            if nums[i] != nums[i - 1]:
                if nums[i] == nums[i - 1] + 1:
                    current_streak += 1
                else:
                    longest_streak = max(longest_streak, current_streak)
                    current_streak = 1

        return max(longest_streak, current_streak)


if __name__ == "__main__":
    nums = [100, 4, 200, 1, 3, 2]
    so = Solution_128_LongestConsecutiveSequence_2()
    res = so.longestConsecutive(nums)
    print(res)
