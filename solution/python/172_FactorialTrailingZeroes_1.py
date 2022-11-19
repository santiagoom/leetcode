
from typing import List  
from utils import *
import collections
                    
class Solution_172_FactorialTrailingZeroes_1:    
    def trailingZeroes(self, n: int) -> int:

        # Calculate n!
        n_factorial = 1
        for i in range(2, n + 1):
            n_factorial *= i

        # Count how many 0's are on the end.
        zero_count = 0
        while n_factorial % 10 == 0:
            zero_count += 1
            n_factorial //= 10

        return zero_count

if __name__ == "__main__":
    so = Solution_172_FactorialTrailingZeroes_1()
    num = 6
    res = so.trailingZeroes(num)
    print(res)
