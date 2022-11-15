
                        
                    import java.util.*;
                    import utils.TreeNode;
                    import utils.ListNode;
                    import utils.JavaUtils;
                                            
                                                
class Solution_326_PowerofThree_2 {
    public boolean isPowerOfThree(int n) {
        return Integer.toString(n, 3).matches("^10*$");
    }
}

                                                public class _326_PowerofThree_2 {
                                                    public static void main(String[] args) {
                                                        Solution_326_PowerofThree_2 so = new Solution_326_PowerofThree_2();
                                                        int[] nums = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
                                                        JavaUtils.print_1d_array(nums);
                                                        int[][] arrays = {{2, 7, 9}, {3, 6, 1}, {7, 4, 2}};
                                                        JavaUtils.print_2d_array(arrays);
                                                
                                                        int target = 26;
                                                        String s = "aa";
                                                    }
                                                }
                                                