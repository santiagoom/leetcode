
from typing import List  
from utils import *
import collections
                    
from collections import Counter
class Solution_260_SingleNumberIII_1:
    def singleNumber(self, nums: int) -> List[int]:
        hashmap = Counter(nums)
        return [x for x in hashmap if hashmap[x] == 1]

if __name__ == "__main__":
    nums = [2, 7, 11, 15]
    target = 26
    so = Solution_260_SingleNumberIII_1()
    s = "aa"
    arrays = [[1, 2, 3], [4, 5, 6]]
    print(arrays)
                    