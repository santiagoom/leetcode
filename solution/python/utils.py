import math
import sys

class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

        # l1 = ListNode(1)
        # l1.next = ListNode(2)
        # l1.next.next = ListNode(3)
        # l1.next.next.next = ListNode(4)
        # l1.next.next.next.next = ListNode(5)


class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


tree_list = []


def BinaryTreeInorderTraversal(treeNode):
    if (treeNode == None):
        return
    if (treeNode.left):
        BinaryTreeInorderTraversal(treeNode.left)

    tree_list.append(treeNode.val)

    if (treeNode.right):
        BinaryTreeInorderTraversal(treeNode.right)

    return tree_list
