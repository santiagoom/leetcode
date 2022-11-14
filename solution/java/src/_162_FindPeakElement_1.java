

import java.util.*;

import utils.TreeNode;
import utils.ListNode;
import utils.JavaUtils;


class Solution_162_FindPeakElement_1 {
    public int findPeakElement(int[] nums) {
        for (int i = 0; i < nums.length - 1; i++) {
            if (nums[i] > nums[i + 1])
                return i;
        }
        return nums.length - 1;
    }
}

public class _162_FindPeakElement_1 {
    public static void main(String[] args) {
        Solution_162_FindPeakElement_1 so = new Solution_162_FindPeakElement_1();
//        int[] nums = {1, 2, 3, 1};
        int[] nums = {1,2,1,3,5,6,4};

        int index = so.findPeakElement(nums);
        JavaUtils.print(index);
    }
}
                                                