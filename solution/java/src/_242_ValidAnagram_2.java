

                    import java.util.*;
                    import utils.TreeNode;
                    import utils.ListNode;
                                            
                        class Solution_242_ValidAnagram_2{
                        
public boolean isAnagram(String s, String t) {
    if (s.length() != t.length()) {
        return false;
    }
    int[] counter = new int[26];
    for (int i = 0; i < s.length(); i++) {
        counter[s.charAt(i) - 'a']++;
        counter[t.charAt(i) - 'a']--;
    }
    for (int count : counter) {
        if (count != 0) {
            return false;
        }
    }
    return true;
}

                        }
                        public class _242_ValidAnagram_2 {
                            public static void main(String[] args) {
                                Solution_242_ValidAnagram_2 so = new Solution_242_ValidAnagram_2();
                            }
                        }
                        