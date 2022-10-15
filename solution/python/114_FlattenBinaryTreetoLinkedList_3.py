
from typing import List  
from utils import *
                    
class Solution_114_FlattenBinaryTreetoLinkedList_3:
    
    def flatten(self, root: TreeNode) -> None:
        """
        Do not return anything, modify root in-place instead.
        """
        
        # Handle the null scenario
        if not root:
            return None
        
        node = root
        while node:
            
            # If the node has a left child
            if node.left:
                
                # Find the rightmost node
                rightmost = node.left
                while rightmost.right:
                    rightmost = rightmost.right
                
                # rewire the connections
                rightmost.right = node.right
                node.right = node.left
                node.left = None
            
            # move on to the right side of the tree
            node = node.right

if __name__ == "__main__":
    nums = [2, 7, 11, 15]
    target = 26
    s = "aa"
    arrays = [[1, 2, 3], [4, 5, 6]]
    print(arrays)
                    