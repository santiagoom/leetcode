
                        
                    import java.util.*;
                    import utils.TreeNode;
                    import utils.ListNode;
                                            
                                                
class Solution_094_BinaryTreeInorderTraversal_2 {
    public List<Integer> inorderTraversal(TreeNode root) {
        List<Integer> res = new ArrayList<>();
        Stack<TreeNode> stack = new Stack<>();
        TreeNode curr = root;
        while (curr != null || !stack.isEmpty()) {
            while (curr != null) {
                stack.push(curr);
                curr = curr.left;
            }
            curr = stack.pop();
            res.add(curr.val);
            curr = curr.right;
        }
        return res;
    }
}

                                                public class _094_BinaryTreeInorderTraversal_2 {
                                                    public static void main(String[] args) {
                                                        Solution_094_BinaryTreeInorderTraversal_2 so = new Solution_094_BinaryTreeInorderTraversal_2();
                                                    }
                                                }
                                                