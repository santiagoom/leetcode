package _045_042_TrappingRainWater;

public class Solutions {
	public static void main(String[] args) {
//		SolutionBF sobf = new SolutionBF();
		SolutionUsingTwoPointers sosl = new SolutionUsingTwoPointers();
		int height[] = { 0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1 };
//		int out = sobf.trap(height);
		int out = sosl.trap(height);

		System.out.println(out);
	}
}

class SolutionBF {
	int trap(int[] height) {
		int ans = 0;
		int size = height.length;
//		int height[] = { 0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1 };
		for (int i = 1; i < size - 1; i++) {
			int max_left = 0, max_right = 0;
			for (int j = i; j >= 0; j--) { // Search the left part for max bar size
				max_left = Math.max(max_left, height[j]);
				System.out.println(max_left);
			}
			System.out.println();
			for (int j = i; j < size; j++) { // Search the right part for max bar size
				max_right = Math.max(max_right, height[j]);
				System.out.println(max_right);
			}
			System.out.println();
			ans += Math.min(max_left, max_right) - height[i];
			System.out.println("i: " + i + " ans: " + ans);
			System.out.println();
		}
		return ans;
	}
}

class SolutionUsingTwoPointers {
	/*
	 * Time complexity: O(n)O(n). Single iteration of O(n)O(n).
	 * 
	 * Space complexity: O(1)O(1) extra space. Only constant space required for
	 * \text{left}left, \text{right}right, left_max and right_max.
	 */

	public int trap(int[] A) {
		int a = 0;
		int b = A.length - 1;
		int max = 0;
		int leftmax = 0;
		int rightmax = 0;
		while (a <= b) {
			leftmax = Math.max(leftmax, A[a]);
			rightmax = Math.max(rightmax, A[b]);
			if (leftmax < rightmax) {
				max += (leftmax - A[a]); // leftmax is smaller than rightmax, so the (leftmax-A[a]) water can be stored
				a++;
			} else {
				max += (rightmax - A[b]);
				b--;
			}
		}
		return max;
	}
}