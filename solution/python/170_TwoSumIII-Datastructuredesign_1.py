
from typing import List  
from utils import *
                    
class TwoSum(object):

    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.nums = []
        self.is_sorted = False


    def add(self, number):
        """
        Add the number to an internal data structure..
        :type number: int
        :rtype: None
        """
        # Inserting while maintaining the ascending order.
        # for index, num in enumerate(self.nums):
        #     if number <= num:
        #         self.nums.insert(index, number)
        #         return
        # larger than any number
        #self.nums.append(number)

        self.nums.append(number)
        self.is_sorted = False
    

    def find(self, value):
        """
        Find if there exists any pair of numbers which sum is equal to the value.
        :type value: int
        :rtype: bool
        """
        if not self.is_sorted:
            self.nums.sort()
            self.is_sorted = True

        low, high = 0, len(self.nums)-1
        while low < high:
            currSum = self.nums[low] + self.nums[high]
            if currSum < value:
                low += 1
            elif currSum > value:
                high -= 1
            else: # currSum == value
                return True
        
        return False


if __name__ == "__main__":
    nums = [2, 7, 11, 15]
    target = 26
    s = "aa"
    arrays = [[1, 2, 3], [4, 5, 6]]
    print(arrays)
                    