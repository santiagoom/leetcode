
                        
                    import java.util.*;
                    import utils.TreeNode;
                    import utils.ListNode;
                                            
                                                
class Solution_070_ClimbingStairs_1 {
    public int climbStairs(int n) {
        return climb_Stairs(0, n);
    }
    public int climb_Stairs(int i, int n) {
        if (i > n) {
            return 0;
        }
        if (i == n) {
            return 1;
        }
        return climb_Stairs(i + 1, n) + climb_Stairs(i + 2, n);
    }
}

                                                public class _070_ClimbingStairs_1 {
                                                    public static void main(String[] args) {
                                                        Solution_070_ClimbingStairs_1 so = new Solution_070_ClimbingStairs_1();
                                                    }
                                                }
                                                