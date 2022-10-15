from typing import List
from utils import *


class Solution_034_FindFirstandLastPositionofElementinSortedArray_1:
    def searchRange(self, nums: List[int], target: int) -> List[int]:
        lower_bound = self.findBound(nums, target, True)

        if (lower_bound == -1):
            return [-1, -1]

        upper_bound = self.findBound(nums, target, False)
        return [lower_bound, upper_bound]

    def findBound(self, nums: List[int], target: int, isFirst: bool) -> int:
        N = len(nums)
        begin, end = 0, N - 1
        while begin <= end:
            mid = int((begin + end) / 2)
            if nums[mid] == target:
                if isFirst:
                    # This means we found our lower bound.
                    if mid == begin or nums[mid - 1] < target:
                        return mid
                    # Search on the left side for the bound.
                    end = mid - 1
                else:
                    # This means we found our upper bound.
                    if mid == end or nums[mid + 1] > target:
                        return mid
                    # Search on the right side for the bound.
                    begin = mid + 1
            elif nums[mid] > target:
                end = mid - 1
            else:
                begin = mid + 1

        return -1


if __name__ == "__main__":
    nums = [2, 7, 11, 15]
    target = 26
    s = "aa"
    arrays = [[1, 2, 3], [4, 5, 6]]
    print(arrays)
