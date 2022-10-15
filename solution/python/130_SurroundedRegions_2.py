
from typing import List  
from utils import *
                    
def DFS(self, board, row, col):
    if row < 0 or row >= self.ROWS or col < 0 or col >= self.COLS:
        return
    if board[row][col] != 'O':
        return
    board[row][col] = 'E'
    # jump to the neighbors without boundary checks
    for ro, co in [(0, 1), (1, 0), (0, -1), (-1, 0)]:
        self.DFS(board, row+ro, col+co)

if __name__ == "__main__":
    nums = [2, 7, 11, 15]
    target = 26
    s = "aa"
    arrays = [[1, 2, 3], [4, 5, 6]]
    print(arrays)
                    