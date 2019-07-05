package _000_algorithm_paradigm;

import java.util.Arrays;

public class DynamicProgramming {

	public static void main(String[] args) {
//		long startTime = System.nanoTime(); // 获取开始时间
		long startTime = System.currentTimeMillis(); // 获取开始时间

		NumbersFormN so = new NumbersFormN();
		// 20 1188
//		int out = so.solveBF(40);

		// 20 1
		Arrays.fill(so.dp, -1);
		int out = so.solveDP(40);
		System.out.println(out);

//		long endTime = System.nanoTime(); // 获取结束时间
		long endTime = System.currentTimeMillis(); // 获取结束时间
		System.out.println(endTime - startTime);

//		for (int i = 0; i < so.dp.length; i++)
//			System.out.println(so.dp[i]);

	}

}

class NumbersFormN {

	// Returns the number of arrangements to
	// form 'n'
	int solveBF(int n) {
		// base case
//		System.out.println(n);
		if (n < 0)
			return 0;
		if (n == 0)
			return 1;

		return solveBF(n - 1) + solveBF(n - 3) + solveBF(n - 5);
	}

	// initialize to -1
	final int MAXN = 50;
	int dp[] = new int[MAXN];

	// this function returns the number of
	// arrangements to form 'n'
	int solveDP(int n) {
		// base case
		if (n < 0)
			return 0;
		if (n == 0)
			return 1;

		// checking if already calculated
		if (dp[n] != -1)
			return dp[n];

		// storing the result and returning
		return dp[n] = solveDP(n - 1) + solveDP(n - 3) + solveDP(n - 5);
	}

}