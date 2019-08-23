package _047_Permutations_II;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class Std {
	/*
	 * int[] nums = { 1, 1, 1, 2, 2, 3 };
	 * 
	 * Permutation_num = A6/(A3*A2)
	 * 
	 * note: if nums[i] == nums[i - 1], no need to use nums[i - 1]
	 */

	public static void main(String[] args) {
		Solution so  = new Solution();
		int[] nums = { 1, 2, 2};

		List<List<Integer>> L = so.permuteUnique(nums);
		int count = 0;
		for (List<Integer> l : L) {
			count++;
			System.out.println(l);
		}
		System.out.println(count);

	}

}

class Solution {

	public List<List<Integer>> permuteUnique(int[] nums) {
		List<List<Integer>> list = new ArrayList<>();
		Arrays.sort(nums);
		backtrack(list, new ArrayList<>(), nums, new boolean[nums.length]);
		return list;
	}

	private void backtrack(List<List<Integer>> list, List<Integer> tempList, int[] nums, boolean[] used) {
		if (tempList.size() == nums.length) {
			list.add(new ArrayList<>(tempList));
		} else {
			for (int i = 0; i < nums.length; i++) {
				if (used[i] || i > 0 && nums[i] == nums[i - 1] && used[i - 1])
					continue;
				used[i] = true;
				tempList.add(nums[i]);
				backtrack(list, tempList, nums, used);
				used[i] = false;
				tempList.remove(tempList.size() - 1);
			}
		}
	}
}