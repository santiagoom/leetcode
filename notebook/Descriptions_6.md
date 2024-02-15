## 560_SubarraySumEqualsK


```
public class Solution {
    public int subarraySum(int[] nums, int k) {
        int count = 0;
        for (int start = 0; start < nums.length; start++) {
            for (int end = start + 1; end <= nums.length; end++) {
                int sum = 0;
                for (int i = start; i < end; i++)
                    sum += nums[i];
                if (sum == k)
                    count++;
            }
        }
        return count;
    }
}
```



```
public class Solution {
    public int subarraySum(int[] nums, int k) {
        int count = 0;
        int[] sum = new int[nums.length + 1];
        sum[0] = 0;
        for (int i = 1; i <= nums.length; i++)
            sum[i] = sum[i - 1] + nums[i - 1];
        for (int start = 0; start < nums.length; start++) {
            for (int end = start + 1; end <= nums.length; end++) {
                if (sum[end] - sum[start] == k)
                    count++;
            }
        }
        return count;
    }
}
```



```
public class Solution {
    public int subarraySum(int[] nums, int k) {
        int count = 0;
        for (int start = 0; start < nums.length; start++) {
            int sum=0;
            for (int end = start; end < nums.length; end++) {
                sum+=nums[end];
                if (sum == k)
                    count++;
            }
        }
        return count;
    }
}
```



```
public class Solution {
    public int subarraySum(int[] nums, int k) {
        int count = 0, sum = 0;
        HashMap < Integer, Integer > map = new HashMap < > ();
        map.put(0, 1);
        for (int i = 0; i < nums.length; i++) {
            sum += nums[i];
            if (map.containsKey(sum - k))
                count += map.get(sum - k);
            map.put(sum, map.getOrDefault(sum, 0) + 1);
        }
        return count;
    }
}
```



## 572_SubtreeofAnotherTree

```
class Solution:
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


```



## 889_ConstructBinaryTreefromPreorderandPostorderTraversal



```
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def constructFromPrePost(self, pre: List[int], post: List[int]) -> TreeNode:
        # read this: https://www.techiedelight.com/construct-full-binary-tree-from-preorder-postorder-sequence/
        def helper(pre,post):
            print('pre is: ', pre, 'post is: ', post)
            if not pre:
                return None
        
            if len(pre)==1:
                return TreeNode(post.pop())
        
        
            node=TreeNode(post.pop()) #3
            ind=pre.index(post[-1]) #4
        
            node.right=helper(pre[ind:],post) #1
            node.left=helper(pre[1:ind],post) #2
            return node
    
        return helper(pre,post)
```



```
class Solution:
    def constructFromPrePost(self, pre, post):
        if not pre or not post: return None
        root = TreeNode(pre[0])
        if len(post) == 1: return root
        idx = pre.index(post[-2])
        root.left = self.constructFromPrePost(pre[1: idx], post[:(idx - 1)])
        root.right = self.constructFromPrePost(pre[idx: ], post[(idx - 1):-1])
        return root


```



## 1143_LongestCommonSubsequence

```
    class Solution:
        def longestCommonSubsequence(self, s1: str, s2: str) -> int:
            return self.helper(s1, s2, 0, 0)
            
        def helper(self, s1, s2, i, j):
            if i == len(s1) or j == len(s2):
                return 0
            if s1[i] == s2[j]:
                return 1 + self.helper(s1, s2, i + 1, j + 1)
            else:
                return max(self.helper(s1, s2, i+1, j), self.helper(s1, s2, i, j + 1))
```



```
    class Solution:
        def longestCommonSubsequence(self, s1: str, s2: str) -> int:
            m = len(s1)
            n = len(s2)
            memo = [[-1 for _ in range(n + 1)] for _ in range(m + 1)]
            return self.helper(s1, s2, 0, 0, memo)
    
        def helper(self, s1, s2, i, j, memo):
            if memo[i][j] < 0:
                if i == len(s1) or j == len(s2):
                    memo[i][j] = 0
                elif s1[i] == s2[j]:
                    memo[i][j] = 1 + self.helper(s1, s2, i + 1, j + 1, memo)
                else:
                    memo[i][j] = max(
                        self.helper(s1, s2, i + 1, j, memo),
                        self.helper(s1, s2, i, j + 1, memo),
                    )
            return memo[i][j]
```



```

    class Solution:
        def longestCommonSubsequence(self, s1: str, s2: str) -> int:
            m = len(s1)
            n = len(s2)
            memo = [[0 for _ in range(n + 1)] for _ in range(m + 1)]
    
            for row in range(1, m + 1):
                for col in range(1, n + 1):
                    if s1[row - 1] == s2[col - 1]:
                        memo[row][col] = 1 + memo[row - 1][col - 1]
                    else:
                        memo[row][col] = max(memo[row][col - 1], memo[row - 1][col])
    
            return memo[m][n]
```



```
class Solution:
    def longestCommonSubsequence(self, s1: str, s2: str) -> int:
        m = len(s1)
        n = len(s2)
        if m < n:
            return self.longestCommonSubsequence(s2, s1)
        memo = [[0 for _ in range(n + 1)] for _ in range(2)]

        for i in range(m):
            for j in range(n):
                if s1[i] == s2[j]:
                    memo[1 - i % 2][j + 1] = 1 + memo[i % 2][j]
                else:
                    memo[1 - i % 2][j + 1] = max(memo[1 - i % 2][j], memo[i % 2][j + 1])

        return memo[m % 2][n]
```

