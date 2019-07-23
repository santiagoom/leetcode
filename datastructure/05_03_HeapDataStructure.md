# Heap Data Structure

## Binary Heap

### Introduction

A Binary Heap is a Binary Tree with following properties.

1) It’s a complete tree (All levels are completely filled except possibly the last level and the last level has all keys as left as possible). This property of Binary Heap makes them suitable to be stored in an array.

2) A Binary Heap is either Min Heap or Max Heap. In a Min Binary Heap, the key at root must be minimum among all keys present in Binary Heap. The same property must be recursively true for all nodes in Binary Tree. Max Binary Heap is similar to MinHeap.



**Examples of Min Heap:**

```
            10                      10
         /      \               /       \  
       20        100          15         30  
      /                      /  \        /  \
    30                     40    50    100   40
```



==**Compare the following two implementation of basic heap Heapify**==

**C++ Code**

```c++
// A recursive method to heapify a subtree with the root at given index
// This method assumes that the subtrees are already heapified
void MinHeap::MinHeapify(int i)
{
    int l = left(i);
    int r = right(i);
    int smallest = i;
    if (l < heap_size && harr[l] < harr[i])
        smallest = l;
    if (r < heap_size && harr[r] < harr[smallest])
        smallest = r;
    if (smallest != i)
    {
        swap(&harr[i], &harr[smallest]);
        MinHeapify(smallest);
    }
}
```

**Python Code**

```python
# A Python program for Prims's MST for
# adjacency list representation of graph

    # A standard function to heapify at given idx
    # This function also updates position of nodes
    # when they are swapped. Position is needed
    # for decreaseKey()
    def minHeapify(self, idx):
        smallest = idx
        left = 2 * idx + 1
        right = 2 * idx + 2

        if left < self.size and self.array[left][1] < \
                self.array[smallest][1]:
            smallest = left

        if right < self.size and self.array[right][1] < \
                self.array[smallest][1]:
            smallest = right

        # The nodes to be swapped in min heap
        # if idx is not smallest
        if smallest != idx:
            # Swap positions
            self.pos[self.array[smallest][0]] = idx
            self.pos[self.array[idx][0]] = smallest

            # Swap nodes
            self.swapMinHeapNode(smallest, idx)

            self.minHeapify(smallest)
```



### Array Representation

**How is Binary Heap represented?**

A Binary Heap is a Complete Binary Tree. A binary heap is typically represented as an array.

- The root element will be at Arr[0].
- Below table shows indexes of other nodes for the ith node, i.e., Arr[i]:

| Arr[(i-1)/2] | Returns the parent node      |
| ------------- | ------------- |
| Arr[(2*i)+1] | Returns the left child node  |
| Arr[(2*i)+2] | Returns the right child node |

The traversal method use to achieve Array representation is **Level Order**

![](C:\Users\Administrator\Desktop\Algorithems\binaryTree\part03\binaryheap.png)

### Operations on Min Heap

- **1)** getMini(): It returns the root element of Min Heap. Time Complexity of this operation is O(1).
- **2)** extractMin(): Removes the minimum element from MinHeap. Time Complexity of this Operation is O(Logn) as this operation needs to maintain the heap property (by calling heapify()) after removing root.
- **3)** **decreaseKey()**: Decreases value of key. The time complexity of this operation is O(Logn). If the decreases key value of a node is greater than the parent of the node, then we don’t need to do anything. Otherwise, we need to traverse up to fix the violated heap property.
- **4)** insert(): Inserting a new key takes O(Logn) time. We add a new key at the end of the tree. IF new key is greater than its parent, then we don’t need to do anything. Otherwise, we need to traverse up to fix the violated heap property.
- **5)** delete(): Deleting a key also takes O(Logn) time. We replace the key to be deleted with minum infinite by calling decreaseKey(). After decreaseKey(), the minus infinite value must reach root, so we call extractMin() to remove the key.



**Python Code**

```python
# A Python program to demonstrate common binary heap operations
 
# Import the heap functions from python library
from heapq import heappush, heappop, heapify 
 
# heappop - pop and return the smallest element from heap
# heappush - push the value item onto the heap, maintaining
#             heap invarient
# heapify - transform list into heap, in place, in linear time
 
# A class for Min Heap
class MinHeap:
     
    # Constructor to initialize a heap
    def __init__(self):
        self.heap = [] 
 
    def parent(self, i):
        return (i-1)/2
     
    # Inserts a new key 'k'
    def insertKey(self, k):
        heappush(self.heap, k)           
 
    # Decrease value of key at index 'i' to new_val
    # It is assumed that new_val is smaller than heap[i]
    def decreaseKey(self, i, new_val):
        self.heap[i]  = new_val 
        while(i != 0 and self.heap[self.parent(i)] > self.heap[i]):
            # Swap heap[i] with heap[parent(i)]
            self.heap[i] , self.heap[self.parent(i)] = (
            self.heap[self.parent(i)], self.heap[i])
            i = self.parent(i)
             
    # Method to remove minium element from min heap
    def extractMin(self):
        return heappop(self.heap)
 
    # This functon deletes key at index i. It first reduces
    # value to minus infinite and then calls extractMin()
    def deleteKey(self, i):
        self.decreaseKey(i, float("-inf"))
        self.extractMin()
 
    # Get the minimum element from the heap
    def getMin(self):
        return self.heap[0]
 
# Driver pgoratm to test above function
heapObj = MinHeap()
heapObj.insertKey(3)
heapObj.insertKey(2)
heapObj.deleteKey(1)
heapObj.insertKey(15)
heapObj.insertKey(5)
heapObj.insertKey(4)
heapObj.insertKey(45)
 
print heapObj.extractMin(),
print heapObj.getMin(),
heapObj.decreaseKey(2, 1)
print heapObj.getMin()
 
# This code is contributed by Nikhil Kumar Singh(nickzuck_007)

# output: 2 4 1
```

==**Note: original code lacks line 33**==



## Building a Heap

### Time Complexity of building a heap

reference: Introduction to Algorithms Thomas H. Cormen  part six

Consider the following algorithm for building a Heap of an input array A.

```
BUILD-HEAP(A) 
    heapsize := size(A); 
    for i := floor(heapsize/2) downto 1 
        do HEAPIFY(A, i); 
    end for 
END
```

A quick look over the above algorithm suggests that the running time is ![O(nlg(n))](https://www.geeksforgeeks.org/wp-content/ql-cache/quicklatex.com-ad1e0425bcffe637a86253c8fe18f69b_l3.svg), since each call to **Heapify** costs ![O(lg(n))](https://www.geeksforgeeks.org/wp-content/ql-cache/quicklatex.com-44bb8c9d3ee0919ae381f87c480882c1_l3.svg) and **Build-Heap** makes ![O(n)](https://www.geeksforgeeks.org/wp-content/ql-cache/quicklatex.com-9567d404baff2c322642ed8e476ad1af_l3.svg) such calls.

This upper bound, though correct, is not asymptotically tight.

We can derive a tighter bound by observing that the running time of **Heapify** depends on the height of the tree ‘h’ (which is equal to lg(n), where n is number of nodes) and the heights of most sub-trees are small.
The height ’h’ increases as we move upwards along the tree. Line-3 of **Build-Heap** runs a loop from the index of the last internal node (heapsize/2) with height=1, to the index of root(1) with height = lg(n). Hence, **Heapify** takes different time for each node, which is ![O(h)](https://www.geeksforgeeks.org/wp-content/ql-cache/quicklatex.com-1f07b302acaaaa1fe22132c976509862_l3.svg).

For finding the Time Complexity of building a heap, we must know the number of nodes having height h.
For this we use the fact that, A heap of size n has at most ![\left \lceil \frac{n}{2^{h+1}} \right \rceil ](https://www.geeksforgeeks.org/wp-content/ql-cache/quicklatex.com-10098723d0619faa221e59a735844f4c_l3.svg) nodes with height h.

Now to derive the time complexity, we express the total cost of **Build-Heap** as-



(1) ![ \begin{flalign*} T(n) &= \sum_{h = 0}^{lg(n)}\left \lceil \frac{n}{2^{h+1}} \right \rceil * O(h)\\ &= O(n * \sum_{h = 0}^{lg(n)}\frac{h}{2^{h}})\\ &= O(n * \sum_{h = 0}^{\infty}\frac{h}{2^{h}})\\ \end{flalign*} ](https://www.geeksforgeeks.org/wp-content/ql-cache/quicklatex.com-c68cff1daa1d0880c2e65ab4062ef3d1_l3.svg)

Step 2 uses the properties of the Big-Oh notation to ignore the ceiling function and the constant 2(![2^{h+1} = 2.2^h](https://www.geeksforgeeks.org/wp-content/ql-cache/quicklatex.com-1f0b8459c2a2d852183d443eb4f78fbb_l3.svg)). Similarly in Step three, the upper limit of the summation can be increased to infinity since we are using Big-Oh notation.

Sum of infinite G.P. (x < 1)

(2) ![ \begin{align*} \sum_{n = 0}^{\infty}{x}^{n} = \frac{1}{1-x} \end{align*} ](https://www.geeksforgeeks.org/wp-content/ql-cache/quicklatex.com-185c07cec4efa614ebfb52b4434fa6b5_l3.svg)

On differentiating both sides and multiplying by x, we get

(3) ![ \begin{align*} \sum_{n = 0}^{\infty}n{x}^{n} = \frac{x}{(1-x)^{2}} \end{align*} ](https://www.geeksforgeeks.org/wp-content/ql-cache/quicklatex.com-f533b28af7646ab9d7894fe78e24e68a_l3.svg)

Putting the result obtained in (3) back in our derivation (1), we get

(4) ![ \begin{flalign*} &= O(n * \frac{\frac{1}{2}}{(1 - \frac{1}{2})^2})\\ &= O(n * 2)\\ &= O(n)\\ \end{flalign*} ](https://www.geeksforgeeks.org/wp-content/ql-cache/quicklatex.com-1f5a465fbfa61f71a5b89cc630df2817_l3.svg)

Hence Proved that the Time complexity for Building a Binary Heap is ![O(n)](https://www.geeksforgeeks.org/wp-content/ql-cache/quicklatex.com-9567d404baff2c322642ed8e476ad1af_l3.svg).



## **Applications of Heaps**

Applications of Heaps:

1) Heap Sort: Heap Sort uses Binary Heap to sort an array in O(nLogn) time.

2) Priority Queue: Priority queues can be efficiently implemented using Binary Heap because it supports insert(), delete() and extractmax(), decreaseKey() operations in O(logn) time. Binomoial Heap and Fibonacci Heap are variations of Binary Heap. These variations perform union also efficiently.

3) Graph Algorithms: The priority queues are especially used in Graph Algorithms like Dijkstra’s Shortest Path and Prim’s Minimum Spanning Tree.

4) Many problems can be efficiently solved using Heaps. See following for example.
a) K’th Largest Element in an array.
b) Sort an almost sorted array/
c) Merge K Sorted Arrays.