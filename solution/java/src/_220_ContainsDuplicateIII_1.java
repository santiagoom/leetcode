
                        
                    import java.util.*;
                    import utils.TreeNode;
                    import utils.ListNode;
                                            
                                                
class Solution_220_ContainsDuplicateIII_1 {
    public boolean containsNearbyAlmostDuplicate(int[] nums, int k, int t) {
        for (int i = 0; i < nums.length; ++i) {
            for (int j = Math.max(i - k, 0); j < i; ++j) {
                if (Math.abs((long) nums[i] - nums[j]) <= t) return true;
            }
        }
        return false;
    }
}

                                                public class _220_ContainsDuplicateIII_1 {
                                                    public static void main(String[] args) {
                                                        Solution_220_ContainsDuplicateIII_1 so = new Solution_220_ContainsDuplicateIII_1();
                                                    }
                                                }
                                                