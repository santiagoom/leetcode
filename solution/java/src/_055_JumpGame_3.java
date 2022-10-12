
                        
                    import java.util.*;
                    import utils.TreeNode;
                    import utils.ListNode;
                                            
                                                
enum Index {
    GOOD, BAD, UNKNOWN
}

class Solution_055_JumpGame_3 {
    public boolean canJump(int[] nums) {
        Index[] memo = new Index[nums.length];
        for (int i = 0; i < memo.length; i++) {
            memo[i] = Index.UNKNOWN;
        }
        memo[memo.length - 1] = Index.GOOD;

        for (int i = nums.length - 2; i >= 0; i--) {
            int furthestJump = Math.min(i + nums[i], nums.length - 1);
            for (int j = i + 1; j <= furthestJump; j++) {
                if (memo[j] == Index.GOOD) {
                    memo[i] = Index.GOOD;
                    break;
                }
            }
        }

        return memo[0] == Index.GOOD;
    }
}

                                                public class _055_JumpGame_3 {
                                                    public static void main(String[] args) {
                                                        Solution_055_JumpGame_3 so = new Solution_055_JumpGame_3();
                                                    }
                                                }
                                                