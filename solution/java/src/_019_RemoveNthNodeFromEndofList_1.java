

                    import java.util.*;
                    import utils.TreeNode;
                    import utils.ListNode;
                    import utils.JavaUtils;
                                            
                        class Solution_019_RemoveNthNodeFromEndofList_1{
                        
public ListNode removeNthFromEnd(ListNode head, int n) {
    ListNode dummy = new ListNode(0);
    dummy.next = head;
    int length  = 0;
    ListNode first = head;
    while (first != null) {
        length++;
        first = first.next;
    }
    length -= n;
    first = dummy;
    while (length > 0) {
        length--;
        first = first.next;
    }
    first.next = first.next.next;
    return dummy.next;
}

                        }
                        public class _019_RemoveNthNodeFromEndofList_1 {
                            public static void main(String[] args) {
                                Solution_019_RemoveNthNodeFromEndofList_1 so = new Solution_019_RemoveNthNodeFromEndofList_1();
                                 int[] nums = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
                                                        JavaUtils.print_1d_array(nums);
                                                        int[][] arrays = {{2, 7, 9}, {3, 6, 1}, {7, 4, 2}};
                                                        JavaUtils.print_2d_array(arrays);
                                                
                                                        int target = 26;
                                                        String s = "aa";
                            }
                        }
                        