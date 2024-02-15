from typing import List
from utils import *
import collections


class Solution_889_ConstructBinaryTreefromPreorderandPostorderTraversal_2:
    def constructFromPrePost(self, pre, post):
        if not pre or not post: return None
        root = TreeNode(pre[0])
        if len(post) == 1:
            return root
        idx = pre.index(post[-2])
        root.left = self.constructFromPrePost(pre[1: idx], post[:(idx - 1)])
        root.right = self.constructFromPrePost(pre[idx:], post[(idx - 1):-1])
        return root


if __name__ == "__main__":
    pre = [1, 2, 4, 5, 3, 6, 7]
    post = [4, 5, 2, 6, 7, 3, 1]

    so = Solution_889_ConstructBinaryTreefromPreorderandPostorderTraversal_2()

    res = so.constructFromPrePost(pre, post)

    l = []
    BinaryTreePreorderTraversal(res, l)
    print(l)
