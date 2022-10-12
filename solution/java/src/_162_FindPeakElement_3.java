
                        
                    import java.util.*;
                    import utils.TreeNode;
                    import utils.ListNode;
                                            
                                                
class Solution_162_FindPeakElement_3 {
    public int findPeakElement(int[] nums) {
        int l = 0, r = nums.length - 1;
        while (l < r) {
            int mid = (l + r) / 2;
            if (nums[mid] > nums[mid + 1])
                r = mid;
            else
                l = mid + 1;
        }
        return l;
    }
}

                                                public class _162_FindPeakElement_3 {
                                                    public static void main(String[] args) {
                                                        Solution_162_FindPeakElement_3 so = new Solution_162_FindPeakElement_3();
                                                    }
                                                }
                                                