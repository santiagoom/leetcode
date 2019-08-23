package _078_Subsets;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class Std {

    public static void main(String[] args) {
        Solution so = new Solution();

        int nums[] = {1, 2, 2,2};
        List<List<Integer>> out = so.subsets(nums);
        for (List list : out) {
            System.out.println(list);
        }
    }
}

class Solution {

    public List<List<Integer>> subsets(int[] nums) {
        List<List<Integer>> list = new ArrayList<>();
        Arrays.sort(nums);
        backtrack(list, new ArrayList<>(), nums, 0);
        return list;
    }

    private void backtrack(List<List<Integer>> list, List<Integer> tempList, int[] nums, int start) {
        list.add(new ArrayList<>(tempList));
        for (int i = start; i < nums.length; i++) {
            tempList.add(nums[i]);
            System.out.print(start + " " + i + " ");
            System.out.println(tempList);
            backtrack(list, tempList, nums, i + 1);
            tempList.remove(tempList.size() - 1);
        }
    }
}