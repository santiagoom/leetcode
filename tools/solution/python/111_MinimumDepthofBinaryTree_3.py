
from collections import deque
class Solution:
    def minDepth(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """
        if not root:
            return 0
        else:
            node_deque = deque([(1, root),])
        
        while node_deque:
            depth, root = node_deque.popleft()
            children = [root.left, root.right]
            if not any(children):
                return depth
            for c in children:
                if c:
                    node_deque.append((depth + 1, c))
