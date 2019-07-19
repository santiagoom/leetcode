"""
Definition of TreeNode:
class TreeNode:
    def __init__(self, val):
        self.val = val
        self.left, self.right = None, None
"""


class Solution1:
    """
    @param: : the root of tree
    @param: : the target sum
    @return: two numbers from tree which sum is n
    """

    def twoSum(self, root, n):
        # write your code here

        def search(visited, val):
            node = visited
            while node:
                if node.val == val:
                    return visited != node
                elif node.val < val:
                    node = node.right
                else:
                    node = node.left
            return False

        def traval(node):
            if not node:
                return None

            if search(node, n - node.val):
                return [node.val, n - node.val]
            left = traval(node.left)
            if left:
                return left
            right = traval(node.right)
            if right:
                return right

            return None

        return traval(root)

"""
Definition of TreeNode:
class TreeNode:
    def __init__(self, val):
        self.val = val
        self.left, self.right = None, None
"""

class Solution2:
    """
    @param: : the root of tree
    @param: : the target sum
    @return: two numbers from tree which sum is n
    """

    def twoSum(self, root, n):
        # write your code here
        if root is None:
            return None
        table = {}
        queue = []
        queue.append(root)
        table[root.val] = 1
        while queue:
            node = queue.pop(0)
            if node.val in table:
                return [node.val, n-node.val]
            if node.left:
                queue.append(node.left)
                table[node.left.val] = 1
            if node.right:
                queue.append(node.right)
                table[node.right.val] = 1
        return None