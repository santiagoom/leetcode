
from typing import List  
from utils import *
                    
class Solution_088_MergeSortedArray_2:
    def merge(self, nums1: List[int], m: int, nums2: List[int], n: int) -> None:
        """
        Do not return anything, modify nums1 in-place instead.
        """
        # Make a copy of the first m elements of nums1.
        nums1_copy = nums1[:m] 
        
        # Read pointers for nums1Copy and nums2 respectively.
        p1 = 0
        p2 = 0
        
        # Compare elements from nums1Copy and nums2 and write the smallest to nums1.
        for p in range(n + m):
            # We also need to ensure that p1 and p2 aren't over the boundaries
            # of their respective arrays.
            if p2 >= n or (p1 < m and nums1_copy[p1] <= nums2[p2]):
                nums1[p] = nums1_copy[p1] 
                p1 += 1
            else:
                nums1[p] = nums2[p2]
                p2 += 1

if __name__ == "__main__":
    nums = [2, 7, 11, 15]
    target = 26
    s = "aa"
    arrays = [[1, 2, 3], [4, 5, 6]]
    print(arrays)
                    