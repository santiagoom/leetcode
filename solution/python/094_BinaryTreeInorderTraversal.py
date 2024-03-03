from utils import *


class Solution:
    def inorderTraversal(self, root):
        res = []
        stack = []
        curr = root
        while curr is not None or len(stack) > 0:
            while curr is not None:
                stack.append(curr)
                curr = curr.left
            curr = stack.pop()
            res.append(curr.val)
            curr = curr.right
        return res


if __name__ == "__main__":
    root = TreeNode(val=1)
    root.right = TreeNode(val=2)
    root.right.left = TreeNode(val=3)

    so = Solution()
    res = so.inorderTraversal(root)
    print(res)
