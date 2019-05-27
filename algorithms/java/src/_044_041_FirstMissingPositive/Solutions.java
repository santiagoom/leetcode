package _044_041_FirstMissingPositive;

public class Solutions {
	/*
	 * The basic idea is
	 * 
	 * for any k positive numbers (duplicates allowed), the first missing positive
	 * number must be within [1,k+1].
	 * 
	 * The reason is like you put k balls into k+1 bins, there must be a bin empty,
	 * the empty bin can be viewed as the missing number.
	 * 
	 * Unfortunately, there are 0 and negative numbers in the array, so firstly I
	 * think of using partition technique (used in quick sort) to put all positive
	 * numbers together in one side. This can be finished in O(n) time, O(1) space.
	 * 
	 * After partition step, you get all the positive numbers lying within A[0,k-1].
	 * Now, According to the basic idea, I infer the first missing number must be
	 * within [1,k+1]. I decide to use A[i] (0<=i<=k-1) to indicate whether the
	 * number (i+1) exists. But here I still have to main the original information
	 * A[i] holds. Fortunately, A[i] are all positive numbers, so I can set them to
	 * negative to indicate the existence of (i+1) and I can still use abs(A[i]) to
	 * get the original information A[i] holds.
	 * 
	 * After step 2, I can again scan all elements between A[0,k-1] to find the
	 * first positive element A[i], that means (i+1) doesn't exist, which is what I
	 * want.
	 */
	public static void main(String[] args) {
//		int nums[] = {7,8,9,11,12};
		int nums[] = { 3, 3, 4, -1, 1 };

		Solution so = new Solution();
		int out = so.firstMissingPositive(nums);
		System.out.println(out);
	}
}

class Solution {
	public int firstMissingPositive(int[] A) {
		int n = A.length;
		if (n == 0)
			return 1;
		int k = partition(A) + 1;
		System.out.println(k);
		for (int i = 0; i < A.length; i++)
			System.out.print(A[i]);
		System.out.println();
		int temp = 0;
		int first_missing_Index = k;
		for (int i = 0; i < k; i++) {
			temp = Math.abs(A[i]);
			if (temp <= k)
				A[temp - 1] = (A[temp - 1] < 0) ? A[temp - 1] : -A[temp - 1];
			for (int j = 0; j < A.length; j++)
				System.out.print(A[j]);
			System.out.println();
		}
		for (int i = 0; i < k; i++) {
			if (A[i] > 0) {
				first_missing_Index = i;
				break;
			}
		}
		return first_missing_Index + 1;
	}

	public int partition(int[] A) {
		int n = A.length;
		int q = -1;
		for (int i = 0; i < n; i++) {
			if (A[i] > 0) {
				q++;
				swap(A, q, i);
			}
		}
		return q;
	}

	public void swap(int[] A, int i, int j) {
		if (i != j) {
			A[i] ^= A[j];
			A[j] ^= A[i];
			A[i] ^= A[j];
		}
	}
}