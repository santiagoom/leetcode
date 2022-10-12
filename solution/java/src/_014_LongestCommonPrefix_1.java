

                    import java.util.*;
                    import utils.TreeNode;
                    import utils.ListNode;
                                            
                        class Solution_014_LongestCommonPrefix_1{
                        
 public String longestCommonPrefix(String[] strs) {
    if (strs.length == 0) return "";
    String prefix = strs[0];
    for (int i = 1; i < strs.length; i++)
        while (strs[i].indexOf(prefix) != 0) {
            prefix = prefix.substring(0, prefix.length() - 1);
            if (prefix.isEmpty()) return "";
        }        
    return prefix;
}

                        }
                        public class _014_LongestCommonPrefix_1 {
                            public static void main(String[] args) {
                                Solution_014_LongestCommonPrefix_1 so = new Solution_014_LongestCommonPrefix_1();
                            }
                        }
                        