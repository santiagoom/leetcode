
                        
                    import java.util.*;
                    import utils.TreeNode;
                    import utils.ListNode;
                                            
                                                
class Solution_219_ContainsDuplicateII_3 {
public boolean containsNearbyDuplicate(int[] nums, int k) {
    Set<Integer> set = new HashSet<>();
    for (int i = 0; i < nums.length; ++i) {
        if (set.contains(nums[i])) return true;
        set.add(nums[i]);
        if (set.size() > k) {
            set.remove(nums[i - k]);
        }
    }
    return false;
}
}

                                                public class _219_ContainsDuplicateII_3 {
                                                    public static void main(String[] args) {
                                                        Solution_219_ContainsDuplicateII_3 so = new Solution_219_ContainsDuplicateII_3();
                                                    }
                                                }
                                                