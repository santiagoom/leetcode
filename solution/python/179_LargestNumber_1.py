
from typing import List  
from utils import *
import collections
                    
class LargerNumKey(str):
    def __lt__(x, y):
        return x+y > y+x
        
class Solution_179_LargestNumber_1:
    def largestNumber(self, nums):
        largest_num = ''.join(sorted(map(str, nums), key=LargerNumKey))
        return '0' if largest_num[0] == '0' else largest_num

if __name__ == "__main__":
    nums = [2, 7, 11, 15]
    target = 26
    so = Solution_179_LargestNumber_1()
    s = "aa"
    arrays = [[1, 2, 3], [4, 5, 6]]
    print(arrays)
                    