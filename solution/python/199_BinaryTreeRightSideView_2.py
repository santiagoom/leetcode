
from typing import List  
from utils import *
import collections
                    
class Solution_199_BinaryTreeRightSideView_2:
    def rightSideView(self, root: TreeNode) -> List[int]:
        if root is None:
            return []
        
        queue = deque([root, None,])
        rightside = []
        
        curr = root
        while queue:
            prev, curr = curr, queue.popleft()

            while curr:
                # add child nodes in the queue
                if curr.left:
                    queue.append(curr.left)
                if curr.right:
                    queue.append(curr.right)
                    
                prev, curr = curr, queue.popleft()
            
            # the current level is finished
            # and prev is its rightmost element      
            rightside.append(prev.val)
            # add a sentinel to mark the end 
            # of the next level
            if queue:
                queue.append(None)
        
        return rightside

if __name__ == "__main__":
    nums = [2, 7, 11, 15]
    target = 26
    so = Solution_199_BinaryTreeRightSideView_2()
    s = "aa"
    arrays = [[1, 2, 3], [4, 5, 6]]
    print(arrays)
                    