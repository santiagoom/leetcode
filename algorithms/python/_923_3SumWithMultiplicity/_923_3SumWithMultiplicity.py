import collections


class Solution1(object):
    def threeSumMulti(self, A, target):
        MOD = 10 ** 9 + 7
        ans = 0
        A.sort()

        for i, x in enumerate(A):
            # We'll try to find the number of i < j < k
            # with A[j] + A[k] == T, where T = target - A[i].

            # The below is a "two sum with multiplicity".
            T = target - A[i]
            j, k = i + 1, len(A) - 1

            while j < k:
                # These steps proceed as in a typical two-sum.
                if A[j] + A[k] < T:
                    j += 1
                elif A[j] + A[k] > T:
                    k -= 1
                # These steps differ:
                elif A[j] != A[k]:  # We have A[j] + A[k] == T.
                    # Let's count "left": the number of A[j] == A[j+1] == A[j+2] == ...
                    # And similarly for "right".
                    left = right = 1
                    while j + 1 < k and A[j] == A[j + 1]:
                        left += 1
                        j += 1
                    while k - 1 > j and A[k] == A[k - 1]:
                        right += 1
                        k -= 1

                    # We contributed left * right many pairs.
                    ans += left * right
                    ans %= MOD
                    j += 1
                    k -= 1

                else:
                    # M = k - j + 1
                    # We contributed M * (M-1) / 2 pairs.
                    ans += (k - j + 1) * (k - j) / 2
                    ans %= MOD
                    break

        return ans


class Solution2(object):
    def threeSumMulti(self, A, target):
        MOD = 10 ** 9 + 7
        count = [0] * 101
        for x in A:
            count[x] += 1

        ans = 0

        # All different
        for x in range(101):
            for y in range(x + 1, 101):
                z = target - x - y
                if y < z <= 100:
                    ans += count[x] * count[y] * count[z]
                    ans %= MOD

        # x == y
        for x in range(101):
            z = target - 2 * x
            if x < z <= 100:
                ans += count[x] * (count[x] - 1) / 2 * count[z]
                ans %= MOD

        # y == z
        for x in range(101):
            if (target - x) % 2 == 0:
                y = (target - x) / 2
                if x < y <= 100:
                    ans += count[x] * count[y] * (count[y] - 1) / 2
                    ans %= MOD

        # x == y == z
        if target % 3 == 0:
            x = target / 3
            if 0 <= x <= 100:
                ans += count[x] * (count[x] - 1) * (count[x] - 2) / 6
                ans %= MOD

        return ans


class Solution3(object):
    def threeSumMulti(self, A, target):
        MOD = 10 ** 9 + 7
        count = collections.Counter(A)
        keys = sorted(count)

        ans = 0

        # Now, let's do a 3sum on "keys", for i <= j <= k.
        # We will use count to add the correct contribution to ans.
        for i, x in enumerate(keys):
            T = target - x
            j, k = i, len(keys) - 1
            while j <= k:
                y, z = keys[j], keys[k]
                if y + z < T:
                    j += 1
                elif y + z > T:
                    k -= 1
                else:  # x+y+z == T, now calculate the size of the contribution
                    if i < j < k:
                        ans += count[x] * count[y] * count[z]
                    elif i == j < k:
                        ans += count[x] * (count[x] - 1) / 2 * count[z]
                    elif i < j == k:
                        ans += count[x] * count[y] * (count[y] - 1) / 2
                    else:  # i == j == k
                        ans += count[x] * (count[x] - 1) * (count[x] - 2) / 6

                    j += 1
                    k -= 1

        return ans % MOD
