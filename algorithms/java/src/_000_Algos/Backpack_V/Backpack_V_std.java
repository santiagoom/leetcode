package _000_Algos.Backpack_V;

public class Backpack_V_std {
    public static void main(String[] args) {
        Solution1 so = new Solution1();
        int[] nums = {1,2,3,3,7};
        int target = 7;
        int res = so.backPackV(nums, target);
        System.out.println(res);

    }
}

class Backpack_V_std_ {

}


/**
 * This reference program is provided by @jiuzhang.com
 * Copyright is reserved. Please indicate the source for forwarding
 */

class Solution1 {
    /**
     * @param nums   an integer array and all positive numbers
     * @param target an integer
     * @return an integer
     */
    public int backPackV(int[] nums, int target) {
        // Write your code here
        int[] f = new int[target + 1];
        f[0] = 1;
        for (int i = 0; i < nums.length; ++i)
            for (int j = target; j >= nums[i]; --j)
                f[j] += f[j - nums[i]];

        return f[target];
    }
}