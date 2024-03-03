#!/usr/bin/env python 3
# -*- coding: utf-8 -*-

#
# Copyright (c) 2024 , Inc. All Rights Reserved
#
"""
brief

Authors:
Date:    2024/02/18 15:50:00
"""
import os
import sys
import time


class Solution:
    def merge(self, intervals):
        intervals.sort()

        merged = []
        for interval in intervals:
            # If the list of merged intervals is empty or if the current
            # interval does not overlap with the previous, simply append it.
            if not merged or merged[-1][1] < interval[0]:
                merged.append(interval)
            # Otherwise, there is overlap, so we merge the current and previous
            # intervals.
            else:
                merged[-1][1] = max(merged[-1][1], interval[1])
        return merged


def func():
    intervals = [
        [1, 3],
        [8, 10],
        [2, 6],
        [15, 18],
    ]

    intervals = [[1, 3], [6, 9], [2, 5]]
    # newInterval = [2, 5]

    s = Solution()
    res = s.merge(intervals)
    print(res)
    pass


def run():
    func()


if __name__ == '__main__':
    run()
