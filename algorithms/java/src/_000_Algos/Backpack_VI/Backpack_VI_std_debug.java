package _000_Algos.Backpack_VI;

public class Backpack_VI_std_debug {
    public static void main(String[] args) {
        Solution1_debug so = new Solution1_debug();
        int[] nums = {1, 2, 4};
        int target = 4;
        int res = so.backPackVI(nums, target);
        System.out.println(res);
    }
}


class Solution1_debug {
    /**
     * @param A: an integer array and all positive numbers, no duplicates
     * @param k: An integer
     * @return: An integer
     */
//    int[] nums = {1, 2, 4};
    public int backPackVI(int[] A, int k) {
        // write your code here
        int n = A.length;

        int[] dp = new int[k + 1];

        dp[0] = 1;

        for (int i = 1; i <= k; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i - A[j] >= 0) {
                    dp[i] += dp[i - A[j]];
                }
            }
            System.out.println("i:" + i);
            for (int m = 0; m < dp.length; m++) {
                System.out.print(dp[m]);
            }
            System.out.println();
        }

        return dp[k];
    }
}