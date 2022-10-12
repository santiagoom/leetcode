
                        
                    import java.util.*;
                    import utils.TreeNode;
                    import utils.ListNode;
                                            
                                                
class Solution_055_JumpGame_4 {
    public boolean canJump(int[] nums) {
        int lastPos = nums.length - 1;
        for (int i = nums.length - 1; i >= 0; i--) {
            if (i + nums[i] >= lastPos) {
                lastPos = i;
            }
        }
        return lastPos == 0;
    }
}

                                                public class _055_JumpGame_4 {
                                                    public static void main(String[] args) {
                                                        Solution_055_JumpGame_4 so = new Solution_055_JumpGame_4();
                                                    }
                                                }
                                                