#!/usr/bin/env python 3
# -*- coding: utf-8 -*-

#
# Copyright (c) 2024 python, Inc. All Rights Reserved
#
"""
brief

Authors: python
Date:    2024/02/26 00:06:00
"""
import os
import sys
import time
from utils import *


class Solution:
    def preorderTraversal(self, root):
        res = []
        self.helper(root, res)
        return res

    def helper(self, root, res):
        if root:
            res.append(root.val)
            self.helper(root.left, res)
            self.helper(root.right, res)


def func():
    root = TreeNode(val=1)
    root.right = TreeNode(val=2)
    root.right.left = TreeNode(val=3)
    print(root)
    s = Solution()
    print(s.preorderTraversal(root))


def run():
    func()


if __name__ == '__main__':
    run()
