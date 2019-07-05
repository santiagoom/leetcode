package _037_078_Subsets;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class _78_Subsets {
	public static void main(String[] args) {
		_78_Subsets sb = new _78_Subsets();

		int[] nums = { 1, 2, 3 };

		List<List<Integer>> l = sb.subsets(nums);
		for (List l1 : l) {
			System.out.println(l1);
		}
	}

	public List<List<Integer>> subsets(int[] nums) {
		List<List<Integer>> list = new ArrayList<>();
		Arrays.sort(nums);
		backtrack(list, new ArrayList<>(), nums, 0);
		return list;
	}

	static int step = 0;

	private void backtrack(List<List<Integer>> list, List<Integer> tempList, int[] nums, int start) {
		list.add(new ArrayList<>(tempList));
//		for (int i = start; i < nums.length; System.out.print(start),System.out.print(" "),System.out.print(i),i++) {
		System.out.println("start(before): " + start);
		for (int i = start; i < nums.length; i++) {
			step++;
//			System.out.print(step+"  ");
			System.out.print(start + " mid " + i + "    ");
			tempList.add(nums[i]);
			System.out.print(tempList + ": before");
			System.out.println();
			backtrack(list, tempList, nums, i + 1);
			tempList.remove(tempList.size() - 1);
			System.out.println(tempList + ": after  ");
			System.out.print(start + " after " + i + "    ");
			System.out.println();
		}
		System.out.println();
		System.out.println("hhh");
		System.out.println();
	}
}
