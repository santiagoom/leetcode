package _007_005_LongestPalindromicSubstring;

public class Solutions {

	/**
	 * Approach 1: Longest Common Substring Common mistake
	 * 
	 * Some people will be tempted to come up with a quick solution, which is
	 * unfortunately flawed (however can be corrected easily): Reverse SS and become
	 * S&#x27;S ¡ä . Find the longest common substring between SS and S&#x27;S ¡ä ,
	 * which must also be the longest palindromic substring. This seemed to work,
	 * let¡¯s see some examples below. For example, SS = "caba", S&#x27;S ¡ä = "abac".
	 * The longest common substring between SS and S&#x27;S ¡ä is "aba", which is the
	 * answer.
	 * 
	 * Let¡¯s try another example: SS = "abacdfgdcaba", S&#x27;S ¡ä = "abacdgfdcaba".
	 * The longest common substring between SS and S&#x27;S ¡ä is "abacd". Clearly,
	 * this is not a valid palindrome.
	 */

	/**
	 * You might be asking why there are 2n - 1 but not n centers? The reason is the
	 * center of a palindrome can be in between two letters. Such palindromes have
	 * even number of letters (such as "abba") and its center are between the two
	 * 'b's.
	 */

	public String longestPalindromeExpandAroundCenter(String s) {
		if (s == null || s.length() < 1)
			return "";
		int start = 0, end = 0;
		for (int i = 0; i < s.length(); i++) {
			int len1 = expandAroundCenter(s, i, i);
			int len2 = expandAroundCenter(s, i, i + 1);
			int len = Math.max(len1, len2);
			if (len > end - start) {
				start = i - (len - 1) / 2;
				end = i + len / 2;
			}
		}
		return s.substring(start, end + 1);
	}

	private int expandAroundCenter(String s, int left, int right) {
		int L = left, R = right;
		while (L >= 0 && R < s.length() && s.charAt(L) == s.charAt(R)) {
			L--;
			R++;
		}
		return R - L - 1;
	}

}
