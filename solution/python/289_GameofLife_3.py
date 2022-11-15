
from typing import List  
from utils import *
import collections
                    
    
class Solution_289_GameofLife_3:
    def gameOfLifeInfinite(self, live):
        ctr = collections.Counter((I, J)
                                  for i, j in live
                                  for I in range(i-1, i+2)
                                  for J in range(j-1, j+2)
                                  if I != i or J != j)
        return {ij
                for ij in ctr
                if ctr[ij] == 3 or ctr[ij] == 2 and ij in live}

    def gameOfLife(self, board):
        live = {(i, j) for i, row in enumerate(board) for j, live in enumerate(row) if live}
        live = self.gameOfLifeInfinite(live)
        for i, row in enumerate(board):
            for j in range(len(row)):
                row[j] = int((i, j) in live)

if __name__ == "__main__":
    nums = [2, 7, 11, 15]
    target = 26
    so = Solution_289_GameofLife_3()
    s = "aa"
    arrays = [[1, 2, 3], [4, 5, 6]]
    print(arrays)
                    