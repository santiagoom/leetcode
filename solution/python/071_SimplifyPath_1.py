
from typing import List  
from utils import *
import collections
                    
class Solution_071_SimplifyPath_1:
    def simplifyPath(self, path: str) -> str:

        # Initialize a stack
        stack = []

        # Split the input string on "/" as the delimiter
        # and process each portion one by one
        for portion in path.split("/"):

            # If the current component is a "..", then
            # we pop an entry from the stack if it's non-empty
            if portion == "..":
                if stack:
                    stack.pop()
            elif portion == "." or not portion:
                # A no-op for a "." or an empty string
                continue
            else:
                # Finally, a legitimate directory name, so we add it
                # to our stack
                stack.append(portion)

        # Stich together all the directory names together
        aa = "".join(stack)
        bb = "/".join(stack)
        final_str = "/" + "/".join(stack)
        return final_str

if __name__ == "__main__":
    so = Solution_071_SimplifyPath_1()
    s = "/a/./b/../../c/"
    res = so.simplifyPath(s)
    print(res)
                    