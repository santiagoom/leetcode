package _023_022_GenerateParentheses;

import java.util.ArrayList;
import java.util.List;

public class Solutions {
	public static void main(String[] args) {
//		SolutionBruteForce sobf = new SolutionBruteForce();
//		List<String> out = sobf.generateParenthesis(3);
//		System.out.println();
//		for (String s : out) {
//			System.out.println(s);
//		}

		SolutionBacktracking sobk = new SolutionBacktracking();
		List<String> out = sobk.generateParenthesis(3);
		for (String s : out) {
			System.out.println(s);
		}
	}
}

class SolutionBacktracking {
	/*
	 * Instead of adding '(' or ')' every time as in Approach 1, let's only add them
	 * when we know it will remain a valid sequence. We can do this by keeping track
	 * of the number of opening and closing brackets we have placed so far.
	 * 
	 * We can start an opening bracket if we still have one (of n) left to place.
	 * And we can start a closing bracket if it would not exceed the number of
	 * opening brackets.
	 * 
	 * Our complexity analysis rests on understanding how many elements there are in
	 * generateParenthesis(n). This analysis is outside the scope of this article,
	 * but it turns out this is the n-th Catalan number
	 */
	public List<String> generateParenthesis(int n) {
		List<String> ans = new ArrayList();
		backtrack(ans, "", 0, 0, n);
		return ans;
	}

	public void backtrack(List<String> ans, String cur, int open, int close, int max) {
		if (cur.length() == max * 2) {
			ans.add(cur);
			return;
		}

		if (open < max)
			backtrack(ans, cur + "(", open + 1, close, max);
		if (close < open)
			backtrack(ans, cur + ")", open, close + 1, max);
	}
}

class SolutionBruteForce {
	/*
	 * We can generate all 2^{2n}2 2n sequences of '(' and ')' characters. Then, we
	 * will check if each one is valid. Complexity Analysis
	 * 
	 * Time Complexity : O(2^{2n}n)O(2 2n n). For each of 2^{2n}2 2n sequences, we
	 * need to create and validate the sequence, which takes O(n)O(n) work.
	 * 
	 * Space Complexity : O(2^{2n}n)O(2 2n n). Naively, every sequence could be
	 * valid. See Approach 3 for development of a tighter asymptotic bound.
	 */
	public List<String> generateParenthesis(int n) {
		List<String> combinations = new ArrayList();
		generateAll(new char[2 * n], 0, combinations);
		return combinations;
	}

	public void generateAll(char[] current, int pos, List<String> result) {
		if (pos == current.length) {
			if (valid(current))
				result.add(new String(current));
		} else {
			current[pos] = '(';
			System.out.println(current);
			generateAll(current, pos + 1, result);
			current[pos] = ')';
			System.out.println(current);
			generateAll(current, pos + 1, result);
		}
	}

	public boolean valid(char[] current) {
		int balance = 0;
		for (char c : current) {
			if (c == '(')
				balance++;
			else
				balance--;
			if (balance < 0)
				return false;
		}
		return (balance == 0);
	}
}
