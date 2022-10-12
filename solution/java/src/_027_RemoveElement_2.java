

                    import java.util.*;
                    import utils.TreeNode;
                    import utils.ListNode;
                                            
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
                            }
                        }
                        