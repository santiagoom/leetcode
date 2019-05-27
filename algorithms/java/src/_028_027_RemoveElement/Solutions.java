package _028_027_RemoveElement;

public class Solutions {

	/*
	 * // nums is passed in by reference. (i.e., without making a copy) int len =
	 * removeElement(nums, val);
	 * 
	 * // any modification to nums in your function would be known by the caller. //
	 * using the length returned by your function, it prints the first len elements.
	 * for (int i = 0; i < len; i++) { print(nums[i]); }
	 */
}

class SolutionTwoPointers {
	/*
	 * Complexity analysis
	 * 
	 * Time complexity : O(n)O(n). Assume the array has a total of nn elements, both
	 * ii and jj traverse at most 2n2n steps.
	 * 
	 * Space complexity : O(1)O(1).
	 */
	public int removeElement(int[] nums, int val) {
		int i = 0;
		for (int j = 0; j < nums.length; j++) {
			if (nums[j] != val) {
				nums[i] = nums[j];
				i++;
			}
		}
		return i;
	}
}

//Two Pointers - when elements to remove are rare
class SolutiaonTwoPointersOptimized {
	/*
	 * Complexity analysis
	 * 
	 * Time complexity : O(n)O(n). Both ii and nn traverse at most nn steps. In this
	 * approach, the number of assignment operation is equal to the number of
	 * elements to remove. So it is more efficient if elements to remove are rare.
	 * 
	 * Space complexity : O(1)O(1).
	 */
	public int removeElement(int[] nums, int val) {
		int i = 0;
		int n = nums.length;
		while (i < n) {
			if (nums[i] == val) {
				nums[i] = nums[n - 1];
				// reduce array size by one
				n--;
			} else {
				i++;
			}
		}
		return n;
	}
}