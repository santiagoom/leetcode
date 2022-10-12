
                        
                    import java.util.*;
                    import utils.TreeNode;
                    import utils.ListNode;
                                            
                                                
class Solution_242_ValidAnagram_3 {
public boolean isAnagram(String s, String t) {
    if (s.length() != t.length()) {
        return false;
    }
    int[] table = new int[26];
    for (int i = 0; i < s.length(); i++) {
        table[s.charAt(i) - 'a']++;
    }
    for (int i = 0; i < t.length(); i++) {
        table[t.charAt(i) - 'a']--;
        if (table[t.charAt(i) - 'a'] < 0) {
            return false;
        }
    }
    return true;
}
}

                                                public class _242_ValidAnagram_3 {
                                                    public static void main(String[] args) {
                                                        Solution_242_ValidAnagram_3 so = new Solution_242_ValidAnagram_3();
                                                    }
                                                }
                                                