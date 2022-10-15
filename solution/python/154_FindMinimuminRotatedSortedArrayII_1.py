
from typing import List  
from utils import *
                    
class Solution_154_FindMinimuminRotatedSortedArrayII_1:
    def findMin(self, nums: List[int]) -> int:    
        low = 0
        high = len(nums)-1
        while high > low:
            pivot = low + (high - low) // 2
            # risk of overflow: pivot = (low + high) // 2
            # Case 1):
            if nums[pivot] < nums[high]:
                high = pivot 
                # alternative: high = pivot - 1
                # too aggressive to move the `high` index,
                # it won't work for the test case of [3, 1, 3]
            # Case 2):
            elif nums[pivot] > nums[high]:
                low = pivot + 1
            # Case 3):
            else:
                high -= 1
        # the 'low' and 'high' index converge to the inflection point.
        return nums[low]

if __name__ == "__main__":
    nums = [2, 7, 11, 15]
    target = 26
    s = "aa"
    arrays = [[1, 2, 3], [4, 5, 6]]
    print(arrays)
                    