package _946_ValidateStackSequences;

import java.util.Stack;

public class _946_ValidateStackSequences_std {
	public static void main(String[] args) {
	    _946_ValidateStackSequences_std_ so = new _946_ValidateStackSequences_std_();

	}
}

class _946_ValidateStackSequences_std_ {

}

class Solution {
	public boolean validateStackSequences(int[] pushed, int[] popped) {
		int N = pushed.length;
		Stack<Integer> stack = new Stack();

		int j = 0;
		for (int x: pushed) {
			stack.push(x);
			while (!stack.isEmpty() && j < N && stack.peek() == popped[j]) {
				stack.pop();
				j++;
			}
		}

		return j == N;
	}
}
