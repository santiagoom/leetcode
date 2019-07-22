package _003_LongestSubstringWithoutRepeatingCharacters;

import java.util.HashMap;
import java.util.HashSet;
import java.util.Map;
import java.util.Set;

public class _003_LongestSubstringWithoutRepeatingCharacters_practise {
    public static void main(String[] args) {

        Solution_p2 so = new Solution_p2();
//        String s = "abcabcbb";
        String s = "tmmzuxt";
        int res = so.lengthOfLongestSubstring(s);
        System.out.println(res);

    }
}


class Solution_p {
    /*
    start: 2019-07-22 18:17:17
    end: 2019-07-22 18:26:31
     */
    public int lengthOfLongestSubstring(String s) {
        int len = s.length();
        Set<Character> set = new HashSet<>();
        int res = 0, i = 0, j = 0;
        while (i < len && j < len) {
            if (!set.contains(s.charAt(j))) {
                set.add(s.charAt(j++));
                res = Math.max(res, j - i);
            } else {
                set.remove(s.charAt(i++));
            }
        }
        return res;
    }
}
class Solution_p2 {
    /*
    start: 2019-07-22 18:17:17
    end: 2019-07-22 18:26:31
     */
    public int lengthOfLongestSubstring(String s) {
        int n = s.length(), ans = 0;
        Map<Character, Integer> map = new HashMap<>(); // current index of character
        // try to extend the range [i, j]
        for (int j = 0, i = 0; j < n; j++) {
            if (map.containsKey(s.charAt(j))) {
                System.out.println(map.get(s.charAt(j)));
                i = Math.max(map.get(s.charAt(j)), i);
            }
            ans = Math.max(ans, j - i + 1);
            System.out.println(ans);
            map.put(s.charAt(j), j + 1);
        }
        return ans;
    }
}
