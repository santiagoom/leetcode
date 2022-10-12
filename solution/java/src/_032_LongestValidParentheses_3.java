
                        
                    import java.util.*;
                    import utils.TreeNode;
                    import utils.ListNode;
                                            
                                                
class Solution_032_LongestValidParentheses_3 {

    public int longestValidParentheses(String s) {
        int maxans = 0;
        Stack<Integer> stack = new Stack<>();
        stack.push(-1);
        for (int i = 0; i < s.length(); i++) {
            if (s.charAt(i) == '(') {
                stack.push(i);
            } else {
                stack.pop();
                if (stack.empty()) {
                    stack.push(i);
                } else {
                    maxans = Math.max(maxans, i - stack.peek());
                }
            }
        }
        return maxans;
    }
}

                                                public class _032_LongestValidParentheses_3 {
                                                    public static void main(String[] args) {
                                                        Solution_032_LongestValidParentheses_3 so = new Solution_032_LongestValidParentheses_3();
                                                    }
                                                }
                                                