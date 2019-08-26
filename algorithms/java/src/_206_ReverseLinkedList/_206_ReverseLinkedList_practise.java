package _206_ReverseLinkedList;

public class _206_ReverseLinkedList_practise {
    public static void main(String[] args) {
//        2019-08-24 18:07:28
//        2019-08-24 18:15:23
        Solutionp so = new Solutionp();
    }
}

class Solutionp {
    public ListNode reverseList(ListNode head) {
        ListNode curr = head, prev = null, next;
        while (curr != null) {
            next = curr.next;
            curr.next = prev;
            prev = curr;
            curr = next;
        }

        return prev;
    }
}

////Definition for singly-linked list.
//class ListNode {
//    int val;
//    ListNode next;
//
//    ListNode(int x) {
//        val = x;
//    }
//}

