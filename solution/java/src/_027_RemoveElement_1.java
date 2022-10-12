

                    import java.util.*;
                    import utils.TreeNode;
                    import utils.ListNode;
                                            
                        class Solution_027_RemoveElement_1{
                        
public int removeElement(int[] nums, int val) {
    int i = 0;
    for (int j = 0; j < nums.length; j++) {
        if (nums[j] != val) {
            nums[i] = nums[j];
            i++;
        }
    }
    return i;
}

                        }
                        public class _027_RemoveElement_1 {
                            public static void main(String[] args) {
                                Solution_027_RemoveElement_1 so = new Solution_027_RemoveElement_1();
                            }
                        }
                        