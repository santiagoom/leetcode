
                        
                    import java.util.*;
                    import utils.TreeNode;
                    import utils.ListNode;
                                            
                                                
class Solution_083_RemoveDuplicatesfromSortedList_1 {
public ListNode deleteDuplicates(ListNode head) {
    ListNode current = head;
    while (current != null && current.next != null) {
        if (current.next.val == current.val) {
            current.next = current.next.next;
        } else {
            current = current.next;
        }
    }
    return head;
}
}

                                                public class _083_RemoveDuplicatesfromSortedList_1 {
                                                    public static void main(String[] args) {
                                                        Solution_083_RemoveDuplicatesfromSortedList_1 so = new Solution_083_RemoveDuplicatesfromSortedList_1();
                                                    }
                                                }
                                                