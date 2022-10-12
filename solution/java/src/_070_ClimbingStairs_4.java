
                        
                    import java.util.*;
                    import utils.TreeNode;
                    import utils.ListNode;
                                            
                                                

class Solution_070_ClimbingStairs_4 {
    public int climbStairs(int n) {
        if (n == 1) {
            return 1;
        }
        int first = 1;
        int second = 2;
        for (int i = 3; i <= n; i++) {
            int third = first + second;
            first = second;
            second = third;
        }
        return second;
    }
}

                                                public class _070_ClimbingStairs_4 {
                                                    public static void main(String[] args) {
                                                        Solution_070_ClimbingStairs_4 so = new Solution_070_ClimbingStairs_4();
                                                    }
                                                }
                                                