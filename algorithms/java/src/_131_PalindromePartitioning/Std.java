package _131_PalindromePartitioning;

import java.util.ArrayList;
import java.util.List;

public class Std {
	public static void main(String[] args) {
		Solution so = new Solution();
		String s = "abbaabba";
		List<List<String>> lists = so.partition(s);
		for(List<String> list :lists) {
			System.out.println(list);
		}
	}
}

class Solution {

	public List<List<String>> partition(String s) {
		List<List<String>> list = new ArrayList<>();
		backtrack(list, new ArrayList<>(), s, 0);
		return list;
	}

	public void backtrack(List<List<String>> list, List<String> tempList, String s, int start) {
		if (start == s.length())
			list.add(new ArrayList<>(tempList));
		else {
			for (int i = start; i < s.length(); i++) {
				if (isPalindrome(s, start, i)) {
					tempList.add(s.substring(start, i + 1));
					backtrack(list, tempList, s, i + 1);
					tempList.remove(tempList.size() - 1);
				}
			}
		}
	}

	public boolean isPalindrome(String s, int low, int high) {
		while (low < high)
			if (s.charAt(low++) != s.charAt(high--))
				return false;
		return true;
	}

}