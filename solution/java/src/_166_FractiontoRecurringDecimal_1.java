

import java.util.*;

import utils.TreeNode;
import utils.ListNode;
import utils.JavaUtils;


class Solution_166_FractiontoRecurringDecimal_1 {
    public String fractionToDecimal(int numerator, int denominator) {
        if (numerator == 0) {
            return "0";
        }
        StringBuilder fraction = new StringBuilder();
        // If either one is negative (not both)
        if (numerator < 0 ^ denominator < 0) {
            fraction.append("-");
        }
        // Convert to Long or else abs(-2147483648) overflows
        long dividend = Math.abs(Long.valueOf(numerator));
        long divisor = Math.abs(Long.valueOf(denominator));
        fraction.append(String.valueOf(dividend / divisor));
        long remainder = dividend % divisor;
        if (remainder == 0) {
            return fraction.toString();
        }
        fraction.append(".");
        Map<Long, Integer> map = new HashMap<>();
        while (remainder != 0) {
            if (map.containsKey(remainder)) {
                fraction.insert(map.get(remainder), "(");
                fraction.append(")");
                break;
            }
            map.put(remainder, fraction.length());
            remainder *= 10;
            fraction.append(String.valueOf(remainder / divisor));
            remainder %= divisor;
        }
        return fraction.toString();
    }
}

public class _166_FractiontoRecurringDecimal_1 {
    public static void main(String[] args) {
        Solution_166_FractiontoRecurringDecimal_1 so = new Solution_166_FractiontoRecurringDecimal_1();
        int numerator = 1;
        int denominator = 3;
        String res =  so.fractionToDecimal(numerator,denominator);
        JavaUtils.print(res);
        int target = 26;
        String s = "aa";
    }
}
                                                