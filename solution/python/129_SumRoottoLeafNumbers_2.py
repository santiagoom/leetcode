
from typing import List  
from utils import *
                    
class Solution_129_SumRoottoLeafNumbers_2:
    def sumNumbers(self, root: TreeNode):
        def preorder(r, curr_number):
            nonlocal root_to_leaf
            if r:
                curr_number = curr_number * 10 + r.val
                # if it's a leaf, update root-to-leaf sum
                if not (r.left or r.right):
                    root_to_leaf += curr_number
                    
                preorder(r.left, curr_number)
                preorder(r.right, curr_number) 
        
        root_to_leaf = 0
        preorder(root, 0)
        return root_to_leaf

if __name__ == "__main__":
    nums = [2, 7, 11, 15]
    target = 26
    s = "aa"
    arrays = [[1, 2, 3], [4, 5, 6]]
    print(arrays)
                    