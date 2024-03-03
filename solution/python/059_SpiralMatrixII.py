#!/usr/bin/env python 3
# -*- coding: utf-8 -*-

#
# Copyright (c) 2024 , Inc. All Rights Reserved
#
"""
brief

Authors:
Date:    2024/02/18 16:36:00
"""
import os
import sys
import time


class Solution:
    def generateMatrix(self, n):
        result = [[0] * n for _ in range(n)]
        cnt = 1
        for layer in range((n + 1) // 2):
            # direction 1 - traverse from left to right
            for ptr in range(layer, n - layer):
                result[layer][ptr] = cnt
                cnt += 1
            # direction 2 - traverse from top to bottom
            for ptr in range(layer + 1, n - layer):
                result[ptr][n - layer - 1] = cnt
                cnt += 1
            # direction 3 - traverse from right to left
            for ptr in range(n - layer - 2, layer - 1, -1):
                result[n - layer - 1][ptr] = cnt
                cnt += 1
            # direction 4 - traverse from bottom to top
            for ptr in range(n - layer - 2, layer, -1):
                result[ptr][layer] = cnt
                cnt += 1

        return result


def func():
    n = 3
    print(Solution().generateMatrix(n))
    pass


def run():
    func()


if __name__ == '__main__':
    run()
