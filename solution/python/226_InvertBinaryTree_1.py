
from typing import List  
from utils import *
import collections
                    
class Solution_226_InvertBinaryTree_1:
    def invertTree(self, root: Optional[TreeNode]) -> Optional[TreeNode]:
        if not root:
            return None
        
        right = self.invertTree(root.right)
        left = self.invertTree(root.left)
        root.left = right
        root.right = left
        return root

if __name__ == "__main__":
    nums = [2, 7, 11, 15]
    target = 26
    so = Solution_226_InvertBinaryTree_1()
    s = "aa"
    arrays = [[1, 2, 3], [4, 5, 6]]
    print(arrays)
                    