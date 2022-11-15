
from typing import List  
from utils import *
import collections
                    
class Solution_230_KthSmallestElementinaBST_1:
    def kthSmallest(self, root, k):
        """
        :type root: TreeNode
        :type k: int
        :rtype: int
        """
        def inorder(r):
            return inorder(r.left) + [r.val] + inorder(r.right) if r else []
    
        return inorder(root)[k - 1]

if __name__ == "__main__":
    nums = [2, 7, 11, 15]
    target = 26
    so = Solution_230_KthSmallestElementinaBST_1()
    s = "aa"
    arrays = [[1, 2, 3], [4, 5, 6]]
    print(arrays)
                    