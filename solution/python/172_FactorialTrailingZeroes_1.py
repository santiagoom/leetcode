
from typing import List  
from utils import *
                    
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
    nums = [2, 7, 11, 15]
    target = 26
    s = "aa"
    arrays = [[1, 2, 3], [4, 5, 6]]
    print(arrays)
                    