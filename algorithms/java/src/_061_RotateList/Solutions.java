package _060_061_RotateList;

public class Solutions {
	public static void main(String[] args) {
		Solution so = new Solution();

	}
}

class Solution {
	/*
	 * Ex: {1,2,3} k=2 Move the list after the 1st node to the front
	 * 
	 * Ex: {1,2,3} k=5, In this case Move the list after (3-5%3=1)st node to the
	 * front.
	 * 
	 * So the code has three parts.
	 * 
	 * Get the length
	 * 
	 * Move to the (l-n%l)th node
	 * 
	 * Do the rotation
	 */
	
	//note: the key to the problem is to find the head listnode!!
	public ListNode rotateRight(ListNode head, int n) {
		if (head == null || head.next == null)
			return head;
		ListNode dummy = new ListNode(0);
		dummy.next = head;
		ListNode fast = dummy, slow = dummy;

		int i;
		for (i = 0; fast.next != null; i++)// Get the total length
			fast = fast.next;
		// j 需要移动位置的个数 the position numbers that need to shift
		for (int j = i - n % i; j > 0; j--) // Get the i-n%i th node
			slow = slow.next;

		fast.next = dummy.next; // Do the rotation
		dummy.next = slow.next;
		slow.next = null;

		return dummy.next;
	}

}

//Definition for singly-linked list.
class ListNode {
	int val;
	ListNode next;

	ListNode(int x) {
		val = x;
	}
}
