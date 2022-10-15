
from typing import List  
from utils import *
                    
def isPalindrome(self, head: ListNode) -> bool:

    self.front_pointer = head

    def recursively_check(current_node=head):
        if current_node is not None:
            if not recursively_check(current_node.next):
                return False
            if self.front_pointer.val != current_node.val:
                return False
            self.front_pointer = self.front_pointer.next
        return True

    return recursively_check()

if __name__ == "__main__":
    nums = [2, 7, 11, 15]
    target = 26
    s = "aa"
    arrays = [[1, 2, 3], [4, 5, 6]]
    print(arrays)
                    