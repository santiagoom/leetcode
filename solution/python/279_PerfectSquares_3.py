
from typing import List  
from utils import *
import collections
                    
class Solution_279_PerfectSquares_3:
    def numSquares(self, n):
        
        def is_divided_by(n, count):
            """
                return: true if "n" can be decomposed into "count" number of perfect square numbers.
                e.g. n=12, count=3:  true.
                     n=12, count=2:  false
            """
            if count == 1:
                return n in square_nums
            
            for k in square_nums:
                if is_divided_by(n - k, count - 1):
                    return True
            return False

        square_nums = set([i * i for i in range(1, int(n**0.5)+1)])
    
        for count in range(1, n+1):
            if is_divided_by(n, count):
                return count

if __name__ == "__main__":
    nums = [2, 7, 11, 15]
    target = 26
    so = Solution_279_PerfectSquares_3()
    s = "aa"
    arrays = [[1, 2, 3], [4, 5, 6]]
    print(arrays)
                    