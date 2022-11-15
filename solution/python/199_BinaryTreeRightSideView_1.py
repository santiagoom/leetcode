
from typing import List  
from utils import *
import collections
                    
class Solution_199_BinaryTreeRightSideView_1:
    def rightSideView(self, root: TreeNode) -> List[int]:
        if root is None:
            return []
        
        next_level = deque([root,])
        rightside = []
        
        while next_level:
            # prepare for the next level
            curr_level = next_level
            next_level = deque()

            while curr_level:
                node = curr_level.popleft()
                    
                # add child nodes of the current level
                # in the queue for the next level
                if node.left:
                    next_level.append(node.left)
                if node.right:
                    next_level.append(node.right)
            
            # The current level is finished.
            # Its last element is the rightmost one.
            rightside.append(node.val)
        
        return rightside

if __name__ == "__main__":
    nums = [2, 7, 11, 15]
    target = 26
    so = Solution_199_BinaryTreeRightSideView_1()
    s = "aa"
    arrays = [[1, 2, 3], [4, 5, 6]]
    print(arrays)
                    