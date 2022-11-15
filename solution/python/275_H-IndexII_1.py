
from typing import List  
from utils import *
import collections
                    
class Solution_275_H-IndexII_1:
    def hIndex(self, citations):
        """
        :type citations: List[int]
        :rtype: int
        """
        n = len(citations)
        for idx, c in enumerate(citations):
            if c >= n - idx:
                return n - idx
        return 0

if __name__ == "__main__":
    nums = [2, 7, 11, 15]
    target = 26
    so = Solution_275_H-IndexII_1()
    s = "aa"
    arrays = [[1, 2, 3], [4, 5, 6]]
    print(arrays)
                    