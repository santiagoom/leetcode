
from typing import List  
from utils import *
import collections
                    
class Solution_275_H-IndexII_2:
    def hIndex(self, citations):
        """
        :type citations: List[int]
        :rtype: int
        """
        n = len(citations)
        left, right = 0, n - 1

        # We need to find the rightmost 'index' such that: (citations[index] <= n - index)
        while left <= right:
            mid = left + (right - left) // 2

            # There's (n - mid) papers with an equal or higher citation count than citations[mid]
            # If (citations[mid] == n - mid) it's the optimal result and can be returned right away
            if citations[mid] == n - mid:
                return n - mid

            # If citations[mid] is less than (n - mid), narrow down on the right half to look for a paper
            # at a future index that meets the h-index criteria. Otherwise, narrow down on the left half
            if citations[mid] < n - mid:
                left = mid + 1
            else:
                right = mid - 1

        # We didn't find an exact match, so there's exactly (n - left) papers that have citations
        # greater than or equal to citations[left] and that is our answer
        return n - left

if __name__ == "__main__":
    nums = [2, 7, 11, 15]
    target = 26
    so = Solution_275_H-IndexII_2()
    s = "aa"
    arrays = [[1, 2, 3], [4, 5, 6]]
    print(arrays)
                    