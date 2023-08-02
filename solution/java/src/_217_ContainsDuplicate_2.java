

import java.util.*;

import utils.TreeNode;
import utils.ListNode;
import utils.JavaUtils;

class Solution_217_ContainsDuplicate_2 {

    public boolean containsDuplicate(int[] nums) {
        Arrays.sort(nums);
        for (int i = 0; i < nums.length - 1; ++i) {
            if (nums[i] == nums[i + 1]) return true;
        }
        return false;
    }

}

public class _217_ContainsDuplicate_2 {
    public static void main(String[] args) {
        Solution_217_ContainsDuplicate_2 so = new Solution_217_ContainsDuplicate_2();
        int[] nums = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
        JavaUtils.print_1d_array(nums);
        int[][] arrays = {{2, 7, 9}, {3, 6, 1}, {7, 4, 2}};
        JavaUtils.print_2d_array(arrays);

        int target = 26;
        String s = "aa";
    }
}
                        