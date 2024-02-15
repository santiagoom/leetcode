from typing import List
from utils import *
import collections


class Solution_1143_LongestCommonSubsequence_1:
    def longestCommonSubsequence(self, s1: str, s2: str) -> int:
        return self.helper(s1, s2, 0, 0)

    def helper(self, s1, s2, i, j):
        if i == len(s1) or j == len(s2):
            return 0
        if s1[i] == s2[j]:
            return 1 + self.helper(s1, s2, i + 1, j + 1)
        else:
            return max(self.helper(s1, s2, i + 1, j), self.helper(s1, s2, i, j + 1))


if __name__ == "__main__":
    nums = [2, 7, 11, 15]
    target = 26
    arrays = [[1, 2, 3], [4, 5, 6]]
    print(arrays)
    so = Solution_1143_LongestCommonSubsequence_1()
    s = "aa"
    res = 1
    print(res)
