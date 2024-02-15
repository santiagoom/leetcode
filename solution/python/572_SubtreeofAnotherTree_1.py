
from typing import List  
from utils import *
import collections
                    
class Solution_572_SubtreeofAnotherTree_1:
    def isSubtree(self, root: Optional[TreeNode], subRoot: Optional[TreeNode]) -> bool:

        # Check for all subtree rooted at all nodes of tree "root"
        def dfs(node):

            # If this node is Empty, then no tree is rooted at this Node
            # Thus "tree rooted at node" cannot be same as "rooted at subRoot"
            # "tree rooted at subRoot" will always be non-empty (constraints)
            if node is None:
                return False

            # If "tree rooted at node" is identical to "tree at subRoot"
            elif is_identical(node, subRoot):
                return True

            # If "tree rooted at node" was not identical.
            # Check for tree rooted at children
            return dfs(node.left) or dfs(node.right)

        def is_identical(node1, node2):

            # If any one Node is Empty, both should be Empty
            if node1 is None or node2 is None:
                return node1 is None and node2 is None

            # Both Nodes Value should be Equal
            # And their respective left and right subtree should be identical
            return (node1.val == node2.val and
                    is_identical(node1.left, node2.left) and
                    is_identical(node1.right, node2.right))

        # Check for node rooted at "root"
        return dfs(root)



if __name__ == "__main__":
    nums = [2, 7, 11, 15]
    target = 26
    arrays = [[1, 2, 3], [4, 5, 6]]
    print(arrays)
    so = Solution_572_SubtreeofAnotherTree_1()
    s = "aa"
    res = 1
    print(res)
                    