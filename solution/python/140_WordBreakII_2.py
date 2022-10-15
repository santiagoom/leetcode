
from typing import List  
from utils import *
                    
class Solution_140_WordBreakII_2:
    def wordBreak(self, s: str, wordDict: List[str]) -> List[str]:
        # quick check on the characters,
        #   otherwise it would exceed the time limit for certain test cases.
        if set(Counter(s).keys()) > set(Counter("".join(wordDict)).keys()):
            return []

        wordSet = set(wordDict)

        dp = [[]] * (len(s)+1)
        dp[0] = [""]

        for endIndex in range(1, len(s)+1):
            sublist = []
            # fill up the values in the dp array.
            for startIndex in range(0, endIndex):
                word = s[startIndex:endIndex]
                if word in wordSet:
                    for subsentence in dp[startIndex]:
                        sublist.append((subsentence + ' ' + word).strip())

            dp[endIndex] = sublist

        return dp[len(s)]

if __name__ == "__main__":
    nums = [2, 7, 11, 15]
    target = 26
    s = "aa"
    arrays = [[1, 2, 3], [4, 5, 6]]
    print(arrays)
                    