
from typing import List  
from utils import *
                    

    def backtrack(self, row, col, suffix):
        """
            backtracking with side-effect,
               the matched letter in the board would be marked with "#".
        """
        # bottom case: we find match for each letter in the word
        if len(suffix) == 0:
            return True

        # Check the current status, before jumping into backtracking
        if row < 0 or row == self.ROWS or col < 0 or col == self.COLS \
                or self.board[row][col] != suffix[0]:
            return False

        # mark the choice before exploring further.
        self.board[row][col] = '#'
        # explore the 4 neighbor directions
        for rowOffset, colOffset in [(0, 1), (-1, 0), (0, -1), (1, 0)]:
            # sudden-death return, no cleanup.
            if self.backtrack(row + rowOffset, col + colOffset, suffix[1:]):
                return True

        # revert the marking
        self.board[row][col] = suffix[0]

        # Tried all directions, and did not find any match
        return False

if __name__ == "__main__":
    nums = [2, 7, 11, 15]
    target = 26
    s = "aa"
    arrays = [[1, 2, 3], [4, 5, 6]]
    print(arrays)
                    