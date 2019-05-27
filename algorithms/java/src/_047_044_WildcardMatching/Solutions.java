package _047_044_WildcardMatching;

public class Solutions {
	public static void main(String[] args) {
		Solution so = new Solution();

		String s = "adceb";
//		String p = "*e*b";
		String p = "*a*b";
		boolean b = so.comparison(s, p);
		System.out.println(b);
	}

}

class Solution {
	/*
	 * The basic idea is to have one pointer for the string and one pointer for the
	 * pattern. This algorithm iterates at most length(string) + length(pattern)
	 * times, for each iteration, at least one pointer advance one step.
	 * 
	 * Analysis:
	 * 
	 * For each element in s If *s==*p or *p == ? which means this is a match, then
	 * goes to next element s++ p++. If p=='*', this is also a match, but one or
	 * many chars may be available, so let us save this *'s position and the matched
	 * s position. If not match, then we check if there is a * previously showed up,
	 * if there is no *, return false; if there is an *, we set current p to the
	 * next element of *, and set current s to the next saved s position.
	 * 
	 * e.g.
	 * 
	 * abed ?b*d**
	 * 
	 * a=?, go on, b=b, go on, e=*, save * position star=3, save s position ss = 3,
	 * p++ e!=d, check if there was a *, yes, ss++, s=ss; p=star+1 d=d, go on, meet
	 * the end. check the rest element in p, if all are *, true, else false;
	 * 
	 * s = "adceb" p = "*e*b" s = "adceb" p = "*a*b"
	 * 
	 * Linear runtime and constant space solution
	 * 
	 */
	boolean comparison(String str, String pattern) {
		int s = 0, p = 0, match = 0, starIdx = -1;
		while (s < str.length()) {
			System.out.println(str.charAt(s));
			System.out.println(pattern.charAt(p));
			// advancing both pointers
			if (p < pattern.length() && (pattern.charAt(p) == '?' || str.charAt(s) == pattern.charAt(p))) {
				s++;
				p++;
				System.out.println("1");
				System.out.println("s: " + s);
				System.out.println("p: " + p);
				System.out.println("m: " + match);
				System.out.println("sId: " + starIdx);
				System.out.println();
			}
			// * found, only advancing pattern pointer
			else if (p < pattern.length() && pattern.charAt(p) == '*') {
				starIdx = p;
				match = s;
				p++;
				System.out.println("2");
				System.out.println("s: " + s);
				System.out.println("p: " + p);
				System.out.println("m: " + match);
				System.out.println("sId: " + starIdx);
				System.out.println();
			}
			// last pattern pointer was *, advancing string pointer
			else if (starIdx != -1) {
				p = starIdx + 1;
				match++;
				s = match;
				System.out.println("3");
				System.out.println("s: " + s);
				System.out.println("p: " + p);
				System.out.println("m: " + match);
				System.out.println("sId: " + starIdx);
				System.out.println();
			}
			// current pattern pointer is not star, last patter pointer was not *
			// characters do not match
			else
				return false;
		}
		// check for remaining characters in pattern
		while (p < pattern.length() && pattern.charAt(p) == '*')
			p++;
		return p == pattern.length();
	}
}