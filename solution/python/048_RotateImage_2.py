from typing import List
from utils import *


class Solution_048_RotateImage_2:
    def rotate(self, matrix: List[List[int]]) -> None:
        self.transpose(matrix)
        self.reflect(matrix)

    def transpose(self, matrix):
        n = len(matrix)
        for i in range(n):
            for j in range(i + 1, n):
                matrix[j][i], matrix[i][j] = matrix[i][j], matrix[j][i]

    def reflect(self, matrix):
        n = len(matrix)
        for i in range(n):
            for j in range(n // 2):
                matrix[i][j], matrix[i][-j - 1] = matrix[i][-j - 1], matrix[i][j]


if __name__ == "__main__":
    matrix =[
        [1, 2, 3],
        [4, 5, 6],
        [7, 8, 9]
    ],

    so = Solution_048_RotateImage_2()

    res = so.rotate(*matrix)

    print(matrix)
