
from typing import List  
from utils import *
import collections
                    
class Solution_270_ClosestBinarySearchTreeValue_2:
    def closestValue(self, root: TreeNode, target: float) -> int:
        stack, pred = [], float('-inf')
        
        while stack or root:
            while root:
                stack.append(root)
                root = root.left
            root = stack.pop()
            
            if pred <= target and target < root.val:
                return min(pred, root.val, key = lambda x: abs(target - x))
                
            pred = root.val
            root = root.right

        return pred

if __name__ == "__main__":
    nums = [2, 7, 11, 15]
    target = 26
    so = Solution_270_ClosestBinarySearchTreeValue_2()
    s = "aa"
    arrays = [[1, 2, 3], [4, 5, 6]]
    print(arrays)
                    