
from typing import List  
from utils import *
import collections
                    
class Solution_270_ClosestBinarySearchTreeValue_1:
    def closestValue(self, root: TreeNode, target: float) -> int:
        def inorder(r: TreeNode):
            return inorder(r.left) + [r.val] + inorder(r.right) if r else []
        
        return min(inorder(root), key = lambda x: abs(target - x))

if __name__ == "__main__":
    nums = [2, 7, 11, 15]
    target = 26
    so = Solution_270_ClosestBinarySearchTreeValue_1()
    s = "aa"
    arrays = [[1, 2, 3], [4, 5, 6]]
    print(arrays)
                    