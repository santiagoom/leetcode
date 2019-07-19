package _653_TwoSumIV_InputIsA_BST;

import java.util.*;

public class _653_TwoSumIV_InputIsA_BST {
    public static void main(String[] args) {
        _653_TwoSumIV_InputIsA_BST_ so = new _653_TwoSumIV_InputIsA_BST_();

    }
}

class _653_TwoSumIV_InputIsA_BST_ {

}


class Solution3 {
    /*
    Approach #3 Using BST [Accepted]
    Complexity Analysis

    Time complexity : O(n)O(n). We need to traverse over the whole tree once to do the inorder traversal. Here, nn refers to the number of nodes in the given tree.

    Space complexity : O(n)O(n). The sorted listlist will contain nn elements.
     */
    public boolean findTarget(TreeNode root, int k) {
        List<Integer> list = new ArrayList();
        inorder(root, list);
        int l = 0, r = list.size() - 1;
        while (l < r) {
            int sum = list.get(l) + list.get(r);
            if (sum == k)
                return true;
            if (sum < k)
                l++;
            else
                r--;
        }
        return false;
    }

    public void inorder(TreeNode root, List<Integer> list) {
        if (root == null)
            return;
        inorder(root.left, list);
        list.add(root.val);
        inorder(root.right, list);
    }
}

class Solution2 {
    /*
    Approach #2 Using BFS and HashSet [Accepted]
    Complexity Analysis
    Time complexity : O(n)O(n). We need to traverse over the whole tree once in the worst case. Here, nn refers to the number of nodes in the given tree.
    Space complexity : O(n)O(n). The size of the setset can grow atmost upto nn.
     */
    public boolean findTarget(TreeNode root, int k) {
        Set<Integer> set = new HashSet();
        Queue<TreeNode> queue = new LinkedList();
        queue.add(root);
        while (!queue.isEmpty()) {
            if (queue.peek() != null) {
                TreeNode node = queue.remove();
                if (set.contains(k - node.val))
                    return true;
                set.add(node.val);
                queue.add(node.right);
                queue.add(node.left);
            } else
                queue.remove();
        }
        return false;
    }
}

class Solution1 {
    /*
    Approach #1 Using HashSet[Accepted]
    Complexity Analysis
    Time complexity : O(n)O(n). The entire tree is traversed only once in the worst case. Here, nn refers to the number of nodes in the given tree.
    Space complexity : O(n)O(n). The size of the setset can grow upto nn in the worst case.
     */

    public boolean findTarget(TreeNode root, int k) {
        Set<Integer> set = new HashSet();
        return find(root, k, set);
    }

    public boolean find(TreeNode root, int k, Set<Integer> set) {
        if (root == null)
            return false;
        if (set.contains(k - root.val))
            return true;
        set.add(root.val);
        return find(root.left, k, set) || find(root.right, k, set);
    }
}

class TreeNode {
    int val;
    TreeNode left;
    TreeNode right;

    TreeNode(int x) {
        val = x;
    }
}
