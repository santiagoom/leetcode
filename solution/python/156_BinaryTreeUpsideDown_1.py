from typing import List
from utils import *


class Solution_156_BinaryTreeUpsideDown_1:
    def upsideDownBinaryTree(self, root):
        if not root or not root.left:
            return root
        lRoot = self.upsideDownBinaryTree(root.left)
        rMost = lRoot
        while rMost.right:
            rMost = rMost.right
        root, rMost.left, rMost.right = lRoot, root.right, TreeNode(root.val)
        return root


if __name__ == "__main__":
    t1 = TreeNode(1)
    t1.left = TreeNode(2)
    t1.right = TreeNode(3)
    t1.left.left = TreeNode(4)
    t1.left.right = TreeNode(5)

    so = Solution_156_BinaryTreeUpsideDown_1()

    res = so.upsideDownBinaryTree(t1)


    output = []

    BinaryTreeInorderTraversal(res,output)

    print(output)