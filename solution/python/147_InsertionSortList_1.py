
from typing import List  
from utils import *
                    
class Solution_147_InsertionSortList_1:
    def insertionSortList(self, head: ListNode) -> ListNode:
        dummy = ListNode()
        curr = head

        while curr:
            # At each iteration, we insert an element into the resulting list.
            prev = dummy

            # find the position to insert the current node
            while prev.next and prev.next.val <= curr.val:
                prev = prev.next

            next = curr.next
            # insert the current node to the new list
            curr.next = prev.next
            prev.next = curr

            # moving on to the next iteration
            curr = next

        return dummy.next

if __name__ == "__main__":
    l1 = ListNode(1)
    l1.next = ListNode(5)
    l1.next.next = ListNode(2)
    l1.next.next.next = ListNode(4)
    l1.next.next.next.next = ListNode(3)

    so = Solution_147_InsertionSortList_1()

    l = so.insertionSortList(l1)

    printList(l)


                    