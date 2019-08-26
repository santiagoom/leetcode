package _029_DivideTwoIntegers;

class Solutions {
    /*
     * Note:
     *
     * Both dividend and divisor will be 32-bit signed integers. The divisor will
     * never be 0. Assume we are dealing with an environment which could only store
     * integers within the 32-bit signed integer range: [−2^31, 2^31 − 1]. For the
     * purpose of this problem, assume that your function returns 2^31 − 1 when the
     * division result overflows.
     *
     */
    public static void main(String[] args) {
        Solution so = new Solution();
        so.divide(10, 3);

    }
}

class Solution {
    /*
     *
     * This problem can be solved based on the fact that any number can be converted
     * to the format of the following:
     *
     * num=a_0*2^0+a_1*2^1+a_2*2^2+...+a_n*2^n
     *
     * The time complexity is O(logn).
     *
     */
    public int divide(int dividend, int divisor) {
        // Reduce the problem to positive long integer to make it easier.
        // Use long to avoid integer overflow cases.
        int sign = 1;
        if ((dividend > 0 && divisor < 0) || (dividend < 0 && divisor > 0))
            sign = -1;
        long ldividend = Math.abs((long) dividend);
        long ldivisor = Math.abs((long) divisor);

        // Take care the edge cases.
        if (ldivisor == 0)
            return Integer.MAX_VALUE;
        if ((ldividend == 0) || (ldividend < ldivisor))
            return 0;

        long lans = ldivide(ldividend, ldivisor);

        int ans;
        if (lans > Integer.MAX_VALUE) { // Handle overflow.
            ans = (sign == 1) ? Integer.MAX_VALUE : Integer.MIN_VALUE;
        } else {
            ans = (int) (sign * lans);
        }
        return ans;
    }

    private long ldivide(long ldividend, long ldivisor) {
        // Recursion exit condition
        if (ldividend < ldivisor)
            return 0;

        // Find the largest multiple so that (divisor * multiple <= dividend),
        // whereas we are moving with stride 1, 2, 4, 8, 16...2^n for performance
        // reason.
        // Think this as a binary search.
        long sum = ldivisor;
        long multiple = 1;
        while ((sum + sum) <= ldividend) {
            sum += sum;
            multiple += multiple;
        }
        // Look for additional value for the multiple from the reminder (dividend - sum)
        // recursively.
        return multiple + ldivide(ldividend - sum, ldivisor);
    }
}