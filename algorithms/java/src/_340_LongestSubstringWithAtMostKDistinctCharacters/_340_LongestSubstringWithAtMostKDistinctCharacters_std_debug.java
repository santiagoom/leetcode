package _340_LongestSubstringWithAtMostKDistinctCharacters;

public class _340_LongestSubstringWithAtMostKDistinctCharacters_std_debug {
	public static void main(String[] args) {

		Solution2_debug so2 = new Solution2_debug();

		String s = "eceba" ;
		int k = 3;

		int res = so2.lengthOfLongestSubstringKDistinct(s,k);
		System.out.println(res);
	}
}


class Solution2_debug {
	/*
	 * @param s: A string
	 * @param k: An integer
	 * @return: An integer
	 */
	public int lengthOfLongestSubstringKDistinct(String s, int k) {
		// write your code here
		int[] cnt = new int[256];
		char[] sc = s.toCharArray();

		cnt['a'] = 10;

		for(int x:cnt)
			System.out.println(x);

		int ans = 0;
		int sum = 0;
		for (int l = 0, r = 0; r < s.length(); r++) {
			System.out.println(sc[r]);
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

