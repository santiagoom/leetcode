
from typing import List  
from utils import *
                    
class Solution_169_MajorityElement_2:
    def majorityElement(self, nums):
        counts = collections.Counter(nums)
        return max(counts.keys(), key=counts.get)

if __name__ == "__main__":
    so = Solution_169_MajorityElement_2()
    nums = [2, 2, 1, 1, 1, 2, 2]
    res = so.majorityElement(nums)
    print(res)