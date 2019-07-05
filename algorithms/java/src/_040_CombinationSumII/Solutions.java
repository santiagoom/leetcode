package _042_040_CombinationSumII;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class Solutions {
	public static void main(String[] args) {
		Solution so = new Solution();

		int[] nums = { 2, 2, 3, 4, 5, 7 };
		int target = 7;
		List<List<Integer>> L = so.combinationSum2(nums, target);
		for (List<Integer> l : L) {
			System.out.println(l);
		}

	}

}

class Solution {

	public List<List<Integer>> combinationSum2(int[] nums, int target) {
		List<List<Integer>> list = new ArrayList<>();
		Arrays.sort(nums);
		backtrack(list, new ArrayList<>(), nums, target, 0);
		return list;

	}

	private void backtrack(List<List<Integer>> list, List<Integer> tempList, int[] nums, int remain, int start) {
		if (remain < 0)
			return;
		else if (remain == 0)
			list.add(new ArrayList<>(tempList));
		else {
			for (int i = start; i < nums.length; i++) {
				if (i > start && nums[i] == nums[i - 1])
					continue; // skip duplicates
				tempList.add(nums[i]);
				backtrack(list, tempList, nums, remain - nums[i], i + 1);
				tempList.remove(tempList.size() - 1);
			}
		}
	}
}