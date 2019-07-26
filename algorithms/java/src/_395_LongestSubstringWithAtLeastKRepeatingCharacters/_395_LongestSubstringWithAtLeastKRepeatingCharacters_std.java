package _395_LongestSubstringWithAtLeastKRepeatingCharacters;

public class _395_LongestSubstringWithAtLeastKRepeatingCharacters_std {
    public static void main(String[] args) {
        _395_LongestSubstringWithAtLeastKRepeatingCharacters_std_ so = new _395_LongestSubstringWithAtLeastKRepeatingCharacters_std_();

    }
}

class _395_LongestSubstringWithAtLeastKRepeatingCharacters_std_ {

}

class Solution1 {
    /**
     * @param s: a string
     * @param k: an integer
     * @return: return an integer
     */
    public int longestSubstring(String s, int k) {
        // write your code here
        if (s == null || s.length() == 0 || k > s.length()) return 0;
        int[] counts = new int[26];
        char[] sArr = s.toCharArray();
        for (char c : sArr) {
            counts[c - 'a']++;
        }
        boolean fullValid = true;
        for (int i = 0; i < 26; ++i) {
            if (counts[i] > 0 && counts[i] < k) {
                fullValid = false;
                break;
            }
        }
        if (fullValid) return s.length();
        int left = 0, res = 0;
        for (int right = 0; right < s.length(); ++right) {
            if (counts[sArr[right] - 'a'] < k && counts[sArr[right] - 'a'] > 0) {
                res = Math.max(res, longestSubstring(s.substring(left, right), k));
                left = right + 1;
            }
        }
        res = Math.max(res, longestSubstring(s.substring(left, s.length()), k));
        return res;
    }
}


class Solution2 {
    /**
     * @param s: a string
     * @param k: an integer
     * @return: return an integer
     */
    public int longestSubstring(String s, int k) {
        // write your code here
        if (s == null || s.length() == 0) {
            return 0;
        }

        char[] sc = s.toCharArray();
        return helper(sc, 0, sc.length - 1, k);
    }

    public int helper(char[] sc,
                      int start,
                      int end,
                      int k) {
        if (start == end && k == 1) {
            return 1;
        }
        if (start >= end) {
            return 0;
        }

        int[] map = new int[256];
        for (int i = start; i <= end; i++) {
            map[sc[i]]++;
        }

        int last = start;
        int len = 0;
        boolean flag = false;

        for (int i = start; i <= end; i++) {
            if (map[sc[i]] < k) {
                flag = true;
                len = Math.max(len, helper(sc, last, i - 1, k));
                last = i + 1;
            }
        }

        if (!flag) {
            return end - start + 1;
        }

        if (last <= end) {
            len = Math.max(len, helper(sc, last, end, k));
        }

        return len;

    }
}
