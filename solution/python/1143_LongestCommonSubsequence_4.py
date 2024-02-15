from typing import List
from utils import *
import collections


class Solution_1143_LongestCommonSubsequence_4:
    def longestCommonSubsequence(self, s1: str, s2: str) -> int:
        m = len(s1)
        n = len(s2)
        if m < n:
            return self.longestCommonSubsequence(s2, s1)
        memo = [[0 for _ in range(n + 1)] for _ in range(2)]

        for i in range(m):
            for j in range(n):
                if s1[i] == s2[j]:
                    memo[1 - i % 2][j + 1] = 1 + memo[i % 2][j]
                else:
                    memo[1 - i % 2][j + 1] = max(memo[1 - i % 2][j], memo[i % 2][j + 1])

        return memo[m % 2][n]


if __name__ == "__main__":
    nums = [2, 7, 11, 15]
    target = 26
    arrays = [[1, 2, 3], [4, 5, 6]]
    print(arrays)
    so = Solution_1143_LongestCommonSubsequence_4()
    s = "aa"
    res = 1
    print(res)
