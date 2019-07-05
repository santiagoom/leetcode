package _054_055_JumpGame;

public class Solutions {
	public static void main(String[] args) {
		Solution so = new Solution();

//		int[] nums = { 2, 3, 1, 1, 4 };

		int[] nums = { 2, 4, 2, 1, 0, 2, 0 };
		SolutionTopdown sotd = new SolutionTopdown();
		boolean flag = sotd.canJump(nums);
		System.out.println(flag);

	}
}

class Solution {

}

// find the longest jump distance
class SolutionGreedy {
	public boolean canJump(int[] nums) {
		int lastPos = nums.length - 1;
		for (int i = nums.length - 1; i >= 0; i--) {
			if (i + nums[i] >= lastPos) {
				lastPos = i;
			}
		}
		return lastPos == 0;
	}
}

enum Index {
	GOOD, BAD, UNKNOWN
}

class SolutionBottomup {
	public boolean canJump(int[] nums) {
		Index[] memo = new Index[nums.length];
		for (int i = 0; i < memo.length; i++) {
			memo[i] = Index.UNKNOWN;
		}
		memo[memo.length - 1] = Index.GOOD;

		for (int i = nums.length - 2; i >= 0; i--) {
			int furthestJump = Math.min(i + nums[i], nums.length - 1);
			for (int j = i + 1; j <= furthestJump; j++) {
				if (memo[j] == Index.GOOD) {
					memo[i] = Index.GOOD;
					break;
				}
			}
		}

		return memo[0] == Index.GOOD;
	}
}

class SolutionTopdown {
	Index[] memo;

//	int[] nums = { 2, 4, 2, 1, 0, 2, 0 };
	public boolean canJumpFromPosition(int position, int[] nums) {
		if (memo[position] != Index.UNKNOWN) {
			return memo[position] == Index.GOOD ? true : false;
		}

		int furthestJump = Math.min(position + nums[position], nums.length - 1);
		for (int nextPosition = position + 1; nextPosition <= furthestJump; nextPosition++) {
			System.out.println(position);
			System.out.println(nextPosition);
			System.out.println();
			if (canJumpFromPosition(nextPosition, nums)) {
				memo[position] = Index.GOOD;
				return true;
			}
		}

		memo[position] = Index.BAD;
		return false;
	}

	public boolean canJump(int[] nums) {
		memo = new Index[nums.length];
		for (int i = 0; i < memo.length; i++) {
			memo[i] = Index.UNKNOWN;
		}
		memo[memo.length - 1] = Index.GOOD;
		return canJumpFromPosition(0, nums);
	}
}

class SolutionBacktracking {
	/*
	 * Input: [2,3,1,1,4]
	 * 
	 * Output: true
	 */

	public boolean canJumpFromPosition(int position, int[] nums) {
		if (position == nums.length - 1) {
			return true;
		}

		int furthestJump = Math.min(position + nums[position], nums.length - 1);
		for (int nextPosition = position + 1; nextPosition <= furthestJump; nextPosition++) {
			if (canJumpFromPosition(nextPosition, nums)) {
				return true;
			}
		}

		return false;
	}

	public boolean canJump(int[] nums) {
		return canJumpFromPosition(0, nums);
	}
}
