
from typing import List  
from utils import *
import collections
                    
class Solution_277_FindtheCelebrity_2:
    def findCelebrity(self, n: int) -> int:
        self.n = n
        celebrity_candidate = 0
        for i in range(1, n):
            if knows(celebrity_candidate, i):
                celebrity_candidate = i
        if self.is_celebrity(celebrity_candidate):
            return celebrity_candidate
        return -1

    def is_celebrity(self, i):
        for j in range(self.n):
            if i == j: continue
            if knows(i, j) or not knows(j, i):
                return False
        return True

if __name__ == "__main__":
    nums = [2, 7, 11, 15]
    target = 26
    so = Solution_277_FindtheCelebrity_2()
    s = "aa"
    arrays = [[1, 2, 3], [4, 5, 6]]
    print(arrays)
                    