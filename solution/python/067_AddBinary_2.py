from typing import List
from utils import *


class Solution_067_AddBinary_2:
    def addBinary(self, a, b) -> str:
        x, y = int(a, 2), int(b, 2)
        while y:
            answer = x ^ y
            carry = (x & y) << 1
            x, y = answer, carry
        return bin(x)[2:]


if __name__ == "__main__":
    a = "1010"
    b = "1011"
    so = Solution_067_AddBinary_2()
    res = so.addBinary(a, b)
    print(res)
