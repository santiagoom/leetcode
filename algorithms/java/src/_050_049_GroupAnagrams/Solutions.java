package _050_049_GroupAnagrams;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

public class Solutions {
	public static void main(String[] args) {
		SolutionApproach1 so = new SolutionApproach1();
		String strs[] = { "eat", "tea", "tan", "ate", "nat", "bat" };
		List out = so.groupAnagrams(strs);
		System.out.println(out);
	}
}

class SolutionApproach1 {
	/*
	 * Approach 1: Categorize by Sorted String
	 * 
	 * Complexity Analysis
	 * 
	 * Time Complexity: O(NK \log K)O(NKlogK), where NN is the length of strs, and
	 * KK is the maximum length of a string in strs. The outer loop has complexity
	 * O(N)O(N) as we iterate through each string. Then, we sort each string in O(K
	 * \log K)O(KlogK) time.
	 * 
	 * Space Complexity: O(NK)O(NK), the total information content stored in ans.
	 */
	public List<List<String>> groupAnagrams(String[] strs) {
		if (strs.length == 0)
			return new ArrayList();
		Map<String, List> ans = new HashMap<String, List>();
		for (String s : strs) {
			char[] ca = s.toCharArray();
			Arrays.sort(ca);
			System.out.println(ca);
			String key = String.valueOf(ca);
			System.out.println(key);
			if (!ans.containsKey(key))
				ans.put(key, new ArrayList());
			ans.get(key).add(s);
		}
		return new ArrayList(ans.values());
	}
}

class SolutionApproach2 {
	/*
	 * Approach 2: Categorize by Count Intuition
	 * 
	 * Two strings are anagrams if and only if their character counts (respective
	 * number of occurrences of each character) are the same.
	 * 
	 * two linear for loop
	 */
	public List<List<String>> groupAnagrams(String[] strs) {
		if (strs.length == 0)
			return new ArrayList();
		Map<String, List> ans = new HashMap<String, List>();
		int[] count = new int[26];
		for (String s : strs) {
			Arrays.fill(count, 0);
			for (char c : s.toCharArray())
				count[c - 'a']++;

			StringBuilder sb = new StringBuilder("");
			for (int i = 0; i < 26; i++) {
				sb.append('#');
				sb.append(count[i]);
			}
			String key = sb.toString();
			if (!ans.containsKey(key))
				ans.put(key, new ArrayList());
			ans.get(key).add(s);
		}
		return new ArrayList(ans.values());
	}
}
