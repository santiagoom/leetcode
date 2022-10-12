

                    import java.util.*;
                    import utils.TreeNode;
                    import utils.ListNode;
                                            
                        class Solution_217_ContainsDuplicate_1{
                        
public boolean containsDuplicate(int[] nums) {
    for (int i = 0; i < nums.length; ++i) {
        for (int j = 0; j < i; ++j) {
            if (nums[j] == nums[i]) return true;  
        }
    }
    return false;
}
// Time Limit Exceeded

                        }
                        public class _217_ContainsDuplicate_1 {
                            public static void main(String[] args) {
                                Solution_217_ContainsDuplicate_1 so = new Solution_217_ContainsDuplicate_1();
                            }
                        }
                        