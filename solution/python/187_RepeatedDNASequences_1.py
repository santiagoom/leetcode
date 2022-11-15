
from typing import List  
from utils import *
import collections
                    
class Solution_187_RepeatedDNASequences_1:
    def findRepeatedDnaSequences(self, s: str) -> List[str]:
        L, n = 10, len(s)     
        seen, output = set(), set()

        # iterate over all sequences of length L
        for start in range(n - L + 1):
            tmp = s[start:start + L]
            if tmp in seen:
                output.add(tmp[:])
            seen.add(tmp)
        return output

if __name__ == "__main__":
    nums = [2, 7, 11, 15]
    target = 26
    so = Solution_187_RepeatedDNASequences_1()
    s = "aa"
    arrays = [[1, 2, 3], [4, 5, 6]]
    print(arrays)
                    