class Solution1:
    """
    @param numbers: Give an array
    @param target: An integer
    @return: Find all unique quadruplets in the array which gives the sum of zero
    """
    def fourSum(self, numbers, target):
        numbers.sort()
        res = []
        for i in range(len(numbers) - 3):
            if i and numbers[i] == numbers[i - 1]:
                continue
            for j in range(i + 1, len(numbers) - 2):
                if j != i + 1 and numbers[j] == numbers[j - 1]:
                    continue
                sum = target - numbers[i] - numbers[j]
                left, right = j + 1, len(numbers) - 1
                while left < right:
                    if numbers[left] + numbers[right] == sum:
                        res.append([numbers[i], numbers[j], numbers[left], numbers[right]])
                        left += 1
                        right -= 1
                        while left < right and numbers[left] == numbers[left - 1]:
                            left += 1
                        while left < right and numbers[right] == numbers[right + 1]:
                            right -= 1
                    elif numbers[left] + numbers[right] > sum:
                        right -= 1
                    else:
                        left += 1
        return res


class Solution2:
    """
    @param numbers: Give an array
    @param target: An integer
    @return: Find all unique quadruplets in the array which gives the sum of zero
    """

    def fourSum(self, nums, target):
        if not nums or len(nums) < 4:
            return []

        nums.sort()
        result = []
        n = len(nums)
        for i in range(0, n - 3):
            if i > 0 and nums[i] == nums[i - 1]:
                continue

            for j in range(i + 1, n - 2):
                if j > i + 1 and nums[j] == nums[j - 1]:
                    continue
                sum = target - nums[i] - nums[j]
                l, r = j + 1, n - 1
                while l < r:
                    if nums[l] + nums[r] == sum:
                        result.append([nums[i], nums[j], nums[l], nums[r]])
                        l += 1
                        r -= 1
                        # remove duplicates:
                        while l < r and nums[l] == nums[l - 1]:
                            l += 1
                        while l < r and nums[r] == nums[r + 1]:
                            r -= 1

                    elif nums[l] + nums[r] < sum:
                        l += 1

                    else:
                        r -= 1

        return result