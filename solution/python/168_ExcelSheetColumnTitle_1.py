from typing import List
from utils import *


class Solution_168_ExcelSheetColumnTitle_1:
    # @return a string
    def convertToTitle(self, num):
        aa = [x for x in range(ord('A'), ord('Z') + 1)]
        capitals = [chr(x) for x in range(ord('A'), ord('Z') + 1)]
        result = []
        while num > 0:
            result.append(capitals[(num - 1) % 26])
            num = (num - 1) // 26
        result.reverse()
        return ''.join(result)


if __name__ == "__main__":
    so = Solution_168_ExcelSheetColumnTitle_1()
    num = 30
    res = so.convertToTitle(num)
    print(res)
