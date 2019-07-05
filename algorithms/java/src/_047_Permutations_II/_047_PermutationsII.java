package _040_047_Permutations_II;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class _047_PermutationsII {

	public static void main(String[] args) {
		_047_PermutationsII puII = new _047_PermutationsII();

//		int[] nums = { 1, 1, 1, 2, 2, 3 };
		int[] nums = { 1, 2, 2};

		List<List<Integer>> L = puII.permuteUnique(nums);
		int count = 0;
		for (List<Integer> l : L) {
			count++;
			System.out.println(l);
		}
		System.out.println(count);
	}

	public List<List<Integer>> permuteUnique(int[] nums) {
		List<List<Integer>> list = new ArrayList<>();
		Arrays.sort(nums);
		backtrack(list, new ArrayList<>(), nums, new boolean[nums.length]);
		return list;
	}

	private void backtrack(List<List<Integer>> list, List<Integer> tempList, int[] nums, boolean[] used) {
		System.out.println("out: " + tempList);
		for (boolean f : used) {
			System.out.print(f + " ");
		}
		System.out.println();
		if (tempList.size() == nums.length) {
			list.add(new ArrayList<>(tempList));
		} else {
			for (int i = 0; i < nums.length; i++,System.out.println("I: "+i)) {
				System.out.println("i: " + i);
				boolean f = used[i] || i > 0 && nums[i] == nums[i - 1] && !used[i - 1];
				System.out.println(f);
				if (used[i] || i > 0 && nums[i] == nums[i - 1] && !used[i - 1]) {
					System.out.println("continue: " + tempList);
					continue;
				}
				used[i] = true;
				tempList.add(nums[i]);
				System.out.println();
				backtrack(list, tempList, nums, used);
				System.out.println("after i: " + i);
				used[i] = false;
				for (boolean f1 : used) {
					System.out.print(f1 + " +");
				}
				System.out.println();
				tempList.remove(tempList.size() - 1);
				System.out.println("remove: " + tempList);

			}
		}
	}
}
