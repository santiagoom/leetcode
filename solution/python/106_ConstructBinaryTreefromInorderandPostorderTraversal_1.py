from typing import List
from utils import *


class Solution_106_ConstructBinaryTreefromInorderandPostorderTraversal_1:
    def buildTree(self, inorder: List[int], postorder: List[int]) -> TreeNode:
        def helper(in_left, in_right):
            # if there is no elements to construct subtrees
            if in_left > in_right:
                return None

            # pick up the last element as a root
            val = postorder.pop()
            root = TreeNode(val)

            # root splits inorder list
            # into left and right subtrees
            index = idx_map[val]

            # build right subtree
            root.right = helper(index + 1, in_right)
            # build left subtree
            root.left = helper(in_left, index - 1)
            return root

        # build a hashmap value -> its index
        idx_map = {val: idx for idx, val in enumerate(inorder)}
        return helper(0, len(inorder) - 1)


if __name__ == "__main__":

    inorder = [9, 3, 15, 20, 7]
    postorder = [9, 15, 7, 20, 3]



    so = Solution_106_ConstructBinaryTreefromInorderandPostorderTraversal_1()

    res = so.buildTree(inorder, postorder)

    l = []
    BinaryTreeInorderTraversal(res, l)
    print(l)

