

                    import java.util.*;
                    import utils.TreeNode;
                    import utils.ListNode;
                    import utils.JavaUtils;
                                            
                        class Solution_027_RemoveElement_2{
                        
public int removeElement(int[] nums, int val) {
    int i = 0;
    int n = nums.length;
    while (i < n) {
        if (nums[i] == val) {
            nums[i] = nums[n - 1];
            // reduce array size by one
            n--;
        } else {
            i++;
        }
    }
    return n;
}

                        }
                        public class _027_RemoveElement_2 {
                            public static void main(String[] args) {
                                Solution_027_RemoveElement_2 so = new Solution_027_RemoveElement_2();
                                 int[] nums = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
                                                        JavaUtils.print_1d_array(nums);
                                                        int[][] arrays = {{2, 7, 9}, {3, 6, 1}, {7, 4, 2}};
                                                        JavaUtils.print_2d_array(arrays);
                                                
                                                        int target = 26;
                                                        String s = "aa";
                            }
                        }
                        