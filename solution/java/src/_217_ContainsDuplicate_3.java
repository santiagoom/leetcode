
                        
                    import java.util.*;
                    import utils.TreeNode;
                    import utils.ListNode;
                                            
                                                
class Solution_217_ContainsDuplicate_3{
public boolean containsDuplicate(int[] nums) {
    Set<Integer> set = new HashSet<>(nums.length);
    for (int x: nums) {
        if (set.contains(x)) return true;
        set.add(x);
    }
    return false;
}
}

                                                public class _217_ContainsDuplicate_3 {
                                                    public static void main(String[] args) {
                                                        Solution_217_ContainsDuplicate_3 so = new Solution_217_ContainsDuplicate_3();
                                                    }
                                                }
                                                