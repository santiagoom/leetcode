from utils import *


class Solution:
    def postorderTraversal(self, root):
        res = []
        stack = []
        curr = root
        if root is None:
            return res

        while True:
            while curr is not None:
                if curr.right is not None:
                    stack.append(curr.right)
                stack.append(curr)
                curr = curr.left
            curr = stack.pop()
            if curr.right is not None and len(stack) > 0 and stack[-1] == curr.right:
                stack.pop()
                stack.append(curr)
                curr = curr.right
            else:
                res.append(curr.val)
                curr = None
            if len(stack) == 0:
                break
        return res


if __name__ == "__main__":
    root = TreeNode(val=1)
    root.right = TreeNode(val=2)
    root.right.left = TreeNode(val=3)
    print(root)
    s = Solution()
    print(s.postorderTraversal(root))
