
from typing import List  
from utils import *
                    
class Solution_001_TwoSum_2:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        hashmap = {}
        for i in range(len(nums)):
            hashmap[nums[i]] = i
        for i in range(len(nums)):
            complement = target - nums[i]
            if complement in hashmap and hashmap[complement] != i:
                return [i, hashmap[complement]] 

if __name__ == "__main__":
    nums = [2, 7, 11, 15]


    print(nums)
    # target = 26
    # s = "aa"
    # arrays = [[1, 2, 3], [4, 5, 6]]
    # print(arrays)
    #
    # so = Solution_001_TwoSum_2
    # so.twoSum(nums,target)
                    