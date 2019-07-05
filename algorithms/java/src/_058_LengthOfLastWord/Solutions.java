package _057_058_LengthOfLastWord;

public class Solutions {
	public static void main(String[] args) {
		Solution so = new Solution();

	}
}

class Solution {
}

class SolutionV2 {
	public int lengthOfLastWord(String s) {
		return s.trim().length() - s.trim().lastIndexOf(" ") - 1;
	}
}

class SolutionV1 {

	public int lengthOfLastWord(String s) {
		String use = s.trim();
		int count = 0;
		for (int i = use.length() - 1; i >= 0; i--) {
			if (use.charAt(i) != ' ')
				count++;
			else
				break;
		}
		return count;
	}

}
