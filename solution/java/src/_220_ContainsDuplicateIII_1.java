

import java.util.*;

import utils.TreeNode;
import utils.ListNode;
import utils.JavaUtils;


class Solution_220_ContainsDuplicateIII_1 {
    public boolean containsNearbyAlmostDuplicate(int[] nums, int k, int t) {
        for (int i = 0; i < nums.length; ++i) {
            for (int j = Math.max(i - k, 0); j < i; ++j) {
                if (Math.abs((long) nums[i] - nums[j]) <= t) return true;
            }
        }
        return false;
    }
}

public class _220_ContainsDuplicateIII_1 {
    public static void main(String[] args) {
        Solution_220_ContainsDuplicateIII_1 so = new Solution_220_ContainsDuplicateIII_1();
        int[] nums = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
        JavaUtils.print_1d_array(nums);
        int[][] arrays = {{2, 7, 9}, {3, 6, 1}, {7, 4, 2}};
        JavaUtils.print_2d_array(arrays);

        int target = 26;
        String s = "aa";
    }
}
                                                