

import java.util.*;

import utils.TreeNode;
import utils.ListNode;
import utils.JavaUtils;

class Solution_219_ContainsDuplicateII_2 {

    public boolean containsNearbyDuplicate(int[] nums, int k) {
        Set<Integer> set = new TreeSet<>();
        for (int i = 0; i < nums.length; ++i) {
            if (set.contains(nums[i])) return true;
            set.add(nums[i]);
            if (set.size() > k) {
                set.remove(nums[i - k]);
            }
        }
        return false;
    }
// Time Limit Exceeded.

}

public class _219_ContainsDuplicateII_2 {
    public static void main(String[] args) {
        Solution_219_ContainsDuplicateII_2 so = new Solution_219_ContainsDuplicateII_2();
        int[] nums = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
        JavaUtils.print_1d_array(nums);
        int[][] arrays = {{2, 7, 9}, {3, 6, 1}, {7, 4, 2}};
        JavaUtils.print_2d_array(arrays);

        int target = 26;
        String s = "aa";
    }
}
                        