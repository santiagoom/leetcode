
from typing import List  
from utils import *
import collections
                    
class Solution_272_ClosestBinarySearchTreeValueII_1:
    def closestKValues(self, root: TreeNode, target: float, k: int) -> List[int]:
        def inorder(r: TreeNode):
            return inorder(r.left) + [r.val] + inorder(r.right) if r else []
        
        nums = inorder(root)
        nums.sort(key = lambda x: abs(x - target))
        return nums[:k]

if __name__ == "__main__":
    nums = [2, 7, 11, 15]
    target = 26
    so = Solution_272_ClosestBinarySearchTreeValueII_1()
    s = "aa"
    arrays = [[1, 2, 3], [4, 5, 6]]
    print(arrays)
                    