

                    import java.util.*;
                    import utils.TreeNode;
                    import utils.ListNode;
                    import utils.JavaUtils;
                                            
                        class Solution_019_RemoveNthNodeFromEndofList_2{
                        
public ListNode removeNthFromEnd(ListNode head, int n) {
    ListNode dummy = new ListNode(0);
    dummy.next = head;
    ListNode first = dummy;
    ListNode second = dummy;
    // Advances first pointer so that the gap between first and second is n nodes apart
    for (int i = 1; i <= n + 1; i++) {
        first = first.next;
    }
    // Move first to the end, maintaining the gap
    while (first != null) {
        first = first.next;
        second = second.next;
    }
    second.next = second.next.next;
    return dummy.next;
}

                        }
                        public class _019_RemoveNthNodeFromEndofList_2 {
                            public static void main(String[] args) {
                                Solution_019_RemoveNthNodeFromEndofList_2 so = new Solution_019_RemoveNthNodeFromEndofList_2();
                                 int[] nums = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
                                                        JavaUtils.print_1d_array(nums);
                                                        int[][] arrays = {{2, 7, 9}, {3, 6, 1}, {7, 4, 2}};
                                                        JavaUtils.print_2d_array(arrays);
                                                
                                                        int target = 26;
                                                        String s = "aa";
                            }
                        }
                        