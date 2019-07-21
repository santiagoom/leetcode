package _454_4SumII;

import java.util.HashMap;
import java.util.Map;

public class _454_4SumII {
    public static void main(String[] args) {
        _454_4SumII_ so = new _454_4SumII_();

    }
}

class _454_4SumII_ {

}

class Solution1 {
    /**
     * @param A: a list
     * @param B: a list
     * @param C: a list
     * @param D: a list
     * @return: how many tuples (i, j, k, l) there are such that A[i] + B[j] + C[k] + D[l] is zero
     */
    public int fourSumCount(int[] A, int[] B, int[] C, int[] D) {
        int res = 0;
        HashMap<Integer, Integer> map = new HashMap<Integer, Integer>();
        for (int i = 0; i < A.length; i++) {
            for (int j = 0; j < B.length; j++) {
                map.put(A[i] + B[j], map.getOrDefault(A[i] + B[j], 0) + 1);
            }
        }

        for (int i = 0; i < C.length; i++) {
            for (int j = 0; j < D.length; j++) {
                res += map.getOrDefault(-(C[i] + D[j]), 0);
            }
        }
        return res;

    }
}

class Solution2 {
    /**
     * @param A: a list
     * @param B: a list
     * @param C: a list
     * @param D: a list
     * @return: how many tuples (i, j, k, l) there are such that A[i] + B[j] + C[k] + D[l] is zero
     */
    public int fourSumCount(int[] A, int[] B, int[] C, int[] D) {
        // Write your code here
        Map<Integer, Integer> map = new HashMap<>();
        int ans = 0;
        for (int i = 0; i < A.length; i++) {
            for (int j = 0; j < B.length; j++) {
                int sum = A[i] + B[j];
                if (map.containsKey(sum)) {
                    map.put(sum, map.get(sum) + 1);
                } else {
                    map.put(sum, 1);
                }
            }
        }
        for (int i = 0; i < C.length; i++) {
            for (int j = 0; j < D.length; j++) {
                int sum = -(C[i] + D[j]);
                if (map.containsKey(sum)) {
                    ans += map.get(sum);
                }
            }
        }
        return ans;
    }
}
