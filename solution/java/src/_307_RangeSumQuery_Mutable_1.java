//
//
//                    import java.util.*;
//                    import utils.TreeNode;
//                    import utils.ListNode;
//                    import utils.JavaUtils;
//
//                        class Solution_307_RangeSumQuery_Mutable_1{
//
//private int[] nums;
//public int sumRange(int i, int j) {
//    int sum = 0;
//    for (int l = i; l <= j; l++) {
//        sum += data[l];
//    }
//    return sum;
//}
//
//public int update(int i, int val) {
//    nums[i] = val;
//}
//// Time Limit Exceeded
//
//                        }
//                        public class _307_RangeSumQuery_Mutable_1 {
//                            public static void main(String[] args) {
//                                Solution_307_RangeSumQuery_Mutable_1 so = new Solution_307_RangeSumQuery_Mutable_1();
//                                 int[] nums = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
//                                                        JavaUtils.print_1d_array(nums);
//                                                        int[][] arrays = {{2, 7, 9}, {3, 6, 1}, {7, 4, 2}};
//                                                        JavaUtils.print_2d_array(arrays);
//
//                                                        int target = 26;
//                                                        String s = "aa";
//                            }
//                        }
//