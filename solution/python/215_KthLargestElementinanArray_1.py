
from typing import List  
from utils import *
import collections
                    
class Solution_215_KthLargestElementinanArray_1:
    def findKthLargest(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: int
        """
        return heapq.nlargest(k, nums)[-1]

if __name__ == "__main__":
    nums = [2, 7, 11, 15]
    target = 26
    so = Solution_215_KthLargestElementinanArray_1()
    s = "aa"
    arrays = [[1, 2, 3], [4, 5, 6]]
    print(arrays)
                    