
from typing import List  
from utils import *
import collections
                    
class Solution_202_HappyNumber_1:
    def isHappy(self, n: int) -> bool:

        def get_next(n):
            total_sum = 0
            while n > 0:
                n, digit = divmod(n, 10)
                total_sum += digit ** 2
            return total_sum

        seen = set()
        while n != 1 and n not in seen:
            seen.add(n)
            n = get_next(n)

        return n == 1

if __name__ == "__main__":
    nums = [2, 7, 11, 15]
    target = 26
    arrays = [[1, 2, 3], [4, 5, 6]]
    print(arrays)
    so = Solution_202_HappyNumber_1()
    s = "aa"
    res = 1
    print(res)
                    