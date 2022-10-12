
class Solution:
    def wordBreak(self, s: str, wordDict: List[str]) -> List[str]:
        # quick check on the characters,
        #   otherwise it would exceed the time limit for certain test cases.
        if set(Counter(s).keys()) > set(Counter("".join(wordDict)).keys()):
            return []

        wordSet = set(wordDict)

        # the dp array stores the positions to insert breaks/stops
        dp = [[]] * (len(s)+1)
        dp[0] = [[0]]

        for endIndex in range(1, len(s)+1):
            stops = []
            for startIndex in range(0, endIndex):
                word = s[startIndex:endIndex]
                if word in wordSet:
                    for subsentence in dp[startIndex]:
                        copy = subsentence.copy()
                        copy.append(endIndex)
                        stops.append(copy)
            dp[endIndex] = stops

        ret = []
        # reconstruct the words list from the positions of breaks/stops
        for stops in dp[len(s)]:
            words = []
            for i in range(len(stops)-1):
                words.append(s[stops[i]:stops[i+1]])
            ret.append(" ".join(words))
        return ret
