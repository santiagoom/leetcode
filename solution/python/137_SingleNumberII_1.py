
from typing import List  
from utils import *
                    
class Solution_137_SingleNumberII_1:
    def singleNumber(self, nums):
        return (3 * sum(set(nums)) - sum(nums)) // 2

if __name__ == "__main__":
    nums = [2, 7, 11, 15]
    target = 26
    s = "aa"
    arrays = [[1, 2, 3], [4, 5, 6]]
    print(arrays)
                    