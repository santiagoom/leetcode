

                    import java.util.*;
                    import utils.TreeNode;
                    import utils.ListNode;
                                            
                        class Solution_219_ContainsDuplicateII_2{
                        
public boolean containsNearbyDuplicate(int[] nums, int k) {
    Set<Integer> set = new TreeSet<>();
    for (int i = 0; i < nums.length; ++i) {
        if (set.contains(nums[i])) return true;
        set.add(nums[i]);
        if (set.size() > k) {
            set.remove(nums[i - k]);
        }
    }
    return false;
}
// Time Limit Exceeded.

                        }
                        public class _219_ContainsDuplicateII_2 {
                            public static void main(String[] args) {
                                Solution_219_ContainsDuplicateII_2 so = new Solution_219_ContainsDuplicateII_2();
                            }
                        }
                        