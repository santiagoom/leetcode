
from typing import List  
from utils import *
import collections
                    
class Solution_318_MaximumProductofWordLengths_1:
    def maxProduct(self, words: List[str]) -> int:
        def no_common_letters(s1, s2):
            # TODO
            
        n = len(words)
        max_prod = 0
        for i in range(n):
            for j in range(i + 1, n):
                if no_common_letters(words[i], words[j]):
                    max_prod = max(max_prod, len(words[i]) * len(words[j]))
        return max_prod

if __name__ == "__main__":
    nums = [2, 7, 11, 15]
    target = 26
    so = Solution_318_MaximumProductofWordLengths_1()
    s = "aa"
    arrays = [[1, 2, 3], [4, 5, 6]]
    print(arrays)
                    