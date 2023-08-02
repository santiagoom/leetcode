

import java.util.*;

import utils.TreeNode;
import utils.ListNode;
import utils.JavaUtils;


class Solution_217_ContainsDuplicate_3 {
    public boolean containsDuplicate(int[] nums) {
        Set<Integer> set = new HashSet<>(nums.length);
        for (int x : nums) {
            if (set.contains(x)) return true;
            set.add(x);
        }
        return false;
    }
}

public class _217_ContainsDuplicate_3 {
    public static void main(String[] args) {
        Solution_217_ContainsDuplicate_3 so = new Solution_217_ContainsDuplicate_3();
        int[] nums = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
        JavaUtils.print_1d_array(nums);
        int[][] arrays = {{2, 7, 9}, {3, 6, 1}, {7, 4, 2}};
        JavaUtils.print_2d_array(arrays);

        int target = 26;
        String s = "aa";
    }
}
                                                