
from typing import List  
from utils import *
import collections
                    
class Solution_277_FindtheCelebrity_1:
    def findCelebrity(self, n: int) -> int:
        self.n = n
        for i in range(n):
            if self.is_celebrity(i):
                return i
        return -1
    
    def is_celebrity(self, i):
        for j in range(self.n):
            if i == j: continue # Don't ask if they know themselves.
            if knows(i, j) or not knows(j, i):
                return False
        return True

if __name__ == "__main__":
    nums = [2, 7, 11, 15]
    target = 26
    so = Solution_277_FindtheCelebrity_1()
    s = "aa"
    arrays = [[1, 2, 3], [4, 5, 6]]
    print(arrays)
                    