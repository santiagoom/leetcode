#!/usr/bin/env python 3
# -*- coding: utf-8 -*-

#
# Copyright (c) 2024 , Inc. All Rights Reserved
#
"""
brief

Authors:
Date:    2024/02/15 21:44:00
"""
import os
import sys
import time
from typing import Tuple, Dict


def LongestSubstringWithoutRepeatingCharacters_5(string: str) -> int:
    n = len(string)
    map: Dict[str, int] = {}
    res = 0
    left = 0
    for i in range(n):
        if map.get(string[i], 0) > 0:
            left = max(left, map.get(string[i]))
        res = max(res, i - left + 1)
        map[string[i]] = i + 1
    return res


def run():
    s = "abcabcabc"
    s = "abcbdefgj"
    res = LongestSubstringWithoutRepeatingCharacters_5(s)
    print(res)


if __name__ == '__main__':
    run()
