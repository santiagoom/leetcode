
from typing import List  
from utils import *
import collections
                    
class WordDictionary:
    def __init__(self):
        self.d = defaultdict(set)


    def addWord(self, word: str) -> None:
        self.d[len(word)].add(word)


    def search(self, word: str) -> bool:
        m = len(word)
        for dict_word in self.d[m]:
            i = 0
            while i < m and (dict_word[i] == word[i] or word[i] == '.'):
                i += 1
            if i == m:
                return True
        return False

if __name__ == "__main__":
    nums = [2, 7, 11, 15]
    target = 26
    so = Solution_211_DesignAddandSearchWordsDataStructure_1()
    s = "aa"
    arrays = [[1, 2, 3], [4, 5, 6]]
    print(arrays)
                    