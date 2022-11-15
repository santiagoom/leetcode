
from typing import List  
from utils import *
import collections
                    
class Solution_189_RotateArray_3:
    def rotate(self, nums: List[int], k: int) -> None:
        n = len(nums)
        k %= n
        
        start = count = 0
        while count < n:
            current, prev = start, nums[start]
            while True:
                next_idx = (current + k) % n
                nums[next_idx], prev = prev, nums[next_idx]
                current = next_idx
                count += 1
                
                if start == current:
                    break
            start += 1

if __name__ == "__main__":
    nums = [2, 7, 11, 15]
    target = 26
    so = Solution_189_RotateArray_3()
    s = "aa"
    arrays = [[1, 2, 3], [4, 5, 6]]
    print(arrays)
                    