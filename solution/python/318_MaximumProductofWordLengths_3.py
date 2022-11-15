
from typing import List  
from utils import *
import collections
                    
from collections import defaultdict
class Solution_318_MaximumProductofWordLengths_3:
    def maxProduct(self, words: List[str]) -> int:
        hashmap = defaultdict(int)
        bit_number = lambda ch : ord(ch) - ord('a')
        
        for word in words:
            bitmask = 0
            for ch in word:
                # add bit number bit_number in bitmask
                bitmask |= 1 << bit_number(ch)
            # there could be different words with the same bitmask
            # ex. ab and aabb
            hashmap[bitmask] = max(hashmap[bitmask], len(word))
        
        max_prod = 0
        for x in hashmap:
            for y in hashmap:
                if x & y == 0:
                    max_prod = max(max_prod, hashmap[x] * hashmap[y])
        return max_prod

if __name__ == "__main__":
    nums = [2, 7, 11, 15]
    target = 26
    so = Solution_318_MaximumProductofWordLengths_3()
    s = "aa"
    arrays = [[1, 2, 3], [4, 5, 6]]
    print(arrays)
                    