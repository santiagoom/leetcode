
                        
                    import java.util.*;
                    import utils.TreeNode;
                    import utils.ListNode;
                                            
                                                
class Solution_064_MinimumPathSum_1 {
    public int calculate(int[][] grid, int i, int j) {
        if (i == grid.length || j == grid[0].length) return Integer.MAX_VALUE;
        if (i == grid.length - 1 && j == grid[0].length - 1) return grid[i][j];
        return grid[i][j] + Math.min(calculate(grid, i + 1, j), calculate(grid, i, j + 1));
    }
    public int minPathSum(int[][] grid) {
        return calculate(grid, 0, 0);
    }
}

                                                public class _064_MinimumPathSum_1 {
                                                    public static void main(String[] args) {
                                                        Solution_064_MinimumPathSum_1 so = new Solution_064_MinimumPathSum_1();
                                                    }
                                                }
                                                