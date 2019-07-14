# two-pointer
def twoSum1(self, numbers, target):
    l, r = 0, len(numbers) - 1
    while l < r:
        s = numbers[l] + numbers[r]
        if s == target:
            return [l + 1, r + 1]
        elif s < target:
            l += 1
        else:
            r -= 1


# dictionary
def twoSum2(self, numbers, target):
    dic = {}
    for i, num in enumerate(numbers):
        if target - num in dic:
            return [dic[target - num] + 1, i + 1]
        dic[num] = i


# binary search
def twoSum(self, numbers, target):
    for i in range(len(numbers)):
        l, r = i + 1, len(numbers) - 1
        tmp = target - numbers[i]
        while l <= r:
            mid = l + (r - l) // 2
            if numbers[mid] == tmp:
                return [i + 1, mid + 1]
            elif numbers[mid] < tmp:
                l = mid + 1
            else:
                r = mid - 1


# Here's a summary of how long it takes to run for three methods:
#
# Two pointers: 43 ms
# Dictionary: 46 ms
# Binary Search: 75 ms

# It was odd to me that binary search is significantly slower than other two methods;
# it should be faster since we are using the sorted feature.
# It turns out that if we don't repeat investigating the elements that have been already investigated,
# binary search becomes the fastest method.
# Here's the modified version which takes 35 ms:

def twoSum(self, numbers, target):
    investigatedSoFar = []
    for i in range(len(numbers)):
        if not numbers[i] in investigatedSoFar:
            investigatedSoFar.append(numbers[i])
            l, r = i + 1, len(numbers) - 1
            tmp = target - numbers[i]
            while l <= r:
                mid = l + (r - l) // 2
                if numbers[mid] == tmp:
                    return ([i + 1, mid + 1])
                elif numbers[mid] < tmp:
                    l = mid + 1
                else:
                    r = mid - 1


# For the two-pointer one, this seems to be faster

def twoSum1(self, numbers, target):
    f, l = 0, len(numbers) - 1
    while numbers[f] + numbers[l] != target:
        if numbers[f] + numbers[l] > target:
            l -= 1
        else:
            f += 1
    return [f + 1, l + 1]
