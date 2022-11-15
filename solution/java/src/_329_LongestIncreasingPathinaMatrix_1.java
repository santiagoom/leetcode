
                        
                    import java.util.*;
                    import utils.TreeNode;
                    import utils.ListNode;
                    import utils.JavaUtils;
                                            
                                                
// Naive DFS Solution
// Time Limit Exceeded
class Solution_329_LongestIncreasingPathinaMatrix_1 {
  private static final int[][] dirs = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
  private int m, n;

  public int longestIncreasingPath(int[][] matrix) {
      if (matrix.length == 0) return 0;
      m = matrix.length;
      n = matrix[0].length;
      int ans = 0;
      for (int i = 0; i < m; ++i)
          for (int j = 0; j < n; ++j)
              ans = Math.max(ans, dfs(matrix, i, j));
      return ans;
  }

  private int dfs(int[][] matrix, int i, int j) {
      int ans = 0;
      for (int[] d : dirs) {
          int x = i + d[0], y = j + d[1];
          if (0 <= x && x < m && 0 <= y && y < n && matrix[x][y] > matrix[i][j])
              ans = Math.max(ans, dfs(matrix, x, y));
      }
      return ++ans;
  }
}

                                                public class _329_LongestIncreasingPathinaMatrix_1 {
                                                    public static void main(String[] args) {
                                                        Solution_329_LongestIncreasingPathinaMatrix_1 so = new Solution_329_LongestIncreasingPathinaMatrix_1();
                                                        int[] nums = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
                                                        JavaUtils.print_1d_array(nums);
                                                        int[][] arrays = {{2, 7, 9}, {3, 6, 1}, {7, 4, 2}};
                                                        JavaUtils.print_2d_array(arrays);
                                                
                                                        int target = 26;
                                                        String s = "aa";
                                                    }
                                                }
                                                