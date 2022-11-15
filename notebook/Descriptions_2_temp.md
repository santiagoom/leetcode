101_SymmetricTree
```
class Solution {
public boolean isSymmetric(TreeNode root) {
    return isMirror(root, root);
}

public boolean isMirror(TreeNode t1, TreeNode t2) {
    if (t1 == null && t2 == null) return true;
    if (t1 == null || t2 == null) return false;
    return (t1.val == t2.val)
        && isMirror(t1.right, t2.left)
        && isMirror(t1.left, t2.right);
}
}
```
```
public boolean isSymmetric(TreeNode root) {
    Queue<TreeNode> q = new LinkedList<>();
    q.add(root);
    q.add(root);
    while (!q.isEmpty()) {
        TreeNode t1 = q.poll();
        TreeNode t2 = q.poll();
        if (t1 == null && t2 == null) continue;
        if (t1 == null || t2 == null) return false;
        if (t1.val != t2.val) return false;
        q.add(t1.left);
        q.add(t2.right);
        q.add(t1.right);
        q.add(t2.left);
    }
    return true;
}
```
```
```
102_BinaryTreeLevelOrderTraversal
```
class Solution:
    def levelOrder(self, root):
        """
        :type root: TreeNode
        :rtype: List[List[int]]
        """
        levels = []
        if not root:
            return levels
        
        def helper(node, level):
            # start the current level
            if len(levels) == level:
                levels.append([])

            # append the current node value
            levels[level].append(node.val)

            # process child nodes for the next level
            if node.left:
                helper(node.left, level + 1)
            if node.right:
                helper(node.right, level + 1)
            
        helper(root, 0)
        return levels
```
```
from collections import deque
class Solution:
    def levelOrder(self, root):
        """
        :type root: TreeNode
        :rtype: List[List[int]]
        """
        levels = []
        if not root:
            return levels
        
        level = 0
        queue = deque([root,])
        while queue:
            # start the current level
            levels.append([])
            # number of elements in the current level 
            level_length = len(queue)
            
            for i in range(level_length):
                node = queue.popleft()
                # fulfill the current level
                levels[level].append(node.val)
                
                # add child nodes of the current level
                # in the queue for the next level
                if node.left:
                    queue.append(node.left)
                if node.right:
                    queue.append(node.right)
            
            # go to next level
            level += 1
        
        return levels
```
```
```
103_BinaryTreeZigzagLevelOrderTraversal
```
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None
from collections import deque

class Solution:
    def zigzagLevelOrder(self, root):
        """
        :type root: TreeNode
        :rtype: List[List[int]]
        """
        ret = []
        level_list = deque()
        if root is None:
            return []
        # start with the level 0 with a delimiter
        node_queue = deque([root, None])
        is_order_left = True

        while len(node_queue) > 0:
            curr_node = node_queue.popleft()

            if curr_node:
                if is_order_left:
                    level_list.append(curr_node.val)
                else:
                    level_list.appendleft(curr_node.val)

                if curr_node.left:
                    node_queue.append(curr_node.left)
                if curr_node.right:
                    node_queue.append(curr_node.right)
            else:
                # we finish one level
                ret.append(level_list)
                # add a delimiter to mark the level
                if len(node_queue) > 0:
                    node_queue.append(None)

                # prepare for the next level
                level_list = deque()
                is_order_left = not is_order_left

        return ret
```
```
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None
from collections import deque

class Solution:
    def zigzagLevelOrder(self, root):
        """
        :type root: TreeNode
        :rtype: List[List[int]]
        """
        if root is None:
            return []

        results = []
        def dfs(node, level):
            if level >= len(results):
                results.append(deque([node.val]))
            else:
                if level % 2 == 0:
                    results[level].append(node.val)
                else:
                    results[level].appendleft(node.val)

            for next_node in [node.left, node.right]:
                if next_node is not None:
                    dfs(next_node, level+1)

        # normal level order traversal with DFS
        dfs(root, 0)

        return results
```
```
```
104_MaximumDepthofBinaryTree
```
class Solution {
  public:
    int maxDepth(TreeNode *root) {
      if (root == NULL) {
        return 0;
      }
      return max(1 + maxDepth(root -> left), 1 + maxDepth(root -> right));
    }
};
```
```
class Solution {

  private:
    // The queue that contains the next nodes to visit, 
    //   along with the level/depth that each node is located.
    queue<pair<TreeNode*, int>> next_items;
    int max_depth = 0;
    
    /**
     * A tail recursion function to calculate the max depth
     *   of the binary tree.
     */
    int next_maxDepth() {
    
      if (next_items.size() == 0) {
        return max_depth;
      }
        
      auto next_item = next_items.front();
      next_items.pop();

      auto next_node = next_item.first;
      auto next_level = next_item.second + 1;
      
      max_depth = max(max_depth, next_level);

      // Add the nodes to visit in the following recursive calls.
      if (next_node->left != NULL) {
        next_items.push(make_pair(next_node->left, next_level));
      }
      if (next_node->right != NULL) {
        next_items.push(make_pair(next_node->right, next_level));
      }
    
      // The last action should be the ONLY recursive call
      //   in the tail-recursion function.
      return next_maxDepth();
    }
    
  public:
    int maxDepth(TreeNode* root) {
      if (root == NULL) return 0;
        
      // clear the previous queue.
      std::queue<pair<TreeNode*, int>> empty;
      std::swap(next_items, empty);
      max_depth = 0;
        
      // push the root node into the queue to kick off the next visit.
      next_items.push(make_pair(root, 0));
        
      return next_maxDepth();
    }
};
```
```
class Solution {
  public:
  int maxDepth(TreeNode* root) {
    if (root == NULL) {
      return 0;
    }

    vector<pair<int, TreeNode*>> my_stack;
    my_stack.push_back(pair<int, TreeNode*>(1, root));
    int max_depth = 0;
    while (!my_stack.empty()) {
      pair<int, TreeNode*> my_pair = my_stack.back();
      int c_depth = get<0>(my_pair);
      TreeNode* c_node = get<1>(my_pair);
      max_depth = max(max_depth, c_depth);
      my_stack.pop_back();
      if (c_node->left != NULL) {
        my_stack.push_back(pair<int, TreeNode*>(c_depth + 1, c_node->left));
      }
      if (c_node->right != NULL) {
        my_stack.push_back(pair<int, TreeNode*>(c_depth + 1, c_node->right));
      }
    }
    return max_depth;
  }
};
```
105_ConstructBinaryTreefromPreorderandInorderTraversal
```
class Solution:
    def buildTree(self, preorder: List[int], inorder: List[int]) -> TreeNode:

        def array_to_tree(left, right):
            nonlocal preorder_index
            # if there are no elements to construct the tree
            if left > right: return None

            # select the preorder_index element as the root and increment it
            root_value = preorder[preorder_index]
            root = TreeNode(root_value)


            preorder_index += 1

            # build left and right subtree
            # excluding inorder_index_map[root_value] element because it's the root
            root.left = array_to_tree(left, inorder_index_map[root_value] - 1)
            root.right = array_to_tree(inorder_index_map[root_value] + 1, right)

            return root

        preorder_index = 0

        # build a hashmap to store value -> its index relations
        inorder_index_map = {}
        for index, value in enumerate(inorder):
            inorder_index_map[value] = index

        return array_to_tree(0, len(preorder) - 1)
```
```
```
```
```
106_ConstructBinaryTreefromInorderandPostorderTraversal
```
class Solution:
    def buildTree(self, inorder: List[int], postorder: List[int]) -> TreeNode:
        def helper(in_left, in_right):
            # if there is no elements to construct subtrees
            if in_left > in_right:
                return None
            
            # pick up the last element as a root
            val = postorder.pop()
            root = TreeNode(val)

            # root splits inorder list
            # into left and right subtrees
            index = idx_map[val]
 
            # build right subtree
            root.right = helper(index + 1, in_right)
            # build left subtree
            root.left = helper(in_left, index - 1)
            return root
        
        # build a hashmap value -> its index
        idx_map = {val:idx for idx, val in enumerate(inorder)} 
        return helper(0, len(inorder) - 1)
```
```
```
```
```
107_BinaryTreeLevelOrderTraversalII
```
class Solution:
    def levelOrderBottom(self, root: TreeNode) -> List[List[int]]:
        levels = []
        if not root:
            return levels
        
        def helper(node, level):
            # start the current level
            if len(levels) == level:
                levels.append([])

            # append the current node value
            levels[level].append(node.val)

            # process child nodes for the next level
            if node.left:
                helper(node.left, level + 1)
            if node.right:
                helper(node.right, level + 1)
            
        helper(root, 0)
        return levels[::-1]
```
```
class Solution:
    def levelOrderBottom(self, root: TreeNode) -> List[List[int]]:
        levels = []
        next_level = deque([root])
        
        while root and next_level:
            curr_level = next_level
            next_level = deque()
            levels.append([])
            
            for node in curr_level:
                # append the current node value
                levels[-1].append(node.val)
                # process child nodes for the next level
                if node.left:
                    next_level.append(node.left)
                if node.right:
                    next_level.append(node.right)
                    
        return levels[::-1]
```
```
```
108_ConvertSortedArraytoBinarySearchTree
```
class Solution:
    def sortedArrayToBST(self, nums: List[int]) -> TreeNode:        
        def helper(left, right):
            if left > right:
                return None

            # always choose left middle node as a root
            p = (left + right) // 2

            # preorder traversal: node -> left -> right
            root = TreeNode(nums[p])
            root.left = helper(left, p - 1)
            root.right = helper(p + 1, right)
            return root
        
        return helper(0, len(nums) - 1)
```
```
class Solution:
    def sortedArrayToBST(self, nums: List[int]) -> TreeNode:        
        def helper(left, right):
            if left > right:
                return None
            
            # always choose right middle node as a root
            p = (left + right) // 2 
            if (left + right) % 2:
                p += 1 

            # preorder traversal: node -> left -> right
            root = TreeNode(nums[p])
            root.left = helper(left, p - 1)
            root.right = helper(p + 1, right)
            return root
        
        return helper(0, len(nums) - 1)
```
```
from random import randint
class Solution:
    def sortedArrayToBST(self, nums: List[int]) -> TreeNode:        
        def helper(left, right):
            if left > right:
                return None
            
            # choose random middle node as a root
            p = (left + right) // 2 
            if (left + right) % 2:
                p += randint(0, 1) 

            # preorder traversal: node -> left -> right
            root = TreeNode(nums[p])
            root.left = helper(left, p - 1)
            root.right = helper(p + 1, right)
            return root
        
        return helper(0, len(nums) - 1)
```
109_ConvertSortedListtoBinarySearchTree
```
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:

    def findMiddle(self, head):

        # The pointer used to disconnect the left half from the mid node.
        prevPtr = None
        slowPtr = head
        fastPtr = head

        # Iterate until fastPr doesn't reach the end of the linked list.
        while fastPtr and fastPtr.next:
            prevPtr = slowPtr
            slowPtr = slowPtr.next
            fastPtr = fastPtr.next.next

        # Handling the case when slowPtr was equal to head.
        if prevPtr:
            prevPtr.next = None

        return slowPtr


    def sortedListToBST(self, head):
        """
        :type head: ListNode
        :rtype: TreeNode
        """

        # If the head doesn't exist, then the linked list is empty
        if not head:
            return None

        # Find the middle element for the list.
        mid = self.findMiddle(head)

        # The mid becomes the root of the BST.
        node = TreeNode(mid.val)

        # Base case when there is just one element in the linked list
        if head == mid:
            return node

        # Recursively form balanced BSTs using the left and right halves of the original list.
        node.left = self.sortedListToBST(head)
        node.right = self.sortedListToBST(mid.next)
        return node
```
```
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:

    # Convert the given linked list to an array
    def mapListToValues(self, head):
        vals = []
        while head:
            vals.append(head.val)
            head = head.next
        return vals    

    def sortedListToBST(self, head):
        """
        :type head: ListNode
        :rtype: TreeNode
        """

        # Form an array out of the given linked list and then
        # use the array to form the BST.
        values = self.mapListToValues(head)

        # l and r represent the start and end of the given array
        def convertListToBST(l, r):

            # Invalid case
            if l > r:
                return None

            # Middle element forms the root.
            mid = (l + r) // 2
            node = TreeNode(values[mid])

            # Base case for when there is only one element left in the array
            if l == r:
                return node

            # Recursively form BST on the two halves
            node.left = convertListToBST(l, mid - 1)
            node.right = convertListToBST(mid + 1, r)
            return node
        return convertListToBST(0, len(values) - 1)
```
```
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:

    def findSize(self, head):
        ptr = head
        c = 0
        while ptr:
            ptr = ptr.next
            c += 1
        return c


    def sortedListToBST(self, head):
        """
        :type head: ListNode
        :rtype: TreeNode
        """

        # Get the size of the linked list first
        size = self.findSize(head)

        # Recursively form a BST out of linked list from l --> r
        def convert(l, r):
            nonlocal head

            # Invalid case
            if l > r:
                return None

            mid = (l + r) // 2

            # First step of simulated inorder traversal. Recursively form
            # the left half
            left = convert(l, mid - 1)

            # Once left half is traversed, process the current node
            node = TreeNode(head.val)   
            node.left = left

            # Maintain the invariance mentioned in the algorithm
            head = head.next

            # Recurse on the right hand side and form BST out of them
            node.right = convert(mid + 1, r)
            return node
        return convert(0, size - 1)
```
110_BalancedBinaryTree
```
class Solution {
private:
  // Recursively obtain the height of a tree. An empty tree has -1 height
  int height(TreeNode* root) { 
    // An empty tree has height -1
    if (root == NULL) {
      return -1;
    }
    return 1 + max(height(root->left), height(root->right));
  }
public:
  bool isBalanced(TreeNode* root) {
    // An empty tree satisfies the definition of a balanced tree
    if (root == NULL) {
      return true;
    }

    // Check if subtrees have height within 1. If they do, check if the
    // subtrees are balanced
    return abs(height(root->left) - height(root->right)) < 2 &&
      isBalanced(root->left) &&
      isBalanced(root->right);
  }
};
```
```
class Solution {
private:
  // Return whether or not the tree at root is balanced while also storing
  // the tree's height in a reference variable. 
  bool isBalancedTreeHelper(TreeNode* root, int& height) {
    // An empty tree is balanced and has height = -1
    if (root == NULL) {
      height = -1;
      return true;
    }

    // Check subtrees to see if they are balanced. If they are, check if the 
    // current node is also balanced using the heights obtained from the 
    // recursive calls.
    int left, right;
    if (isBalancedTreeHelper(root->left, left)  &&
        isBalancedTreeHelper(root->right, right) &&
        abs(left - right) < 2) {
      // Store the current tree's height
      height = max(left, right) + 1;
      return true;
    }
    return false;
  }
public:
  bool isBalanced(TreeNode* root) {
    int height;
    return isBalancedTreeHelper(root, height);
  }
};
```
```
```
111_MinimumDepthofBinaryTree
```
class Solution:
    def minDepth(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """
        if not root: 
            return 0 
        
        children = [root.left, root.right]
        # if we're at leaf node
        if not any(children):
            return 1
        
        min_depth = float('inf')
        for c in children:
            if c:
                min_depth = min(self.minDepth(c), min_depth)
        return min_depth + 1 
```
```
class Solution:
    def minDepth(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """
        if not root:
            return 0
        else:
            stack, min_depth = [(1, root),], float('inf')
        
        while stack:
            depth, root = stack.pop()
            children = [root.left, root.right]
            if not any(children):
                min_depth = min(depth, min_depth)
            for c in children:
                if c:
                    stack.append((depth + 1, c))
        
        return min_depth 
```
```
from collections import deque
class Solution:
    def minDepth(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """
        if not root:
            return 0
        else:
            node_deque = deque([(1, root),])
        
        while node_deque:
            depth, root = node_deque.popleft()
            children = [root.left, root.right]
            if not any(children):
                return depth
            for c in children:
                if c:
                    node_deque.append((depth + 1, c))
```
112_PathSum
```
class Solution:
    def hasPathSum(self, root, sum):
        """
        :type root: TreeNode
        :type sum: int
        :rtype: bool
        """
        if not root:
            return False

        sum -= root.val
        if not root.left and not root.right:  # if reach a leaf
            return sum == 0
        return self.hasPathSum(root.left, sum) or self.hasPathSum(root.right, sum)
```
```
class Solution:
    def hasPathSum(self, root, sum):
        """
        :type root: TreeNode
        :type sum: int
        :rtype: bool
        """
        if not root:
            return False

        de = [(root, sum - root.val), ]
        while de:
            node, curr_sum = de.pop()
            if not node.left and not node.right and curr_sum == 0:  
                return True
            if node.right:
                de.append((node.right, curr_sum - node.right.val))
            if node.left:
                de.append((node.left, curr_sum - node.left.val))
        return False
```
```
```
113_PathSumII
```
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    
    def recurseTree(self, node, remainingSum, pathNodes, pathsList):
        
        if not node:
            return 
        
        # Add the current node to the path's list
        pathNodes.append(node.val)
        
        # Check if the current node is a leaf and also, if it
        # equals our remaining sum. If it does, we add the path to
        # our list of paths
        if remainingSum == node.val and not node.left and not node.right:
            pathsList.append(list(pathNodes))
        else:    
            # Else, we will recurse on the left and the right children
            self.recurseTree(node.left, remainingSum - node.val, pathNodes, pathsList)
            self.recurseTree(node.right, remainingSum - node.val, pathNodes, pathsList)
            
        # We need to pop the node once we are done processing ALL of it's
        # subtrees.
        pathNodes.pop()    
    
    def pathSum(self, root: TreeNode, sum: int) -> List[List[int]]:
        pathsList = []
        self.recurseTree(root, sum, [], pathsList)
        return pathsList
```
```
```
```
```
114_FlattenBinaryTreetoLinkedList
```
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    
    def flattenTree(self, node):
        
        # Handle the null scenario
        if not node:
            return None
        
        # For a leaf node, we simply return the
        # node as is.
        if not node.left and not node.right:
            return node
        
        # Recursively flatten the left subtree
        leftTail = self.flattenTree(node.left)
        
        # Recursively flatten the right subtree
        rightTail = self.flattenTree(node.right)
        
        # If there was a left subtree, we shuffle the connections
        # around so that there is nothing on the left side
        # anymore.
        if leftTail:
            leftTail.right = node.right
            node.right = node.left
            node.left = None
        
        # We need to return the "rightmost" node after we are
        # done wiring the new connections. 
        return rightTail if rightTail else leftTail
    
    def flatten(self, root: TreeNode) -> None:
        """
        Do not return anything, modify root in-place instead.
        """
        
        self.flattenTree(root)
```
```
import collections
class Solution:
    
    def flatten(self, root: TreeNode) -> None:
        """
        Do not return anything, modify root in-place instead.
        """
        
        # Handle the null scenario
        if not root:
            return None
        
        START, END = 1, 2
        
        tailNode = None
        stack = collections.deque([(root, START)])
        
        while stack:
            
            currentNode, recursionState = stack.pop()
            
            # We reached a leaf node. Record this as a tail
            # node and move on.
            if not currentNode.left and not currentNode.right:
                tailNode = currentNode
                continue
            
            # If the node is in the START state, it means we still
            # haven't processed it's left child yet.
            if recursionState == START:
                
                # If the current node has a left child, we add it
                # to the stack AFTER adding the current node again
                # to the stack with the END recursion state. 
                if currentNode.left:          
                    stack.append((currentNode, END))
                    stack.append((currentNode.left, START))
                elif currentNode.right:
                    
                    # In case the current node didn't have a left child
                    # we will add it's right child
                    stack.append((currentNode.right, START))
            else:
                # If the current node is in the END recursion state,
                # that means we did process one of it's children. Left
                # if it existed, else right.
                rightNode = currentNode.right
                
                # If there was a left child, there must have been a leaf
                # node and so, we would have set the tailNode
                if tailNode:
                    
                    # Establish the proper connections. 
                    tailNode.right = currentNode.right
                    currentNode.right = currentNode.left
                    currentNode.left = None
                    rightNode = tailNode.right
                
                if rightNode:
                    stack.append((rightNode, START))                
```
```
class Solution:
    
    def flatten(self, root: TreeNode) -> None:
        """
        Do not return anything, modify root in-place instead.
        """
        
        # Handle the null scenario
        if not root:
            return None
        
        node = root
        while node:
            
            # If the node has a left child
            if node.left:
                
                # Find the rightmost node
                rightmost = node.left
                while rightmost.right:
                    rightmost = rightmost.right
                
                # rewire the connections
                rightmost.right = node.right
                node.right = node.left
                node.left = None
            
            # move on to the right side of the tree
            node = node.right
```
115_DistinctSubsequences
```
class Solution:
    def numDistinct(self, s: str, t: str) -> int:
        
        # Dictionary for memoization
        memo = {}
        
        def uniqueSubsequences(i, j):
            
            M, N = len(s), len(t)
            
            # Base case
            if i == M or j == N or M - i < N - j:
                return int(j == len(t))
            
            # Check if the result is already cached
            if (i, j) in memo:
                return memo[i,j]
            
            # Always make this recursive call
            ans = uniqueSubsequences(i + 1, j)
            
            # If the characters match, make the other
            # one and add the result to "ans"
            if s[i] == t[j]:
                ans += uniqueSubsequences(i + 1, j + 1)
            
            # Cache the answer and return
            memo[i, j] = ans
            return ans                
        
        return uniqueSubsequences(0, 0)
```
```
class Solution:
    def numDistinct(self, s: str, t: str) -> int:
        
        M, N = len(s), len(t)
        
        # Dynamic Programming table
        dp = [[0 for i in range(N + 1)] for j in range(M + 1)] 
        
        # Base case initialization
        for j in range(N + 1):
            dp[M][j] = 0
        
        # Base case initialization
        for i in range(M + 1):
            dp[i][N] = 1
        
        # Iterate over the strings in reverse so as to
        # satisfy the way we've modeled our recursive solution
        for i in range(M - 1, -1, -1):
            for j in range(N - 1, -1, -1):
          
                # Remember, we always need this result
                dp[i][j] = dp[i + 1][j]

                # If the characters match, we add the
                # result of the next recursion call (in this
                # case, the value of a cell in the dp table
                if s[i] == t[j]:
                    dp[i][j] += dp[i + 1][j + 1]
            
        return dp[0][0]
```
```
class Solution:
    def numDistinct(self, s: str, t: str) -> int:
        
        M, N = len(s), len(t)
        
        # Dynamic Programming table
        dp = [0 for j in range(N)] 
        
        # Iterate over the strings in reverse so as to
        # satisfy the way we've modeled our recursive solution
        for i in range(M - 1, -1, -1):
            
            # At each step we start with the last value in
            # the row which is always 1. Notice how we are
            # starting the loop from N - 1 instead of N like
            # in the previous solution.
            prev = 1
            
            for j in range(N - 1, -1, -1):
          
                # Record the current value in this cell so that
                # we can use it to calculate the value of dp[j - 1]
                old_dpj = dp[j]
        
                # If the characters match, we add the
                # result of the next recursion call (in this
                # case, the value of a cell in the dp table
                if s[i] == t[j]:
                    dp[j] += prev
                
                # Update the prev variable
                prev = old_dpj    
        
        return dp[0]
```
116_PopulatingNextRightPointersinEachNode

```
import collections 

class Solution:
    def connect(self, root: 'Node') -> 'Node':
        
        if not root:
            return root
        
        # Initialize a queue data structure which contains
        # just the root of the tree
        Q = collections.deque([root])
        
        # Outer while loop which iterates over 
        # each level
        while Q:
            
            # Note the size of the queue
            size = len(Q)
            
            # Iterate over all the nodes on the current level
            for i in range(size):
                
                # Pop a node from the front of the queue
                node = Q.popleft()
                
                # This check is important. We don't want to
                # establish any wrong connections. The queue will
                # contain nodes from 2 levels at most at any
                # point in time. This check ensures we only 
                # don't establish next pointers beyond the end
                # of a level
                if i < size - 1:
                    node.next = Q[0]
                
                # Add the children, if any, to the back of
                # the queue
                if node.left:
                    Q.append(node.left)
                if node.right:
                    Q.append(node.right)
        
        # Since the tree has now been modified, return the root node
        return root
```
```
class Solution:
    def connect(self, root: 'Node') -> 'Node':
        
        if not root:
            return root
        
        # Start with the root node. There are no next pointers
        # that need to be set up on the first level
        leftmost = root
        
        # Once we reach the final level, we are done
        while leftmost.left:
            
            # Iterate the "linked list" starting from the head
            # node and using the next pointers, establish the 
            # corresponding links for the next level
            head = leftmost
            while head:
                
                # CONNECTION 1
                head.left.next = head.right
                
                # CONNECTION 2
                if head.next:
                    head.right.next = head.next.left
                
                # Progress along the list (nodes on the current level)
                head = head.next
            
            # Move onto the next level
            leftmost = leftmost.left
        
        return root 
```
```
```
117_PopulatingNextRightPointersinEachNodeII
```
class Solution:
    def connect(self, root: Optional['Node']) -> Optional['Node']:
        
        if not root:
            return root
        
        # Initialize a queue data structure which contains
        # just the root of the tree
        Q = collections.deque([root])
        
        # Outer while loop which iterates over 
        # each level
        while Q:
            
            # Note the size of the queue
            size = len(Q)
            
            # Iterate over all the nodes on the current level
            for i in range(size):
                
                # Pop a node from the front of the queue
                node = Q.popleft()
                
                # This check is important. We don't want to
                # establish any wrong connections. The queue will
                # contain nodes from 2 levels at most at any
                # point in time. This check ensures we only 
                # don't establish next pointers beyond the end
                # of a level
                if i < size - 1:
                    node.next = Q[0]
                
                # Add the children, if any, to the back of
                # the queue
                if node.left:
                    Q.append(node.left)
                if node.right:
                    Q.append(node.right)
        
        # Since the tree has now been modified, return the root node
        return root
```
```
class Solution:
    
    def processChild(self, childNode, prev, leftmost):
        if childNode:
            
            # If the "prev" pointer is alread set i.e. if we
            # already found atleast one node on the next level,
            # setup its next pointer
            if prev:
                prev.next = childNode
            else:    
                # Else it means this child node is the first node
                # we have encountered on the next level, so, we
                # set the leftmost pointer
                leftmost = childNode
            prev = childNode 
        return prev, leftmost
    
    def connect(self, root: Optional['Node']) -> Optional['Node']:
        
        if not root:
            return root
        
        # The root node is the only node on the first level
        # and hence its the leftmost node for that level
        leftmost = root
        
        # We have no idea about the structure of the tree,
        # so, we keep going until we do find the last level.
        # The nodes on the last level won't have any children
        while leftmost:
            
            # "prev" tracks the latest node on the "next" level
            # while "curr" tracks the latest node on the current
            # level.
            prev, curr = None, leftmost
            
            # We reset this so that we can re-assign it to the leftmost
            # node of the next level. Also, if there isn't one, this
            # would help break us out of the outermost loop.
            leftmost = None
            
            # Iterate on the nodes in the current level using
            # the next pointers already established.
            while curr:
                
                # Process both the children and update the prev
                # and leftmost pointers as necessary.
                prev, leftmost = self.processChild(curr.left, prev, leftmost)
                prev, leftmost = self.processChild(curr.right, prev, leftmost)
                
                # Move onto the next node.
                curr = curr.next
                
        return root 
```
```
```
118_Pascal'sTriangle
```
class Solution:
    def generate(self, num_rows: int) -> List[List[int]]:
        triangle = []

        for row_num in range(num_rows):
            # The first and last row elements are always 1.
            row = [None for _ in range(row_num + 1)]
            row[0], row[-1] = 1, 1

            # Each triangle element is equal to the sum of the elements
            # above-and-to-the-left and above-and-to-the-right.
            for j in range(1, len(row) - 1):
                row[j] = triangle[row_num - 1][j - 1] + triangle[row_num - 1][j]

            triangle.append(row)

        return triangle
```
```
```
```
```
119_Pascal'sTriangleII
```
class Solution {
 public:
  int getNum(int row, int col) {
    if (row == 0 || col == 0 || row == col)
      return 1;

    return getNum(row - 1, col - 1) + getNum(row - 1, col);
  }

  vector<int> getRow(int rowIndex) {
    vector<int> ans;

    for (int i = 0; i <= rowIndex; i++)
      ans.push_back(getNum(rowIndex, i));

    return ans;
  }
};
```
```
class Solution {
  unordered_map<size_t, int> cache;

  // use a better hashing function like `boost::hash_combine` in the real world.
  int key(int i, int j) const {
    size_t hash_i = hash<int>{}(i), hash_j = hash<int>{}(j);
    int hashed = (int)(hash_i ^ (hash_i >> 32));
    return (hashed << 5) - 1 + (int)(hash_j ^ (hash_j >> 32));
  }

 public:
  int getNum(int row, int col) {
    auto rowCol = key(row, col);

    if (cache.count(rowCol) > 0)
      return cache[rowCol];

    if (row == 0 || col == 0 || row == col)
      return (cache[rowCol] = 1);

    return (cache[rowCol] = getNum(row - 1, col - 1) + getNum(row - 1, col));
  }

  vector<int> getRow(int rowIndex) {
    vector<int> ans;

    for (int i = 0; i <= rowIndex; i++)
      ans.push_back(getNum(rowIndex, i));

    return ans;
  }
};
```
```
class Solution {
 public:
  vector<int> getRow(int rowIndex) {
    vector<int> curr, prev = {1};

    for (int i = 1; i <= rowIndex; i++) {
      curr.assign(i + 1, 1);

      for (int j = 1; j < i; j++)
        curr[j] = prev[j - 1] + prev[j];

      prev = move(curr);  // This is O(1)
    }

    return prev;
  }
};
```
```
class Solution {
 public:
  vector<int> getRow(int rowIndex) {
    vector<int> ans = vector<int>(rowIndex + 1, 1);

    for (int i = 1; i < rowIndex; i++)
      for (int j = i; j > 0; j--)
        ans[j] += ans[j - 1];  // ans[j] = ans[j-1] + ans[j]

    return ans;
  }
};
```

```

class Solution {
 public:
  vector<int> getRow(int n) {
    vector<int> ans = {1};

    for (int k = 1; k <= n; k++)
      ans.push_back((int)((ans.back() * (long long)(n - k + 1)) / k));

    return ans;
  }
};
```



120_Triangle

```
class Solution:
    def minimumTotal(self, triangle: List[List[int]]) -> int:
        for row in range(1, len(triangle)):
            for col in range(row + 1):
                smallest_above = math.inf
                if col > 0:
                    smallest_above = triangle[row - 1][col - 1]
                if col < row:
                    smallest_above = min(smallest_above, triangle[row - 1][col])
                triangle[row][col] += smallest_above
        return min(triangle[-1])
```
```
class Solution:
    def minimumTotal(self, triangle: List[List[int]]) -> int:
        prev_row = triangle[0]
        for row in range(1, len(triangle)):
            curr_row = []
            for col in range(row + 1):
                smallest_above = math.inf
                if col > 0:
                    smallest_above = prev_row[col - 1]
                if col < row:
                    smallest_above = min(smallest_above, prev_row[col])
                curr_row.append(triangle[row][col] + smallest_above)
            prev_row = curr_row
        return min(prev_row)
```
```
class Solution:
    def minimumTotal(self, triangle: List[List[int]]) -> int:
        below_row = triangle[-1] 
        n = len(triangle)
        for row in reversed(range(n - 1)):     
            curr_row = []
            for col in range(row + 1):
                smallest_below = min(below_row[col], below_row[col + 1])
                curr_row.append(triangle[row][col] + smallest_below)
            below_row = curr_row
        return below_row[0]
```
```
class Solution:
    def minimumTotal(self, triangle: List[List[int]]) -> int:
        below_row = triangle[-1] 
        n = len(triangle)
        for row in reversed(range(n - 1)):       
            curr_row = []
            for col in range(row + 1):
                smallest_below = min(below_row[col], below_row[col + 1])
                curr_row.append(triangle[row][col] + smallest_below)
            below_row = curr_row
        return below_row[0]
```

```
class Solution:
    def minimumTotal(self, triangle: List[List[int]]) -> int:
        @lru_cache(maxsize=None)
        def min_path(row, col):
            path = triangle[row][col]
            if row < len(triangle) - 1:
                path += min(min_path(row + 1, col), min_path(row + 1, col + 1))
            return path
        return min_path(0, 0)
```



121_BestTimetoBuyandSellStock

```
class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        max_profit = 0
        for i in range(len(prices) - 1):
            for j in range(i + 1, len(prices)):
                profit = prices[j] - prices[i]
                if profit > max_profit:
                    max_profit = profit
                    
        return max_profit
```
```
class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        min_price = float('inf')
        max_profit = 0
        for i in range(len(prices)):
            if prices[i] < min_price:
                min_price = prices[i]
            elif prices[i] - min_price > max_profit:
                max_profit = prices[i] - min_price
                
        return max_profit
```
```
```
122_BestTimetoBuyandSellStockII
```
class Solution {
    public int maxProfit(int[] prices) {
        return calculate(prices, 0);
    }

    public int calculate(int prices[], int s) {
        if (s >= prices.length)
            return 0;
        int max = 0;
        for (int start = s; start < prices.length; start++) {
            int maxprofit = 0;
            for (int i = start + 1; i < prices.length; i++) {
                if (prices[start] < prices[i]) {
                    int profit = calculate(prices, i + 1) + prices[i] - prices[start];
                    if (profit > maxprofit)
                        maxprofit = profit;
                }
            }
            if (maxprofit > max)
                max = maxprofit;
        }
        return max;
    }
}
```
```
class Solution {
    public int maxProfit(int[] prices) {
        int i = 0;
        int valley = prices[0];
        int peak = prices[0];
        int maxprofit = 0;
        while (i < prices.length - 1) {
            while (i < prices.length - 1 && prices[i] >= prices[i + 1])
                i++;
            valley = prices[i];
            while (i < prices.length - 1 && prices[i] <= prices[i + 1])
                i++;
            peak = prices[i];
            maxprofit += peak - valley;
        }
        return maxprofit;
    }
}
```
```
class Solution {
    public int maxProfit(int[] prices) {
        int maxprofit = 0;
        for (int i = 1; i < prices.length; i++) {
            if (prices[i] > prices[i - 1])
                maxprofit += prices[i] - prices[i - 1];
        }
        return maxprofit;
    }
}
```
123_BestTimetoBuyandSellStockIII
```
class Solution {
  public:
  int maxProfit(vector<int>& prices) {
    int length = prices.size();
    if (length <= 1) return 0;

    int leftMin = prices[0];
    int rightMax = prices[length - 1];

    vector<int> leftProfits(length, 0);
    // pad the right DP array with an additional zero for convenience.
    vector<int> rightProfits(length + 1, 0);

    // construct the bidirectional DP array
    for (int l = 1; l < length; ++l) {
      leftProfits[l] = max(leftProfits[l - 1], prices[l] - leftMin);
      leftMin = min(leftMin, prices[l]);

      int r = length - 1 - l;
      rightProfits[r] = max(rightProfits[r + 1], rightMax - prices[r]);
      rightMax = max(rightMax, prices[r]);
    }

    int maxProfit = 0;
    for (int i = 0; i < length; ++i) {
      maxProfit = max(maxProfit, leftProfits[i] + rightProfits[i + 1]);
    }
    return maxProfit;
  }
};
```
```
class Solution {
  public:
  int maxProfit(vector<int>& prices) {
    int t1Cost = INT_MAX, 
        t2Cost = INT_MAX;
    int t1Profit = 0,
        t2Profit = 0;

    for (int price : prices) {
        // the maximum profit if only one transaction is allowed
        t1Cost = min(t1Cost, price);
        t1Profit = max(t1Profit, price - t1Cost);
        // re-invest the gained profit in the second transaction
        t2Cost = min(t2Cost, price - t1Profit);
        t2Profit = max(t2Profit, price - t2Cost);
    }

    return t2Profit;
  }
};
```
```
```
124_BinaryTreeMaximumPathSum
```
class Solution:
    def maxPathSum(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """
        def max_gain(node):
            nonlocal max_sum
            if not node:
                return 0

            # max sum on the left and right sub-trees of node
            left_gain = max(max_gain(node.left), 0)
            right_gain = max(max_gain(node.right), 0)
            
            # the price to start a new path where `node` is a highest node
            price_newpath = node.val + left_gain + right_gain
            
            # update max_sum if it's better to start a new path
            max_sum = max(max_sum, price_newpath)
        
            # for recursion :
            # return the max gain if continue the same path
            return node.val + max(left_gain, right_gain)
   
        max_sum = float('-inf')
        max_gain(root)
        return max_sum
```
```
```
```
```
125_ValidPalindrome
```
class Solution {
 public:
  bool isPalindrome(string s) {
    string filtered_string, reversed_string;

    for (auto ch : s) {
      if (isalnum(ch))
        filtered_string += tolower(ch);
    }

    reversed_string.resize(filtered_string.size());
    reverse_copy(filtered_string.begin(), filtered_string.end(),
                 reversed_string.begin());

    return filtered_string == reversed_string;
  }
};

```
```
class Solution {
 public:
  bool isPalindrome(string s) {
    for (int i = 0, j = s.size() - 1; i < j; i++, j--) {
      while (i < j && !isalnum(s[i]))
        i++;
      while (i < j && !isalnum(s[j]))
        j--;

      if (tolower(s[i]) != tolower(s[j]))
        return false;
    }

    return true;
  }
};
```
```
```
126_WordLadderII
```
class Solution {
public:
    unordered_map<string, vector<string>> adjList;
    vector<string> currPath;
    vector<vector<string>> shortestPaths;

    vector<string> findNeighbors(string &word, unordered_set<string> &wordList) {
        vector<string> neighbors;

        for (int i = 0; i < word.size(); i++) {
            char oldChar = word[i];

            // replace the i-th character with all letters from a to z except the original character
            for (char c = 'a'; c <= 'z'; c++) {
                word[i] = c;

                // skip if the character is same as original or if the word is not present in the
                // wordList
                if (c == oldChar || !wordList.count(word)) {
                    continue;
                }
                neighbors.push_back(word);
            }
            word[i] = oldChar;
        }
        return neighbors;
    }

    void backtrack(string &source, string &destination) {
        // store the path if we reached the endWord
        if (source == destination) {
            shortestPaths.push_back(vector<string>(currPath.rbegin(), currPath.rend()));
        }
        for (int i = 0; i < adjList[source].size(); i++) {
            currPath.push_back(adjList[source][i]);
            backtrack(adjList[source][i], destination);
            currPath.pop_back();
        }
    }

    void bfs(string& beginWord, string& endWord, unordered_set<string>& wordList) {
        queue<string> q;
        q.push(beginWord);

        // remove the root word which is the first layer
        if (wordList.find(beginWord) != wordList.end()) {
            wordList.erase(wordList.find(beginWord));
        }

        unordered_map<string, int> isEnqueued;
        isEnqueued[beginWord] = 1;

        while (!q.empty()) {
            // visited will store the words of current layer
            vector<string> visited;

            for (int i = q.size() - 1; i >= 0; i--) {
                string currWord = q.front();
                q.pop();

                // findNeighbors will have the adjacent words of the currWord
                vector<string> neighbors = findNeighbors(currWord, wordList);
                for (auto word : neighbors) {
                    visited.push_back(word);
                    // add the edge from word to currWord in the list
                    adjList[word].push_back(currWord);

                    if (isEnqueued.find(word) == isEnqueued.end()) {
                        q.push(word);
                        isEnqueued[word] = 1;
                    }
                }
            }
            // removing the words of the previous layer
            for (int i = 0; i < visited.size(); i++) {
                if (wordList.find(visited[i]) != wordList.end()) {
                    wordList.erase(wordList.find(visited[i]));
                }
            }
        }
    }

    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string> &wordList) {
        // copying the words into the set for efficient deletion in BFS
        unordered_set<string> copiedWordList(wordList.begin(), wordList.end());
        // build the DAG using BFS
        bfs(beginWord, endWord, copiedWordList);

        // every path will start from the endWord
        currPath = {endWord};
        // traverse the DAG to find all the paths between endWord and beginWord
        backtrack(endWord, beginWord);

        return shortestPaths;
    }
};

```
```
class Solution {
public:
    unordered_map<string, vector<string>> adjList;
    vector<string> currPath;
    vector<vector<string>> shortestPaths;
    
    vector<string> findNeighbors(string &word, unordered_set<string>& wordList) {
        vector<string> neighbors;
        
        for (int i = 0; i < word.size(); i++) {
            char oldChar = word[i];   
            
            // replace the i-th character with all letters from a to z except the original character
            for (char c = 'a'; c <= 'z'; c++) {
                word[i] = c;
                
                // skip if the character is same as original or if the word is not present in the wordList
                if (c == oldChar || !wordList.count(word)) {
                    continue;
                }
                neighbors.push_back(word);
            }
            word[i] = oldChar;
        }
        return neighbors;
    }
    
    void backtrack(string &source, string &destination) {
        // store the path if we reached the endWord
        if (source == destination) {
            shortestPaths.push_back(currPath);
        }
        for (int i = 0; i < adjList[source].size(); i++) {
            currPath.push_back(adjList[source][i]);
            backtrack(adjList[source][i], destination);
            currPath.pop_back();
        }
    }
    
    void addEdge(string &word1, string &word2, int direction) {
        if(direction == 1) {
            adjList[word1].push_back(word2);
        } else {
            adjList[word2].push_back(word1);
        }
    }
    
    bool bfs(string beginWord, string endWord, unordered_set<string> wordList) {
        if (wordList.count(endWord) == 0) {
            return false;
        }
        
        // remove the root word which is the first layer
        if (wordList.find(beginWord) != wordList.end()) {
            wordList.erase(wordList.find(beginWord));
        }

        unordered_set<string> forwardQueue, backwardQueue;
        forwardQueue.insert(beginWord);
        backwardQueue.insert(endWord);
        
        bool found = false;
        int direction = 1;
        
        while (forwardQueue.size() != 0)  {
            // visited will store the words of current layer
            unordered_set<string> visited;
            
            // swap the queues because we are always extending the forwardQueue
            if (forwardQueue.size() > backwardQueue.size()) {
                swap(forwardQueue, backwardQueue);
                direction ^= 1;
            }
            
            for (auto currWord : forwardQueue) {
                vector<string> neighbors = findNeighbors(currWord, wordList);

                 for (auto word : neighbors) {
                    
                     // if the backwardQueue already contains it we can stop after completing this level
                     if (backwardQueue.find(word) != backwardQueue.end()) {
                         found = true;
                         addEdge(currWord, word, direction);
                    
                     /* the word shouldn't be presnt in forwardQueue because if it is then the edge will
                        be between two words at the same level which we don't want */
                     } else if (!found && wordList.count(word) != 0 && forwardQueue.count(word) == 0) {
                         visited.insert(word);
                         addEdge(currWord, word, direction);
                     }
                 }
            }
            
            // removing the words of the previous layer
            for (auto currWord : forwardQueue) {
                if (wordList.find(currWord) != wordList.end()) {
                    wordList.erase(wordList.find(currWord));
                }
            }
            if (found) {
                break;
            }
            
            forwardQueue = visited;
        }
        return found;
    }
    
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        // copying the words into the set for efficient deletion in BFS
        unordered_set<string> copiedWordList(wordList.begin(), wordList.end());
        // build the DAG using BFS
        bool sequence_found = bfs(beginWord, endWord, copiedWordList);
        
        // There is no valid sequence that connects `beginWord` to `endWord`
        if (sequence_found == false) {
            return shortestPaths;
        }
        // every path will start from the beginWord
        currPath = {beginWord};
        // traverse the DAG to find all the paths between beginWord and endWord
        backtrack(beginWord, endWord);
        
        return shortestPaths;
    }
};
```
```
```
127_WordLadder
```
from collections import defaultdict
class Solution(object):
    def ladderLength(self, beginWord, endWord, wordList):
        """
        :type beginWord: str
        :type endWord: str
        :type wordList: List[str]
        :rtype: int
        """

        if endWord not in wordList or not endWord or not beginWord or not wordList:
            return 0

        # Since all words are of same length.
        L = len(beginWord)

        # Dictionary to hold combination of words that can be formed,
        # from any given word. By changing one letter at a time.
        all_combo_dict = defaultdict(list)
        for word in wordList:
            for i in range(L):
                # Key is the generic word
                # Value is a list of words which have the same intermediate generic word.
                all_combo_dict[word[:i] + "*" + word[i+1:]].append(word)


        # Queue for BFS
        queue = collections.deque([(beginWord, 1)])
        # Visited to make sure we don't repeat processing same word.
        visited = {beginWord: True}
        while queue:
            current_word, level = queue.popleft()
            for i in range(L):
                # Intermediate words for current word
                intermediate_word = current_word[:i] + "*" + current_word[i+1:]

                # Next states are all the words which share the same intermediate state.
                for word in all_combo_dict[intermediate_word]:
                    # If at any point if we find what we are looking for
                    # i.e. the end word - we can return with the answer.
                    if word == endWord:
                        return level + 1
                    # Otherwise, add it to the BFS Queue. Also mark it visited
                    if word not in visited:
                        visited[word] = True
                        queue.append((word, level + 1))
                all_combo_dict[intermediate_word] = []
        return 0
```
```
from collections import defaultdict
class Solution(object):
    def __init__(self):
        self.length = 0
        # Dictionary to hold combination of words that can be formed,
        # from any given word. By changing one letter at a time.
        self.all_combo_dict = defaultdict(list)

    def visitWordNode(self, queue, visited, others_visited):
        queue_size = len(queue)
        for _ in range(queue_size):
            current_word = queue.popleft()
            for i in range(self.length):
                # Intermediate words for current word
                intermediate_word = current_word[:i] + "*" + current_word[i+1:]

                # Next states are all the words which share the same intermediate state.
                for word in self.all_combo_dict[intermediate_word]:
                    # If the intermediate state/word has already been visited from the
                    # other parallel traversal this means we have found the answer.
                    if word in others_visited:
                        return visited[current_word] + others_visited[word]
                    if word not in visited:
                        # Save the level as the value of the dictionary, to save number of hops.
                        visited[word] = visited[current_word] + 1
                        queue.append(word)
                        
        return None

    def ladderLength(self, beginWord, endWord, wordList):
        """
        :type beginWord: str
        :type endWord: str
        :type wordList: List[str]
        :rtype: int
        """
        if endWord not in wordList or not endWord or not beginWord or not wordList:
            return 0

        # Since all words are of same length.
        self.length = len(beginWord)

        for word in wordList:
            for i in range(self.length):
                # Key is the generic word
                # Value is a list of words which have the same intermediate generic word.
                self.all_combo_dict[word[:i] + "*" + word[i+1:]].append(word)

        # Queues for birdirectional BFS
        queue_begin = collections.deque([beginWord]) # BFS starting from beginWord
        queue_end = collections.deque([endWord]) # BFS starting from endWord

        # Visited to make sure we don't repeat processing same word
        visited_begin = {beginWord : 1}
        visited_end = {endWord : 1}
        ans = None

        # We do a birdirectional search starting one pointer from begin
        # word and one pointer from end word. Hopping one by one.
        while queue_begin and queue_end:
            
            # Progress forward one step from the shorter queue
            if len(queue_begin) <= len(queue_end):
                ans = self.visitWordNode(queue_begin, visited_begin, visited_end)
            else:
                ans = self.visitWordNode(queue_end, visited_end, visited_begin)
            if ans:
                return ans

        return 0
```
```
```
128_LongestConsecutiveSequence
```
class Solution:
    def longestConsecutive(self, nums):
        longest_streak = 0

        for num in nums:
            current_num = num
            current_streak = 1

            while current_num + 1 in nums:
                current_num += 1
                current_streak += 1

            longest_streak = max(longest_streak, current_streak)

        return longest_streak
```
```
class Solution:
    def longestConsecutive(self, nums):
        if not nums:
            return 0

        nums.sort()

        longest_streak = 1
        current_streak = 1

        for i in range(1, len(nums)):
            if nums[i] != nums[i-1]:
                if nums[i] == nums[i-1]+1:
                    current_streak += 1
                else:
                    longest_streak = max(longest_streak, current_streak)
                    current_streak = 1

        return max(longest_streak, current_streak)
```
```
class Solution:
    def longestConsecutive(self, nums):
        longest_streak = 0
        num_set = set(nums)

        for num in num_set:
            if num - 1 not in num_set:
                current_num = num
                current_streak = 1

                while current_num + 1 in num_set:
                    current_num += 1
                    current_streak += 1

                longest_streak = max(longest_streak, current_streak)

        return longest_streak
```
129_SumRoottoLeafNumbers
```
class Solution:
    def sumNumbers(self, root: TreeNode):
        root_to_leaf = 0
        stack = [(root, 0) ]
        
        while stack:
            root, curr_number = stack.pop()
            if root is not None:
                curr_number = curr_number * 10 + root.val
                # if it's a leaf, update root-to-leaf sum
                if root.left is None and root.right is None:
                    root_to_leaf += curr_number
                else:
                    stack.append((root.right, curr_number))
                    stack.append((root.left, curr_number))
                        
        return root_to_leaf
```
```
class Solution:
    def sumNumbers(self, root: TreeNode):
        def preorder(r, curr_number):
            nonlocal root_to_leaf
            if r:
                curr_number = curr_number * 10 + r.val
                # if it's a leaf, update root-to-leaf sum
                if not (r.left or r.right):
                    root_to_leaf += curr_number
                    
                preorder(r.left, curr_number)
                preorder(r.right, curr_number) 
        
        root_to_leaf = 0
        preorder(root, 0)
        return root_to_leaf
```
```
class Solution:
    def sumNumbers(self, root: TreeNode):
        root_to_leaf = curr_number = 0
        
        while root:  
            # If there is a left child,
            # then compute the predecessor.
            # If there is no link predecessor.right = root --> set it.
            # If there is a link predecessor.right = root --> break it.
            if root.left: 
                # Predecessor node is one step to the left 
                # and then to the right till you can.
                predecessor = root.left 
                steps = 1
                while predecessor.right and predecessor.right is not root: 
                    predecessor = predecessor.right 
                    steps += 1

                # Set link predecessor.right = root
                # and go to explore the left subtree
                if predecessor.right is None:
                    curr_number = curr_number * 10 + root.val                    
                    predecessor.right = root  
                    root = root.left  
                # Break the link predecessor.right = root
                # Once the link is broken, 
                # it's time to change subtree and go to the right
                else:
                    # If you're on the leaf, update the sum
                    if predecessor.left is None:
                        root_to_leaf += curr_number
                    # This part of tree is explored, backtrack
                    for _ in range(steps):
                        curr_number //= 10
                    predecessor.right = None
                    root = root.right 
                    
            # If there is no left child
            # then just go right.        
            else: 
                curr_number = curr_number * 10 + root.val
                # if you're on the leaf, update the sum
                if root.right is None:
                    root_to_leaf += curr_number
                root = root.right
                        
        return root_to_leaf
```
130_SurroundedRegions
```
class Solution(object):
    def solve(self, board):
        """
        :type board: List[List[str]]
        :rtype: None Do not return anything, modify board in-place instead.
        """
        if not board or not board[0]:
            return

        self.ROWS = len(board)
        self.COLS = len(board[0])

        # Step 1). retrieve all border cells
        from itertools import product
        borders = list(product(range(self.ROWS), [0, self.COLS-1])) \
                + list(product([0, self.ROWS-1], range(self.COLS)))

        # Step 2). mark the "escaped" cells, with any placeholder, e.g. 'E'
        for row, col in borders:
            self.DFS(board, row, col)

        # Step 3). flip the captured cells ('O'->'X') and the escaped one ('E'->'O')
        for r in range(self.ROWS):
            for c in range(self.COLS):
                if board[r][c] == 'O':   board[r][c] = 'X'  # captured
                elif board[r][c] == 'E': board[r][c] = 'O'  # escaped


    def DFS(self, board, row, col):
        if board[row][col] != 'O':
            return
        board[row][col] = 'E'
        if col < self.COLS-1: self.DFS(board, row, col+1)
        if row < self.ROWS-1: self.DFS(board, row+1, col)
        if col > 0: self.DFS(board, row, col-1)
        if row > 0: self.DFS(board, row-1, col)
```
```
def DFS(self, board, row, col):
    if row < 0 or row >= self.ROWS or col < 0 or col >= self.COLS:
        return
    if board[row][col] != 'O':
        return
    board[row][col] = 'E'
    # jump to the neighbors without boundary checks
    for ro, co in [(0, 1), (1, 0), (0, -1), (-1, 0)]:
        self.DFS(board, row+ro, col+co)
```
```
class Solution(object):
    def solve(self, board):
        """
        :type board: List[List[str]]
        :rtype: None Do not return anything, modify board in-place instead.
        """
        if not board or not board[0]:
            return

        self.ROWS = len(board)
        self.COLS = len(board[0])

        # Step 1). retrieve all border cells
        from itertools import product
        borders = list(product(range(self.ROWS), [0, self.COLS-1])) \
                + list(product([0, self.ROWS-1], range(self.COLS)))

        # Step 2). mark the "escaped" cells, with any placeholder, e.g. 'E'
        for row, col in borders:
            #self.DFS(board, row, col)
            self.BFS(board, row, col)

        # Step 3). flip the captured cells ('O'->'X') and the escaped one ('E'->'O')
        for r in range(self.ROWS):
            for c in range(self.COLS):
                if board[r][c] == 'O':   board[r][c] = 'X'  # captured
                elif board[r][c] == 'E': board[r][c] = 'O'  # escaped


    def BFS(self, board, row, col):
        from collections import deque
        queue = deque([(row, col)])
        while queue:
            (row, col) = queue.popleft()
            if board[row][col] != 'O':
                continue
            # mark this cell as escaped
            board[row][col] = 'E'
            # check its neighbor cells
            if col < self.COLS-1: queue.append((row, col+1))
            if row < self.ROWS-1: queue.append((row+1, col))
            if col > 0: queue.append((row, col-1))
            if row > 0: queue.append((row-1, col))
```
```
    def DFS(self, board, row, col):
        from collections import deque
        queue = deque([(row, col)])
        while queue:
            # pop out the _tail_ element, rather than the head.
            (row, col) = queue.pop()
            if board[row][col] != 'O':
                continue
            # mark this cell as escaped
            board[row][col] = 'E'
            # check its neighbour cells
            if col < self.COLS-1: queue.append((row, col+1))
            if row < self.ROWS-1: queue.append((row+1, col))
            if col > 0: queue.append((row, col-1))
            if row > 0: queue.append((row-1, col))
```



131_PalindromePartitioning

```
class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> result;
        vector<string> currentList;
        dfs(result, s, 0, currentList);
        return result;
    }

    void dfs(vector<vector<string>> &result, string &s, int start, vector<string> &currentList) {
        if (start >= s.length()) result.push_back(currentList);
        for (int end = start; end < s.length(); end++) {
            if (isPalindrome(s, start, end)) {
                // add current substring in the currentList
                currentList.push_back(s.substr(start, end - start + 1));
                dfs(result, s, end + 1, currentList);
                // backtrack and remove the current substring from currentList
                currentList.pop_back();
            }
        }
    }

    bool isPalindrome(string &s, int low, int high) {
        while (low < high) {
            if (s[low++] != s[high--]) return false;
        }
        return true;
    }
};

```
```
class Solution {
public:
    vector<vector<string>> partition(string s) {
        int len = s.length();
        vector<vector<bool>> dp (len, vector <bool> (len, false));
        vector<vector<string>> result;
        vector<string> currentList;
        dfs(result, s, 0, currentList, dp);
        return result;
    }

    void dfs(vector<vector<string>> &result, string &s, int start, vector<string> &currentList, vector<vector<bool>> &dp) {
        if (start >= s.length()) result.push_back(currentList);
        for (int end = start; end < s.length(); end++) {
            if (s[start] == s[end] && (end - start <= 2 || dp[start + 1][end - 1])) {
                dp[start][end] = true;
                currentList.push_back(s.substr(start, end - start + 1));
                dfs(result, s, end + 1, currentList, dp);
                currentList.pop_back();
            }
        }
    }
};

```
```
```
132_PalindromePartitioningII
```

class Solution {
public:
    int minCut(string s) {
        return findMinimumCut(s, 0, s.length() - 1, s.length() - 1);
    }

    int findMinimumCut(string &s, int start, int end, int minimumCut) {
        // base condition, no cut needed for an empty substring or palindrome substring.
        if (start == end || isPalindrome(s, start, end)) {
            return 0;
        }
        for (int currentEndIndex = start; currentEndIndex <= end; currentEndIndex++) {
            // find result for substring (start, currentEnd) if it is palindrome
            if (isPalindrome(s, start, currentEndIndex)) {
                minimumCut = min(
                    minimumCut,
                    1 + findMinimumCut(s, currentEndIndex + 1, end, minimumCut));
            }
        }
        return minimumCut;
    }

    bool isPalindrome(string &s, int start, int end) {
        while (start < end) {
            if (s[start++] != s[end--]) {
                return false;
            }
        }
        return true;
    }
};
```
```
class Solution {
public:
    vector<vector<int>> memoCuts;
    vector<vector<optional<bool>>> memoPalindrome;

    int minCut(string s) {
        memoCuts.resize(s.length(), vector<int>(s.length(), -1));
        memoPalindrome.resize(s.length(),
                              vector<optional<bool>>(s.length(), nullopt));
        return findMinimumCut(s, 0, s.length() - 1, s.length() - 1);
    }

    int findMinimumCut(string &s, int start, int end, int minimumCut) {
        // base case
        if (start == end || isPalindrome(s, start, end)) {
            return 0;
        }

        // check for results in memoCuts
        if (memoCuts[start][end] != -1) {
            return memoCuts[start][end];
        }

        for (int currentEndIndex = start; currentEndIndex <= end;
             currentEndIndex++) {
            if (isPalindrome(s, start, currentEndIndex)) {
                minimumCut =
                    min(minimumCut, 1 + findMinimumCut(s, currentEndIndex + 1,
                                                       end, minimumCut));
            }
        }
        return memoCuts[start][end] = minimumCut;
    }

    bool isPalindrome(string &s, int start, int end) {
        if (start >= end) return true;
        // check for results in memoPalindrome
        if (memoPalindrome[start][end] != nullopt)
            return (memoPalindrome[start][end] == true);
        memoPalindrome[start][end] =
            (s[start] == s[end]) && isPalindrome(s, start + 1, end - 1);
        return (memoPalindrome[start][end] == true);
    }
};class Solution {
public:
    vector<vector<int>> memoCuts;
    vector<vector<optional<bool>>> memoPalindrome;

    int minCut(string s) {
        memoCuts.resize(s.length(), vector<int>(s.length(), -1));
        memoPalindrome.resize(s.length(),
                              vector<optional<bool>>(s.length(), nullopt));
        return findMinimumCut(s, 0, s.length() - 1, s.length() - 1);
    }

    int findMinimumCut(string &s, int start, int end, int minimumCut) {
        // base case
        if (start == end || isPalindrome(s, start, end)) {
            return 0;
        }

        // check for results in memoCuts
        if (memoCuts[start][end] != -1) {
            return memoCuts[start][end];
        }

        for (int currentEndIndex = start; currentEndIndex <= end;
             currentEndIndex++) {
            if (isPalindrome(s, start, currentEndIndex)) {
                minimumCut =
                    min(minimumCut, 1 + findMinimumCut(s, currentEndIndex + 1,
                                                       end, minimumCut));
            }
        }
        return memoCuts[start][end] = minimumCut;
    }

    bool isPalindrome(string &s, int start, int end) {
        if (start >= end) return true;
        // check for results in memoPalindrome
        if (memoPalindrome[start][end] != nullopt)
            return (memoPalindrome[start][end] == true);
        memoPalindrome[start][end] =
            (s[start] == s[end]) && isPalindrome(s, start + 1, end - 1);
        return (memoPalindrome[start][end] == true);
    }
};
```
```
class Solution {
public:
    vector<int> memoCuts;
    vector<vector<optional<bool>>> memoPalindrome;

    int minCut(string s) {
        memoCuts.resize(s.length(), -1);
        memoPalindrome.resize(s.length(),
                              vector<optional<bool>>(s.length(), nullopt));
        return findMinimumCut(s, 0, s.length() - 1, s.length() - 1);
    }

    int findMinimumCut(string &s, int start, int end, int minimumCut) {
        // base case
        if (start == end || isPalindrome(s, start, end)) {
            return 0;
        }

        // check for results in memoCuts
        if (memoCuts[start] != -1) {
            return memoCuts[start];
        }

        for (int currentEndIndex = start; currentEndIndex <= end;
             currentEndIndex++) {
            if (isPalindrome(s, start, currentEndIndex)) {
                minimumCut =
                    min(minimumCut, 1 + findMinimumCut(s, currentEndIndex + 1,
                                                       end, minimumCut));
            }
        }
        return memoCuts[start] = minimumCut;
    }

    bool isPalindrome(string &s, int start, int end) {
        if (start >= end) return true;
        // check for results in memoPalindrome
        if (memoPalindrome[start][end] != nullopt)
            return (memoPalindrome[start][end] == true);
        memoPalindrome[start][end] =
            (s[start] == s[end]) && isPalindrome(s, start + 1, end - 1);
        return (memoPalindrome[start][end] == true);
    }
};
```
```
class Solution {
public:
    vector<int> cutsDp;
    vector<vector<bool>> palindromeDp;
    
    int minCut(string s) {
        cutsDp.resize(s.length());
        palindromeDp.resize(s.length(), vector<bool>(s.length(), false));
        // build the palindrome cutsDp for all susbtrings
        buildPalindromeDp(s, s.length());
        for (int end = 0; end < s.length(); end++) {
            int minimumCut = end;
            for (int start = 0; start <= end; start++) {
                if (palindromeDp[start][end]) {
                    minimumCut =
                        start == 0 ? 0 : min(minimumCut, cutsDp[start - 1] + 1);
                }
            }
            cutsDp[end] = minimumCut;
        }
        return cutsDp[s.length() - 1];
    }

    void buildPalindromeDp(string &s, int n) {
        for (int end = 0; end < s.length(); end++) {
            for (int start = 0; start <= end; start++) {
                if (s[start] == s[end] &&
                    (end - start <= 2 || palindromeDp[start + 1][end - 1])) {
                    palindromeDp[start][end] = true;
                }
            }
        }
    }
};
```

```
class Solution {
public:
    int minCut(string s) {
        vector<int> cutsDp;
        vector<vector<bool>> palindromeDp;
        cutsDp.resize(s.length());
        palindromeDp.resize(s.length(), vector<bool>(s.length(), false));
        for (int end = 0; end < s.length(); end++) {
            int minimumCut = end;
            for (int start = 0; start <= end; start++) {
                // check if substring (start, end) is palidrome
                if (s[start] == s[end] &&
                    (end - start <= 2 || palindromeDp[start + 1][end - 1])) {
                    palindromeDp[start][end] = true;
                    minimumCut =
                        start == 0 ? 0 : min(minimumCut, cutsDp[start - 1] + 1);
                }
            }
            cutsDp[end] = minimumCut;
        }
        return cutsDp[s.length() - 1];
    }
};
```

```
class Solution {
public:
    int minCut(string s) {
        vector<int> cutsDp;
        cutsDp.resize(s.length());
        for (int i = 1; i < s.length(); i++) {
            cutsDp[i] = i;
        }
        for (int mid = 0; mid < s.length(); mid++) {
            // check for odd length palindrome around mid index
            findMinimumCuts(mid, mid, cutsDp, s);
            // check for even length palindrome around mid index
            findMinimumCuts(mid - 1, mid, cutsDp, s);
        }
        return cutsDp[s.length() - 1];
    }

    void findMinimumCuts(int startIndex, int endIndex, vector<int> &cutsDp,
                         string s) {
        for (int start = startIndex, end = endIndex;
             start >= 0 && end < s.length() && s[start] == s[end];
             start--, end++) {
            int newCut = start == 0 ? 0 : cutsDp[start - 1] + 1;
            cutsDp[end] = min(cutsDp[end], newCut);
        }
    }
};
```



133_CloneGraph

```
"""
# Definition for a Node.
class Node(object):
    def __init__(self, val, neighbors):
        self.val = val
        self.neighbors = neighbors
"""
class Solution(object):

    def __init__(self):
        # Dictionary to save the visited node and it's respective clone
        # as key and value respectively. This helps to avoid cycles.
        self.visited = {}

    def cloneGraph(self, node):
        """
        :type node: Node
        :rtype: Node
        """
        if not node:
            return node

        # If the node was already visited before.
        # Return the clone from the visited dictionary.
        if node in self.visited:
            return self.visited[node]

        # Create a clone for the given node.
        # Note that we don't have cloned neighbors as of now, hence [].
        clone_node = Node(node.val, [])

        # The key is original node and value being the clone node.
        self.visited[node] = clone_node

        # Iterate through the neighbors to generate their clones
        # and prepare a list of cloned neighbors to be added to the cloned node.
        if node.neighbors:
            clone_node.neighbors = [self.cloneGraph(n) for n in node.neighbors]

        return clone_node
```
```
"""
# Definition for a Node.
class Node(object):
    def __init__(self, val, neighbors):
        self.val = val
        self.neighbors = neighbors
"""
from collections import deque
class Solution(object):

    def cloneGraph(self, node):
        """
        :type node: Node
        :rtype: Node
        """

        if not node:
            return node

        # Dictionary to save the visited node and it's respective clone
        # as key and value respectively. This helps to avoid cycles.
        visited = {}

        # Put the first node in the queue
        queue = deque([node])
        # Clone the node and put it in the visited dictionary.
        visited[node] = Node(node.val, [])

        # Start BFS traversal
        while queue:
            # Pop a node say "n" from the from the front of the queue.
            n = queue.popleft()
            # Iterate through all the neighbors of the node
            for neighbor in n.neighbors:
                if neighbor not in visited:
                    # Clone the neighbor and put in the visited, if not present already
                    visited[neighbor] = Node(neighbor.val, [])
                    # Add the newly encountered node to the queue.
                    queue.append(neighbor)
                # Add the clone of the neighbor to the neighbors of the clone node "n".
                visited[n].neighbors.append(visited[neighbor])

        # Return the clone of the node from visited.
        return visited[node]
```
```
```
134_GasStation
```
class Solution {
  public:
  int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
    int n = gas.size();

    int total_tank = 0;
    int curr_tank = 0;
    int starting_station = 0;
    for (int i = 0; i < n; ++i) {
      total_tank += gas[i] - cost[i];
      curr_tank += gas[i] - cost[i];
      // If one couldn't get here,
      if (curr_tank < 0) {
        // Pick up the next station as the starting one.
        starting_station = i + 1;
        // Start with an empty tank.
        curr_tank = 0;
      }
    }
    return total_tank >= 0 ? starting_station : -1;
  }
};
```
```
```
```
```
135_Candy
```
public class Solution {
    public int candy(int[] ratings) {
        int[] candies = new int[ratings.length];
        Arrays.fill(candies, 1);
        boolean hasChanged = true;
        while (hasChanged) {
            hasChanged = false;
            for (int i = 0; i < ratings.length; i++) {
                if (i != ratings.length - 1 && ratings[i] > ratings[i + 1] && candies[i] <= candies[i + 1]) {
                    candies[i] = candies[i + 1] + 1;
                    hasChanged = true;
                }
                if (i > 0 && ratings[i] > ratings[i - 1] && candies[i] <= candies[i - 1]) {
                    candies[i] = candies[i - 1] + 1;
                    hasChanged = true;
                }
            }
        }
        int sum = 0;
        for (int candy : candies) {
            sum += candy;
        }
        return sum;
    }
}
```
```
public class Solution {
    public int candy(int[] ratings) {
        int sum = 0;
        int[] left2right = new int[ratings.length];
        int[] right2left = new int[ratings.length];
        Arrays.fill(left2right, 1);
        Arrays.fill(right2left, 1);
        for (int i = 1; i < ratings.length; i++) {
            if (ratings[i] > ratings[i - 1]) {
                left2right[i] = left2right[i - 1] + 1;
            }
        }
        for (int i = ratings.length - 2; i >= 0; i--) {
            if (ratings[i] > ratings[i + 1]) {
                right2left[i] = right2left[i + 1] + 1;
            }
        }
        for (int i = 0; i < ratings.length; i++) {
            sum += Math.max(left2right[i], right2left[i]);
        }
        return sum;
    }
}
```
```
public class Solution {
    public int candy(int[] ratings) {
        int[] candies = new int[ratings.length];
        Arrays.fill(candies, 1);
        for (int i = 1; i < ratings.length; i++) {
            if (ratings[i] > ratings[i - 1]) {
                candies[i] = candies[i - 1] + 1;
            }
        }
        int sum = candies[ratings.length - 1];
        for (int i = ratings.length - 2; i >= 0; i--) {
            if (ratings[i] > ratings[i + 1]) {
                candies[i] = Math.max(candies[i], candies[i + 1] + 1);
            }
            sum += candies[i];
        }
        return sum;
    }
}
```
```
public class Solution {
    public int count(int n) {
        return (n * (n + 1)) / 2;
    }
    public int candy(int[] ratings) {
        if (ratings.length <= 1) {
            return ratings.length;
        }
        int candies = 0;
        int up = 0;
        int down = 0;
        int oldSlope = 0;
        for (int i = 1; i < ratings.length; i++) {
            int newSlope = (ratings[i] > ratings[i - 1]) ? 1 
                : (ratings[i] < ratings[i - 1] ? -1 
                : 0);

            if ((oldSlope > 0 && newSlope == 0) || (oldSlope < 0 && newSlope >= 0)) {
                candies += count(up) + count(down) + Math.max(up, down);
                up = 0;
                down = 0;
            }
            if (newSlope > 0) {
                up++;
            } else if (newSlope < 0) {
                down++;
            } else {
                candies++;
            }

            oldSlope = newSlope;
        }
        candies += count(up) + count(down) + Math.max(up, down) + 1;
        return candies;
    }
}
```



136_SingleNumber

```
class Solution(object):
    def singleNumber(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        no_duplicate_list = []
        for i in nums:
            if i not in no_duplicate_list:
                no_duplicate_list.append(i)
            else:
                no_duplicate_list.remove(i)
        return no_duplicate_list.pop()
```
```
from collections import defaultdict
class Solution:
    def singleNumber(self, nums: List[int]) -> int:
        hash_table = defaultdict(int)
        for i in nums:
            hash_table[i] += 1
        
        for i in hash_table:
            if hash_table[i] == 1:
                return i
```
```
class Solution(object):
    def singleNumber(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        return 2 * sum(set(nums)) - sum(nums)
```
```
class Solution(object):
    def singleNumber(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        a = 0
        for i in nums:
            a ^= i
        return a
```



137_SingleNumberII

```
class Solution:
    def singleNumber(self, nums):
        return (3 * sum(set(nums)) - sum(nums)) // 2
```
```
from collections import Counter
class Solution:
    def singleNumber(self, nums):
        hashmap = Counter(nums)
            
        for k in hashmap.keys():
            if hashmap[k] == 1:
                return k
```
```
class Solution:
    def singleNumber(self, nums: List[int]) -> int:
        seen_once = seen_twice = 0
        
        for num in nums:
            # first appearance: 
            # add num to seen_once 
            # don't add to seen_twice because of presence in seen_once
            
            # second appearance: 
            # remove num from seen_once 
            # add num to seen_twice
            
            # third appearance: 
            # don't add to seen_once because of presence in seen_twice
            # remove num from seen_twice
            seen_once = ~seen_twice & (seen_once ^ num)
            seen_twice = ~seen_once & (seen_twice ^ num)

        return seen_once
```
138_CopyListwithRandomPointer
```
class Solution(object):
    """
    :type head: Node
    :rtype: Node
    """
    def __init__(self):
        # Dictionary which holds old nodes as keys and new nodes as its values.
        self.visitedHash = {}

    def copyRandomList(self, head):

        if head == None:
            return None

        # If we have already processed the current node, then we simply return the cloned version of it.
        if head in self.visitedHash:
            return self.visitedHash[head]

        # create a new node
        # with the value same as old node.
        node = Node(head.val, None, None)

        # Save this value in the hash map. This is needed since there might be
        # loops during traversal due to randomness of random pointers and this would help us avoid them.
        self.visitedHash[head] = node

        # Recursively copy the remaining linked list starting once from the next pointer and then from the random pointer.
        # Thus we have two independent recursive calls.
        # Finally we update the next and random pointers for the new node created.
        node.next = self.copyRandomList(head.next)
        node.random = self.copyRandomList(head.random)

        return node
```
```
class Solution(object):
    def __init__(self):
        # Creating a visited dictionary to hold old node reference as "key" and new node reference as the "value"
        self.visited = {}

    def getClonedNode(self, node):
        # If node exists then
        if node:
            # Check if its in the visited dictionary          
            if node in self.visited:
                # If its in the visited dictionary then return the new node reference from the dictionary
                return self.visited[node]
            else:
                # Otherwise create a new node, save the reference in the visited dictionary and return it.
                self.visited[node] = Node(node.val, None, None)
                return self.visited[node]
        return None

    def copyRandomList(self, head):
        """
        :type head: Node
        :rtype: Node
        """

        if not head:
            return head

        old_node = head
        # Creating the new head node.       
        new_node = Node(old_node.val, None, None)
        self.visited[old_node] = new_node

        # Iterate on the linked list until all nodes are cloned.
        while old_node != None:

            # Get the clones of the nodes referenced by random and next pointers.
            new_node.random = self.getClonedNode(old_node.random)
            new_node.next = self.getClonedNode(old_node.next)

            # Move one step ahead in the linked list.
            old_node = old_node.next
            new_node = new_node.next

        return self.visited[head]
```
```
class Solution(object):
    def copyRandomList(self, head):
        """
        :type head: Node
        :rtype: Node
        """
        if not head:
            return head

        # Creating a new weaved list of original and copied nodes.
        ptr = head
        while ptr:

            # Cloned node
            new_node = Node(ptr.val, None, None)

            # Inserting the cloned node just next to the original node.
            # If A->B->C is the original linked list,
            # Linked list after weaving cloned nodes would be A->A'->B->B'->C->C'
            new_node.next = ptr.next
            ptr.next = new_node
            ptr = new_node.next

        ptr = head

        # Now link the random pointers of the new nodes created.
        # Iterate the newly created list and use the original nodes random pointers,
        # to assign references to random pointers for cloned nodes.
        while ptr:
            ptr.next.random = ptr.random.next if ptr.random else None
            ptr = ptr.next.next

        # Unweave the linked list to get back the original linked list and the cloned list.
        # i.e. A->A'->B->B'->C->C' would be broken to A->B->C and A'->B'->C'
        ptr_old_list = head # A->B->C
        ptr_new_list = head.next # A'->B'->C'
        head_new = head.next
        while ptr_old_list:
            ptr_old_list.next = ptr_old_list.next.next
            ptr_new_list.next = ptr_new_list.next.next if ptr_new_list.next else None
            ptr_old_list = ptr_old_list.next
            ptr_new_list = ptr_new_list.next
        return head_new
```
139_WordBreak
```
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        set<string> word_set(wordDict.begin(), wordDict.end());
        return wordBreakRecur(s, word_set, 0);
    }

    bool wordBreakRecur(string& s, set<string>& word_set, int start) {
        if (start == s.length()) {
            return true;
        }
        for (int end = start + 1; end <= s.length(); end++) {
            if (word_set.find(s.substr(start, end - start)) != word_set.end() and
                wordBreakRecur(s, word_set, end)) {
                return true;
            }
        }
        return false;
    }
};
```
```
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        set<string> word_set(wordDict.begin(), wordDict.end());
        // In the memo table, -1 stands for the state not yet reached,
        // 0 for false and 1 for true
        vector<int> memo(s.length(), -1);
        return wordBreakMemo(s, word_set, 0, memo);
    }

    bool wordBreakMemo(string& s, set<string>& word_set, int start, vector<int>& memo) {
        if (start == s.length()) {
            return true;
        }
        if (memo[start] != -1) {
            return memo[start];
        }
        for (int end = start + 1; end <= s.length(); end++) {
            if (word_set.find(s.substr(start, end - start)) != word_set.end() and
                wordBreakMemo(s, word_set, end, memo)) {
                return memo[start] = true;
            }
        }
        return memo[start] = false;
    }
};
```
```
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        set<string> word_set(wordDict.begin(), wordDict.end());
        queue<int> q;
        vector<bool> visited(s.length(), false);
        q.push(0);
        while (!q.empty()) {
            int start = q.front();
            q.pop();
            if (visited[start]) {
                continue;
            }
            for (int end = start + 1; end <= s.length(); end++) {
                if (word_set.find(s.substr(start, end - start)) !=
                    word_set.end()) {
                    q.push(end);
                    if (end == s.length()) {
                        return true;
                    }
                }
            }
            visited[start] = true;
        }
        return false;
    }
};
```
```
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        set<string> word_set(wordDict.begin(), wordDict.end());
        vector<bool> dp(s.length() + 1);
        dp[0] = true;

        for (int i = 1; i <= s.length(); i++) {
            for (int j = 0; j < i; j++) {
                if (dp[j] and
                    word_set.find(s.substr(j, i - j)) != word_set.end()) {
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[s.length()];
    }
};
```



140_WordBreakII

```
class Solution:
    def wordBreak(self, s: str, wordDict: List[str]) -> List[str]:
        wordSet = set(wordDict)
        # table to map a string to its corresponding words break
        # {string: [['word1', 'word2'...], ['word3', 'word4', ...]]}
        memo = defaultdict(list)

        #@lru_cache(maxsize=None)    # alternative memoization solution
        def _wordBreak_topdown(s):
            """ return list of word lists """
            if not s:
                return [[]]  # list of empty list

            if s in memo:
                # returned the cached solution directly.
                return memo[s]

            for endIndex in range(1, len(s)+1):
                word = s[:endIndex]
                if word in wordSet:
                    # move forwards to break the postfix into words
                    for subsentence in _wordBreak_topdown(s[endIndex:]):
                        memo[s].append([word] + subsentence)
            return memo[s]

        # break the input string into lists of words list
        _wordBreak_topdown(s)

        # chain up the lists of words into sentences.
        return [" ".join(words) for words in memo[s]]
```
```
class Solution:
    def wordBreak(self, s: str, wordDict: List[str]) -> List[str]:
        # quick check on the characters,
        #   otherwise it would exceed the time limit for certain test cases.
        if set(Counter(s).keys()) > set(Counter("".join(wordDict)).keys()):
            return []

        wordSet = set(wordDict)

        dp = [[]] * (len(s)+1)
        dp[0] = [""]

        for endIndex in range(1, len(s)+1):
            sublist = []
            # fill up the values in the dp array.
            for startIndex in range(0, endIndex):
                word = s[startIndex:endIndex]
                if word in wordSet:
                    for subsentence in dp[startIndex]:
                        sublist.append((subsentence + ' ' + word).strip())

            dp[endIndex] = sublist

        return dp[len(s)]
```
```
class Solution:
    def wordBreak(self, s: str, wordDict: List[str]) -> List[str]:
        # quick check on the characters,
        #   otherwise it would exceed the time limit for certain test cases.
        if set(Counter(s).keys()) > set(Counter("".join(wordDict)).keys()):
            return []

        wordSet = set(wordDict)

        # the dp array stores the positions to insert breaks/stops
        dp = [[]] * (len(s)+1)
        dp[0] = [[0]]

        for endIndex in range(1, len(s)+1):
            stops = []
            for startIndex in range(0, endIndex):
                word = s[startIndex:endIndex]
                if word in wordSet:
                    for subsentence in dp[startIndex]:
                        copy = subsentence.copy()
                        copy.append(endIndex)
                        stops.append(copy)
            dp[endIndex] = stops

        ret = []
        # reconstruct the words list from the positions of breaks/stops
        for stops in dp[len(s)]:
            words = []
            for i in range(len(stops)-1):
                words.append(s[stops[i]:stops[i+1]])
            ret.append(" ".join(words))
        return ret
```
```
class Solution:
    def wordBreak(self, s: str, wordDict: List[str]) -> List[str]:
        # quick check on the characters,
        #   otherwise it would exceed the time limit for certain test cases.
        if set(Counter(s).keys()) > set(Counter("".join(wordDict)).keys()):
            return []

        wordSet = set(wordDict)

        dp = [[]] * (len(s)+1)
        dp[0] = [[0]]

        for endIndex in range(1, len(s)+1):
            stops = []
            for startIndex in range(0, endIndex):
                word = s[startIndex:endIndex]
                if word in wordSet:
                    stops.append([startIndex, endIndex])
            dp[endIndex] = stops

        ret = []
        def wordDFS(sentence, dp_index):
            if dp_index == 0:
                ret.append(" ".join(sentence))
                return

            for start, end in dp[dp_index]:
                word = s[start:end]
                wordDFS([word] + sentence, start)

        wordDFS([], len(s))

        return ret
```



141_LinkedListCycle

```
class Solution:
    def hasCycle(self, head: ListNode) -> bool:
        nodes_seen = set()
        while head is not None:
            if head in nodes_seen:
                return True
            nodes_seen.add(head)
            head = head.next
        return False
```
```
class Solution:
    def hasCycle(self, head: ListNode) -> bool:
        if head is None:
            return False
        slow = head
        fast = head.next
        while slow != fast:
            if fast is None or fast.next is None:
                return False
            slow = slow.next
            fast = fast.next.next
        return True
```
```
```
142_LinkedListCycleII

```
class Solution(object):
    def detectCycle(self, head):
        visited = set()

        node = head
        while node is not None:
            if node in visited:
                return node
            else:
                visited.add(node)
                node = node.next

        return None
```
```
class Solution(object):
    def getIntersect(self, head):
        tortoise = head
        hare = head

        # A fast pointer will either loop around a cycle and meet the slow
        # pointer or reach the `null` at the end of a non-cyclic list.
        while hare is not None and hare.next is not None:
            tortoise = tortoise.next
            hare = hare.next.next
            if tortoise == hare:
                return tortoise

        return None

    def detectCycle(self, head):
        if head is None:
            return None

        # If there is a cycle, the fast/slow pointers will intersect at some
        # node. Otherwise, there is no cycle, so we cannot find an entrance to
        # a cycle.
        intersect = self.getIntersect(head)
        if intersect is None:
            return None

        # To find the entrance to the cycle, we have two pointers traverse at
        # the same speed -- one from the front of the list, and the other from
        # the point of intersection.
        ptr1 = head
        ptr2 = intersect
        while ptr1 != ptr2:
            ptr1 = ptr1.next
            ptr2 = ptr2.next

        return ptr1

```
```
```
143_ReorderList
```
class Solution:
    def reorderList(self, head: ListNode) -> None:
        if not head:
            return 
        
        # find the middle of linked list [Problem 876]
        # in 1->2->3->4->5->6 find 4 
        slow = fast = head
        while fast and fast.next:
            slow = slow.next
            fast = fast.next.next 
            
        # reverse the second part of the list [Problem 206]
        # convert 1->2->3->4->5->6 into 1->2->3->4 and 6->5->4
        # reverse the second half in-place
        prev, curr = None, slow
        while curr:
            curr.next, prev, curr = prev, curr, curr.next       

        # merge two sorted linked lists [Problem 21]
        # merge 1->2->3->4 and 6->5->4 into 1->6->2->5->3->4
        first, second = head, prev
        while second.next:
            first.next, first = second, first.next
            second.next, second = first, second.next
```
```
```
```
```
144_BinaryTreePreorderTraversal

```
class Solution(object):
    def preorderTraversal(self, root):
        """
        :type root: TreeNode
        :rtype: List[int]
        """
        if root is None:
            return []
        
        stack, output = [root, ], []
        
        while stack:
            root = stack.pop()
            if root is not None:
                output.append(root.val)
                if root.right is not None:
                    stack.append(root.right)
                if root.left is not None:
                    stack.append(root.left)
        
        return output
```
```
class Solution(object):
    def preorderTraversal(self, root):
        """
        :type root: TreeNode
        :rtype: List[int]
        """
        node, output = root, []
        while node:  
            if not node.left: 
                output.append(node.val)
                node = node.right 
            else: 
                predecessor = node.left 

                while predecessor.right and predecessor.right is not node: 
                    predecessor = predecessor.right 

                if not predecessor.right:
                    output.append(node.val)
                    predecessor.right = node  
                    node = node.left  
                else:
                    predecessor.right = None
                    node = node.right         

        return output
```
```
```
145_BinaryTreePostorderTraversal
```
```
```
```
```
```
146_LRUCache
```
from collections import OrderedDict
class LRUCache(OrderedDict):

    def __init__(self, capacity):
        """
        :type capacity: int
        """
        self.capacity = capacity

    def get(self, key):
        """
        :type key: int
        :rtype: int
        """
        if key not in self:
            return - 1
        
        self.move_to_end(key)
        return self[key]

    def put(self, key, value):
        """
        :type key: int
        :type value: int
        :rtype: void
        """
        if key in self:
            self.move_to_end(key)
        self[key] = value
        if len(self) > self.capacity:
            self.popitem(last = False)

# Your LRUCache object will be instantiated and called as such:
# obj = LRUCache(capacity)
# param_1 = obj.get(key)
# obj.put(key,value)
```
```
class DLinkedNode(): 
    def __init__(self):
        self.key = 0
        self.value = 0
        self.prev = None
        self.next = None
            
class LRUCache():
    def _add_node(self, node):
        """
        Always add the new node right after head.
        """
        node.prev = self.head
        node.next = self.head.next

        self.head.next.prev = node
        self.head.next = node

    def _remove_node(self, node):
        """
        Remove an existing node from the linked list.
        """
        prev = node.prev
        new = node.next

        prev.next = new
        new.prev = prev

    def _move_to_head(self, node):
        """
        Move certain node in between to the head.
        """
        self._remove_node(node)
        self._add_node(node)

    def _pop_tail(self):
        """
        Pop the current tail.
        """
        res = self.tail.prev
        self._remove_node(res)
        return res

    def __init__(self, capacity):
        """
        :type capacity: int
        """
        self.cache = {}
        self.size = 0
        self.capacity = capacity
        self.head, self.tail = DLinkedNode(), DLinkedNode()

        self.head.next = self.tail
        self.tail.prev = self.head
        

    def get(self, key):
        """
        :type key: int
        :rtype: int
        """
        node = self.cache.get(key, None)
        if not node:
            return -1

        # move the accessed node to the head;
        self._move_to_head(node)

        return node.value

    def put(self, key, value):
        """
        :type key: int
        :type value: int
        :rtype: void
        """
        node = self.cache.get(key)

        if not node: 
            newNode = DLinkedNode()
            newNode.key = key
            newNode.value = value

            self.cache[key] = newNode
            self._add_node(newNode)

            self.size += 1

            if self.size > self.capacity:
                # pop the tail
                tail = self._pop_tail()
                del self.cache[tail.key]
                self.size -= 1
        else:
            # update the value.
            node.value = value
            self._move_to_head(node)
```
```
```
147_InsertionSortList

```
class Solution:
    def insertionSortList(self, head: ListNode) -> ListNode:
        dummy = ListNode()
        curr = head

        while curr:
            # At each iteration, we insert an element into the resulting list.
            prev = dummy

            # find the position to insert the current node
            while prev.next and prev.next.val <= curr.val:
                prev = prev.next

            next = curr.next
            # insert the current node to the new list
            curr.next = prev.next
            prev.next = curr

            # moving on to the next iteration
            curr = next

        return dummy.next
```
```
```
```
```
148_SortList

```

class Solution {
public:
    ListNode* sortList(ListNode* head) {
        if (!head || !head->next)
            return head;
        ListNode* mid = getMid(head);
        ListNode* left = sortList(head);
        ListNode* right = sortList(mid);
        return merge(left, right);
    }

    ListNode* merge(ListNode* list1, ListNode* list2) {
        ListNode dummyHead(0);
        ListNode* ptr = &dummyHead;
        while (list1 && list2) {
            if (list1->val < list2->val) {
                ptr->next = list1;
                list1 = list1->next;
            } else {
                ptr->next = list2;
                list2 = list2->next;
            }
            ptr = ptr->next;
        }
        if(list1) ptr->next = list1;
        else ptr->next = list2;

        return dummyHead.next;
    }

    ListNode* getMid(ListNode* head) {
        ListNode* midPrev = nullptr;
        while (head && head->next) {
            midPrev = (midPrev == nullptr) ? head : midPrev->next;
            head = head->next->next;
        }
        ListNode* mid = midPrev->next;
        midPrev->next = nullptr;
        return mid;
    }
};

```
```

class Solution {
public:
    ListNode* tail = new ListNode();
    ListNode* nextSubList = new ListNode();

    ListNode* sortList(ListNode* head) {
        if (!head || !head -> next)
            return head;
        int n = getCount(head);
        ListNode* start = head;
        ListNode dummyHead(0);
        for (int size = 1; size < n; size = size * 2) {
            tail = &dummyHead;
            while (start) {
                if (!start->next) {
                    tail->next = start;
                    break;
                }
                ListNode* mid = split(start, size);
                merge(start, mid);
                start = nextSubList;
            }
            start = dummyHead.next;
        }
        return dummyHead.next;
    }

    ListNode* split(ListNode* start, int size) {
        ListNode* midPrev = start;
        ListNode* end = start->next;
        //use fast and slow approach to find middle and end of second linked list
        for (int index = 1; index < size && (midPrev->next || end->next); index++) {
            if (end->next) {
                end = (end->next->next) ? end->next->next : end->next;
            }
            if (midPrev->next) {
                midPrev = midPrev->next;
            }
        }
        ListNode* mid = midPrev->next;
        nextSubList = end->next;
        midPrev->next = nullptr;
        end->next = nullptr;
        // return the start of second linked list
        return mid;
    }

    void merge(ListNode* list1, ListNode* list2) {
        ListNode dummyHead(0);
        ListNode* newTail = &dummyHead;
        while (list1 && list2) {
            if (list1->val < list2->val) {
                newTail->next = list1;
                list1 = list1->next;
                newTail = newTail->next;
            } else {
                newTail->next = list2;
                list2 = list2->next;
                newTail = newTail->next;
            }
        }
        newTail->next = (list1) ? list1 : list2;
        // traverse till the end of merged list to get the newTail
        while (newTail->next) {
            newTail = newTail->next;
        }
        // link the old tail with the head of merged list
        tail->next = dummyHead.next;
        // update the old tail with the new tail of merged list
        tail = newTail;
    }

    int getCount(ListNode* head) {
        int cnt = 0;
        ListNode* ptr = head;
        while (ptr) {
            ptr = ptr->next;
            cnt++;
        }
        return cnt;
    }
};

```
```
```
149_MaxPointsonaLine
```
class Solution(object):
    def maxPoints(self, points):
        """
        :type points: List[List[int]]
        :rtype: int
        """
        def max_points_on_a_line_containing_point_i(i):
            """
            Compute the max number of points
            for a line containing point i.
            """
            def slope_coprime(x1, y1, x2, y2):
                """ to avoid the precision issue with the float/double number,
                    using a pair of co-prime numbers to represent the slope.
                """
                delta_x, delta_y = x1 - x2, y1 - y2
                if delta_x == 0:    # vertical line
                    return (0, 0)
                elif delta_y == 0:  # horizontal line
                    return (sys.maxsize, sys.maxsize)
                elif delta_x < 0:
                    # to have a consistent representation,
                    #   keep the delta_x always positive.
                    delta_x, delta_y = - delta_x, - delta_y
                gcd = math.gcd(delta_x, delta_y)
                slope = (delta_x / gcd, delta_y / gcd)
                return slope


            def add_line(i, j, count, duplicates):
                """
                Add a line passing through i and j points.
                Update max number of points on a line containing point i.
                Update a number of duplicates of i point.
                """
                # rewrite points as coordinates
                x1 = points[i][0]
                y1 = points[i][1]
                x2 = points[j][0]
                y2 = points[j][1]
                # add a duplicate point
                if x1 == x2 and y1 == y2:  
                    duplicates += 1
                # add a horisontal line : y = const
                elif y1 == y2:
                    nonlocal horizontal_lines
                    horizontal_lines += 1
                    count = max(horizontal_lines, count)
                # add a line : x = slope * y + c
                # only slope is needed for a hash-map
                # since we always start from the same point
                else:
                    slope = slope_coprime(x1, y1, x2, y2)
                    lines[slope] = lines.get(slope, 1) + 1
                    count = max(lines[slope], count)
                return count, duplicates
            
            # init lines passing through point i
            lines, horizontal_lines = {}, 1
            # One starts with just one point on a line : point i.
            count = 1
            # There is no duplicates of a point i so far.
            duplicates = 0
            # Compute lines passing through point i (fixed)
            # and point j (interation).
            # Update in a loop the number of points on a line
            # and the number of duplicates of point i.
            for j in range(i + 1, n):
                count, duplicates = add_line(i, j, count, duplicates)
            return count + duplicates
            
        # If the number of points is less than 3
        # they are all on the same line.
        n = len(points)
        if n < 3:
            return n
        
        max_count = 1
        # Compute in a loop a max number of points 
        # on a line containing point i.
        for i in range(n - 1):
            max_count = max(max_points_on_a_line_containing_point_i(i), max_count)
        return max_count
```
```
```
```
```
150_EvaluateReversePolishNotation
```
class Solution:
    def evalRPN(self, tokens: List[str]) -> int:

            operations = {
                "+": lambda a, b: a + b,
                "-": lambda a, b: a - b,
                "/": lambda a, b: int(a / b),
                "*": lambda a, b: a * b
            }

            current_position = 0

            while len(tokens) > 1:

                # Move the current position pointer to the next operator.
                while tokens[current_position] not in "+-*/":
                    current_position += 1

                # Extract the operator and numbers from the list.
                operator = tokens[current_position]
                number_1 = int(tokens[current_position - 2])
                number_2 = int(tokens[current_position - 1])

                # Calculate the result to overwrite the operator with.
                operation = operations[operator]
                tokens[current_position] = operation(number_1, number_2)

                # Remove the numbers and move the pointer to the position
                # after the new number we just added.
                tokens.pop(current_position - 2)
                tokens.pop(current_position - 2)
                current_position -= 1

            return tokens[0]

```
```
def evalRPN(self, tokens: List[str]) -> int:

    current_position = 0

    while len(tokens) > 1:
        
        # Move the current position pointer to the next operator.
        while tokens[current_position] not in "+-*/":
            current_position += 1
    
        # Extract the operator and numbers from the list.
        operator = tokens[current_position]
        number_1 = int(tokens[current_position - 2])
        number_2 = int(tokens[current_position - 1])
        
        # Calculate the result to overwrite the operator with.
        if operator == "+":
            tokens[current_position] = number_1 + number_2
        elif operator == "-":
            tokens[current_position] = number_1 - number_2
        elif operator == "*":
            tokens[current_position] = number_1 * number_2
        else:
            tokens[current_position] = int(number_1 / number_2)
        
        # Remove the numbers and move the pointer to the position
        # after the new number we just added.
        tokens.pop(current_position - 2)
        tokens.pop(current_position - 2)
        current_position -= 1
        
    return tokens[0]
```
```
def evalRPN(self, tokens: List[str]) -> int:
        
    operations = {
        "+": lambda a, b: a + b,
        "-": lambda a, b: a - b,
        "/": lambda a, b: int(a / b),
        "*": lambda a, b: a * b
    }
    
    stack = []
    for token in tokens:
        if token in operations:
            number_2 = stack.pop()
            number_1 = stack.pop()
            operation = operations[token]
            stack.append(operation(number_1, number_2))
        else:
            stack.append(int(token))
    return stack.pop()
```
```
class Solution:
    def evalRPN(self, tokens):

        stack = []

        for token in tokens:

            if token not in "+-/*":
                stack.append(int(token))
                continue

            number_2 = stack.pop()
            number_1 = stack.pop()

            result = 0
            if token == "+":
                result = number_1 + number_2
            elif token == "-":
                result = number_1 - number_2
            elif token == "*":
                result = number_1 * number_2
            else:
                result = int(number_1 / number_2)

            stack.append(result)

        return stack.pop()
```



151_ReverseWordsinaString

```
class Solution:
    def reverseWords(self, s: str) -> str:
        return " ".join(reversed(s.split()))
```
```
class Solution {
  public:
  string reverseWords(string s) {
    // reverse the whole string
    reverse(s.begin(), s.end());

    int n = s.size();
    int idx = 0;
    for (int start = 0; start < n; ++start) {
      if (s[start] != ' ') {
        // go to the beginning of the word
        if (idx != 0) s[idx++] = ' ';

        // go to the end of the word
        int end = start;
        while (end < n && s[end] != ' ') s[idx++] = s[end++];

        // reverse the word
        reverse(s.begin() + idx - (end - start), s.begin() + idx);

        // move to the next word
        start = end;
      }
    }
    s.erase(s.begin() + idx, s.end());
    return s;
  }
};
```
```
from collections import deque
class Solution:
    def reverseWords(self, s: str) -> str:
        left, right = 0, len(s) - 1
        # remove leading spaces
        while left <= right and s[left] == ' ':
            left += 1
        
        # remove trailing spaces
        while left <= right and s[right] == ' ':
            right -= 1
            
        d, word = deque(), []
        # push word by word in front of deque
        while left <= right:
            if s[left] == ' ' and word:
                d.appendleft(''.join(word))
                word = []
            elif s[left] != ' ':
                word.append(s[left])
            left += 1
        d.appendleft(''.join(word))
        
        return ' '.join(d)
```
152_MaximumProductSubarray
```
class Solution:
    def maxProduct(self, nums: List[int]) -> int:
        if len(nums) == 0:
            return 0

        result = nums[0]

        for i in range(len(nums)):
            accu = 1
            for j in range(i, len(nums)):
                accu *= nums[j]
                result = max(result, accu)

        return result
```
```
class Solution:
    def maxProduct(self, nums: List[int]) -> int:
        if len(nums) == 0:
            return 0

        max_so_far = nums[0]
        min_so_far = nums[0]
        result = max_so_far

        for i in range(1, len(nums)):
            curr = nums[i]
            temp_max = max(curr, max_so_far * curr, min_so_far * curr)
            min_so_far = min(curr, max_so_far * curr, min_so_far * curr)

            max_so_far = temp_max

            result = max(max_so_far, result)

        return result
```
```
```
153_FindMinimuminRotatedSortedArray
```
class Solution:
    def findMin(self, nums: List[int]) -> int:
        # If the list has just one element then return that element.
        if len(nums) == 1:
            return nums[0]

        # left pointer
        left = 0
        # right pointer
        right = len(nums) - 1

        # if the last element is greater than the first element then there is no rotation.
        # e.g. 1 < 2 < 3 < 4 < 5 < 7. Already sorted array.
        # Hence the smallest element is first element. A[0]
        if nums[right] > nums[0]:
            return nums[0]

        # Binary search way
        while right >= left:
            # Find the mid element
            mid = left + (right - left) // 2
            # if the mid element is greater than its next element then mid+1 element is the smallest
            # This point would be the point of change. From higher to lower value.
            if nums[mid] > nums[mid + 1]:
                return nums[mid + 1]
            # if the mid element is lesser than its previous element then mid element is the smallest
            if nums[mid - 1] > nums[mid]:
                return nums[mid]

            # if the mid elements value is greater than the 0th element this means
            # the least value is still somewhere to the right as we are still dealing with elements greater than nums[0]
            if nums[mid] > nums[0]:
                left = mid + 1
            # if nums[0] is greater than the mid value then this means the smallest value is somewhere to the left
            else:
                right = mid - 1
```
```
```
```
```
154_FindMinimuminRotatedSortedArrayII
```
class Solution:
    def findMin(self, nums: List[int]) -> int:    
        low = 0
        high = len(nums)-1
        while high > low:
            pivot = low + (high - low) // 2
            # risk of overflow: pivot = (low + high) // 2
            # Case 1):
            if nums[pivot] < nums[high]:
                high = pivot 
                # alternative: high = pivot - 1
                # too aggressive to move the `high` index,
                # it won't work for the test case of [3, 1, 3]
            # Case 2):
            elif nums[pivot] > nums[high]:
                low = pivot + 1
            # Case 3):
            else:
                high -= 1
        # the 'low' and 'high' index converge to the inflection point.
        return nums[low]
```
```
```
```
```
155_MinStack
```
class MinStack:

    def __init__(self):
        self.stack = []
        

    def push(self, x: int) -> None:
        
        # If the stack is empty, then the min value
        # must just be the first value we add
        if not self.stack:
            self.stack.append((x, x))
            return

        current_min = self.stack[-1][1]
        self.stack.append((x, min(x, current_min)))
        
        
    def pop(self) -> None:
        self.stack.pop()
        

    def top(self) -> int:
        return self.stack[-1][0]
        

    def getMin(self) -> int:
        return self.stack[-1][1]
```
```
class MinStack:

    def __init__(self):
        self.stack = []
        self.min_stack = []        
        

    def push(self, x: int) -> None:
        self.stack.append(x)
        if not self.min_stack or x <= self.min_stack[-1]:
            self.min_stack.append(x)
    
    def pop(self) -> None:
        if self.min_stack[-1] == self.stack[-1]:
            self.min_stack.pop()
        self.stack.pop()

    def top(self) -> int:
        return self.stack[-1]

    def getMin(self) -> int:
        return self.min_stack[-1]
```
```
class MinStack:

    def __init__(self):
        self.stack = []
        self.min_stack = []        
        

    def push(self, x: int) -> None:
        
        # We always put the number onto the main stack.
        self.stack.append(x)
        
        # If the min stack is empty, or this number is smaller than
        # the top of the min stack, put it on with a count of 1.
        if not self.min_stack or x < self.min_stack[-1][0]:
            self.min_stack.append([x, 1])
            
        # Else if this number is equal to what's currently at the top
        # of the min stack, then increment the count at the top by 1.
        elif x == self.min_stack[-1][0]:
            self.min_stack[-1][1] += 1

    
    def pop(self) -> None:

        # If the top of min stack is the same as the top of stack
        # then we need to decrement the count at the top by 1.
        if self.min_stack[-1][0] == self.stack[-1]:
            self.min_stack[-1][1] -= 1
            
        # If the count at the top of min stack is now 0, then remove
        # that value as we're done with it.
        if self.min_stack[-1][1] == 0:
            self.min_stack.pop()
            
        # And like before, pop the top of the main stack.
        self.stack.pop()


    def top(self) -> int:
        return self.stack[-1]


    def getMin(self) -> int:
        return self.min_stack[-1][0]   
```
156_BinaryTreeUpsideDown
```
class Solution:
    def upsideDownBinaryTree(self, root):
        if not root or not root.left:
            return root
        lRoot = self.upsideDownBinaryTree(root.left)
        rMost = lRoot
        while rMost.right:
            rMost = rMost.right
        root, rMost.left, rMost.right = lRoot, root.right, TreeNode(root.val)
        return root
```
```
```
```
```
157_ReadNCharactersGivenRead4
```
class Solution:
    def read(self, buf: List[str], n: int) -> int:
        copied_chars = 0
        read_chars = 4
        buf4 = [''] * 4
        
        while copied_chars < n and read_chars == 4:
            read_chars = read4(buf4)
            
            for i in range(read_chars):
                if copied_chars == n:
                    return copied_chars
                buf[copied_chars] = buf4[i]
                copied_chars += 1
        
        return copied_chars
```
```
class Solution {
public:
    int read(char *buf, int n) {
        int copiedChars = 0;
        int readChars = 4;
        int remainingChars = n;
        
        // While there are at least 4 characters remaining to be read and the last
        // call to readChars returned 4 characters, write directly to buf.
        while (remainingChars >= 4 && readChars == 4) {
            readChars = read4(buf + copiedChars);
            copiedChars += readChars;
        }
        
        // If there are between 1 and 3 characters that we still want to read and
        // readChars was not 0 last time we called read4, then create a buffer
        // for just this one call so we can ensure buf does not overflow.
        if (remainingChars && readChars) {
            char buf4[4];
            readChars = read4(buf4);
            for (int i = 0; i < min(remainingChars, readChars); i++) {
                buf[copiedChars++] = buf4[i];
            }
        }
        
        return min(n, copiedChars);
    }
};
```
```
```
158_ReadNCharactersGivenread4II-CallMultipleTimes
```
```
```
```
```
```
159_LongestSubstringwithAtMostTwoDistinctCharacters
```
class Solution {
public:
    int lengthOfLongestSubstringTwoDistinct(string s) {
        size_t n = s.length();
        if (n < 3) {
            return n;
        }

        // sliding window left and right pointers
        int left = 0, right = 0;
        // hashmap character -> its rightmost position
        // in the sliding window
        map<char, int> hashmap;

        int max_len = 2;

        while (right < n) {
            // when the sliding window contains less than 3 characters
            hashmap[s[right]] = right;
            right++;

            // slidewindow contains 3 characters
            if (hashmap.size() == 3) {
                int del_idx = INT_MAX;
                for (pair<char, int> element : hashmap) {
                    del_idx = min(del_idx, element.second);
                }
                // delete the leftmost character
                hashmap.erase(s[del_idx]);
                left = del_idx + 1;
            }
            max_len = max(max_len, right - left);
        }
        return max_len;
    }
};
```
```
```
```
```
160_IntersectionofTwoLinkedLists
```
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        while (headA != nullptr) {
            ListNode *pB = headB;
            while (pB != nullptr) {
                if (headA == pB) return headA;
                pB = pB->next;
            }
            headA = headA->next;
        }
        return nullptr;
    }
};
```
```
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        set<ListNode *> nodes_in_B;

        while (headB != nullptr) {
            nodes_in_B.insert(headB);
            headB = headB->next;
        }

        while (headA != nullptr) {
            // if we find the node pointed to by headA,
            // in our set containing nodes of B, then return the node
            if (nodes_in_B.find(headA) != nodes_in_B.end()) {
                return headA;
            }
            headA = headA->next;
        }

        return nullptr;
    }
};
```
```
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *pA = headA;
        ListNode *pB = headB;
        while (pA != pB) {
            pA = pA == nullptr ? headB : pA->next;
            pB = pB == nullptr ? headA : pB->next;
        }
        return pA;
        // Note: In the case lists do not intersect, the pointers for A and B
        // will still line up in the 2nd iteration, just that here won't be
        // a common node down the list and both will reach their respective ends
        // at the same time. So pA will be NULL in that case.
    }
};
```
161_OneEditDistance
```
class Solution:
    def isOneEditDistance(self, s: 'str', t: 'str') -> 'bool':
        ns, nt = len(s), len(t)

        # Ensure that s is shorter than t.
        if ns > nt:
            return self.isOneEditDistance(t, s)

        # The strings are NOT one edit away distance  
        # if the length diff is more than 1.
        if nt - ns > 1:
            return False

        for i in range(ns):
            if s[i] != t[i]:
                # if strings have the same length
                if ns == nt:
                    return s[i + 1:] == t[i + 1:]
                # if strings have different lengths
                else:
                    return s[i:] == t[i + 1:]
        
        # If there is no diffs on ns distance
        # the strings are one edit away only if
        # t has one more character. 
        return ns + 1 == nt
```
```
```
```
```
162_FindPeakElement
```
public class Solution {
    public int findPeakElement(int[] nums) {
        for (int i = 0; i < nums.length - 1; i++) {
            if (nums[i] > nums[i + 1])
                return i;
        }
        return nums.length - 1;
    }
}
```
```
public class Solution {
    public int findPeakElement(int[] nums) {
        return search(nums, 0, nums.length - 1);
    }
    public int search(int[] nums, int l, int r) {
        if (l == r)
            return l;
        int mid = (l + r) / 2;
        if (nums[mid] > nums[mid + 1])
            return search(nums, l, mid);
        return search(nums, mid + 1, r);
    }
}
```
```
public class Solution {
    public int findPeakElement(int[] nums) {
        int l = 0, r = nums.length - 1;
        while (l < r) {
            int mid = (l + r) / 2;
            if (nums[mid] > nums[mid + 1])
                r = mid;
            else
                l = mid + 1;
        }
        return l;
    }
}
```
163_MissingRanges
```
class Solution {
public:
    vector<string> findMissingRanges(vector<int>& nums, int lower, int upper) {
        vector<string> result;
        int prev = lower - 1;
        for (size_t i = 0; i <= nums.size(); i++) {
            int curr = (i < nums.size()) ? nums[i] : upper + 1;
            if (prev + 1 <= curr - 1) {
                result.push_back(formatRange(prev + 1, curr - 1));
            }
            prev = curr;
        }
        return result;
    }

    // formats range in the requested format
    string formatRange(int lower, int upper) {
        if (lower == upper) {
            return to_string(lower);
        }
        return to_string(lower) + "->" + to_string(upper);
    }
};
```
```
```
```
```
164_MaximumGap
```
class Solution{
public:
int maximumGap(vector<int>& nums)
{
    if (nums.empty() || nums.size() < 2)            // check if array is empty or small sized
        return 0;

    sort(nums.begin(), nums.end());                 // sort the array

    int maxGap = 0;

    for (int i = 0; i < nums.size() - 1; i++)
        maxGap = max(nums[i + 1] - nums[i], maxGap);

    return maxGap;
}
};
```
```
int maximumGap(vector<int>& nums)
{
    if (nums.empty() || nums.size() < 2)
        return 0;

    int maxVal = *max_element(nums.begin(), nums.end());

    int exp = 1;                                 // 1, 10, 100, 1000 ...
    int radix = 10;                              // base 10 system

    vector<int> aux(nums.size());

    /* LSD Radix Sort */
    while (maxVal / exp > 0) {                   // Go through all digits from LSD to MSD
        vector<int> count(radix, 0);

        for (int i = 0; i < nums.size(); i++)    // Counting sort
            count[(nums[i] / exp) % 10]++;

        for (int i = 1; i < count.size(); i++)   // you could also use partial_sum()
            count[i] += count[i - 1];

        for (int i = nums.size() - 1; i >= 0; i--)
            aux[--count[(nums[i] / exp) % 10]] = nums[i];

        for (int i = 0; i < nums.size(); i++)
            nums[i] = aux[i];

        exp *= 10;
    }

    int maxGap = 0;

    for (int i = 0; i < nums.size() - 1; i++)
        maxGap = max(nums[i + 1] - nums[i], maxGap);

    return maxGap;
}
```
```
class Bucket {
public:
    bool used = false;
    int minval = numeric_limits<int>::max();        // same as INT_MAX
    int maxval = numeric_limits<int>::min();        // same as INT_MIN
};

int maximumGap(vector<int>& nums)
{
    if (nums.empty() || nums.size() < 2)
        return 0;

    int mini = *min_element(nums.begin(), nums.end()),
        maxi = *max_element(nums.begin(), nums.end());

    int bucketSize = max(1, (maxi - mini) / ((int)nums.size() - 1));        // bucket size or capacity
    int bucketNum = (maxi - mini) / bucketSize + 1;                         // number of buckets
    vector<Bucket> buckets(bucketNum);

    for (auto&& num : nums) {
        int bucketIdx = (num - mini) / bucketSize;                          // locating correct bucket
        buckets[bucketIdx].used = true;
        buckets[bucketIdx].minval = min(num, buckets[bucketIdx].minval);
        buckets[bucketIdx].maxval = max(num, buckets[bucketIdx].maxval);
    }

    int prevBucketMax = mini, maxGap = 0;
    for (auto&& bucket : buckets) {
        if (!bucket.used)
            continue;

        maxGap = max(maxGap, bucket.minval - prevBucketMax);
        prevBucketMax = bucket.maxval;
    }

    return maxGap;
}
```
165_CompareVersionNumbers
```
class Solution:
    def compareVersion(self, version1: str, version2: str) -> int:
        nums1 = version1.split('.')
        nums2 = version2.split('.')
        n1, n2 = len(nums1), len(nums2)
        
        # compare versions
        for i in range(max(n1, n2)):
            i1 = int(nums1[i]) if i < n1 else 0
            i2 = int(nums2[i]) if i < n2 else 0
            if i1 != i2:
                return 1 if i1 > i2 else -1
        
        # the versions are equal
        return 0 
```
```
class Solution:
    def get_next_chunk(self, version: str, n: int, p: int) -> List[int]:
        # if pointer is set to the end of string
        # return 0
        if p > n - 1:
            return 0, p
        
        # find the end of chunk
        p_end = p
        while p_end < n and version[p_end] != '.':
            p_end += 1
        # retrieve the chunk
        i = int(version[p:p_end]) if p_end != n - 1 else int(version[p:n])
        # find the beginning of next chunk
        p = p_end + 1
        
        return i, p
        
    def compareVersion(self, version1: str, version2: str) -> int:
        p1 = p2 = 0
        n1, n2 = len(version1), len(version2)
        
        # compare versions
        while p1 < n1 or p2 < n2:
            i1, p1 = self.get_next_chunk(version1, n1, p1)
            i2, p2 = self.get_next_chunk(version2, n2, p2)            
            if i1 != i2:
                return 1 if i1 > i2 else -1
        
        # the versions are equal
        return 0    
```
```
```
166_FractiontoRecurringDecimal

```
class Solution {
public String fractionToDecimal(int numerator, int denominator) {
    if (numerator == 0) {
        return "0";
    }
    StringBuilder fraction = new StringBuilder();
    // If either one is negative (not both)
    if (numerator < 0 ^ denominator < 0) {
        fraction.append("-");
    }
    // Convert to Long or else abs(-2147483648) overflows
    long dividend = Math.abs(Long.valueOf(numerator));
    long divisor = Math.abs(Long.valueOf(denominator));
    fraction.append(String.valueOf(dividend / divisor));
    long remainder = dividend % divisor;
    if (remainder == 0) {
        return fraction.toString();
    }
    fraction.append(".");
    Map<Long, Integer> map = new HashMap<>();
    while (remainder != 0) {
        if (map.containsKey(remainder)) {
            fraction.insert(map.get(remainder), "(");
            fraction.append(")");
            break;
        }
        map.put(remainder, fraction.length());
        remainder *= 10;
        fraction.append(String.valueOf(remainder / divisor));
        remainder %= divisor;
    }
    return fraction.toString();
}
}
```
```
```
```
```
167_TwoSumII-InputArrayIsSorted

```
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int low = 0;
        int high = numbers.size() - 1;
        while (low < high) {
            int sum = numbers[low] + numbers[high];
                          
            if (sum == target) {
                return {low + 1, high + 1};
            } else if (sum < target) {
                ++low;
            } else {
                --high;
            }
        }
        // In case there is no solution, return {-1, -1}.
        return {-1, -1};
    }
};
```
```
```
```
```
168_ExcelSheetColumnTitle
```
class Solution:
    # @return a string
    def convertToTitle(self, num):
        capitals = [chr(x) for x in range(ord('A'), ord('Z')+1)]
        result = []
        while num > 0:
            result.append(capitals[(num-1)%26])
            num = (num-1) // 26
        result.reverse()
        return ''.join(result)
```
```
```
```
```
169_MajorityElement
```
class Solution:
    def majorityElement(self, nums):
        majority_count = len(nums)//2
        for num in nums:
            count = sum(1 for elem in nums if elem == num)
            if count > majority_count:
                return num
```
```
class Solution:
    def majorityElement(self, nums):
        counts = collections.Counter(nums)
        return max(counts.keys(), key=counts.get)
```
```
class Solution:
    def majorityElement(self, nums):
        nums.sort()
        return nums[len(nums)//2]
```
```
class Solution:
    def majorityElement(self, nums: List[int]) -> int:
        n = len(nums)
        majority_element = 0
        
        bit = 1
        for i in range(31):
            # Count how many numbers have the current bit set.
            bit_count = sum(bool(num & bit) for num in nums)

            # If this bit is present in more than n / 2 elements
            # then it must be set in the majority element.
            if bit_count > n // 2:
                majority_element += bit
            
            # Shift bit to the left one space. i.e. '00100' << 1 = '01000'
            bit = bit << 1
                
        # In python 1 << 31 will automatically be considered as positive value
        # so we will count how many numbers are negative to determine if
        # the majority element is negative.
        is_negative = sum(num < 0 for num in nums) > (n // 2)

        # When evaluating a 32-bit signed integer, the values of the 1st through 
        # 31st bits are added to the total while the value of the 32nd bit is 
        # subtracted from the total. This is because the 32nd bit is responsible 
        # for signifying if the number is positive or negative.
        if is_negative:
            majority_element -= bit
        
        return majority_element
```

```
import random

class Solution:
    def majorityElement(self, nums):
        majority_count = len(nums)//2
        while True:
            candidate = random.choice(nums)
            if sum(1 for elem in nums if elem == candidate) > majority_count:
                return candidate
```

```
class Solution:
    def majorityElement(self, nums, lo=0, hi=None):
        def majority_element_rec(lo, hi):
            # base case; the only element in an array of size 1 is the majority
            # element.
            if lo == hi:
                return nums[lo]

            # recurse on left and right halves of this slice.
            mid = (hi-lo)//2 + lo
            left = majority_element_rec(lo, mid)
            right = majority_element_rec(mid+1, hi)

            # if the two halves agree on the majority element, return it.
            if left == right:
                return left

            # otherwise, count each element and return the "winner".
            left_count = sum(1 for i in range(lo, hi+1) if nums[i] == left)
            right_count = sum(1 for i in range(lo, hi+1) if nums[i] == right)

            return left if left_count > right_count else right

        return majority_element_rec(0, len(nums)-1)

```

```
class Solution:
    def majorityElement(self, nums):
        count = 0
        candidate = None

        for num in nums:
            if count == 0:
                candidate = num
            count += (1 if num == candidate else -1)

        return candidate
```



170_TwoSumIII-Datastructuredesign

```
class TwoSum(object):

    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.nums = []
        self.is_sorted = False


    def add(self, number):
        """
        Add the number to an internal data structure..
        :type number: int
        :rtype: None
        """
        # Inserting while maintaining the ascending order.
        # for index, num in enumerate(self.nums):
        #     if number <= num:
        #         self.nums.insert(index, number)
        #         return
        # larger than any number
        #self.nums.append(number)

        self.nums.append(number)
        self.is_sorted = False
    

    def find(self, value):
        """
        Find if there exists any pair of numbers which sum is equal to the value.
        :type value: int
        :rtype: bool
        """
        if not self.is_sorted:
            self.nums.sort()
            self.is_sorted = True

        low, high = 0, len(self.nums)-1
        while low < high:
            currSum = self.nums[low] + self.nums[high]
            if currSum < value:
                low += 1
            elif currSum > value:
                high -= 1
            else: # currSum == value
                return True
        
        return False

```
```
class TwoSum(object):

    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.num_counts = {}


    def add(self, number):
        """
        Add the number to an internal data structure..
        :type number: int
        :rtype: None
        """
        if number in self.num_counts:
            self.num_counts[number] += 1
        else:
            self.num_counts[number] = 1

    def find(self, value):
        """
        Find if there exists any pair of numbers which sum is equal to the value.
        :type value: int
        :rtype: bool
        """
        for num in self.num_counts.keys():
            comple = value - num
            if num != comple:
                if comple in self.num_counts:
                    return True
            elif self.num_counts[num] > 1:
                return True
        
        return False

```
```
```
171_ExcelSheetColumnNumber

```
class Solution:
    def titleToNumber(self, s: str) -> int:
        result = 0
        
        # Decimal 65 in ASCII corresponds to char 'A'
        alpha_map = {chr(i + 65): i + 1 for i in range(26)}

        n = len(s)
        for i in range(n):
            cur_char = s[n - 1 - i]
            result += (alpha_map[cur_char] * (26 ** i))
        return result
```
```
class Solution:
    def titleToNumber(self, s: str) -> int:
        result = 0
        n = len(s)
        for i in range(n):
            result = result * 26
            result += (ord(s[i]) - ord('A') + 1)
        return result
```
```
```
172_FactorialTrailingZeroes

```
class Solution:    
    def trailingZeroes(self, n: int) -> int:

        # Calculate n!
        n_factorial = 1
        for i in range(2, n + 1):
            n_factorial *= i

        # Count how many 0's are on the end.
        zero_count = 0
        while n_factorial % 10 == 0:
            zero_count += 1
            n_factorial //= 10

        return zero_count
```
```
class Solution:
    def trailingZeroes(self, n: int) -> int:

        zero_count = 0
        for i in range(5, n + 1, 5):
            current = i
            while current % 5 == 0:
                zero_count += 1
                current //= 5

        return zero_count
```
```
class Solution:
    def trailingZeroes(self, n: int) -> int:

        zero_count = 0
        for i in range(5, n + 1, 5):
            power_of_5 = 5
            while i % power_of_5 == 0:
                zero_count += 1
                power_of_5 *= 5

        return zero_count
```
```
class Solution:    
    def trailingZeroes(self, n: int) -> int:
        zero_count = 0
        current_multiple = 5
        while n >= current_multiple:
            zero_count += n // current_multiple
            current_multiple *= 5
        return zero_count
```

```
class Solution:    
    def trailingZeroes(self, n: int) -> int:
        zero_count = 0
        while n > 0:
            n //= 5
            zero_count += n
        return zero_count
```



173_BinarySearchTreeIterator

```
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class BSTIterator:

    def __init__(self, root: TreeNode):

        # Array containing all the nodes in the sorted order
        self.nodes_sorted = []

        # Pointer to the next smallest element in the BST
        self.index = -1

        # Call to flatten the input binary search tree
        self._inorder(root)

    def _inorder(self, root):
        if not root:
            return
        self._inorder(root.left)
        self.nodes_sorted.append(root.val)
        self._inorder(root.right)

    def next(self) -> int:
        """
        @return the next smallest number
        """
        self.index += 1
        return self.nodes_sorted[self.index]

    def hasNext(self) -> bool:
        """
        @return whether we have a next smallest number
        """
        return self.index + 1 < len(self.nodes_sorted)
```
```
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class BSTIterator:

    def __init__(self, root: TreeNode):

        # Stack for the recursion simulation
        self.stack = []

        # Remember that the algorithm starts with a call to the helper function
        # with the root node as the input
        self._leftmost_inorder(root)

    def _leftmost_inorder(self, root):

        # For a given node, add all the elements in the leftmost branch of the tree
        # under it to the stack.
        while root:
            self.stack.append(root)
            root = root.left

    def next(self) -> int:
        """
        @return the next smallest number
        """

        # Node at the top of the stack is the next smallest element
        topmost_node = self.stack.pop()

        # Need to maintain the invariant. If the node has a right child, call the
        # helper function for the right child
        if topmost_node.right:
            self._leftmost_inorder(topmost_node.right)
        return topmost_node.val

    def hasNext(self) -> bool:
        """
        @return whether we have a next smallest number
        """
        return len(self.stack) > 0
```
```
```
174_DungeonGame
```
class Solution(object):
    def calculateMinimumHP(self, dungeon):
        """
        :type dungeon: List[List[int]]
        :rtype: int
        """
        rows, cols = len(dungeon), len(dungeon[0])
        dp = [[float('inf')] * cols for _ in range(rows)]

        def get_min_health(currCell, nextRow, nextCol):
            if nextRow >= rows or nextCol >= cols:
                return float('inf')
            nextCell = dp[nextRow][nextCol]
            # hero needs at least 1 point to survive
            return max(1, nextCell - currCell)

        for row in reversed(range(rows)):
            for col in reversed(range(cols)):
                currCell = dungeon[row][col]

                right_health = get_min_health(currCell, row, col+1)
                down_health = get_min_health(currCell, row+1, col)
                next_health = min(right_health, down_health)

                if next_health != float('inf'):
                    min_health = next_health
                else:
                    min_health = 1 if currCell >= 0 else (1 - currCell)

                dp[row][col] = min_health

        return dp[0][0]
```
```
class MyCircularQueue:
    def __init__(self, capacity):
        """
        Set the size of the queue to be k.
        """
        self.queue = [0]*capacity
        self.tailIndex = 0
        self.capacity = capacity

    def enQueue(self, value):
        """
        Insert an element into the circular queue.
        """
        self.queue[self.tailIndex] = value
        self.tailIndex = (self.tailIndex + 1) % self.capacity

    def get(self, index):
        return self.queue[index % self.capacity]


class Solution(object):
    def calculateMinimumHP(self, dungeon):
        """
        :type dungeon: List[List[int]]
        :rtype: int
        """
        rows, cols = len(dungeon), len(dungeon[0])
        # Use a circular queue to keep a sliding window of DP values
        dp = MyCircularQueue(cols)

        def get_min_health(currCell, nextRow, nextCol):
            if nextRow < 0 or nextCol < 0:
                return float('inf')
            index = cols * nextRow + nextCol
            nextCell = dp.get(index)
            # hero needs at least 1 point to survive
            return max(1, nextCell - currCell)

        for row in range(rows):
            for col in range(cols):
                # iterate the grid in the reversed order
                currCell = dungeon[rows-row-1][cols-col-1]

                right_health = get_min_health(currCell, row, col-1)
                down_health = get_min_health(currCell, row-1, col)
                next_health = min(right_health, down_health)

                if next_health != float('inf'):
                    min_health = next_health
                else:
                    min_health = 1 if currCell >= 0 else (1 - currCell)

                dp.enQueue(min_health)
        # return the last element in the queue
        return dp.get(cols-1)
```
```
```
175_CombineTwoTables
```
select FirstName, LastName, City, State
from Person left join Address
on Person.PersonId = Address.PersonId
;
```
```
```
```
```
176_SecondHighestSalary
```
SELECT DISTINCT
    Salary AS SecondHighestSalary
FROM
    Employee
ORDER BY Salary DESC
LIMIT 1 OFFSET 1
```
```
SELECT
    (SELECT DISTINCT
            Salary
        FROM
            Employee
        ORDER BY Salary DESC
        LIMIT 1 OFFSET 1) AS SecondHighestSalary
;
```
```
SELECT
    IFNULL(
      (SELECT DISTINCT Salary
       FROM Employee
       ORDER BY Salary DESC
        LIMIT 1 OFFSET 1),
    NULL) AS SecondHighestSalary
```
177_NthHighestSalary
```
CREATE FUNCTION getNthHighestSalary(N INT) RETURNS INT
BEGIN
DECLARE M INT;
SET M=N-1;
  RETURN (
      # Write your MySQL query statement below.
      SELECT DISTINCT Salary FROM Employee ORDER BY Salary DESC LIMIT M, 1
  );
END
```
```
```
```
```
178_RankScores
```
SELECT
  S.score,
  DENSE_RANK() OVER (
    ORDER BY
      S.score DESC
  ) AS 'rank'
FROM
  Scores S;
```
```
```
```
```
179_LargestNumber
```
class LargerNumKey(str):
    def __lt__(x, y):
        return x+y > y+x
        
class Solution:
    def largestNumber(self, nums):
        largest_num = ''.join(sorted(map(str, nums), key=LargerNumKey))
        return '0' if largest_num[0] == '0' else largest_num
```
```
```
```
```
180_ConsecutiveNumbers
```
# Write your MySQL query statement below
SELECT DISTINCT
    l1.Num AS ConsecutiveNums
FROM
    Logs l1,
    Logs l2,
    Logs l3
WHERE
    l1.Id = l2.Id - 1
    AND l2.Id = l3.Id - 1
    AND l1.Num = l2.Num
    AND l2.Num = l3.Num
;
```
```
```
```
```
181_EmployeesEarningMoreThanTheirManagers
```
SELECT
    a.Name AS 'Employee'
FROM
    Employee AS a,
    Employee AS b
WHERE
    a.ManagerId = b.Id
        AND a.Salary > b.Salary
;
```
```
```
```
```
182_DuplicateEmails
```
select Email from
(
  select Email, count(Email) as num
  from Person
  group by Email
) as statistic
where num > 1
;
```
```
```
```
```
183_CustomersWhoNeverOrder
```
select customers.name as 'Customers'
from customers
where customers.id not in
(
    select customerid from orders
);
```
```
```
```
```
184_DepartmentHighestSalary
```
SELECT
    Department.name AS 'Department',
    Employee.name AS 'Employee',
    Salary
FROM
    Employee
        JOIN
    Department ON Employee.DepartmentId = Department.Id
WHERE
    (Employee.DepartmentId , Salary) IN
    (   SELECT
            DepartmentId, MAX(Salary)
        FROM
            Employee
        GROUP BY DepartmentId
    )
;
```
```
```
```
```
185_DepartmentTopThreeSalaries
```
select e1.Name as 'Employee', e1.Salary
from Employee e1
where 3 >
(
    select count(distinct e2.Salary)
    from Employee e2
    where e2.Salary > e1.Salary
)
;SELECT
    d.Name AS 'Department', e1.Name AS 'Employee', e1.Salary
FROM
    Employee e1
        JOIN
    Department d ON e1.DepartmentId = d.Id
WHERE
    3 > (SELECT
            COUNT(DISTINCT e2.Salary)
        FROM
            Employee e2
        WHERE
            e2.Salary > e1.Salary
                AND e1.DepartmentId = e2.DepartmentId
        )
;
```
```
```
```
```
186_ReverseWordsinaStringII
```
class Solution {
public:

    // Summary: Reverse entire string. Then reverse each word within the string.
    void reverseWords(vector<char>& s) {
        reverse(s.begin(), s.end());

        // 'start' points to the beginning of the current word
        // 'end' points to the position just after the current word
        int start = 0, end = 0;
        int n = s.size();

        while (start < n) {

            // Move 'right' to the position just after the current word
            while (end < n && s[end] != ' ')
                end++;

            // Note: in C++, reverse() operates on [start, end)
            // In other words, the leftmost element is included, while the rightmost element is not
            reverse(s.begin() + start, s.begin() + end);

            // Move 'start' and 'end' to the beginning of the next word
            end++;
            start = end;
        }
    }
};
```
```
```
```
```
187_RepeatedDNASequences
```
class Solution:
    def findRepeatedDnaSequences(self, s: str) -> List[str]:
        L, n = 10, len(s)     
        seen, output = set(), set()

        # iterate over all sequences of length L
        for start in range(n - L + 1):
            tmp = s[start:start + L]
            if tmp in seen:
                output.add(tmp[:])
            seen.add(tmp)
        return output
```
```
class Solution:
    def findRepeatedDnaSequences(self, s: str) -> List[str]:
        L, n = 10, len(s)
        if n <= L:
            return []
        
        # rolling hash parameters: base a
        a = 4
        aL = pow(a, L) 
        
        # convert string to array of integers
        to_int = {'A': 0, 'C': 1, 'G': 2, 'T': 3}
        nums = [to_int.get(s[i]) for i in range(n)]
        
        h = 0
        seen, output = set(), set()
        # iterate over all sequences of length L
        for start in range(n - L + 1):
            # compute hash of the current sequence in O(1) time
            if start != 0:
                h = h * a - nums[start - 1] * aL + nums[start + L - 1]
            # compute hash of the first sequence in O(L) time
            else:
                for i in range(L):
                    h = h * a + nums[i]
            # update output and hashset of seen sequences
            if h in seen:
                output.add(s[start:start + L])
            seen.add(h)
        return output
```
```
class Solution:
    def findRepeatedDnaSequences(self, s: str) -> List[str]:
        L, n = 10, len(s)
        if n <= L:
            return []
        
        # convert string to the array of 2-bits integers:
        # 00_2, 01_2, 10_2 or 11_2
        to_int = {'A': 0, 'C': 1, 'G': 2, 'T': 3}
        nums = [to_int.get(s[i]) for i in range(n)]
        
        bitmask = 0
        seen, output = set(), set()
        # iterate over all sequences of length L
        for start in range(n - L + 1):
            # compute bitmask of the sequence in O(1) time
            if start != 0:
                # left shift to free the last 2 bit
                bitmask <<= 2
                # add a new 2-bits number in the last two bits
                bitmask |= nums[start + L - 1]
                # unset first two bits: 2L-bit and (2L + 1)-bit
                bitmask &= ~(3 << 2 * L)
            # compute bitmask of the first sequence in O(L) time
            else:
                for i in range(L):
                    bitmask <<= 2
                    bitmask |= nums[i]
            if bitmask in seen:
                output.add(s[start:start + L])
            seen.add(bitmask)
        return output
```
188_BestTimetoBuyandSellStockIV
```
class Solution:
    def maxProfit(self, k: int, prices: List[int]) -> int:
        n = len(prices)

        # solve special cases
        if not prices or k==0:
            return 0

        if 2*k > n:
            res = 0
            for i, j in zip(prices[1:], prices[:-1]):
                res += max(0, i - j)
            return res

        # dp[i][used_k][ishold] = balance
        # ishold: 0 nothold, 1 hold
        dp = [[[-math.inf]*2 for _ in range(k+1)] for _ in range(n)]

        # set starting value
        dp[0][0][0] = 0
        dp[0][1][1] = -prices[0]

        # fill the array
        for i in range(1, n):
            for j in range(k+1):
                # transition equation
                dp[i][j][0] = max(dp[i-1][j][0], dp[i-1][j][1]+prices[i])
                # you can't hold stock without any transaction
                if j > 0:
                    dp[i][j][1] = max(dp[i-1][j][1], dp[i-1][j-1][0]-prices[i])

        res = max(dp[n-1][j][0] for j in range(k+1))
        return res
```
```
class Solution:
    def maxProfit(self, k: int, prices) -> int:
        n = len(prices)

        # solve special cases
        if not prices or k == 0:
            return 0

        # find all consecutively increasing subsequence
        transactions = []
        start = 0
        end = 0
        for i in range(1, n):
            if prices[i] >= prices[i-1]:
                end = i
            else:
                if end > start:
                    transactions.append([start, end])
                start = i
        if end > start:
            transactions.append([start, end])

        while len(transactions) > k:
            # check delete loss
            delete_index = 0
            min_delete_loss = math.inf
            for i in range(len(transactions)):
                t = transactions[i]
                profit_loss = prices[t[1]] - prices[t[0]]
                if profit_loss < min_delete_loss:
                    min_delete_loss = profit_loss
                    delete_index = i

            # check merge loss
            merge_index = 0
            min_merge_loss = math.inf
            for i in range(1, len(transactions)):
                t1 = transactions[i-1]
                t2 = transactions[i]
                profit_loss = prices[t1[1]] - prices[t2[0]]
                if profit_loss < min_merge_loss:
                    min_merge_loss = profit_loss
                    merge_index = i

            # delete or merge
            if min_delete_loss <= min_merge_loss:
                transactions.pop(delete_index)
            else:
                transactions[merge_index - 1][1] = transactions[merge_index][1]
                transactions.pop(merge_index)

        return sum(prices[j]-prices[i] for i, j in transactions)
```
```
```
189_RotateArray
```
class Solution:
    def rotate(self, nums: List[int], k: int) -> None:
        # speed up the rotation
        k %= len(nums)

        for i in range(k):
            previous = nums[-1]
            for j in range(len(nums)):
                nums[j], previous = previous, nums[j]
```
```
class Solution:
    def rotate(self, nums: List[int], k: int) -> None:
        n = len(nums)
        a = [0] * n
        for i in range(n):
            a[(i + k) % n] = nums[i]
            
        nums[:] = a
```
```
class Solution:
    def rotate(self, nums: List[int], k: int) -> None:
        n = len(nums)
        k %= n
        
        start = count = 0
        while count < n:
            current, prev = start, nums[start]
            while True:
                next_idx = (current + k) % n
                nums[next_idx], prev = prev, nums[next_idx]
                current = next_idx
                count += 1
                
                if start == current:
                    break
            start += 1
```
```

class Solution:
    def reverse(self, nums: list, start: int, end: int) -> None:
        while start < end:
            nums[start], nums[end] = nums[end], nums[start]
            start, end = start + 1, end - 1
                
    def rotate(self, nums: List[int], k: int) -> None:
        n = len(nums)
        k %= n

        self.reverse(nums, 0, n - 1)
        self.reverse(nums, 0, k - 1)
        self.reverse(nums, k, n - 1)
```



190_ReverseBits

```
class Solution {
  public:
  uint32_t reverseBits(uint32_t n) {
    uint32_t ret = 0, power = 31;
    while (n != 0) {
      ret += (n & 1) << power;
      n = n >> 1;
      power -= 1;
    }
    return ret;
  }
};
```
```
class Solution {
public:
    uint32_t reverseByte(uint32_t byte, map<uint32_t, uint32_t> cache) {
        if (cache.find(byte) != cache.end()) {
            return cache[byte];
        }
        uint32_t value = (byte * 0x0202020202 & 0x010884422010) % 1023;
        cache.emplace(byte, value);
        return value;
    }

    uint32_t reverseBits(uint32_t n) {
        uint32_t ret = 0, power = 24;
        map<uint32_t, uint32_t> cache;
        while (n != 0) {
            ret += reverseByte(n & 0xff, cache) << power;
            n = n >> 8;
            power -= 8;
        }
        return ret;
    }
};
```
```
class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        n = (n >> 16) | (n << 16);
        n = ((n & 0xff00ff00) >> 8) | ((n & 0x00ff00ff) << 8);
        n = ((n & 0xf0f0f0f0) >> 4) | ((n & 0x0f0f0f0f) << 4);
        n = ((n & 0xcccccccc) >> 2) | ((n & 0x33333333) << 2);
        n = ((n & 0xaaaaaaaa) >> 1) | ((n & 0x55555555) << 1);
        return n;
    }
};
```
191_Numberof1Bits
```
public int hammingWeight(int n) {
    int bits = 0;
    int mask = 1;
    for (int i = 0; i < 32; i++) {
        if ((n & mask) != 0) {
            bits++;
        }
        mask <<= 1;
    }
    return bits;
}
```
```
public int hammingWeight(int n) {
    int sum = 0;
    while (n != 0) {
        sum++;
        n &= (n - 1);
    }
    return sum;
}
```
```
```
192_WordFrequency
```
cat words.txt | tr -s ' ' '\n' | sort | uniq -c | sort -r | awk '{ print $2, $1 }'
```
```
```
```
```
193_ValidPhoneNumbers
```
egrep "^(\([0-9]{3}\) |[0-9]{3}\-)[0-9]{3}\-[0-9]{4}$" file.txt
```
```
```
```
```
194_TransposeFile
```
awk '
{
    for (i = 1; i <= NF; i++) {
        if(NR == 1) {
            s[i] = $i;
        } else {
            s[i] = s[i] " " $i;
        }
    }
}
END {
    for (i = 1; s[i] != ""; i++) {
        print s[i];
    }
}' file.txt
```
```
```
```
```
195_TenthLine
```
# Solution 1
cnt=0
while read line && [ $cnt -le 10 ]; do
  let 'cnt = cnt + 1'
  if [ $cnt -eq 10 ]; then
    echo $line
    exit 0
  fi
done < file.txt

# Solution 2
awk 'FNR == 10 {print }'  file.txt
# OR
awk 'NR == 10' file.txt

# Solution 3
sed -n 10p file.txt

# Solution 4
tail -n+10 file.txt|head -1
```
```
```
```
```
196_DeleteDuplicateEmails
```
DELETE p1 FROM Person p1,
    Person p2
WHERE
    p1.Email = p2.Email AND p1.Id > p2.Id
```
```
```
```
```
197_RisingTemperature
```
SELECT
    weather.id AS 'Id'
FROM
    weather
        JOIN
    weather w ON DATEDIFF(weather.recordDate, w.recordDate) = 1
        AND weather.Temperature > w.Temperature
;
```
```
```
```
```
198_HouseRobber
```
class Solution:
    
    def __init__(self):
        self.memo = {}
    
    def rob(self, nums: List[int]) -> int:
        
        self.memo = {}
        
        return self.robFrom(0, nums)
    
    def robFrom(self, i, nums):
        
        
        # No more houses left to examine.
        if i >= len(nums):
            return 0
        
        # Return cached value.
        if i in self.memo:
            return self.memo[i]
        
        # Recursive relation evaluation to get the optimal answer.
        ans = max(self.robFrom(i + 1, nums), self.robFrom(i + 2, nums) + nums[i])
        
        # Cache for future use.
        self.memo[i] = ans
        return ans
```
```
class Solution:
    
    def rob(self, nums: List[int]) -> int:
        
        # Special handling for empty case.
        if not nums:
            return 0
        
        maxRobbedAmount = [None for _ in range(len(nums) + 1)]
        N = len(nums)
        
        # Base case initialization.
        maxRobbedAmount[N], maxRobbedAmount[N - 1] = 0, nums[N - 1]
        
        # DP table calculations.
        for i in range(N - 2, -1, -1):
            
            # Same as recursive solution.
            maxRobbedAmount[i] = max(maxRobbedAmount[i + 1], maxRobbedAmount[i + 2] + nums[i])
            
        return maxRobbedAmount[0]    
        
```
```
class Solution:
    
    def rob(self, nums: List[int]) -> int:
        
        # Special handling for empty case.
        if not nums:
            return 0
        
        N = len(nums)
        
        rob_next_plus_one = 0
        rob_next = nums[N - 1]
        
        # DP table calculations.
        for i in range(N - 2, -1, -1):
            
            # Same as recursive solution.
            current = max(rob_next, rob_next_plus_one + nums[i])
            
            # Update the variables
            rob_next_plus_one = rob_next
            rob_next = current
            
        return rob_next
```
199_BinaryTreeRightSideView
```
class Solution:
    def rightSideView(self, root: TreeNode) -> List[int]:
        if root is None:
            return []
        
        next_level = deque([root,])
        rightside = []
        
        while next_level:
            # prepare for the next level
            curr_level = next_level
            next_level = deque()

            while curr_level:
                node = curr_level.popleft()
                    
                # add child nodes of the current level
                # in the queue for the next level
                if node.left:
                    next_level.append(node.left)
                if node.right:
                    next_level.append(node.right)
            
            # The current level is finished.
            # Its last element is the rightmost one.
            rightside.append(node.val)
        
        return rightside
```
```
class Solution:
    def rightSideView(self, root: TreeNode) -> List[int]:
        if root is None:
            return []
        
        queue = deque([root, None,])
        rightside = []
        
        curr = root
        while queue:
            prev, curr = curr, queue.popleft()

            while curr:
                # add child nodes in the queue
                if curr.left:
                    queue.append(curr.left)
                if curr.right:
                    queue.append(curr.right)
                    
                prev, curr = curr, queue.popleft()
            
            # the current level is finished
            # and prev is its rightmost element      
            rightside.append(prev.val)
            # add a sentinel to mark the end 
            # of the next level
            if queue:
                queue.append(None)
        
        return rightside
```
```
class Solution:
    def rightSideView(self, root: TreeNode) -> List[int]:
        if root is None:
            return []
        
        queue = deque([root,])
        rightside = []
        
        while queue:
            level_length = len(queue)

            for i in range(level_length):
                node = queue.popleft()
                # if it's the rightmost element
                if i == level_length - 1:
                    rightside.append(node.val)
                    
                # add child nodes in the queue 
                if node.left:
                    queue.append(node.left)
                if node.right:
                    queue.append(node.right)
        
        return rightside
```
```
class Solution:
    def rightSideView(self, root: TreeNode) -> List[int]:
        if root is None:
            return []
        
        rightside = []
        
        def helper(node: TreeNode, level: int) -> None:
            if level == len(rightside):
                rightside.append(node.val)
            for child in [node.right, node.left]:
                if child:
                    helper(child, level + 1)
                
        helper(root, 0)
        return rightside
```



200_NumberofIslands

```
class Solution {
private:
  void dfs(vector<vector<char>>& grid, int r, int c) {
    int nr = grid.size();
    int nc = grid[0].size();

    grid[r][c] = '0';
    if (r - 1 >= 0 && grid[r-1][c] == '1') dfs(grid, r - 1, c);
    if (r + 1 < nr && grid[r+1][c] == '1') dfs(grid, r + 1, c);
    if (c - 1 >= 0 && grid[r][c-1] == '1') dfs(grid, r, c - 1);
    if (c + 1 < nc && grid[r][c+1] == '1') dfs(grid, r, c + 1);
  }

public:
  int numIslands(vector<vector<char>>& grid) {
    int nr = grid.size();
    if (!nr) return 0;
    int nc = grid[0].size();

    int num_islands = 0;
    for (int r = 0; r < nr; ++r) {
      for (int c = 0; c < nc; ++c) {
        if (grid[r][c] == '1') {
          ++num_islands;
          dfs(grid, r, c);
        }
      }
    }

    return num_islands;
  }
};
```
```
class Solution {
public:
  int numIslands(vector<vector<char>>& grid) {
    int nr = grid.size();
    if (!nr) return 0;
    int nc = grid[0].size();

    int num_islands = 0;
    for (int r = 0; r < nr; ++r) {
      for (int c = 0; c < nc; ++c) {
        if (grid[r][c] == '1') {
          ++num_islands;
          grid[r][c] = '0'; // mark as visited
          queue<pair<int, int>> neighbors;
          neighbors.push({r, c});
          while (!neighbors.empty()) {
            auto rc = neighbors.front();
            neighbors.pop();
            int row = rc.first, col = rc.second;
            if (row - 1 >= 0 && grid[row-1][col] == '1') {
              neighbors.push({row-1, col}); grid[row-1][col] = '0';
            }
            if (row + 1 < nr && grid[row+1][col] == '1') {
              neighbors.push({row+1, col}); grid[row+1][col] = '0';
            }
            if (col - 1 >= 0 && grid[row][col-1] == '1') {
              neighbors.push({row, col-1}); grid[row][col-1] = '0';
            }
            if (col + 1 < nc && grid[row][col+1] == '1') {
              neighbors.push({row, col+1}); grid[row][col+1] = '0';
            }
          }
        }
      }
    }

    return num_islands;
  }
};
```
```
class UnionFind {
public:
  UnionFind(vector<vector<char>>& grid) {
    count = 0;
    int m = grid.size();
    int n = grid[0].size();
      for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
          if (grid[i][j] == '1') {
            parent.push_back(i * n + j);
            ++count;
          }
          else parent.push_back(-1);
          rank.push_back(0);
        }
    }
  }

  int find(int i) { // path compression
    if (parent[i] != i) parent[i] = find(parent[i]);
    return parent[i];
  }

  void Union(int x, int y) { // union with rank
    int rootx = find(x);
    int rooty = find(y);
    if (rootx != rooty) {
      if (rank[rootx] > rank[rooty]) parent[rooty] = rootx;
      else if (rank[rootx] < rank[rooty]) parent[rootx] = rooty;
      else {
        parent[rooty] = rootx; rank[rootx] += 1;
      }
      --count;
    }
  }

  int getCount() const {
    return count;
  }

private:
  vector<int> parent;
  vector<int> rank;
  int count; // # of connected components
};

class Solution {
public:
  int numIslands(vector<vector<char>>& grid) {
    int nr = grid.size();
    if (!nr) return 0;
    int nc = grid[0].size();

    UnionFind uf (grid);
    int num_islands = 0;
    for (int r = 0; r < nr; ++r) {
      for (int c = 0; c < nc; ++c) {
        if (grid[r][c] == '1') {
          grid[r][c] = '0';
          if (r - 1 >= 0 && grid[r-1][c] == '1') uf.Union(r * nc + c, (r-1) * nc + c);
          if (r + 1 < nr && grid[r+1][c] == '1') uf.Union(r * nc + c, (r+1) * nc + c);
          if (c - 1 >= 0 && grid[r][c-1] == '1') uf.Union(r * nc + c, r * nc + c - 1);
          if (c + 1 < nc && grid[r][c+1] == '1') uf.Union(r * nc + c, r * nc + c + 1);
        }
      }
    }

    return uf.getCount();
  }
};
```