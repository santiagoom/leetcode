#!/usr/bin/env python 3
# -*- coding: utf-8 -*-

#
# Copyright (c) 2024 python, Inc. All Rights Reserved
#
"""
brief

Authors: python
Date:    2024/02/25 23:42:00
"""
import os
import sys
import time
from utils import *


class Solution:
    def inorderTraversal(self, root):
        res = []
        self.helper(root, res)
        return res

    def helper(self, root, res):
        if root:
            self.helper(root.left, res)
            res.append(root.val)
            self.helper(root.right, res)


def func():
    root = TreeNode(val=1)
    root.right = TreeNode(val=2)
    root.right.left = TreeNode(val=3)
    print(root)
    s = Solution()
    print(s.inorderTraversal(root))

    pass


def run():
    func()


if __name__ == '__main__':
    run()
