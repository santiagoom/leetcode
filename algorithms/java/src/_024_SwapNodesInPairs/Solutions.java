package _025_024_SwapNodesInPairs;

public class Solutions {
	public static void main(String[] args) {
		ListNode l1 = new ListNode(1);
		l1.next = new ListNode(2);
		l1.next.next = new ListNode(3);
		l1.next.next.next = new ListNode(4);

		SolutionRecursive sor = new SolutionRecursive();
		ListNode out = sor.swapPairs(l1);

		SolutionIterative soi = new SolutionIterative();
//		ListNode out = soi.swapPairs(l1);
		while (out != null) {
			System.out.println(out.val);
			out = out.next;
		}
	}
}

class SolutionIterative {
	public ListNode swapPairs(ListNode head) {
		ListNode dummy = new ListNode(0);
		dummy.next = head;
		ListNode current = dummy;
		while (current.next != null && current.next.next != null) {
			ListNode first = current.next;
			ListNode second = current.next.next;
			first.next = second.next;
			current.next = second;
			current.next.next = first;
			current = current.next.next;
		}
		return dummy.next;
	}
}

class SolutionRecursive {
	/*
	 * 直接看退出条件
	 * look at the return conditions directly!
	 */
	public ListNode swapPairs(ListNode head) {
		if ((head == null) || (head.next == null))
			return head;
		ListNode n = head.next;
		head.next = swapPairs(head.next.next);
		n.next = head;
		return n;
	}
}

class ListNode {
	int val;
	ListNode next;

	ListNode(int x) {
		val = x;
	}
}