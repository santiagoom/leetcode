package _034_034_FindFirstAndLastPositionOfElementInSortedArray;

public class Solutions {

}

class SolutionBinarySearch {
	/*
	 * Complexity Analysis
	 * 
	 * Time complexity : O(\log_{10}(n))O(log 10 ​ (n))
	 * 
	 * Because binary search cuts the search space roughly in half on each
	 * iteration, there can be at most \lceil \log_{10}(n) \rceil⌈log 10 ​ (n)⌉
	 * iterations. Binary search is invoked twice, so the overall complexity is
	 * logarithmic.
	 * 
	 * Space complexity : O(1)O(1)
	 * 
	 * All work is done in place, so the overall memory usage is constant.
	 */
	// returns leftmost (or rightmost) index at which `target` should be
	// inserted in sorted array `nums` via binary search.
	private int extremeInsertionIndex(int[] nums, int target, boolean left) {
		int lo = 0;
		int hi = nums.length;

		while (lo < hi) {
			int mid = (lo + hi) / 2;
			if (nums[mid] > target || (left && target == nums[mid])) {
				hi = mid;
			} else {
				lo = mid + 1;
			}
		}

		return lo;
	}

	public int[] searchRange(int[] nums, int target) {
		int[] targetRange = { -1, -1 };

		int leftIdx = extremeInsertionIndex(nums, target, true);

		// assert that `leftIdx` is within the array bounds and that `target`
		// is actually in `nums`.
		if (leftIdx == nums.length || nums[leftIdx] != target) {
			return targetRange;
		}

		targetRange[0] = leftIdx;
		targetRange[1] = extremeInsertionIndex(nums, target, false) - 1;

		return targetRange;
	}
}

class SolutionBF {
	/*
	 * Complexity Analysis
	 * 
	 * Time complexity : O(n)O(n)
	 * 
	 * This brute-force approach examines each of the n elements of nums exactly
	 * twice, so the overall runtime is linear.
	 * 
	 * Space complexity : O(1)O(1)
	 * 
	 * The linear scan method allocates a fixed-size array and a few integers, so it
	 * has a constant-size memory footprint.
	 */
	public int[] searchRange(int[] nums, int target) {
		int[] targetRange = { -1, -1 };

		// find the index of the leftmost appearance of `target`.
		for (int i = 0; i < nums.length; i++) {
			if (nums[i] == target) {
				targetRange[0] = i;
				break;
			}
		}

		// if the last loop did not find any index, then there is no valid range
		// and we return [-1, -1].
		if (targetRange[0] == -1) {
			return targetRange;
		}

		// find the index of the rightmost appearance of `target` (by reverse
		// iteration). it is guaranteed to appear.
		for (int j = nums.length - 1; j >= 0; j--) {
			if (nums[j] == target) {
				targetRange[1] = j;
				break;
			}
		}

		return targetRange;
	}
}