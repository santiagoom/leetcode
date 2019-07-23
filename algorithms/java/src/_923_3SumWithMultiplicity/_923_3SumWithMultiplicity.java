package _923_3SumWithMultiplicity;

import java.util.Arrays;

public class _923_3SumWithMultiplicity {
    public static void main(String[] args) {
        _923_3SumWithMultiplicity_ so = new _923_3SumWithMultiplicity_();

    }
}

class _923_3SumWithMultiplicity_ {

}

class Solution1 {
    /*
    Approach 1: Three Pointer
Intuition and Algorithm

Sort the array. For each i, set T = target - A[i], the remaining target. We can try using a two-pointer technique to find A[j] + A[k] == T. This approach is the natural continuation of trying to make the two-pointer technique we know from previous problems, work on this problem.

Because some elements are duplicated, we have to be careful. In a typical case, the target is say, 8, and we have a remaining array (A[i+1:]) of [2,2,2,2,3,3,4,4,4,5,5,5,6,6]. We can analyze this situation with cases.

Whenever A[j] + A[k] == T, we should count the multiplicity of A[j] and A[k]. In this example, if A[j] == 2 and A[k] == 6, the multiplicities are 4 and 2, and the total number of pairs is 4 * 2 = 8. We then move to the remaining window A[j:k+1] of [3,3,4,4,4,5,5,5].

As a special case, if A[j] == A[k], then our manner of counting would be incorrect. If for example the remaining window is [4,4,4], there are only 3 such pairs. In general, when A[j] == A[k], we have \binom{M}{2} = \frac{M*(M-1)}{2}(
2
M
​
 )=
2
M∗(M−1)
​
  pairs (j,k) (with j < k) that satisfy A[j] + A[k] == T, where MM is the multiplicity of A[j] (in this case M=3M=3).

For more details, please see the inline comments.
     */
    public int threeSumMulti(int[] A, int target) {
        int MOD = 1_000_000_007;
        long ans = 0;
        Arrays.sort(A);

        for (int i = 0; i < A.length; ++i) {
            // We'll try to find the number of i < j < k
            // with A[j] + A[k] == T, where T = target - A[i].

            // The below is a "two sum with multiplicity".
            int T = target - A[i];
            int j = i + 1, k = A.length - 1;

            while (j < k) {
                // These steps proceed as in a typical two-sum.
                if (A[j] + A[k] < T)
                    j++;
                else if (A[j] + A[k] > T)
                    k--;
                else if (A[j] != A[k]) {  // We have A[j] + A[k] == T.
                    // Let's count "left": the number of A[j] == A[j+1] == A[j+2] == ...
                    // And similarly for "right".
                    int left = 1, right = 1;
                    while (j + 1 < k && A[j] == A[j + 1]) {
                        left++;
                        j++;
                    }
                    while (k - 1 > j && A[k] == A[k - 1]) {
                        right++;
                        k--;
                    }

                    ans += left * right;
                    ans %= MOD;
                    j++;
                    k--;
                } else {
                    // M = k - j + 1
                    // We contributed M * (M-1) / 2 pairs.
                    ans += (k - j + 1) * (k - j) / 2;
                    ans %= MOD;
                    break;
                }
            }
        }

        return (int) ans;
    }
}

class Solution2 {
    public int threeSumMulti(int[] A, int target) {
        int MOD = 1_000_000_007;
        long[] count = new long[101];
        for (int x: A)
            count[x]++;

        long ans = 0;

        // All different
        for (int x = 0; x <= 100; ++x)
            for (int y = x+1; y <= 100; ++y) {
                int z = target - x - y;
                if (y < z && z <= 100) {
                    ans += count[x] * count[y] * count[z];
                    ans %= MOD;
                }
            }

        // x == y != z
        for (int x = 0; x <= 100; ++x) {
            int z = target - 2*x;
            if (x < z && z <= 100) {
                ans += count[x] * (count[x] - 1) / 2 * count[z];
                ans %= MOD;
            }
        }

        // x != y == z
        for (int x = 0; x <= 100; ++x) {
            if (target % 2 == x % 2) {
                int y = (target - x) / 2;
                if (x < y && y <= 100) {
                    ans += count[x] * count[y] * (count[y] - 1) / 2;
                    ans %= MOD;
                }
            }
        }

        // x == y == z
        if (target % 3 == 0) {
            int x = target / 3;
            if (0 <= x && x <= 100) {
                ans += count[x] * (count[x] - 1) * (count[x] - 2) / 6;
                ans %= MOD;
            }
        }

        return (int) ans;
    }
}

class Solution3 {
    public int threeSumMulti(int[] A, int target) {
        int MOD = 1_000_000_007;

        // Initializing as long saves us the trouble of
        // managing count[x] * count[y] * count[z] overflowing later.
        long[] count = new long[101];
        int uniq = 0;
        for (int x: A) {
            count[x]++;
            if (count[x] == 1)
                uniq++;
        }

        int[] keys = new int[uniq];
        int t = 0;
        for (int i = 0; i <= 100; ++i)
            if (count[i] > 0)
                keys[t++] = i;

        long ans = 0;
        // Now, let's do a 3sum on "keys", for i <= j <= k.
        // We will use count to add the correct contribution to ans.

        for (int i = 0; i < keys.length; ++i) {
            int x = keys[i];
            int T = target - x;
            int j = i, k = keys.length - 1;
            while (j <= k) {
                int y = keys[j], z = keys[k];
                if (y + z < T) {
                    j++;
                } else if (y + z > T) {
                    k--;
                } else {  // # x+y+z == T, now calc the size of the contribution
                    if (i < j && j < k) {
                        ans += count[x] * count[y] * count[z];
                    } else if (i == j && j < k) {
                        ans += count[x] * (count[x] - 1) / 2 * count[z];
                    } else if (i < j && j == k) {
                        ans += count[x] * count[y] * (count[y] - 1) / 2;
                    } else {  // i == j == k
                        ans += count[x] * (count[x] - 1) * (count[x] - 2) / 6;
                    }

                    ans %= MOD;
                    j++;
                    k--;
                }
            }
        }

        return (int) ans;
    }
}