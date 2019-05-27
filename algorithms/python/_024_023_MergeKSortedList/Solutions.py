from queue import PriorityQueue


class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None


class SolutionBruteForce(object):
    '''
    Intuition & Algorithm
    Traverse all the linked lists and collect the values of the nodes into an array.
    Sort and iterate over this array to get the proper value of nodes.
    Create a new sorted linked list and extend it with the new nodes.

    Complexity Analysis

    Time complexity : O(N\log N)O(NlogN) where NN is the total number of nodes.
    Collecting all the values costs O(N)O(N) time.
    A stable sorting algorithm costs O(N\log N)O(NlogN) time.
    Iterating for creating the linked list costs O(N)O(N) time.

    Space complexity : O(N)O(N).
    Sorting cost O(N)O(N) space (depends on the algorithm you choose).
    Creating a new linked list costs O(N)O(N) space.

    '''

    def mergeKLists(self, lists):
        """
        :type lists: List[ListNode]
        :rtype: ListNode
        """
        self.nodes = []
        head = point = ListNode(0)
        for l in lists:
            while l:
                self.nodes.append(l.val)
                l = l.next
        for x in sorted(self.nodes):
            point.next = ListNode(x)
            point = point.next
        return head.next


class SolutionOptimizeApproachTwoByPriorityQueue(object):
    '''
    Approach 2: Compare one by one

    Complexity Analysis
    Time complexity : O(kN)O(kN) where \text{k}k is the number of linked lists.
    Almost every selection of node in final linked costs O(k)O(k) (\text{k-1}k-1 times comparison).
    note: create an empty node and compare it with each k node, and select the smallest one

    There are NN nodes in the final linked list.

    Space complexity :
    O(n)O(n) Creating a new linked list costs O(n)O(n) space.
    O(1)O(1) It's not hard to apply in-place method - connect selected nodes instead of creating new nodes to fill the new linked list.

    Approach 3: Optimize Approach 2 by Priority Queue

    Almost the same as the one above but optimize the comparison process by priority queue.

    Complexity Analysis
    Time complexity : O(N\log k)O(Nlogk) where \text{k}k is the number of linked lists.
    The comparison cost will be reduced to O(\log k)O(logk) for every pop and insertion to priority queue. But finding the node with the smallest value just costs O(1)O(1) time.
    There are NN nodes in the final linked list.

    Space complexity :
    O(n)O(n) Creating a new linked list costs O(n)O(n) space.
    O(k)O(k) The code above present applies in-place method which cost O(1)O(1) space. And the priority queue (often implemented with heaps) costs O(k)O(k) space (it's far less than NN in most situations).
    '''

    def mergeKLists(self, lists):
        """
        :type lists: List[ListNode]
        :rtype: ListNode
        """
        head = point = ListNode(0)
        q = PriorityQueue()
        for l in lists:
            if l:
                q.put((l.val, l))
                # q.put(l.val, l)
        # while(q.get()):
        #     print(q.get())
        while not q.empty():
            val, node = q.get()
            point.next = ListNode(val)
            point = point.next
            node = node.next
            if node:
                q.put((node.val, node))
        return head.next


class SolutionDivideAndConquer(object):
    '''

    Complexity Analysis

    Time complexity : O(N\log k)O(Nlogk) where \text{k}k is the number of linked lists.
    We can merge two sorted linked list in O(n)O(n) time where nn is the total number of nodes in two lists.
    Sum up the merge process and we can get: =O(Nlogk)

    Space complexity : O(1)O(1)
    We can merge two sorted linked lists in O(1)O(1) space.
    '''

    def mergeKLists(self, lists):
        """
        :type lists: List[ListNode]
        :rtype: ListNode
        """
        amount = len(lists)
        interval = 1
        while interval < amount:
            for i in range(0, amount - interval, interval * 2):
                print(amount - interval, interval * 2)
                print(i)
                lists[i] = self.merge2Lists(lists[i], lists[i + interval])
            interval *= 2
        return lists[0] if amount > 0 else lists

    def merge2Lists(self, l1, l2):
        head = point = ListNode(0)
        while l1 and l2:
            if l1.val <= l2.val:
                point.next = l1
                l1 = l1.next
            else:
                point.next = l2
                l2 = l1
                l1 = point.next.next
            point = point.next
        if not l1:
            point.next = l2
        else:
            point.next = l1
        return head.next


def SolutionBruteForce_test(lists):
    sobf = SolutionBruteForce()
    head = sobf.mergeKLists(lists)
    while (head):
        print(head.val)
        head = head.next


def SolutionOptimized_test(lists):
    soop = SolutionOptimizeApproachTwoByPriorityQueue()
    head = soop.mergeKLists(lists)
    while (head):
        print(head.val)
        head = head.next


def SolutionDivideAndConquer_test(lists):
    sodc = SolutionDivideAndConquer()
    head = sodc.mergeKLists(lists)
    while (head):
        print(head.val)
        head = head.next


if __name__ == "__main__":
    # 1->4->5,
    # 1->3->4,
    # 2->6
    l1 = ListNode(1)
    l1.next = ListNode(4)
    l1.next.next = ListNode(5)

    l2 = ListNode(1)
    l2.next = ListNode(3)
    l2.next.next = ListNode(4)

    l3 = ListNode(2)
    l3.next = ListNode(6)

    l4 = ListNode(3)
    l4.next = ListNode(7)

    # lists = [l1, l2, l3, l4]
    lists = [l1, l2, l3]
    # SolutionBruteForce_test(lists)

    # Something is wrong with PriorityQueue
    # SolutionOptimized_test(lists)

    SolutionDivideAndConquer_test(lists)
