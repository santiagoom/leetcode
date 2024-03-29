
from typing import List  
from utils import *
                    
class Solution_099_RecoverBinarySearchTree_1:
    def recoverTree(self, root: TreeNode):
        """
        :rtype: void Do not return anything, modify root in-place instead.
        """
        def inorder(r: TreeNode) -> List[int]:
            return inorder(r.left) + [r.val] + inorder(r.right) if r else []
        
        def find_two_swapped(nums: List[int]) -> (int, int):
            n = len(nums)
            x = y = None # Initialize x and y as a value that cannot be the value of a node.
            for i in range(n - 1):
                if nums[i + 1] < nums[i]:
                    y = nums[i + 1]
                    # first swap occurrence
                    if x is None:     
                        x = nums[i]
                    # second swap occurrence
                    else:           
                        break
            return x, y
        
        def recover(r: TreeNode, count: int):
            if r:
                if r.val == x or r.val == y:
                    r.val = y if r.val == x else x
                    count -= 1
                    if count == 0:
                        return      
                recover(r.left, count)
                recover(r.right, count)
            
        nums = inorder(root)
        x, y = find_two_swapped(nums)
        recover(root, 2)

if __name__ == "__main__":
    nums = [2, 7, 11, 15]
    target = 26
    s = "aa"
    arrays = [[1, 2, 3], [4, 5, 6]]
    print(arrays)
                    