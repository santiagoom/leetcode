package _028_ImplementstrStr;

public class Solutions {
}

class SolutionBruteForce {
	/*
	 * Input: haystack = "hello", needle = "ll"
	 * 
	 * Output: 2
	 */
	public int strStr(String haystack, String needle) {
		/*
		 * **Complexity analysis**
		 * 
		 * The worse case happen in this situation,
		 * 
		 * such as Input: haystack = "aaaaaaaaaaaac", needle = "aaac", haystack.length =
		 * n, needle.length = m, T = (n-m) * (m-1) + m.
		 */
		for (int i = 0;; i++) {
			for (int j = 0;; j++) {
				if (j == needle.length())
					return i;
				if (i + j == haystack.length())
					return -1;
				if (needle.charAt(j) != haystack.charAt(i + j))
					break;
			}
		}
	}
}

class SolutionKMP {
	/*
	 * Check out [this
	 * article](http://jakeboxer.com/blog/2009/12/13/the-knuth-morris-pratt-
	 * algorithm-in-my-own-words/) to understand KMP algorithm.
	 */
	public int strStr(String haystack, String needle) {
		if (haystack == null || needle == null)
			return 0;

		int h = haystack.length();
		int n = needle.length();

		if (n > h)
			return -1;
		if (n == 0)
			return 0;

		int[] next = getNext(needle);
		int i = 0;

		while (i <= h - n) {
			int success = 1;
			for (int j = 0; j < n; j++) {
				if (needle.charAt(0) != haystack.charAt(i)) {
					success = 0;
					i++;
					break;
				} else if (needle.charAt(j) != haystack.charAt(i + j)) {
					success = 0;
					i = i + j - next[j - 1];
					break;
				}
			}
			if (success == 1)
				return i;
		}

		return -1;
	}

//calculate KMP array
	public int[] getNext(String needle) {
		int[] next = new int[needle.length()];
		next[0] = 0;

		for (int i = 1; i < needle.length(); i++) {
			int index = next[i - 1];
			while (index > 0 && needle.charAt(index) != needle.charAt(i)) {
				index = next[index - 1];
			}

			if (needle.charAt(index) == needle.charAt(i)) {
				next[i] = next[i - 1] + 1;
			} else {
				next[i] = 0;
			}
		}

		return next;
	}
}