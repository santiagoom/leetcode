#!/usr/bin/env python 3
# -*- coding: utf-8 -*-

#
# Copyright (c) 2024 , Inc. All Rights Reserved
#
"""
brief

Authors:
Date:    2024/02/18 15:23:00
"""
import os
import sys
import time


class Solution:
    def canJump(self, nums):
        last_pos = len(nums) - 1
        for i in range(len(nums) - 1, -1, -1):
            if i + nums[i] >= last_pos:
                last_pos = i
        return last_pos == 0


def func():
    nums = [3, 2, 1, 1, 4]
    s = Solution()
    res = s.canJump(nums)
    print(res)
    pass


def run():
    func()


if __name__ == '__main__':
    run()
