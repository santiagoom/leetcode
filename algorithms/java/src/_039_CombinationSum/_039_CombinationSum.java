package _041_039_CombinationSum;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class _039_CombinationSum {
	public static void main(String[] args) {
		_039_CombinationSum cs = new _039_CombinationSum();

		int[] nums = { 2,2, 3, 4, 5, 7 };
		int target = 7;
		List<List<Integer>> L = cs.combinationSum(nums, target);
		for (List<Integer> l : L) {
			System.out.println(l);
		}

	}

	public List<List<Integer>> combinationSum(int[] nums, int target) {
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
				tempList.add(nums[i]);
				backtrack(list, tempList, nums, remain - nums[i], i); // not i + 1 because we can reuse same elements
				tempList.remove(tempList.size() - 1);
			}
		}
	}

}
