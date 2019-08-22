package _007_ReverseInteger;



class Solution {
	/*
	 * To "pop" and "push" digits without the help of some auxiliary stack/array, we
	 * can use math.
	 * 
	 * //pop operation: pop = x % 10; x /= 10;
	 * 
	 * //push operation: temp = rev * 10 + pop; rev = temp;
	 * 
	 * However, this approach is dangerous, because the statement \text{temp} =
	 * \text{rev} \cdot 10 + \text{pop}temp=rev⋅10+pop can cause overflow.
	 * 
	 * Luckily, it is easy to check beforehand whether or this statement would cause
	 * an overflow.
	 * 
	 * 
	 * 2**31 Out[3]: 2147483648 2**31 - 1 Out[4]: 2147483647
	 * 
	 * Complexity Analysis
	 * 
	 * Time Complexity: O(\log(x))O(log(x)). There are roughly \log_{10}(x)log 10(x)
	 * digits in xx. Space Complexity: O(1)O(1).
	 * 
	 */
	public int reverse(int x) {
		int rev = 0;
		while (x != 0) {
			int pop = x % 10;
			x /= 10;
			if (rev > Integer.MAX_VALUE / 10 || (rev == Integer.MAX_VALUE / 10 && pop > 7))
				return 0;
			if (rev < Integer.MIN_VALUE / 10 || (rev == Integer.MIN_VALUE / 10 && pop < -8))
				return 0;
			rev = rev * 10 + pop;
		}
		return rev;
	}
}