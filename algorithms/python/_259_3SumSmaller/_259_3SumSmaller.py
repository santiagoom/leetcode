class Solution1:
    """
    @param nums:  an array of n integers
    @param target: a target
    @return: the number of index triplets satisfy the condition nums[i] + nums[j] + nums[k] < target
    """
    def threeSumSmaller(self, nums, target):
        # Write your code here
        list.sort(nums)
        sum = 0
        for i in range(len(nums)-2):
            lo, hi = i+1, len(nums)-1
            while lo < hi:
                while lo < hi and nums[lo] + nums[hi] >= target - nums[i]:
                    hi -= 1
                sum += hi - lo
                lo += 1
        return sum

class Solution:
    """
    @param nums:  an array of n integers
    @param target: a target
    @return: the number of index triplets satisfy the condition nums[i] + nums[j] + nums[k] < target
    """
    def threeSumSmaller(self, nums, target):
        # Write your code here
        nums.sort()
        n = len(nums)
        res = n*(n-1)*(n-2)//6
        for i in range(len(nums)-2):
            j = i+1;k=len(nums)-1
            while j < k:
                s = nums[i] + nums[j] + nums[k]
                #[i,j,k],[i,j+1,k],...,[i,k-1,k] all satisfy the condition
                if s >= target:
                    res -= k-j
                    k -= 1
                else:
                    j += 1
        return res