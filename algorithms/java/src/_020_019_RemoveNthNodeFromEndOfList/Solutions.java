package _020_019_RemoveNthNodeFromEndOfList;

public class Solutions {
	/*
	 * Note: Given n will always be valid.
	 * 
	 * Follow up: Could you do this in one pass?
	 */

}

class SolutionOnePassAlgorithm {
	/*
	 * The above algorithm could be optimized to one pass. Instead of one pointer,
	 * we could use two pointers. The first pointer advances the list by n+1n+1
	 * steps from the beginning, while the second pointer starts from the beginning
	 * of the list. Now, both pointers are exactly separated by nn nodes apart. We
	 * maintain this constant gap by advancing both pointers together until the
	 * first pointer arrives past the last node. The second pointer will be pointing
	 * at the nnth node counting from the last. We relink the next pointer of the
	 * node referenced by the second pointer to point to the node's next next node.
	 * 
	 * Complexity Analysis
	 * 
	 * Time complexity : O(L)O(L).
	 * The algorithm makes one traversal of the list of LL nodes. Therefore time
	 * complexity is O(L)O(L).
	 * 
	 * Space complexity : O(1)O(1).
	 * We only used constant extra space.
	 */

	public ListNode removeNthFromEnd(ListNode head, int n) {
		ListNode dummy = new ListNode(0);
		dummy.next = head;
		ListNode first = dummy;
		ListNode second = dummy;
		// Advances first pointer so that the gap between first and second is n nodes
		// apart
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

class SolutionTwoPassAlgorithm {
	/*
	 * We notice that the problem could be simply reduced to another one : Remove
	 * the (L - n + 1)(L−n+1) th node from the beginning in the list , where LL is
	 * the list length. This problem is easy to solve once we found list length LL.
	 * 
	 * Complexity Analysis
	 * 
	 * Time complexity : O(L)O(L). The algorithm makes two traversal of the list,
	 * first to calculate list length LL and second to find the (L - n)(L−n) th
	 * node. There are 2L-n2L−n operations and time complexity is O(L)O(L).
	 * 
	 * Space complexity : O(1)O(1). We only used constant extra space.
	 */
	public ListNode removeNthFromEnd(ListNode head, int n) {
		ListNode dummy = new ListNode(0);
		dummy.next = head;
		int length = 0;
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

class ListNode {
	int val;
	ListNode next;

	ListNode(int x) {
		val = x;
	}
}