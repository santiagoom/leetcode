package _046_Permutations;

import java.util.ArrayList;
import java.util.List;

public class _046_Permutations {
	public static void main(String[] args) {
		_046_Permutations pu = new _046_Permutations();
		int[] nums = { 1, 2, 3 };

		List<List<Integer>> L = pu.permute(nums);
		for (List<Integer> l : L) {
			System.out.println(l);
		}
	}

	public List<List<Integer>> permute(int[] nums) {
		List<List<Integer>> list = new ArrayList<>();
		// Arrays.sort(nums); // not necessary
		backtrack(list, new ArrayList<>(), nums);
		return list;
	}

	private void backtrack(List<List<Integer>> list, List<Integer> tempList, int[] nums) {
		System.out.println("entrance: " + tempList);
		if (tempList.size() == nums.length) {
			list.add(new ArrayList<>(tempList));
		} else {
			for (int i = 0; i < nums.length; i++,System.out.println("I: "+i)) {

				System.out.println("mid: " + i);

				if (tempList.contains(nums[i]))
					continue; // element already exists, skip
				tempList.add(nums[i]);
				System.out.println("mid: " + tempList);
				backtrack(list, tempList, nums);
				tempList.remove(tempList.size() - 1);
				System.out.println("after: " + tempList);
				System.out.println("after: " + i);
			}
		}
	}

}
