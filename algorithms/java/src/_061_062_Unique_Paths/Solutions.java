package _061_062_Unique_Paths;

public class Solutions {
	public static void main(String[] args) {
		Solution so = new Solution();
		SolutionDP sdp = new SolutionDP();
		int m = 3;
		int n = 3;
		int nums = sdp.uniquePaths(m, n);
		System.out.println(nums);

	}
}

class Solution {

}

class SolutionDP {
	/*
	 * The assumptions are
	 * 
	 * When (n==0||m==0) the function always returns 1 since the robot can't go left
	 * or up. For all other cells. The result =
	 * uniquePaths(m-1,n)+uniquePaths(m,n-1) Therefore I populated the edges with 1
	 * first and use DP to get the full 2-D array.
	 * 
	 * Please give any suggestions on improving the code.
	 */
	public int uniquePaths(int m, int n) {
		Integer[][] map = new Integer[m][n];
		for (int i = 0; i < m; i++) {
			map[i][0] = 1;
		}
		for (int j = 0; j < n; j++) {
			map[0][j] = 1;
		}
		for (int i = 1; i < m; i++) {
			for (int j = 1; j < n; j++) {
				map[i][j] = map[i - 1][j] + map[i][j - 1];
			}
		}
		return map[m - 1][n - 1];
	}
}