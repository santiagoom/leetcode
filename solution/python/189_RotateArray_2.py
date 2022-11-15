
from typing import List  
from utils import *
import collections
                    
class Solution_189_RotateArray_2:
    def rotate(self, nums: List[int], k: int) -> None:
        n = len(nums)
        a = [0] * n
        for i in range(n):
            a[(i + k) % n] = nums[i]
            
        nums[:] = a

if __name__ == "__main__":
    nums = [2, 7, 11, 15]
    target = 26
    so = Solution_189_RotateArray_2()
    s = "aa"
    arrays = [[1, 2, 3], [4, 5, 6]]
    print(arrays)
                    