from typing import List
from utils import *
import collections


class Solution_889_ConstructBinaryTreefromPreorderandPostorderTraversal_1:
    def constructFromPrePost(self, pre: List[int], post: List[int]) -> TreeNode:
        def helper(pre, post):
            print('pre is: ', pre, 'post is: ', post)
            if not pre:
                return None

            if len(pre) == 1:
                return TreeNode(post.pop())

            node = TreeNode(post.pop())  # 3
            ind = pre.index(post[-1])  # 4

            node.right = helper(pre[ind:], post)  # 1
            node.left = helper(pre[1:ind], post)  # 2
            return node

        return helper(pre, post)


if __name__ == "__main__":
    pre = [1, 2, 4, 5, 3, 6, 7]
    post = [4, 5, 2, 6, 7, 3, 1]

    so = Solution_889_ConstructBinaryTreefromPreorderandPostorderTraversal_1()

    res = so.constructFromPrePost(pre, post)

    l = []
    BinaryTreePreorderTraversal(res, l)
    print(l)
