
                        
                    import java.util.*;
                    import utils.TreeNode;
                    import utils.ListNode;
                                            
                                                
class Solution_162_FindPeakElement_2 {
    public int findPeakElement(int[] nums) {
        return search(nums, 0, nums.length - 1);
    }
    public int search(int[] nums, int l, int r) {
        if (l == r)
            return l;
        int mid = (l + r) / 2;
        if (nums[mid] > nums[mid + 1])
            return search(nums, l, mid);
        return search(nums, mid + 1, r);
    }
}

                                                public class _162_FindPeakElement_2 {
                                                    public static void main(String[] args) {
                                                        Solution_162_FindPeakElement_2 so = new Solution_162_FindPeakElement_2();
                                                    }
                                                }
                                                