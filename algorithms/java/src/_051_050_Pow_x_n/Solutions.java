package _051_050_Pow_x_n;

public class Solutions {
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
