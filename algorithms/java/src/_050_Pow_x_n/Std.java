package _050_Pow_x_n;

public class Std {
    public static void main(String[] args) {
        Solution so = new Solution();
        double x = 2;
        int n = 3;
        double out = so.pow(x, n);
        System.out.println(out);
    }
}

class Solution {
    public double pow(double x, int n) {
        System.out.println(x);
        System.out.println(n);
        System.out.println();
        if (n == 0)
            return 1;
        if (n < 0) {
            n = -n;
            x = 1 / x;
        }
        return (n % 2 == 0) ? pow(x * x, n / 2) : x * pow(x * x, n / 2);
    }
}


/**
 * This reference program is provided by @jiuzhang.com
 * Copyright is reserved. Please indicate the source for forwarding
 */

class Solution2 {
    /**
     * @param x the base number
     * @param n the power number
     * @return the result
     */
    public double myPow(double x, int n) {
        boolean isNegative = false;
        if (n < 0) {
            x = 1 / x;
            isNegative = true;
            n = -(n + 1);       // Avoid overflow when n == MIN_VALUE
        }

        double ans = 1, tmp = x;

        while (n != 0) {
            if (n % 2 == 1) {
                ans *= tmp;
            }
            tmp *= tmp;
            n /= 2;
        }

        if (isNegative) {
            ans *= x;
        }
        return ans;
    }
}