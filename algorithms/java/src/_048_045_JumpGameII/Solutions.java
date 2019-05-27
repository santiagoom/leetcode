package _048_045_JumpGameII;

public class Solutions {
	public static void main(String[] args) {
		Solution so = new Solution();

		int A[] = { 2, 3, 1, 1, 4 };
		int out = so.jump(A);
		System.out.println(out);

	}
}

class Solution {
	/*
	 * The main idea is based on greedy. Let's say the range of the current jump is
	 * [curBegin, curEnd],
	 * 
	 * curFarthest is the farthest point that all points in [curBegin, curEnd] can
	 * reach.
	 * 
	 * Once the current point reaches curEnd, then trigger another jump, and set the
	 * new curEnd with curFarthest, then keep the above steps, as the following:
	 * 
	 * Input: [2,3,1,1,4] Output: 2
	 */
	public int jump(int[] A) {
		int jumps = 0, curEnd = 0, curFarthest = 0;
		for (int i = 0; i < A.length - 1; i++) {
			System.out.println(A[i]);
			System.out.println(i + A[i]);
			System.out.println(curEnd);
			System.out.println(curFarthest);
			System.out.println();
			curFarthest = Math.max(curFarthest, i + A[i]);
			if (i == curEnd) {
				jumps++;
				curEnd = curFarthest;
			}
		}
		return jumps;
	}
}
