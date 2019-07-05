package _018_017_LetterCombinationsOfAPhoneNumber;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

public class Solutions {
	public static void main(String[] args) {
		Solution so = new Solution();
		String s1 = "237";
		List<String> output = so.letterCombinations(s1);
		for (String s : output) {
			System.out.println(s);
		}
	}
}

class Solution {
	/*
	 * Here is a backtrack function backtrack(combination, next_digits) which takes
	 * as arguments an ongoing letter combination and the next digits to check.
	 * 
	 * If there is no more digits to check that means that the current combination
	 * is done.
	 * 
	 * If there are still digits to check :
	 * 
	 * Iterate over the letters mapping the next available digit. Append the current
	 * letter to the current combination combination = combination + letter. Proceed
	 * to check next digits : backtrack(combination + letter, next_digits[1:]).
	 * 
	 * Complexity Analysis
	 * 
	 * Time complexity : \mathcal{O}(3^N \times 4^M)O(3 N ¡Á4 M ) where N is the
	 * number of digits in the input that maps to 3 letters (e.g. 2, 3, 4, 5, 6, 8)
	 * and M is the number of digits in the input that maps to 4 letters (e.g. 7,
	 * 9), and N+M is the total number digits in the input.
	 * 
	 * Space complexity : \mathcal{O}(3^N \times 4^M)O(3 N ¡Á4 M ) since one has to
	 * keep 3^N \times 4^M3 N ¡Á4 M solutions.
	 * 
	 */
	Map<String, String> phone = new HashMap<String, String>() {
		{
			put("2", "abc");
			put("3", "def");
			put("4", "ghi");
			put("5", "jkl");
			put("6", "mno");
			put("7", "pqrs");
			put("8", "tuv");
			put("9", "wxyz");
		}
	};

	List<String> output = new ArrayList<String>();

	public void backtrack(String combination, String next_digits) {
		// if there is no more digits to check
		if (next_digits.length() == 0) {
			// the combination is done
			output.add(combination);
		}
		// if there are still digits to check
		else {
			// iterate over all letters which map
			// the next available digit
			String digit = next_digits.substring(0, 1);
			String letters = phone.get(digit);
			for (int i = 0; i < letters.length(); i++) {
				String letter = phone.get(digit).substring(i, i + 1);
				// append the current letter to the combination
				// and proceed to the next digits
				System.out.println(next_digits.substring(1));
				backtrack(combination + letter, next_digits.substring(1));
			}
		}
	}

	public List<String> letterCombinations(String digits) {
		if (digits.length() != 0)
			backtrack("", digits);
		return output;
	}
}