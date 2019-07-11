package _706_DesignHashMap;


/*
 *
 * Note:
	All keys and values will be in the range of [0, 1000000].
	The number of operations will be in the range of [1, 10000].
	Please do not use the built-in HashMap library.

 * Author: climberig
 * Collisions are resolved using linked list
 */

public class _706_DesignHashMap_1 {

    public static void main(String[] args) {
        _706_DesignHashMap_1 mhp = new _706_DesignHashMap_1();

        mhp.put(23, 56);
        mhp.put(20023, 56);
        int val = mhp.get(23);
        mhp.remove(23);
        System.out.println(val);
    }

    final ListNode[] nodes = new ListNode[10000];

    public void put(int key, int value) {
        int i = idx(key);
        if (nodes[i] == null)
            nodes[i] = new ListNode(-1, -1);
        ListNode prev = find(nodes[i], key);
        if (prev.next == null)
            prev.next = new ListNode(key, value);
        else
            prev.next.val = value;
    }

    public int get(int key) {
        int i = idx(key);
        if (nodes[i] == null)
            return -1;
        ListNode node = find(nodes[i], key);
        return node.next == null ? -1 : node.next.val;
    }

    public void remove(int key) {
        int i = idx(key);
        if (nodes[i] == null)
            return;
        ListNode prev = find(nodes[i], key);
        if (prev.next == null)
            return;
        prev.next = prev.next.next;
    }

    int idx(int key) {
        return Integer.hashCode(key) % nodes.length;
    }

    ListNode find(ListNode bucket, int key) {
        ListNode node = bucket, prev = null;
        while (node != null && node.key != key) {
            prev = node;
            node = node.next;
        }
        return prev;
    }

    class ListNode {
        int key, val;
        ListNode next;

        ListNode(int key, int val) {
            this.key = key;
            this.val = val;
        }
    }
}