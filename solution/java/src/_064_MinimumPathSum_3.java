

import java.util.*;

import utils.TreeNode;
import utils.ListNode;
import utils.JavaUtils;


class Solution_064_MinimumPathSum_3 {
    public int minPathSum(int[][] grid) {
        int[] dp = new int[grid[0].length];
        for (int i = grid.length - 1; i >= 0; i--) {
            for (int j = grid[0].length - 1; j >= 0; j--) {
                if (i == grid.length - 1 && j != grid[0].length - 1)
                    dp[j] = grid[i][j] + dp[j + 1];
                else if (j == grid[0].length - 1 && i != grid.length - 1)
                    dp[j] = grid[i][j] + dp[j];
                else if (j != grid[0].length - 1 && i != grid.length - 1)
                    dp[j] = grid[i][j] + Math.min(dp[j], dp[j + 1]);
                else
                    dp[j] = grid[i][j];
            }
        }
        return dp[0];
    }
}


public class _064_MinimumPathSum_3 {
    public static void main(String[] args) {
        Solution_064_MinimumPathSum_3 so = new Solution_064_MinimumPathSum_3();

        int[][] arrays = {{1, 3, 1}, {1, 5, 1}, {4, 2, 1}};
        int res = so.minPathSum(arrays);
        JavaUtils.print(res);

        int target = 26;
        String s = "aa";
    }
}
                                                