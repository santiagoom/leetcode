class Solution1(object):
    def longestPalindromeSubseq(self, s):
        """
        :type s: str
        :rtype: int
        """

        # case 1, case 2 jishu he ou shu
        def lps(s, i, j):
            if (i == j):
                return 1
            if (s[i] == s[j] and i + 1 == j):
                return 2
            if (s[i] == s[j]):
                return lps(s, i + 1, j - 1) + 2
            else:
                return max(lps(s, i, j - 1), lps(s, i + 1, j))

        return lps(s, 0, len(s) - 1)


class Solution:
    def longestPalindromeSubseq(self, s):
        n = len(s)
        table = [[0] * n for _ in range(n)]

        for i in range(n):
            table[i][i] = 1

        for k in range(2, n + 1):
            for i in range(n - k + 1):
                j = i + k - 1
                if (s[i] == s[j] and k == 2):
                    table[i][j] = 2
                elif (s[i] == s[j]):
                    table[i][j] = table[i + 1][j - 1] + 2
                else:
                    table[i][j] = max(table[i][j - 1], table[i + 1][j])

        return table[0][n - 1]


if __name__ == "__main__":
    # 2019-08-16 22:09:42
    # 2019-08-16 22:24:54
    s = "bbbab"
    so = Solution()
    res = so.longestPalindromeSubseq(s)
    print(res)
