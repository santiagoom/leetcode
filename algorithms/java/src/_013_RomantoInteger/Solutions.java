package _014_013_RomantoInteger;

import java.util.HashMap;

public class Solutions {
	public static void main(String[] args) {
		String s = "MCMXCIV";
		int out = Solutions.romanToInt_v1(s);
		System.out.println(out);
		System.out.println(s.charAt(0));
	}

	public static int romanToInt_v1(String s) {
		if (s == null || s.length() == 0)
			return -1;
		HashMap<Character, Integer> map = new HashMap<Character, Integer>();
		map.put('I', 1);
		map.put('V', 5);
		map.put('X', 10);
		map.put('L', 50);
		map.put('C', 100);
		map.put('D', 500);
		map.put('M', 1000);
		int len = s.length(), result = map.get(s.charAt(len - 1));
		for (int i = len - 2; i >= 0; i--) {
			if (map.get(s.charAt(i)) >= map.get(s.charAt(i + 1)))
				result += map.get(s.charAt(i));
			else
				result -= map.get(s.charAt(i));
		}
		return result;
	}

	public static int romanToInt_v2(String s) {
		// Input: "MCMXCIV"
		// Output: 1994
		// Explanation: M = 1000, CM = 900, XC = 90 and IV = 4.

		HashMap<String, Integer> map = new HashMap<String, Integer>();
		map.put("M", 1000);
		map.put("CM", 900);
		map.put("D", 500);
		map.put("CD", 400);
		map.put("C", 100);
		map.put("XC", 90);
		map.put("L", 50);
		map.put("XL", 40);
		map.put("X", 10);
		map.put("IX", 9);
		map.put("V", 5);
		map.put("IV", 4);
		map.put("I", 1);

		int result = 0;
		for (int i = s.length() - 1; i > 0; i--) {

		}

		return 0;
	}
}
