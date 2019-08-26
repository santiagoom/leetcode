package _021_MergeTwoSortedLists;

public class Std {

}

class SolutionWithoutDummyNode {
    public ListNode mergeTwoLists(ListNode l1, ListNode l2) {
        if (l1 == null) {
            return l2;
        }
        if (l2 == null) {
            return l1;
        }

        ListNode head = (l1.val <= l2.val) ? l1 : l2;
        ListNode current = head;

        if (l1 == head) {
            l1 = l1.next;
        } else {
            l2 = l2.next;
        }

        while (l1 != null || l2 != null) {
            if (l1 == null) {
                current.next = l2;
                break;
            }
            if (l2 == null) {
                current.next = l1;
                break;
            }

            if (l1.val < l2.val) {
                current.next = l1;
                l1 = l1.next;
            } else {
                current.next = l2;
                l2 = l2.next;
            }
            current = current.next;
        }
        return head;
    }
}

class SolutionGeneral {
    /*
     * The key to solve the problem is defining a fake head. Then compare the first
     * elements from each list. Add the smaller one to the merged list. Finally,
     * when one of them is empty, simply append it to the merged list, since it is
     * already sorted.
     *
     */

    public ListNode mergeTwoLists(ListNode l1, ListNode l2) {
        ListNode head = new ListNode(0);
        ListNode p = head;

        while (l1 != null || l2 != null) {
            if (l1 != null && l2 != null) {
                if (l1.val < l2.val) {
                    p.next = l1;
                    l1 = l1.next;
                } else {
                    p.next = l2;
                    l2 = l2.next;
                }
                p = p.next;
            } else if (l1 == null) {
                p.next = l2;
                break;
            } else if (l2 == null) {
                p.next = l1;
                break;
            }
        }
        return head.next;
    }
}

class SolutionUsingRecursion {
    public ListNode mergeTwoLists(ListNode l1, ListNode l2) {
        if (l1 == null)
            return l2;
        if (l2 == null)
            return l1;
        if (l1.val < l2.val) {
            l1.next = mergeTwoLists(l1.next, l2);
            return l1;
        } else {
            l2.next = mergeTwoLists(l1, l2.next);
            return l2;
        }
    }
}

class ListNode {
    int val;
    ListNode next;

    ListNode(int x) {
        val = x;
    }
}