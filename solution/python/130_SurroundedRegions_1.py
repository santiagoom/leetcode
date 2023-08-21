from typing import List
from utils import *
import collections


class Solution_130_SurroundedRegions_1:
    def solve(self, board):
        """
        :type board: List[List[str]]
        :rtype: None Do not return anything, modify board in-place instead.
        """
        if not board or not board[0]:
            return

        self.ROWS = len(board)
        self.COLS = len(board[0])

        # Step 1). retrieve all border cells
        from itertools import product


        aa = list(product(range(self.ROWS), [0, self.COLS - 1]))
        bb = list(product([0, self.ROWS - 1], range(self.COLS)))
        borders = list(product(range(self.ROWS), [0, self.COLS - 1])) \
                  + list(product([0, self.ROWS - 1], range(self.COLS)))

        # Step 2). mark the "escaped" cells, with any placeholder, e.g. 'E'
        for row, col in borders:
            self.DFS(board, row, col)

        print(board)

        # Step 3). flip the captured cells ('O'->'X') and the escaped one ('E'->'O')
        for r in range(self.ROWS):
            for c in range(self.COLS):
                if board[r][c] == 'O':
                    board[r][c] = 'X'  # captured
                elif board[r][c] == 'E':
                    board[r][c] = 'O'  # escaped

    def DFS(self, board, row, col):
        if board[row][col] != 'O':
            return
        board[row][col] = 'E'
        if col < self.COLS - 1: self.DFS(board, row, col + 1)
        if row < self.ROWS - 1: self.DFS(board, row + 1, col)
        if col > 0: self.DFS(board, row, col - 1)
        if row > 0: self.DFS(board, row - 1, col)


if __name__ == "__main__":
    board = [["X", "X", "X", "X"], ["X", "O", "O", "X"], ["X", "X", "O", "X"], ["X", "O", "X", "X"]]
    # board = [["X", "X", "X", "X"], ["X", "O", "O", "X"], ["X", "O", "O", "X"], ["X", "O", "X", "X"]]
    print(board)
    so = Solution_130_SurroundedRegions_1()
    res = so.solve(board)
    print(board)
