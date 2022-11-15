
                        
                    import java.util.*;
                    import utils.TreeNode;
                    import utils.ListNode;
                    import utils.JavaUtils;
                                            
                                                
class Solution_267_PalindromePermutationII_1 {
    Set < String > set = new HashSet < > ();
    public List < String > generatePalindromes(String s) {
        permute(s.toCharArray(), 0);
        return new ArrayList < String > (set);
    }
    public boolean isPalindrome(char[] s) {
        for (int i = 0; i < s.length; i++) {
            if (s[i] != s[s.length - 1 - i])
                return false;
        }
        return true;
    }
    public void swap(char[] s, int i, int j) {
        char temp = s[i];
        s[i] = s[j];
        s[j] = temp;
    }
    void permute(char[] s, int l) {
        if (l == s.length) {
            if (isPalindrome(s))
                set.add(new String(s));
        } else {
            for (int i = l; i < s.length; i++) {
                swap(s, l, i);
                permute(s, l + 1);
                swap(s, l, i);
            }
        }
    }
}



                                                public class _267_PalindromePermutationII_1 {
                                                    public static void main(String[] args) {
                                                        Solution_267_PalindromePermutationII_1 so = new Solution_267_PalindromePermutationII_1();
                                                        int[] nums = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
                                                        JavaUtils.print_1d_array(nums);
                                                        int[][] arrays = {{2, 7, 9}, {3, 6, 1}, {7, 4, 2}};
                                                        JavaUtils.print_2d_array(arrays);
                                                
                                                        int target = 26;
                                                        String s = "aa";
                                                    }
                                                }
                                                