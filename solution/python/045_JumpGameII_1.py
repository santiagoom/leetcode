from typing import List
from utils import *


class Solution_045_JumpGameII_1:
    def jump(self, nums: List[int]) -> int:
        jumps = 0
        current_jump_end = 0
        farthest = 0
        for i in range(len(nums) - 1):
            # we continuously find the how far we can reach in the current jump
            farthest = max(farthest, i + nums[i])
            # if we have come to the end of the current jump,
            # we need to make another jump
            if i == current_jump_end:
                jumps += 1
                current_jump_end = farthest
        return jumps


if __name__ == "__main__":
    nums = [2,3,1,1,4]
    so = Solution_045_JumpGameII_1()
    res = so.jump(nums)
    print(res)
