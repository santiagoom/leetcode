

                    import java.util.*;
                    import utils.TreeNode;
                    import utils.ListNode;
                    import utils.JavaUtils;
                                            
                        class Solution_191_Numberof1Bits_2{
                        
public int hammingWeight(int n) {
    int sum = 0;
    while (n != 0) {
        sum++;
        n &= (n - 1);
    }
    return sum;
}

                        }
                        public class _191_Numberof1Bits_2 {
                            public static void main(String[] args) {
                                Solution_191_Numberof1Bits_2 so = new Solution_191_Numberof1Bits_2();
                                 int[] nums = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
                                                        JavaUtils.print_1d_array(nums);
                                                        int[][] arrays = {{2, 7, 9}, {3, 6, 1}, {7, 4, 2}};
                                                        JavaUtils.print_2d_array(arrays);
                                                
                                                        int target = 26;
                                                        String s = "aa";
                            }
                        }
                        