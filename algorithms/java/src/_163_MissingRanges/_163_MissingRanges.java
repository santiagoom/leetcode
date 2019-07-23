package _163_MissingRanges;

import java.util.ArrayList;
import java.util.List;

public class _163_MissingRanges {
	public static void main(String[] args) {
	    _163_MissingRanges_ so = new _163_MissingRanges_();

	}
}

class _163_MissingRanges_ {

}

 class Solution1 {
	/*
	 * @param nums: a sorted integer array
	 * @param lower: An integer
	 * @param upper: An integer
	 * @return: a list of its missing ranges
	 */

	private void addRange(List<String> res, long st, long ed) {
		if (st > ed)
			return;
		if (st == ed) {
			res.add(st + "");
			return;
		}
		res.add(st + "->" + ed);
	}

	public List<String> findMissingRanges(int[] nums, int lower, int upper) {
		// write your code here
		List<String> res = new ArrayList<String>();
		if (nums == null || nums.length == 0) {
			addRange(res, (long)lower, (long)upper);
			return res;
		}

		addRange(res, (long)lower, (long)nums[0] - 1);

		for (int i = 1;i < nums.length;i++) {
			addRange(res, (long)nums[i - 1] + 1, (long)nums[i] - 1);
		}

		addRange(res, (long)nums[nums.length - 1] + 1, (long)upper);

		return res;
	}
}
