package _053_MaximumSubarray;

public class Std {
	public static void main(String[] args) {
		SolutionDP so = new SolutionDP();
		SolutionDP1 so1 = new SolutionDP1();
		int num[] = { -2, 1, -3, 4, -1, 2, 1, -5, 4 };
		int out = so.maxSubArray(num);
		int out1 = so1.maxSubArray(num);
		System.out.println(out1);
	}
}

class SolutionDC {
	/*
	 * A Divide and Conquer based Java program for maximum subarray sum problem
	 *
	 * Note: maxCrossingSum at least includes one left number and one right number.
	 */

	// Find the maximum possible sum in arr[]
	// such that arr[m] is part of it
	static int maxCrossingSum(int arr[], int l, int m, int h) {
		// Include elements on left of mid.
		int sum = 0;
		int left_sum = Integer.MIN_VALUE;
		for (int i = m; i >= l; i--) {
			sum = sum + arr[i];
			if (sum > left_sum)
				left_sum = sum;
		}

		// Include elements on right of mid
		sum = 0;
		int right_sum = Integer.MIN_VALUE;
		for (int i = m + 1; i <= h; i++) {
			sum = sum + arr[i];
			if (sum > right_sum)
				right_sum = sum;
		}

		// Return sum of elements on left
		// and right of mid
		return left_sum + right_sum;
	}

	// Returns sum of maxium sum subarray
	// in aa[l..h]
	static int maxSubArraySum(int arr[], int l, int h) {
		// Base Case: Only one element
		if (l == h)
			return arr[l];

		// Find middle point
		int m = (l + h) / 2;

		/*
		 * Return maximum of following three possible cases: a) Maximum subarray sum in
		 * left half b) Maximum subarray sum in right half c) Maximum subarray sum such
		 * that the subarray crosses the midpoint
		 */
		return Math.max(Math.max(maxSubArraySum(arr, l, m), maxSubArraySum(arr, m + 1, h)),
				maxCrossingSum(arr, l, m, h));
	}

	/* Driver program to test maxSubArraySum */
	public static void main(String[] args) {
		int arr[] = { 2, 3, 4, 5, 7 };
		int n = arr.length;
		int max_sum = maxSubArraySum(arr, 0, n - 1);

		System.out.println("Maximum contiguous sum is " + max_sum);
	}
}
//This code is contributed by Prerna Saini

class SolutionDP1 {
	/*
	 * Kadane��s Algorithm
	 * 
	 * Initialize: max_so_far = 0 max_ending_here = 0
	 * 
	 * Loop for each element of the array
	 * 
	 * (a) max_ending_here = max_ending_here + a[i]
	 * 
	 * (b) if(max_ending_here < 0) max_ending_here = 0
	 * 
	 * (c) if(max_so_far < max_ending_here) max_so_far = max_ending_here
	 * 
	 * return max_so_far
	 */
	public int maxSubArray(int[] A) {
		int maxSoFar = A[0], maxEndingHere = A[0];
		for (int i = 1; i < A.length; ++i) {
			maxEndingHere = Math.max(maxEndingHere + A[i], A[i]);
			maxSoFar = Math.max(maxSoFar, maxEndingHere);
			System.out.println(i + ": " + maxSoFar);

		}
		return maxSoFar;
	}
}

class SolutionDP {
	/*
	 * Input: [-2,1,-3,4,-1,2,1,-5,4],
	 * 
	 * Output: 6
	 * 
	 * Explanation: [4,-1,2,1] has the largest sum = 6.
	 * 
	 */
	public int maxSubArray(int[] A) {
		int n = A.length;
		int[] dp = new int[n];// dp[i] means the maximum subarray ending with A[i];
		dp[0] = A[0];
		int max = dp[0];

		for (int i = 1; i < n; i++) {
			dp[i] = A[i] + (dp[i - 1] > 0 ? dp[i - 1] : 0);
			max = Math.max(max, dp[i]);
			System.out.println(i + ": " + dp[i]);
		}

		return max;
	}

}
