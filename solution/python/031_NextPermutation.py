#!/usr/bin/env python 3
# -*- coding: utf-8 -*-

#
# Copyright (c) 2024 , Inc. All Rights Reserved
#
"""
brief

Authors:
Date:    2024/02/17 16:14:00
"""
import os
import sys
import time
from typing import List


class Solution:
    def nextPermutation(self, nums: List[int]):
        i = len(nums) - 2
        while i >= 0 and nums[i + 1] <= nums[i]:
            i -= 1
        if i >= 0:
            j = len(nums) - 1
            while nums[j] <= nums[i]:
                j -= 1
            self.swap(nums, i, j)
        self.reverse(nums, i + 1)

    def reverse(self, nums, start):
        i, j = start, len(nums) - 1
        while i < j:
            self.swap(nums, i, j)
            i += 1
            j -= 1

    def swap(self, nums, i, j):
        temp = nums[i]
        nums[i] = nums[j]
        nums[j] = temp


def func():
    pass


def run():
    # func()
    s = Solution()
    nums = [1, 2, 7, 4, 3, 1]
    nums = [3, 2, 1]
    s.nextPermutation(nums)
    print(nums)


if __name__ == '__main__':
    run()
