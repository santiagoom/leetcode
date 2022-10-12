

                    import java.util.*;
                    import utils.TreeNode;
                    import utils.ListNode;
                                            
                        class Solution_217_ContainsDuplicate_2{
                        
public boolean containsDuplicate(int[] nums) {
    Arrays.sort(nums);
    for (int i = 0; i < nums.length - 1; ++i) {
        if (nums[i] == nums[i + 1]) return true;
    }
    return false;
}

                        }
                        public class _217_ContainsDuplicate_2 {
                            public static void main(String[] args) {
                                Solution_217_ContainsDuplicate_2 so = new Solution_217_ContainsDuplicate_2();
                            }
                        }
                        