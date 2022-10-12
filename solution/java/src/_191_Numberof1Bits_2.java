

                    import java.util.*;
                    import utils.TreeNode;
                    import utils.ListNode;
                                            
                        class Solution_191_Numberof1Bits_2{
                        
public int hammingWeight(int n) {
    int sum = 0;
    while (n != 0) {
        sum++;
        n &= (n - 1);
    }
    return sum;
}

                        }
                        public class _191_Numberof1Bits_2 {
                            public static void main(String[] args) {
                                Solution_191_Numberof1Bits_2 so = new Solution_191_Numberof1Bits_2();
                            }
                        }
                        