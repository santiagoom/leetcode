
from typing import List  
from utils import *
import collections
                    
def trailingZeroes(self, n: int) -> int:
        
    zero_count = 0
    for i in range(5, n + 1, 5):
        power_of_5 = 5
        while i % power_of_5 == 0:
            zero_count += 1
            power_of_5 *= 5

    return zero_count

if __name__ == "__main__":
    nums = [2, 7, 11, 15]
    target = 26
    so = Solution_172_FactorialTrailingZeroes_3()
    s = "aa"
    arrays = [[1, 2, 3], [4, 5, 6]]
    print(arrays)
                    