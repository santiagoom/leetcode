
from typing import List  
from utils import *
                    
from collections import Counter
class Solution_137_SingleNumberII_2:
    def singleNumber(self, nums):
        hashmap = Counter(nums)
            
        for k in hashmap.keys():
            if hashmap[k] == 1:
                return k

if __name__ == "__main__":
    nums = [2, 7, 11, 15]
    target = 26
    s = "aa"
    arrays = [[1, 2, 3], [4, 5, 6]]
    print(arrays)
                    