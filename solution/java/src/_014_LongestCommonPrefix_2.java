

                    import java.util.*;
                    import utils.TreeNode;
                    import utils.ListNode;
                                            
                        class Solution_014_LongestCommonPrefix_2{
                        
public String longestCommonPrefix(String[] strs) {
    if (strs == null || strs.length == 0) return "";
    for (int i = 0; i < strs[0].length() ; i++){
        char c = strs[0].charAt(i);
        for (int j = 1; j < strs.length; j ++) {
            if (i == strs[j].length() || strs[j].charAt(i) != c)
                return strs[0].substring(0, i);             
        }
    }
    return strs[0];
}

                        }
                        public class _014_LongestCommonPrefix_2 {
                            public static void main(String[] args) {
                                Solution_014_LongestCommonPrefix_2 so = new Solution_014_LongestCommonPrefix_2();
                            }
                        }
                        