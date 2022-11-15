
from typing import List  
from utils import *
import collections
                    
class Solution_276_PaintFence_4:
    def numWays(self, n: int, k: int) -> int:
        if n == 1:
            return k
        
        two_posts_back = k
        one_post_back = k * k
        
        for i in range(3, n + 1):
            curr = (k - 1) * (one_post_back + two_posts_back)
            two_posts_back = one_post_back
            one_post_back = curr

        return one_post_back

if __name__ == "__main__":
    nums = [2, 7, 11, 15]
    target = 26
    so = Solution_276_PaintFence_4()
    s = "aa"
    arrays = [[1, 2, 3], [4, 5, 6]]
    print(arrays)
                    