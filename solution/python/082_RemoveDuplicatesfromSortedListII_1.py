
from typing import List  
from utils import *
                    
class Solution_082_RemoveDuplicatesfromSortedListII_1:
    def deleteDuplicates(self, head: ListNode) -> ListNode:
        # sentinel
        sentinel = ListNode(0, head)

        # predecessor = the last node 
        # before the sublist of duplicates
        pred = sentinel
        
        while head:
            # if it's a beginning of duplicates sublist 
            # skip all duplicates
            if head.next and head.val == head.next.val:
                # move till the end of duplicates sublist
                while head.next and head.val == head.next.val:
                    head = head.next
                # skip all duplicates
                pred.next = head.next 
            # otherwise, move predecessor
            else:
                pred = pred.next 
                
            # move forward
            head = head.next
            
        return sentinel.next

if __name__ == "__main__":
    nums = [2, 7, 11, 15]
    target = 26
    s = "aa"
    arrays = [[1, 2, 3], [4, 5, 6]]
    print(arrays)
                    