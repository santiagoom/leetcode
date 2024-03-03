import collections
import math
import sys
from collections import *

import heapq
import random
from pydantic import BaseModel, Field, StrictStr, StrictInt


# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next


class ListNode(BaseModel):
    val: int = 0
    next: 'ListNode' = None


l1 = ListNode(val=1)
l1.next = ListNode(val=2)
l1.next.next = ListNode(val=3)
l1.next.next.next = ListNode(val=4)
l1.next.next.next.next = ListNode(val=5)


class TreeNode(BaseModel):
    val: int = 0
    left: 'TreeNode' = None
    right: 'TreeNode' = None


root = TreeNode(val=1)
root.left = TreeNode(val=2)
root.left.left = TreeNode(val=3)
root.left.right = TreeNode(val=4)

root.right = TreeNode(val=5)
root.right.right = TreeNode(val=6)


# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right



def BinaryTreePreorderTraversal(treeNode, tree_list):
    if (treeNode == None):
        return
    tree_list.append(treeNode.val)

    if (treeNode.left):
        BinaryTreePreorderTraversal(treeNode.left, tree_list)

    if (treeNode.right):
        BinaryTreePreorderTraversal(treeNode.right, tree_list)


def BinaryTreeInorderTraversal(treeNode, tree_list):
    if (treeNode == None):
        tree_list.append("#")
        return

    if (treeNode.left):
        BinaryTreeInorderTraversal(treeNode.left, tree_list)
    tree_list.append(treeNode.val)

    if (treeNode.right):
        BinaryTreeInorderTraversal(treeNode.right, tree_list)


def BinaryTreePostorderTraversal(treeNode, tree_list):
    if (treeNode == None):
        return
    if (treeNode.left):
        BinaryTreePostorderTraversal(treeNode.left, tree_list)

    if (treeNode.right):
        BinaryTreePostorderTraversal(treeNode.right, tree_list)

    tree_list.append(treeNode.val)


def printList(head):
    while head:
        print(head.val, end=" ")
        head = head.next
    print()
