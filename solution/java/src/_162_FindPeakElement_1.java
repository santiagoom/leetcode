
                        
                    import java.util.*;
                    import utils.TreeNode;
                    import utils.ListNode;
                                            
                                                
class Solution_162_FindPeakElement_1 {
    public int findPeakElement(int[] nums) {
        for (int i = 0; i < nums.length - 1; i++) {
            if (nums[i] > nums[i + 1])
                return i;
        }
        return nums.length - 1;
    }
}

                                                public class _162_FindPeakElement_1 {
                                                    public static void main(String[] args) {
                                                        Solution_162_FindPeakElement_1 so = new Solution_162_FindPeakElement_1();
                                                    }
                                                }
                                                