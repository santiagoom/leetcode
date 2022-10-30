import collections
import math


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

        # root = TreeNode(1)
        # root.left = TreeNode(2)
        # root.left.left = TreeNode(3)
        # root.left.right = TreeNode(4)
        #
        # root.right = TreeNode(5)
        # root.right.right = TreeNode(6)


def BinaryTreeInorderTraversal(treeNode, tree_list):
    if (treeNode == None):
        return
    if (treeNode.left):
        BinaryTreeInorderTraversal(treeNode.left, tree_list)

    tree_list.append(treeNode.val)

    if (treeNode.right):
        BinaryTreeInorderTraversal(treeNode.right, tree_list)


def BinaryTreePreorderTraversal(treeNode, tree_list):
    if (treeNode == None):
        return
    tree_list.append(treeNode.val)

    if (treeNode.left):
        BinaryTreePreorderTraversal(treeNode.left, tree_list)

    if (treeNode.right):
        BinaryTreePreorderTraversal(treeNode.right, tree_list)


def BinaryTreePostorderTraversal(treeNode, tree_list):
    if (treeNode == None):
        return
    if (treeNode.left):
        BinaryTreePostorderTraversal(treeNode.left, tree_list)

    if (treeNode.right):
        BinaryTreePostorderTraversal(treeNode.right, tree_list)

    tree_list.append(treeNode.val)
