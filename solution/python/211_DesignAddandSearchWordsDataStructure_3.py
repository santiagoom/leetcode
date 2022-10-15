
from typing import List  
from utils import *
                    
def search(self, word: str) -> bool:
    """
    Returns if the word is in the data structure. A word could contain the dot character '.' to represent any letter.
    """
    def search_in_node(word, node) -> bool:
        for i, ch in enumerate(word):
            if not ch in node:
                # if the current character is '.'
                # check all possible nodes at this level
                if ch == '.':
                    for x in node:
                        if x != '$' and search_in_node(word[i + 1:], node[x]):
                            return True
                # if no nodes lead to answer
                # or the current character != '.'
                return False
            # if the character is found
            # go down to the next level in trie
            else:
                node = node[ch]
        return '$' in node

    return search_in_node(word, self.trie)

if __name__ == "__main__":
    nums = [2, 7, 11, 15]
    target = 26
    s = "aa"
    arrays = [[1, 2, 3], [4, 5, 6]]
    print(arrays)
                    