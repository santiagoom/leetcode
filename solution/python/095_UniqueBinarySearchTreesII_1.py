from typing import List
from utils import *


class Solution_095_UniqueBinarySearchTreesII_1:
    def generateTrees(self, n):
        """
        :type n: int
        :rtype: List[TreeNode]
        """

        def generate_trees(start, end):
            if start > end:
                return [None, ]

            all_trees = []
            for i in range(start, end + 1):  # pick up a root
                # all possible left subtrees if i is choosen to be a root
                left_trees = generate_trees(start, i - 1)

                # all possible right subtrees if i is choosen to be a root
                right_trees = generate_trees(i + 1, end)

                # connect left and right subtrees to the root i
                for l in left_trees:
                    for r in right_trees:
                        current_tree = TreeNode(i)
                        current_tree.left = l
                        current_tree.right = r
                        all_trees.append(current_tree)

            return all_trees

        return generate_trees(1, n) if n else []


if __name__ == "__main__":
    n = 3
    so = Solution_095_UniqueBinarySearchTreesII_1()
    res = so.generateTrees(n)
    print(res)
    for each in res:
        list_a = []
        BinaryTreeInorderTraversal(each,list_a)
        print(list_a)
