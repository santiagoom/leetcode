package _023_MergekSortedLists;


import java.util.List;

public class _023_MergekSortedLists_std {
    public static void main(String[] args) {
        _023_MergekSortedLists_std_ so = new _023_MergekSortedLists_std_();

    }
}

class _023_MergekSortedLists_std_ {

}


//Definition for ListNode.
class ListNode {
    int val;
    ListNode next;

    ListNode(int val) {
        this.val = val;
        this.next = null;
    }
}

class Solution {
    /**
     * @param lists: a list of ListNode
     * @return: The head of one sorted list.
     */
    public ListNode mergeKLists(List<ListNode> lists) {
        // write your code here
        return helper(lists, 0, lists.size() - 1);
    }

    private ListNode helper(List<ListNode> lists, int start, int end) {
        if (start > end) return null;
        if (start == end) return lists.get(start);
        int mid = (end - start) / 2 + start;
        ListNode left = helper(lists, start, mid);
        ListNode right = helper(lists, mid + 1, end);
        return mergeTwoLists(left, right);
    }

    private ListNode mergeTwoLists(ListNode l1, ListNode l2) {
        if (l1 == null) return l2;
        if (l2 == null) return l1;
        ListNode head = new ListNode(0);
        ListNode p = head;
        while (l1 != null && l2 != null) {
            if (l1.val < l2.val) {
                p.next = l1;
                l1 = l1.next;
            } else {
                p.next = l2;
                l2 = l2.next;
            }
            p = p.next;
        }

        if (l1 != null) p.next = l1;
        if (l2 != null) p.next = l2;
        return head.next;
    }
}