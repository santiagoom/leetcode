

import java.util.*;

import utils.TreeNode;
import utils.ListNode;
import utils.JavaUtils;


class Solution_032_LongestValidParentheses_1 {
    public boolean isValid(String s) {
        Stack<Character> stack = new Stack<Character>();
        for (int i = 0; i < s.length(); i++) {
            if (s.charAt(i) == '(') {
                stack.push('(');
            } else if (!stack.empty() && stack.peek() == '(') {
                stack.pop();
            } else {
                return false;
            }
        }
        return stack.empty();
    }

    public int longestValidParentheses(String s) {
        int maxlen = 0;
        for (int i = 0; i < s.length(); i++) {
            for (int j = i + 2; j <= s.length(); j += 2) {
                if (isValid(s.substring(i, j))) {
                    maxlen = Math.max(maxlen, j - i);
                }
            }
        }
        return maxlen;
    }
}

public class _032_LongestValidParentheses_1 {
    public static void main(String[] args) {
        Solution_032_LongestValidParentheses_1 so = new Solution_032_LongestValidParentheses_1();
        int[] nums = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
        JavaUtils.print_1d_array(nums);
        int[][] arrays = {{2, 7, 9}, {3, 6, 1}, {7, 4, 2}};
        JavaUtils.print_2d_array(arrays);

        int target = 26;
        String s = "aa";
    }
}
                                                