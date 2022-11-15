
                        
                    import java.util.*;
                    import utils.TreeNode;
                    import utils.ListNode;
                    import utils.JavaUtils;
                                            
                                                
 class Solution_278_FirstBadVersion_3 extends VersionControl {
    public int firstBadVersion(int n) {
        int l=1;
        while(l<=n){
            int m=l+(n-l)/2;
            if(isBadVersion(m)){
                n=m-1;
            }else{
                l=m+1;
            }
        }
        return l;
    }
}

                                                public class _278_FirstBadVersion_3 {
                                                    public static void main(String[] args) {
                                                        Solution_278_FirstBadVersion_3 so = new Solution_278_FirstBadVersion_3();
                                                        int[] nums = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
                                                        JavaUtils.print_1d_array(nums);
                                                        int[][] arrays = {{2, 7, 9}, {3, 6, 1}, {7, 4, 2}};
                                                        JavaUtils.print_2d_array(arrays);
                                                
                                                        int target = 26;
                                                        String s = "aa";
                                                    }
                                                }
                                                