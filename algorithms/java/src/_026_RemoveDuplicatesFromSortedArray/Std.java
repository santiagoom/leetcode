package _026_RemoveDuplicatesFromSortedArray;

 class Solutions {
	/*
	 * Internally you can think of this:
	 * 
	 * // nums is passed in by reference. (i.e., without making a copy)
	 * 
	 * int len = removeDuplicates(nums);
	 * 
	 * // any modification to nums in your function would be known by the caller.
	 * 
	 * // using the length returned by your function, it prints the first len
	 * elements.
	 * 
	 * for (int i = 0; i < len; i++) { print(nums[i]); }
	 */
}

class SolutionTwoPointers {
	public int removeDuplicates(int[] nums) {
		if (nums.length == 0)
			return 0;
		int i = 0;
		for (int j = 1; j < nums.length; j++) {
			if (nums[j] != nums[i]) {
				i++;
				nums[i] = nums[j];
			}
		}
		return i + 1;
	}
}