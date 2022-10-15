
from typing import List  
from utils import *
                    
class Solution_099_RecoverBinarySearchTree_3:
    def recoverTree(self, root):
        """
        :type root: TreeNode
        :rtype: void Do not return anything, modify root in-place instead.
        """
        def find_two_swapped(root: TreeNode):
            nonlocal x, y, pred
            if root is None:
                return
            
            find_two_swapped(root.left)
            if pred and root.val < pred.val:
                y = root
                # first swap occurence
                if x is None:
                    x = pred 
                # second swap occurence
                else:
                    return
            pred = root
            find_two_swapped(root.right)
        
        x = y = pred = None
        find_two_swapped(root)
        x.val, y.val = y.val, x.val

if __name__ == "__main__":
    nums = [2, 7, 11, 15]
    target = 26
    s = "aa"
    arrays = [[1, 2, 3], [4, 5, 6]]
    print(arrays)
                    