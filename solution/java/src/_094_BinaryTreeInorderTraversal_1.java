
                        
                    import java.util.*;
                    import utils.TreeNode;
                    import utils.ListNode;
                                            
                                                
class Solution_094_BinaryTreeInorderTraversal_1 {
    public List<Integer> inorderTraversal(TreeNode root) {
        List<Integer> res = new ArrayList<>();
        helper(root, res);
        return res;
    }

    public void helper(TreeNode root, List<Integer> res) {
        if (root != null) {
            helper(root.left, res);
            res.add(root.val);
            helper(root.right, res);
        }
    }
}

                                                public class _094_BinaryTreeInorderTraversal_1 {
                                                    public static void main(String[] args) {
                                                        Solution_094_BinaryTreeInorderTraversal_1 so = new Solution_094_BinaryTreeInorderTraversal_1();
                                                    }
                                                }
                                                