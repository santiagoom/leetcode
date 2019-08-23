package _000_Algos.Backpack_I;

public class Backpack_I_std {
    public static void main(String[] args) {
        int m = 10;
        int[] arr = {3, 4, 8, 5};
        int s = new Solution1().backPack(m, arr);
        System.out.println(s);
    }
}

class Backpack_I_std_ {

}


class Solution1 {
    /**
     * @param m: An integer m denotes the size of a backpack
     * @param A: Given n items with size A[i]
     * @return: The maximum size
     */
    public int backPack(int m, int[] A) {
        if (m <= 0 || A == null || A.length == 0) {
            return 0;
        }
        int len = A.length;
        int[][] dp = new int[len][m + 1];
        for (int i = 0; i <= m; i++) {
            if (i >= A[0])
                dp[0][i] = A[0];
        }
        for(int i = 0;i<len;i++){
            for(int j = 0;j<m+1;j++)
                System.out.print(dp[i][j]);

            System.out.println();
        }
        System.out.println(dp);
        for (int i = 1; i < len; i++) {
            for (int j = 0; j <= m; j++) {
                if (j >= A[i]) {
                    dp[i][j] = Math.max(dp[i - 1][j], dp[i - 1][j - A[i]] + A[i]);
                } else {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }
        return dp[len - 1][m];
    }


}