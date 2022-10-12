

                    import java.util.*;
                    import utils.TreeNode;
                    import utils.ListNode;
                                            
                        class Solution_219_ContainsDuplicateII_1{
                        
public boolean containsNearbyDuplicate(int[] nums, int k) {
    for (int i = 0; i < nums.length; ++i) {
        for (int j = Math.max(i - k, 0); j < i; ++j) {
            if (nums[i] == nums[j]) return true;
        }
    }
    return false;
}
// Time Limit Exceeded.

                        }
                        public class _219_ContainsDuplicateII_1 {
                            public static void main(String[] args) {
                                Solution_219_ContainsDuplicateII_1 so = new Solution_219_ContainsDuplicateII_1();
                            }
                        }
                        