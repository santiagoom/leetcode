
from typing import List  
from utils import *
import collections
                    
class Solution_285_InorderSuccessorinBST_2:
    
    def inorderSuccessor(self, root: 'TreeNode', p: 'TreeNode') -> 'TreeNode':
        
        successor = None
        
        while root:
            
            if p.val >= root.val:
                root = root.right
            else:
                successor = root
                root = root.left
                
        return successor

if __name__ == "__main__":
    nums = [2, 7, 11, 15]
    target = 26
    so = Solution_285_InorderSuccessorinBST_2()
    s = "aa"
    arrays = [[1, 2, 3], [4, 5, 6]]
    print(arrays)
                    