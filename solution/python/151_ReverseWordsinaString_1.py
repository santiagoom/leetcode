from typing import List
from utils import *


class Solution_151_ReverseWordsinaString_1:
    def reverseWords(self, s: str) -> str:
        return " ".join(reversed(s.split()))


if __name__ == "__main__":
    nums = [2, 7, 11, 15]
    target = 26
    s = "aa"
    arrays = [[1, 2, 3], [4, 5, 6]]
    print(arrays)
