
from typing import List  
from utils import *
import collections
                    
class Solution_250_CountUnivalueSubtrees_2:
    def countUnivalSubtrees(self, root):
        self.count = 0
        self.is_valid_part(root, 0)
        return self.count


    def is_valid_part(self, node, val):

        # considered a valid subtree
        if node is None: return True

        # check if node.left and node.right are univalue subtrees of value node.val
        if not all([self.is_valid_part(node.left, node.val),
                    self.is_valid_part(node.right, node.val)]):
            return False

        # if it passed the last step then this a valid subtree - increment
        self.count += 1

        # at this point we know that this node is a univalue subtree of value node.val
        # pass a boolean indicating if this is a valid subtree for the parent node
        return node.val == val

if __name__ == "__main__":
    nums = [2, 7, 11, 15]
    target = 26
    so = Solution_250_CountUnivalueSubtrees_2()
    s = "aa"
    arrays = [[1, 2, 3], [4, 5, 6]]
    print(arrays)
                    