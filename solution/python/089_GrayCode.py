#!/usr/bin/env python 3
# -*- coding: utf-8 -*-

#
# Copyright (c) 2024 , Inc. All Rights Reserved
#
"""
brief

Authors:
Date:    2024/02/25 16:45:00
"""
import os
import sys
import time


class Solution:
    def grayCode(self, n):
        result = [0]

        for i in range(1, n + 1):
            previous_sequence_length = len(result)
            mask = 1 << (i - 1)
            for j in range(previous_sequence_length - 1, -1, -1):
                result.append(mask + result[j])

        return result


def func():
    n = 3
    s = Solution()
    print(s.grayCode(n))
    pass


def run():
    func()


if __name__ == '__main__':
    run()
