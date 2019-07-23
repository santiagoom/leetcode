package _340_LongestSubstringWithAtMostKDistinctCharacters;

import java.util.HashMap;
import java.util.Map;

public class _340_LongestSubstringWithAtMostKDistinctCharacters_std {
    public static void main(String[] args) {
        _340_LongestSubstringWithAtMostKDistinctCharacters_std_ so = new _340_LongestSubstringWithAtMostKDistinctCharacters_std_();

    }
}

class _340_LongestSubstringWithAtMostKDistinctCharacters_std_ {

}

/**
 * This reference program is provided by @jiuzhang.com
 * Copyright is reserved. Please indicate the source for forwarding
 */

class Solution1 {
    /**
     * @param s : A string
     * @return : The length of the longest substring
     * that contains at most k distinct characters.
     */
    public int lengthOfLongestSubstringKDistinct(String s, int k) {
        // write your code here
        int maxLen = 0;

        // Key: letter; value: the number of occurrences.
        Map<Character, Integer> map = new HashMap<Character, Integer>();
        int i, j = 0;
        char c;
        for (i = 0; i < s.length(); i++) {
            while (j < s.length()) {
                c = s.charAt(j);
                if (map.containsKey(c)) {
                    map.put(c, map.get(c) + 1);
                } else {
                    if (map.size() == k)
                        break;
                    map.put(c, 1);
                }
                j++;
            }

            maxLen = Math.max(maxLen, j - i);
            c = s.charAt(i);
            if (map.containsKey(c)) {
                int count = map.get(c);
                if (count > 1) {
                    map.put(c, count - 1);
                } else {
                    map.remove(c);
                }
            }
        }
        return maxLen;
    }
}


class Solution2 {
    /*
     * @param s: A string
     * @param k: An integer
     * @return: An integer
     */
    public int lengthOfLongestSubstringKDistinct(String s, int k) {
        // write your code here
        int[] cnt = new int[256];
        char[] sc = s.toCharArray();

        int ans = 0;
        int sum = 0;
        for (int l = 0, r = 0; r < s.length(); r++) {
            cnt[sc[r]]++;
            if (cnt[sc[r]] == 1) {
                sum++;
            }
            while (sum > k) {
                cnt[sc[l]]--;
                if (cnt[sc[l]] == 0) {
                    sum--;
                }
                l++;
            }
            ans = Math.max(ans, r - l + 1);
        }
        return ans;
    }
}
