from typing import List
from utils import *
import collections


class LargerNumKey(str):
    def __lt__(x, y):
        return x + y > y + x


def cmp(x, y):
    return x + y > y + x


class Solution_179_LargestNumber_1:
    def largestNumber(self, nums):
        # aa = sorted(map(str, nums), key=LargerNumKey)
        # aa = sorted(map(str, nums), key=cmp)
        # print(aa)
        largest_num = ''.join(sorted(map(str, nums), key=LargerNumKey))
        return '0' if largest_num[0] == '0' else largest_num


if __name__ == "__main__":
    nums = [3, 30, 34, 5, 9]
    so = Solution_179_LargestNumber_1()
    res = so.largestNumber(nums)
    print(res)
