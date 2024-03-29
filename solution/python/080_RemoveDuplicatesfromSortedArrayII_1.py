from typing import List
from utils import *


class Solution_080_RemoveDuplicatesfromSortedArrayII_1:
    def removeDuplicates(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """

        # Initialize the counter and the array index.
        i, count = 1, 1

        # Start from the second element of the array and process
        # elements one by one.
        while i < len(nums):

            # If the current element is a duplicate, 
            # increment the count.
            if nums[i] == nums[i - 1]:
                count += 1

                # If the count is more than 2, this is an
                # unwanted duplicate element and hence we 
                # remove it from the array.
                if count > 2:
                    nums.pop(i)

                    # Note that we have to decrement the
                    # array index value to keep it consistent
                    # with the size of the array.
                    i -= 1

            else:

                # Reset the count since we encountered a different element
                # than the previous one
                count = 1

            # Move on to the next element in the array
            i += 1

        return len(nums)


if __name__ == "__main__":
    nums = [2, 7, 11, 15]
    target = 26
    s = "aa"
    arrays = [[1, 2, 3], [4, 5, 6]]
    print(arrays)
