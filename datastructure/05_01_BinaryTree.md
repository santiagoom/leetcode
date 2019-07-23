# Binary Tree

## Introduction

**Trees:** Unlike Arrays, Linked Lists, Stack and queues, which are linear data structures, trees are hierarchical data structures.

**Tree Vocabulary:** The topmost node is called root of the tree. The elements that are directly under an element are called its children. The element directly above something is called its parent. For example, a is a child of f and f is the parent of a. Finally, elements with no children are called leaves.

```
      tree
      ----
       j    <-- root
     /   \
    f      k  
  /   \      \
 a     h      z    <-- leaves 
```



### **Why Trees?**

1. One reason to use trees might be because you want to store information that naturally forms a hierarchy. For example, the file system on a computer: 

```markdown
    file system
    -----------
         /    <-- root
      /      \
    ...       home
          /          \
       ugrad        course
        /       /      |     \
      ...      cs101  cs112  cs113  
```

2. Trees (with some ordering e.g., BST) provide moderate access/search (quicker than Linked List and slower than arrays).
3.  Trees provide moderate insertion/deletion (quicker than Arrays and slower than Unordered Linked Lists).
4. Like Linked Lists and unlike Arrays, Trees don’t have an upper limit on number of nodes as nodes are linked using pointers. 

### **Main applications of trees include** 

**1.** Manipulate hierarchical data. 

**2.** Make information easy to search (see tree traversal). 

**3.** Manipulate sorted lists of data. 

**4.** As a workflow for compositing digital images for visual effects. 

**5.** Router algorithms 

**6.** Form of a multi-stage decision-making (see business chess). 



### **Representation**

#### Dynamic Node Representation (Linked Representation)

A tree is represented by a pointer to the topmost node in tree. If the tree is empty, then value of root is NULL. 

A Tree node contains following parts. 

1. Data 
2. Pointer to left child 
3. Pointer to right child



**First Simple Tree**

**Java Code**

```java
/* Class containing left and right child of current
   node and key value*/
class Node
{
    int key;
    Node left, right;
 
    public Node(int item)
    {
        key = item;
        left = right = null;
    }
}
 
// A Java program to introduce Binary Tree
class BinaryTree
{
    // Root of Binary Tree
    Node root;
 
    // Constructors
    BinaryTree(int key)
    {
        root = new Node(key);
    }
 
    BinaryTree()
    {
        root = null;
    }
 
    public static void main(String[] args)
    {
        BinaryTree tree = new BinaryTree();
 
        /*create root*/
        tree.root = new Node(1);
 
        /* following is the tree after above statement
 
              1
            /   \
          null  null     */
 
        tree.root.left = new Node(2);
        tree.root.right = new Node(3);
 
        /* 2 and 3 become left and right children of 1
               1
             /   \
            2      3
          /    \    /  \
        null null null null  */
 
 
        tree.root.left.left = new Node(4);
        /* 4 becomes left child of 2
                    1
                /       \
               2          3
             /   \       /  \
            4    null  null  null
           /   \
          null null
         */
    }
}
```

**Python Code**

```python
# Python program to introduce Binary Tree
 
# A class that represents an individual node in a
# Binary Tree
class Node:
    def __init__(self,key):
        self.left = None
        self.right = None
        self.val = key
 
 
# create root
root = Node(1)
''' following is the tree after above statement
        1
      /   \
     None  None'''
 
root.left      = Node(2);
root.right     = Node(3);
   
''' 2 and 3 become left and right children of 1
           1
         /   \
        2      3
     /    \    /  \
   None None None None'''
 
 
root.left.left  = Node(4);
'''4 becomes left child of 2
           1
       /       \
      2          3
    /   \       /  \
   4    None  None  None
  /  \
None None'''
```



#### Array Representation (Sequential Representation) 

We are going to talk about sequential representation of the trees.

To represent tree using array, numbering of nodes can start either from 0–(n-1) or 1–n .

```
       A(0)    
     /   \
    B(1)  C(2)  
  /   \      \
 D(3)  E(4)   F(5) 
OR,
      A(1)    
     /   \
    B(2)  C(3)  
  /   \      \
 D(4)  E(4)   F(6)  
```

For first case(0—n-1),
if (say)father=p;
then left_son=(2*p)+1;
and right_son=(2*p)+2;

For second case(1—n),
if (say)father=p;
then left_son=(2*p);
and right_son=(2*p)+1;
where father,left_son and right_son are the values of indices of the array.

**Java Code**

```java
// JAVA implementation of tree using array
// numbering starting from 0 to n-1.
import java.util.*;
import java.lang.*;
import java.io.*;
 
class Tree {
    public static void main(String[] args)
    {
        Array_imp obj = new Array_imp();
        obj.Root("A");
        obj.set_Left("B", 0);
        obj.set_Right("C", 0);
        obj.set_Left("D", 1);
        obj.set_Right("E", 1);
        obj.set_Left("F", 2);
        obj.print_Tree();
    }
}
 
class Array_imp {
    static int root = 0;
    static String[] str = new String[10];
 
    /*create root*/
    public void Root(String key)
    {
        str[0] = key;
    }
 
    /*create left son of root*/
    public void set_Left(String key, int root)
    {
        int t = (root * 2) + 1;
        str[t] = key;
    }
 
    /*create right son of root*/
    public void set_Right(String key, int root)
    {
        int t = (root * 2) + 2;
        str[t] = key;
    }
 
    public void print_Tree()
    {
        for (int i = 0; i < 10; i++) {
            if (str[i] != null)
                System.out.print(str[i]);
        }
    }
}
```



**Summary:** Tree is a hierarchical data structure. Main uses of trees include maintaining hierarchical data, providing moderate access and insert/delete operations. Binary trees are special cases of tree where every node has at most two children.

#### 



## Properties

1. **The maximum number of nodes at level ‘l’ of a binary tree is 2^l-1^**.

Here level is number of nodes on path from root to the node (including root and node). Level of root is 1.
This can be proved by induction.
For root, l = 1, number of nodes = 2^l-1^ = 1
Assume that maximum number of nodes on level l is 2^l-1^
Since in Binary tree every node has at most 2 children, next level would have twice nodes, i.e. 2 * 2^l-1^

2. **Maximum number of nodes in a binary tree of height ‘h’ is 2^h^ – 1**.

Here height of a tree is maximum number of nodes on root to leaf path. Height of a tree with single node is considered as 1.
This result can be derived from point 2 above. A tree has maximum nodes if all levels have maximum nodes. So maximum number of nodes in a binary tree of height h is 1 + 2 + 4 + .. + 2^h-1^. This is a simple geometric series with h terms and sum of this series is 2^h^ – 1.
In some books, height of a leaf is considered as 0. In this convention, the above formula becomes 2^h+1^ – 1

3. **In a Binary Tree with N nodes, minimum possible height or minimum number of levels is  ⌈Log~2~(N+1)⌉**  

This can be directly derived from point 2 above. If we consider the convention where height of a leaf node is considered as 0, then above formula for minimum possible height becomes   ⌈ Log~2~(N+1) ⌉ – 1

4. **A Binary Tree with L leaves has at least   ⌈ Log~2~L ⌉ + 1   levels**

A Binary tree has maximum number of leaves (and minimum number of levels) when all levels are fully filled. Let all leaves be at level l, then below is true for number of leaves L.

   L   <=  2^l-1^  [From Point 1]
   l =   ⌈ Log~2~L ⌉ + 1 
   where l is the minimum number of levels. 

5. **In Binary tree where every node has 0 or 2 children, number of leaf nodes is always one more than nodes with two children**.

```markdown
   L = T + 1
Where L = Number of leaf nodes
      T = Number of internal nodes with two children
```



## Types of Binary Tree

### **Full Binary Tree** 

A Binary Tree is full if every node has 0 or 2 children. Following are examples of full binary tree. We can also say a full binary tree is a binary tree in which all nodes except leaves have two children. 

```
              18
           /       \  
         15         30  
        /  \        /  \
      40    50    100   40

             18
           /    \   
         15     20    
        /  \       
      40    50   
    /   \
   30   50
   
              18
            /     \  
          40       30  
                   /  \
                 100   40
```

**In a Full Binary, number of leaf nodes is number of internal nodes plus 1**   

L = I + 1  Where L = Number of leaf nodes, I = Number of internal nodes 





### **Complete Binary Tree** 

A Binary Tree is complete Binary Tree if all levels are completely filled except possibly the last level and the last level has all keys as left as possible

Following are examples of Complete Binary Trees

```
               18
           /       \  
         15         30  
        /  \        /  \
      40    50    100   40


               18
           /       \  
         15         30  
        /  \        /  \
      40    50    100   40
     /  \   /
    8   7  9 
```

Practical example of Complete Binary Tree is Binary Heap. 



### **Perfect Binary Tree**

A Binary tree is Perfect Binary Tree in which all internal nodes have two children and all leaves are at same level. Following are examples of Perfect Binary Trees. 

```
              18
           /       \  
         15         30  
        /  \        /  \
      40    50    100   40


              18
           /       \  
         15         30  
```

A Perfect Binary Tree of height h (where height is number of nodes on path from root to leaf) has 2^h^ – 1 node. 

### **Balanced Binary Tree**

A binary tree is balanced if height of the tree is O(Log n) where n is number of nodes. For Example, AVL tree maintain O(Log n) height by making sure that the difference between heights of left and right subtrees is 1. Red-Black trees maintain O(Log n) height by making sure that the number of Black nodes on every root to leaf paths are same and there are no adjacent red nodes. Balanced Binary Search trees are performance wise good as they provide O(log n) time for search, insert and delete. 



### **A degenerate (or pathological) tree**

A Tree where every internal node has one child. Such trees are performance-wise same as linked list. 

```
      10
      /
    20
     \
     30
      \
      40    
```







## Enumeration of Binary Trees

A Binary Tree is labeled if every node is assigned a label and a Binary Tree is unlabeled if nodes are not assigned any label.

```
Below two are considered same unlabeled trees
    o                 o
  /   \             /   \ 
 o     o           o     o 

Below two are considered different labeled trees
    A                C
  /   \             /  \ 
 B     C           A    B 
```

**How many different Unlabeled Binary Trees can be there with n nodes?**

```
For n  = 1, there is only one tree
   o

For n  = 2, there are two trees
   o      o
  /        \  
 o          o

For n  = 3, there are five trees
    o      o           o         o      o
   /        \         /  \      /         \
  o          o       o    o     o          o
 /            \                  \        /
o              o                  o      o
```

The idea is to consider all possible pair of counts for nodes in left and right subtrees and multiply the counts for a particular pair. Finally add results of all pairs.

```
For example, let T(n) be count for n nodes.
T(0) = 1  [There is only 1 empty tree]
T(1) = 1
T(2) = 2

T(3) =  T(0)*T(2) + T(1)*T(1) + T(2)*T(0) = 1*2 + 1*1 + 2*1 = 5

T(4) =  T(0)*T(3) + T(1)*T(2) + T(2)*T(1) + T(3)*T(0)
     =  1*5 + 1*2 + 2*1 + 5*1 
     =  14 
```

The above pattern basically represents n’th Catalan Numbers. First few catalan numbers are 1 1 2 5 14 42 132 429 1430 4862,…
![](C:\Users\Administrator\Desktop\Algorithems\binaryTree\quicklatex.com-42d77828864a5ee713f16fe4d89274ce_l3.svg)
Here,
T(i-1) represents number of nodes on the left-sub-tree
T(n−i-1) represents number of nodes on the right-sub-tree

n’th Catalan Number can also be evaluated using direct formula.

```
   T(n) = (2n)! / (n+1)!n!
```

Number of Binary Search Trees (BST) with n nodes is also same as number of unlabeled trees. The reason for this is simple, in BST also we can make any key as root, If root is i’th key in sorted order, then i-1 keys can go on one side and (n-i) keys can go on other side.

**How many labeled Binary Trees can be there with n nodes?**
To count labeled trees, we can use above count for unlabeled trees. The idea is simple, every unlabeled tree with n nodes can create n! different labeled trees by assigning different permutations of labels to all nodes.

Therefore,

```
Number of Labeled Tees = (Number of unlabeled trees) * n!
                       = [(2n)! / (n+1)!n!]  × n!
```

For example for n = 3, there are 5 * 3! = 5*6 = 30 different labeled trees





## Tree Traversals

Unlike linear data structures (Array, Linked List, Queues, Stacks, etc) which have only one logical way to traverse them, trees can be traversed in different ways. Following are the generally used ways for traversing trees. 

![](C:\Users\Administrator\Desktop\Algorithems\binaryTree\tree12.gif)

Depth First Traversals:

(a) Inorder (Left, Root, Right) : 4 2 5 1 3
(b) Preorder (Root, Left, Right) : 1 2 4 5 3
(c) Postorder (Left, Right, Root) : 4 5 2 3 1

Breadth First or Level Order Traversal : 1 2 3 4 5



### **Inorder Traversal**

```
Algorithm Inorder(tree)
   1. Traverse the left subtree, i.e., call Inorder(left-subtree)
   2. Visit the root.
   3. Traverse the right subtree, i.e., call Inorder(right-subtree)
```

Uses of Inorder
In case of binary search trees (BST), Inorder traversal gives nodes in non-decreasing order. To get nodes of BST in non-increasing order, a variation of Inorder traversal where Inorder traversal s reversed can be used.
Example: Inorder traversal for the above-given figure is 4 2 5 1 3.



### **Preorder Traversal**

```
Algorithm Preorder(tree)
   1. Visit the root.
   2. Traverse the left subtree, i.e., call Preorder(left-subtree)
   3. Traverse the right subtree, i.e., call Preorder(right-subtree) 
```

Uses of Preorder
Preorder traversal is used to create a copy of the tree. Preorder traversal is also used to get prefix expression on of an expression tree. Please see this to know why prefix expressions are useful.
Example: Preorder traversal for the above given figure is 1 2 4 5 3.


### **Postorder Traversal**

```
Algorithm Postorder(tree)
   1. Traverse the left subtree, i.e., call Postorder(left-subtree)
   2. Traverse the right subtree, i.e., call Postorder(right-subtree)
   3. Visit the root.
```

Uses of Postorder
Postorder traversal is used to delete the tree. Postorder traversal is also useful to get the postfix expression of an expression tree. 

Example: Postorder traversal for the above given figure is 4 5 2 3 1.

### **Implement**

**Java Code**

```java
// Java program for different tree traversals
 
/* Class containing left and right child of current
   node and key value*/
class Node
{
    int key;
    Node left, right;
 
    public Node(int item)
    {
        key = item;
        left = right = null;
    }
}
 
class BinaryTree
{
    // Root of Binary Tree
    Node root;
 
    BinaryTree()
    {
        root = null;
    }
 
    /* Given a binary tree, print its nodes according to the
      "bottom-up" postorder traversal. */
    void printPostorder(Node node)
    {
        if (node == null)
            return;
 
        // first recur on left subtree
        printPostorder(node.left);
 
        // then recur on right subtree
        printPostorder(node.right);
 
        // now deal with the node
        System.out.print(node.key + " ");
    }
 
    /* Given a binary tree, print its nodes in inorder*/
    void printInorder(Node node)
    {
        if (node == null)
            return;
 
        /* first recur on left child */
        printInorder(node.left);
 
        /* then print the data of node */
        System.out.print(node.key + " ");
 
        /* now recur on right child */
        printInorder(node.right);
    }
 
    /* Given a binary tree, print its nodes in preorder*/
    void printPreorder(Node node)
    {
        if (node == null)
            return;
 
        /* first print data of node */
        System.out.print(node.key + " ");
 
        /* then recur on left sutree */
        printPreorder(node.left);
 
        /* now recur on right subtree */
        printPreorder(node.right);
    }
 
    // Wrappers over above recursive functions
    void printPostorder()  {     printPostorder(root);  }
    void printInorder()    {     printInorder(root);   }
    void printPreorder()   {     printPreorder(root);  }
 
    // Driver method
    public static void main(String[] args)
    {
        BinaryTree tree = new BinaryTree();
        tree.root = new Node(1);
        tree.root.left = new Node(2);
        tree.root.right = new Node(3);
        tree.root.left.left = new Node(4);
        tree.root.left.right = new Node(5);
 
        System.out.println("Preorder traversal of binary tree is ");
        tree.printPreorder();
 
        System.out.println("\nInorder traversal of binary tree is ");
        tree.printInorder();
 
        System.out.println("\nPostorder traversal of binary tree is ");
        tree.printPostorder();
    }
}
```

**Python Code**

```python
# Python program to for tree traversals
 
# A class that represents an individual node in a
# Binary Tree
class Node:
    def __init__(self,key):
        self.left = None
        self.right = None
        self.val = key
 
 
# A function to do inorder tree traversal
def printInorder(root):
 
    if root:
 
        # First recur on left child
        printInorder(root.left)
 
        # then print the data of node
        print(root.val),
 
        # now recur on right child
        printInorder(root.right)
 
 
 
# A function to do postorder tree traversal
def printPostorder(root):
 
    if root:
 
        # First recur on left child
        printPostorder(root.left)
 
        # the recur on right child
        printPostorder(root.right)
 
        # now print the data of node
        print(root.val),
 
 
# A function to do postorder tree traversal
def printPreorder(root):
 
    if root:
 
        # First print the data of node
        print(root.val),
 
        # Then recur on left child
        printPreorder(root.left)
 
        # Finally recur on right child
        printPreorder(root.right)
 
 
# Driver code
root = Node(1)
root.left      = Node(2)
root.right     = Node(3)
root.left.left  = Node(4)
root.left.right  = Node(5)
print "Preorder traversal of binary tree is"
printPreorder(root)
 
print "\nInorder traversal of binary tree is"
printInorder(root)
 
print "\nPostorder traversal of binary tree is"
printPostorder(root)
```



**One more example**

![](C:\Users\Administrator\Desktop\Algorithems\binaryTree\Tree-Traversal.png)



**Time Complexity:** O(n)

Let us see different corner cases.

Complexity function T(n) — for all problem where tree traversal is involved — can be defined as:

T(n) = T(k) + T(n – k – 1) + c

Where k is the number of nodes on one side of root and n-k-1 on the other side.

Let’s do an analysis of boundary conditions

Case 1: Skewed tree (One of the subtrees is empty and other subtree is non-empty )

k is 0 in this case.

T(n) = T(0) + T(n-1) + c
T(n) = 2T(0) + T(n-2) + 2c
T(n) = 3T(0) + T(n-3) + 3c
T(n) = 4T(0) + T(n-4) + 4c

…………………………………………
………………………………………….
T(n) = (n-1)T(0) + T(1) + (n-1)c
T(n) = nT(0) + (n)c

Value of T(0) will be some constant say d. (traversing a empty tree will take some constants time)

T(n) = n(c+d)
T(n) = Θ(n) (Theta of n)

Case 2: Both left and right subtrees have equal number of nodes.

T(n) = 2T(|_n/2_|) + c

This recursive function is in the standard form (T(n) = aT(n/b) + (-)(n) ) for master method . If we solve it by master method we get (-)(n)

**Auxiliary Space :** If we don’t consider size of stack for function calls then O(1) otherwise O(n).



## Insertion in a Binary Tree

Given a binary tree and a key, insert the key into the binary tree at first position available in level order.

[level order]: Level order traversal of a tree is breadth first traversal for the tree.

![](C:\Users\Administrator\Desktop\Algorithems\binaryTree\binary-tree-insertion.png)

The idea is to do iterative level order traversal of the given tree using queue. If we find a node whose left child is empty, we make new key as left child of the node. Else if we find a node whose right child is empty, we make new key as right child. We keep traversing the tree until we find a node whose either left or right is empty. 

**Java Code**

```java
// Java program to insert element in binary tree
import java.util.LinkedList;
import java.util.Queue;
public class GFG {
      
    /* A binary tree node has key, pointer to 
    left child and a pointer to right child */
    static class Node {
        int key;
        Node left, right;
         
        // constructor
        Node(int key){
            this.key = key;
            left = null;
            right = null;
        }
    }
    static Node root;
    static Node temp = root;
     
    /* Inorder traversal of a binary tree*/
    static void inorder(Node temp)
    {
        if (temp == null)
            return;
      
        inorder(temp.left);
        System.out.print(temp.key+" ");
        inorder(temp.right);
    }
      
    /*function to insert element in binary tree */
    static void insert(Node temp, int key)
    {
        Queue<Node> q = new LinkedList<Node>();
        q.add(temp);
      
        // Do level order traversal until we find
        // an empty place. 
        while (!q.isEmpty()) {
            temp = q.peek();
            q.remove();
      
            if (temp.left == null) {
                temp.left = new Node(key);
                break;
            } else
                q.add(temp.left);
      
            if (temp.right == null) {
                temp.right = new Node(key);
                break;
            } else
                q.add(temp.right);
        }
    }
      
    // Driver code
    public static void main(String args[])
    {
        root = new Node(10);
        root.left = new Node(11);
        root.left.left = new Node(7);
        root.right = new Node(9);
        root.right.left = new Node(15);
        root.right.right = new Node(8);
      
        System.out.print( "Inorder traversal before insertion:");
        inorder(root);
      
        int key = 12;
        insert(root, key);
      
        System.out.print("\nInorder traversal after insertion:");
        inorder(root);
    }
}
// This code is contributed by Sumit Ghosh
```



## Deletion in a Binary Tree

Given a binary tree, delete a node from it by making sure that tree shrinks from the bottom (the deleted not is replaced by bottommost and rightmost node).

**Algorithm**

**1.** Starting at root, find the deepest and rightmost node in binary tree and node which we want to delete.
**2.** Replace the deepest rightmost node’s data with node to be deleted.
**3.** Then delete the deepest rightmost node.

![](C:\Users\Administrator\Desktop\Algorithems\binaryTree\deletion-in-binary-tree.png)

## BFS vs DFS for Binary Tree

**What are BFS and DFS for Binary Tree?**

A Tree is typically traversed in two ways:

- Breadth First Traversal (Or Level Order Traversal)
- Depth First Traversals
  - Inorder Traversal (Left-Root-Right)
  - Preorder Traversal (Root-Left-Right)
  - Postorder Traversal (Left-Right-Root)

![Example Tree](C:\Users\Administrator\Desktop\Algorithems\binaryTree\tree12.gif)

```
BFS and DFSs of above Tree

Breadth First Traversal : 1 2 3 4 5

Depth First Traversals:
      Preorder Traversal : 1 2 4 5 3 
      Inorder Traversal  :  4 2 5 1 3 
      Postorder Traversal : 4 5 2 3 1
```

**Why do we care?**

There are many tree questions that can be solved using any of the above four traversals. Examples of such questions are size, maximum, minimum, print left view, etc.

**Is there any difference in terms of Time Complexity?**

All four traversals require O(n) time as they visit every node exactly once.

**Is there any difference in terms of Extra Space?**

There is difference in terms of extra space required.

1. Extra Space required for Level Order Traversal is O(w) where w is maximum width of Binary Tree. In level order traversal, queue one by one stores nodes of different level.
2. Extra Space required for Depth First Traversals is O(h) where h is maximum height of Binary Tree. In Depth First Traversals, stack (or function call stack) stores all ancestors of a node.

Maximum Width of a Binary Tree at depth (or height) h can be 2^h^ where h starts from 0. So the maximum number of nodes can be at the last level. And worst case occurs when Binary Tree is a perfect Binary Tree with numbers of nodes like 1, 3, 7, 15, …etc. In worst case, value of 2^h^ is **Ceil(n/2)**.

Height for a Balanced Binary Tree is O(Log n). Worst case occurs for skewed tree and worst case height becomes O(n).

So in worst case extra space required is O(n) for both. But worst cases occur for different types of trees.

**It is evident from above points that extra space required for Level order traversal is likely to be more when tree is more balanced and extra space for Depth First Traversal is likely to be more when tree is less balanced.**

**How to Pick One?**

1. Extra Space can be one factor (Explained above)
2. Depth First Traversals are typically recursive and recursive code requires function call overheads.
3. The most important points is, BFS starts visiting nodes from root while DFS starts visiting nodes from leaves. So if our problem is to search something that is more likely to closer to root, we would prefer BFS. And if the target node is close to a leaf, we would prefer DFS.





## Applications of tree data structure

Difficulty Level: Rookie

**Why Tree?**
Unlike Array and Linked List, which are linear data structures, tree is hierarchical (or non-linear) data structure.

1)	One reason to use trees might be because you want to store information that naturally forms a hierarchy. For example, the file system on a computer:

file system
———–

         /   <-- root
      /      \
    ...        home
          /          \
       ugrad        course
        /          /    |    \
      ...        cs101 cs112 cs113

2)	If we organize keys in form of a tree (with some ordering e.g., BST), we can search for a given key in moderate time (quicker than Linked List and slower than arrays). Self-balancing search trees like AVL and Red-Black trees guarantee an upper bound of O(Logn) for search.

3)	We can insert/delete keys in moderate time (quicker than Arrays and slower than Unordered Linked Lists). Self-balancing search trees like AVL and Red-Black trees guarantee an upper bound of O(Logn) for insertion/deletion.

4)	Like Linked Lists and unlike Arrays, Pointer implementation of trees don’t have an upper limit on number of nodes as nodes are linked using pointers.

**Following are the common uses of tree.**
1.	Manipulate hierarchical data.
2.	Make information easy to search (see tree traversal).
3.	Manipulate sorted lists of data.
4.	As a workflow for compositing digital images for visual effects.
5.	Router algorithms







