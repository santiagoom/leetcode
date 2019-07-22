package _003_LongestSubstringWithoutRepeatingCharacters;

import java.util.HashMap;
import java.util.Map;

public class _003_LongestSubstringWithoutRepeatingCharacters_std_debug {
	public static void main(String[] args) {
	    _003_LongestSubstringWithoutRepeatingCharacters_std_debug_ so = new _003_LongestSubstringWithoutRepeatingCharacters_std_debug_();

	}
}

class _003_LongestSubstringWithoutRepeatingCharacters_std_debug_ {

}

class Solution3 {
	public int lengthOfLongestSubstring(String s) {
		int n = s.length(), ans = 0;
		Map<Character, Integer> map = new HashMap<>(); // current index of character
		// try to extend the range [i, j]
		for (int j = 0, i = 0; j < n; j++) {
			if (map.containsKey(s.charAt(j))) {
				i = Math.max(map.get(s.charAt(j)), i);
			}
			ans = Math.max(ans, j - i + 1);
			System.out.println(j - i + 1);
			map.put(s.charAt(j), j + 1);
			System.out.println(map);
		}
		return ans;
	}
}