package _026_025_ReverseNodesInK_Group;

public class Solutions {
	/*
	 * Note:
	 * 
	 * Only constant extra memory is allowed. You may not alter the values in the
	 * list's nodes, only nodes itself may be changed.
	 * 
	 * 
	 * understanding: it is insert not circle 
	 * 1 2 3 4 
	 * 2 3 1 4
	 * 3 2 1 4
	 * 
	 */

	public static void main(String[] args) {
		ListNode l1 = new ListNode(1);
		l1.next = new ListNode(2);
		l1.next.next = new ListNode(3);
		l1.next.next.next = new ListNode(4);

		SolutionRecursive sor = new SolutionRecursive();
		SolutionItetative soi = new SolutionItetative();
//		ListNode out = soi.reverseKGroup(l1, 2);
		ListNode out = sor.reverseKGroup(l1, 3);
		while (out != null) {
			System.out.println(out.val);
			out = out.next;
		}
	}
}

class SolutionItetative {
	public ListNode reverseKGroup(ListNode head, int k) {
		if (head == null || head.next == null || k < 2)
			return head;

		ListNode dummy = new ListNode(0);
		dummy.next = head;

		ListNode tail = dummy, prev = dummy, temp;
		int count;
		while (true) {
			count = k;
			while (count > 0 && tail != null) {
				count--;
				tail = tail.next;
			}
			if (tail == null)
				break;// Has reached the end

			head = prev.next;// for next cycle
			System.out.println(head);
			System.out.println(head.next);
			// prev-->temp-->...--->....--->tail-->....
			// Delete @temp and insert to the next position of @tail
			// prev-->...-->...-->tail-->head-->...
			// Assign @temp to the next node of @prev
			// prev-->temp-->...-->tail-->...-->...
			// Keep doing until @tail is the next node of @prev

			while (prev.next != tail) {
//				System.out.println(tail.val);
				temp = prev.next;// Assign
				prev.next = temp.next;// Delete

				temp.next = tail.next;
				tail.next = temp;// Insert
			}
			tail = head;
			System.out.println(head);
			System.out.println(head.next);
			System.out.println();
			prev = head;

//			tail = prev.next;
//			System.out.println(tail.val);
//			prev = prev.next;
//			System.out.println(prev.val);
		}
		return dummy.next;
	}
}

class SolutionRecursive {
	public ListNode reverseKGroup(ListNode head, int k) {
		ListNode curr = head;
		int count = 0;
		while (curr != null && count != k) { // find the k+1 node
			curr = curr.next;
			count++;
		}
		if (count == k) { // if k+1 node is found
			curr = reverseKGroup(curr, k); // reverse list with k+1 node as head
			// head - head-pointer to direct part,
			// curr - head-pointer to reversed part;
			while (count-- > 0) { // reverse current k-group:
				ListNode tmp = head.next; // tmp - next head in direct part
				head.next = curr; // preappending "direct" head to the reversed list
				curr = head; // move head of reversed part to a new node
				head = tmp; // move "direct" head to the next node in direct part
			}
			head = curr;
		}
		return head;
	}
}

class ListNode {
	int val;
	ListNode next;

	ListNode(int x) {
		val = x;
	}
}