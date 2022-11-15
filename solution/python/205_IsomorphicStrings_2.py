
from typing import List  
from utils import *
import collections
                    
class Solution_205_IsomorphicStrings_2:
    
    def transformString(self, s: str) -> str:
        index_mapping = {}
        new_str = []
        
        for i, c in enumerate(s):
            if c not in index_mapping:
                index_mapping[c] = i
            new_str.append(str(index_mapping[c]))
        
        return " ".join(new_str)
    
    def isIsomorphic(self, s: str, t: str) -> bool:
        return self.transformString(s) == self.transformString(t)

if __name__ == "__main__":
    nums = [2, 7, 11, 15]
    target = 26
    so = Solution_205_IsomorphicStrings_2()
    s = "aa"
    arrays = [[1, 2, 3], [4, 5, 6]]
    print(arrays)
                    