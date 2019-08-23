package _000_Algos.Backpack_I;

public class Backpack_I_practise {
    public static void main(String[] args) {
//        Solutionp1 so = new Solutionp1();
        Solutiondp so = new Solutiondp();

        int[] nums = {3, 4, 8, 5};
        int size = 10;
//        int[] nums = {2, 3, 5, 7};
//        int size = 12;

        int res = so.backPack(size, nums);
        System.out.println(res);
    }
}

class Backpack_I_practise_ {

}

class Solutiondp {
    public int backPack(int m, int[] A) {

        int len = A.length;

        int[][] dp = new int[len][m + 1];

        for (int i = 0; i <= m; i++) {
            if (i >= A[0])
                dp[0][i] = A[0];
        }

        for (int i = 1; i < len; i++) {
            for (int j = 0; j <= m; j++) {
                if (j >= A[i]) {
                    dp[i][j] = max(dp[i - 1][j - A[i]] + A[i], dp[i - 1][j]);

                } else {
                    dp[i][j] = dp[i - 1][j];

                }
            }

        }
        return dp[len - 1][m];
    }

    int max(int a, int b) {
        return a > b ? a : b;
    }
}

class Solutionp1 {
    /**
     * @param m: An integer m denotes the size of a backpack
     * @param A: Given n items with size A[i]
     * @return: The maximum size
     */
    public int backPack(int m, int[] A) {
        // write your code here
        return helper(m, A, A.length);
    }

    int helper(int m, int[] A, int length) {
        if (m <= 0 || length == 0)
            return 0;
        if (m < A[length - 1])
            return helper(m, A, length - 1);
        return max(A[length - 1] + helper(m - A[length - 1], A, length - 1), helper(m, A, length - 1));
    }

    int max(int a, int b) {
        return a > b ? a : b;
    }


}