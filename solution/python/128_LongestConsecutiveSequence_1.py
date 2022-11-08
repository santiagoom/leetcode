from typing import List
from utils import *


class Solution_128_LongestConsecutiveSequence_1:
    def longestConsecutive(self, nums):
        longest_streak = 0

        for num in nums:
            current_num = num
            current_streak = 1

            while current_num + 1 in nums:
                current_num += 1
                current_streak += 1

            longest_streak = max(longest_streak, current_streak)

        return longest_streak


if __name__ == "__main__":
    nums = [100, 4, 200, 1, 3, 2]
    so = Solution_128_LongestConsecutiveSequence_1()
    res = so.longestConsecutive(nums)
    print(res)
