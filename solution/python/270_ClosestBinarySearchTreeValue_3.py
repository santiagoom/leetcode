
from typing import List  
from utils import *
import collections
                    
class Solution_270_ClosestBinarySearchTreeValue_3:
    def closestValue(self, root: TreeNode, target: float) -> int:
        closest = root.val
        while root:
            closest = min(root.val, closest, key = lambda x: abs(target - x))
            root = root.left if target < root.val else root.right
        return closest

if __name__ == "__main__":
    nums = [2, 7, 11, 15]
    target = 26
    so = Solution_270_ClosestBinarySearchTreeValue_3()
    s = "aa"
    arrays = [[1, 2, 3], [4, 5, 6]]
    print(arrays)
                    