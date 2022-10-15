
from typing import List  
from utils import *
                    
class Solution_129_SumRoottoLeafNumbers_3:
    def sumNumbers(self, root: TreeNode):
        root_to_leaf = curr_number = 0
        
        while root:  
            # If there is a left child,
            # then compute the predecessor.
            # If there is no link predecessor.right = root --> set it.
            # If there is a link predecessor.right = root --> break it.
            if root.left: 
                # Predecessor node is one step to the left 
                # and then to the right till you can.
                predecessor = root.left 
                steps = 1
                while predecessor.right and predecessor.right is not root: 
                    predecessor = predecessor.right 
                    steps += 1

                # Set link predecessor.right = root
                # and go to explore the left subtree
                if predecessor.right is None:
                    curr_number = curr_number * 10 + root.val                    
                    predecessor.right = root  
                    root = root.left  
                # Break the link predecessor.right = root
                # Once the link is broken, 
                # it's time to change subtree and go to the right
                else:
                    # If you're on the leaf, update the sum
                    if predecessor.left is None:
                        root_to_leaf += curr_number
                    # This part of tree is explored, backtrack
                    for _ in range(steps):
                        curr_number //= 10
                    predecessor.right = None
                    root = root.right 
                    
            # If there is no left child
            # then just go right.        
            else: 
                curr_number = curr_number * 10 + root.val
                # if you're on the leaf, update the sum
                if root.right is None:
                    root_to_leaf += curr_number
                root = root.right
                        
        return root_to_leaf

if __name__ == "__main__":
    nums = [2, 7, 11, 15]
    target = 26
    s = "aa"
    arrays = [[1, 2, 3], [4, 5, 6]]
    print(arrays)
                    