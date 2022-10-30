from typing import List
from utils import *


# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution_114_FlattenBinaryTreetoLinkedList_1:

    def flattenTree(self, node):

        # Handle the null scenario
        if not node:
            return None

        # For a leaf node, we simply return the
        # node as is.
        if not node.left and not node.right:
            return node

        # Recursively flatten the left subtree
        leftTail = self.flattenTree(node.left)

        # Recursively flatten the right subtree
        rightTail = self.flattenTree(node.right)

        # If there was a left subtree, we shuffle the connections
        # around so that there is nothing on the left side
        # anymore.
        if leftTail:
            leftTail.right = node.right
            node.right = node.left
            node.left = None

        # We need to return the "rightmost" node after we are
        # done wiring the new connections. 
        return rightTail if rightTail else leftTail

    def flatten(self, root: TreeNode) -> None:
        """
        Do not return anything, modify root in-place instead.
        """

        self.flattenTree(root)


if __name__ == "__main__":
    root = TreeNode(1)
    root.left = TreeNode(2)
    root.left.left = TreeNode(3)
    root.left.right = TreeNode(4)

    root.right = TreeNode(5)
    root.right.right = TreeNode(6)

    # res = []
    # # BinaryTreeInorderTraversal(root,res)
    # BinaryTreePreorderTraversal(root, res)
    # print(res)

    so = Solution_114_FlattenBinaryTreetoLinkedList_1()
    ret = so.flatten(root)

    res = []
    BinaryTreePostorderTraversal(root,res)
    # BinaryTreePostorderTraversal(ret, res)
    print(res)
