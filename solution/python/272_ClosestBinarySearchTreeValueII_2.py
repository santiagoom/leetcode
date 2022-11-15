
from typing import List  
from utils import *
import collections
                    
from heapq import heappush, heappop
class Solution_272_ClosestBinarySearchTreeValueII_2:
    def closestKValues(self, root: TreeNode, target: float, k: int) -> List[int]:
        def inorder(r: TreeNode):
            if not r:
                return
            
            inorder(r.left)
            heappush(heap, (- abs(r.val - target), r.val))
            if len(heap) > k:
                heappop(heap)
            inorder(r.right) 
    
        heap = []
        inorder(root)
        return [x for _, x in heap]

if __name__ == "__main__":
    nums = [2, 7, 11, 15]
    target = 26
    so = Solution_272_ClosestBinarySearchTreeValueII_2()
    s = "aa"
    arrays = [[1, 2, 3], [4, 5, 6]]
    print(arrays)
                    