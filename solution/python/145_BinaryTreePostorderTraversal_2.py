from utils import *


class Solution:
    """
    not work
    """
    def postorderTraversal(self, root):
        res = []
        stack = []
        curr = root
        while curr is not None or len(stack) > 0:
            while curr is not None:
                stack.append(curr)
                curr = curr.left

            curr = stack.pop()

            if len(stack) > 0:
                parent = stack.pop()
                right = parent.right
                res.append(curr.val)
                res.append(right.val)

            curr = curr.right

        return res


if __name__ == "__main__":
    root = TreeNode(val=1)
    root.right = TreeNode(val=2)
    root.right.left = TreeNode(val=3)
    print(root)
    s = Solution()
    print(s.postorderTraversal(root))
