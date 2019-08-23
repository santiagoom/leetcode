package _000_Algos.Backpack_IV;


public class Backpack_IV_std_debug {
    public static void main(String[] args) {
//        Solution1_debug so = new Solution1_debug();
        Solution2_debug so = new Solution2_debug();
//        Solution1_opt_debug so = new Solution1_opt_debug();
        int[] nums = {2, 3, 6, 7};
        int target = 7;
        int res = so.backPackIV(nums, target);
        System.out.println(res);

    }
}


/**
 * This reference program is provided by @jiuzhang.com
 * Copyright is reserved. Please indicate the source for forwarding
 */

// 方法一
class Solution1_debug {
//    f[i][j]表示只考虑前i件物品，取到物品重量和为j的方法数量，这题和完全背包做法类似

    /**
     * @param nums   an integer array and all positive numbers, no duplicates
     * @param target an integer
     * @return an integer
     */
    public int backPackIV(int[] nums, int target) {
        // Write your code here
        int f[][] = new int[nums.length + 1][target + 1];

        f[0][0] = 1;
//        second dimetion [0] j - nums[i - 1] * k
//        int[] nums = {2, 3, 6, 7};

        for (int i = 1; i <= nums.length; i++) {
            for (int j = 0; j <= target; j++) {
                int k = 0;
                while (k * nums[i - 1] <= j) {
                    f[i][j] += f[i - 1][j - nums[i - 1] * k];
                    System.out.println("i: " + i + ", j: " + j + ", f: " + f[i][j] + " " + nums[i - 1]);
                    k += 1;
                }
                System.out.println();
            } // for j
        } // for i


        for (int i = 0; i <= nums.length; i++) {
            for (int j = 0; j <= target; j++) {
                System.out.print(f[i][j] + " ");

            }
            System.out.println();
        }

        return f[nums.length][target];
    }
}

// 方法一
class Solution1_opt_debug {
//    f[i][j]表示只考虑前i件物品，取到物品重量和为j的方法数量，这题和完全背包做法类似

    /**
     * @param nums   an integer array and all positive numbers, no duplicates
     * @param target an integer
     * @return an integer
     */
    public int backPackIV(int[] nums, int target) {
        // Write your code here
        int f[][] = new int[2][target + 1];

        f[0][0] = 1;
//        second dimetion [0] j - nums[i - 1] * k
//        int[] nums = {2, 3, 6, 7};
        int bi = 1;
        for (int i = 1; i <= nums.length; i++) {

            bi = i & 1;
            f[bi][0] = 0;
            System.out.println(bi);
            for (int j = 1; j <= target; j++) {
                int k = 0;
                while (k * nums[i - 1] <= j) {
                    f[bi][j] += f[1 - bi][j - nums[i - 1] * k];
                    k += 1;
                }
            } // for j
            for (int k = 0; k < 2; k++) {
                for (int j = 0; j < target + 1; j++) {
                    System.out.print(f[k][j]);
                }
                System.out.println();
            }
        } // for i

//        for (int i = 0; i < 2; i++) {
//            for (int j = 0; j < target + 1; j++) {
//                System.out.print(f[i][j]);
//            }
//            System.out.println();
//        }

        return f[bi][target];
    }
}

// 方法二

class Solution2_debug {
    /**
     * @param nums   an integer array and all positive numbers, no duplicates
     * @param target an integer
     * @return an integer
     */
    //        int[] nums = {2, 3, 6, 7};
    public int backPackIV(int[] nums, int target) {
        // Write your code here
        int[] f = new int[target + 1];
        f[0] = 1;
        for (int i = 0; i < nums.length; ++i) {
            for (int j = nums[i]; j <= target; ++j)
                f[j] += f[j - nums[i]];
            for (int k = 0; k < f.length; k++) {
                System.out.print(f[k]);
            }
            System.out.println();
        }

        for (int x : f) {
            System.out.print(x + " ");
        }
        System.out.println();
        return f[target];
    }
}