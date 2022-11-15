
from typing import List  
from utils import *
import collections
                    
class WordDictionary:

    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.trie = {}


    def addWord(self, word: str) -> None:
        """
        Adds a word into the data structure.
        """
        node = self.trie

        for ch in word:
            if not ch in node:
                node[ch] = {}
            node = node[ch]
        node['$'] = True

if __name__ == "__main__":
    nums = [2, 7, 11, 15]
    target = 26
    so = Solution_211_DesignAddandSearchWordsDataStructure_2()
    s = "aa"
    arrays = [[1, 2, 3], [4, 5, 6]]
    print(arrays)
                    