
from typing import List  
from utils import *
import collections
                    
class Solution_199_BinaryTreeRightSideView_3:
    def rightSideView(self, root: TreeNode) -> List[int]:
        if root is None:
            return []
        
        queue = deque([root,])
        rightside = []
        
        while queue:
            level_length = len(queue)

            for i in range(level_length):
                node = queue.popleft()
                # if it's the rightmost element
                if i == level_length - 1:
                    rightside.append(node.val)
                    
                # add child nodes in the queue 
                if node.left:
                    queue.append(node.left)
                if node.right:
                    queue.append(node.right)
        
        return rightside

if __name__ == "__main__":
    nums = [2, 7, 11, 15]
    target = 26
    so = Solution_199_BinaryTreeRightSideView_3()
    s = "aa"
    arrays = [[1, 2, 3], [4, 5, 6]]
    print(arrays)
                    