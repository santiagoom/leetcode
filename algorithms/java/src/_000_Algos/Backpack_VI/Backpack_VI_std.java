package _000_Algos.Backpack_VI;

public class Backpack_VI_std {
    public static void main(String[] args) {
        Backpack_VI_std_ so = new Backpack_VI_std_();

    }
}

class Backpack_VI_std_ {

}

class Solution1 {
    /**
     * @param A: an integer array and all positive numbers, no duplicates
     * @param k: An integer
     * @return: An integer
     */
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
        }

        return dp[k];
    }
}