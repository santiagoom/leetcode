package _069_Sqrt_x;

public class _069_Sqrt_x_std {
    public static void main(String[] args) {
        _069_Sqrt_x_std_ so = new _069_Sqrt_x_std_();

    }
}

class _069_Sqrt_x_std_ {

}

class Solution {
    /**
     * @param x: An integer
     * @return: The sqrt of x
     */

    public int sqrt(int x) {
        int start = 0;
        int end = x;
        while (start + 1 < end) {
            int mid = start + (end - start) / 2;
            int div = x / mid;
            if (div > mid) {
                start = mid;
            } else if (div == mid) {
                return mid;
            } else {
                end = mid;
            }
        }
        if (x != 0 && x / end >= end) {
            return end;
        } else {
            return start;
        }
    }
}