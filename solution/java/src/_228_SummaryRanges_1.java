
                        
                    import java.util.*;
                    import utils.TreeNode;
                    import utils.ListNode;
                                            
                                                
class Solution_228_SummaryRanges_1 {
    public List<String> summaryRanges(int[] nums) {
        List<String> summary = new ArrayList<>();
        for (int i = 0, j = 0; j < nums.length; ++j) {
            // check if j + 1 extends the range [nums[i], nums[j]]
            if (j + 1 < nums.length && nums[j + 1] == nums[j] + 1)
                continue;
            // put the range [nums[i], nums[j]] into the list
            if (i == j)
                summary.add(nums[i] + "");
            else
                summary.add(nums[i] + "->" + nums[j]);
            i = j + 1;
        }
        return summary;
    }
}

                                                public class _228_SummaryRanges_1 {
                                                    public static void main(String[] args) {
                                                        Solution_228_SummaryRanges_1 so = new Solution_228_SummaryRanges_1();
                                                    }
                                                }
                                                