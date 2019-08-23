#include <iostream>
#include <vector>

using namespace std;


class Solutionrecursive {
//    44% test cases passedTotal runtime 3317 ms
public:
    /**
     * @param m: An integer m denotes the size of a backpack
     * @param A: Given n items with size A[i]
     * @return: The maximum size
     */
    int backPack(int m, vector<int> &A) {
        return helper(m, A, A.size());
    }

private:
    int max(int a, int b) {
        return a > b ? a : b;
    }

    int helper(int m, vector<int> &A, int n) {
        if (m <= 0 || n == 0)
            return 0;
        if (m < A[n - 1]) {
            return helper(m, A, n - 1);
        }
        return max(A[n - 1] + helper(m - A[n - 1], A, n - 1), helper(m, A, n - 1));
    }
};

class Solutiondp {
    //    if (j >= A[i])   not if (m >= A[i]) 
public:
    int backPack(int m, vector<int> &A) {
        // write your code here
        int len = A.size();
        int dp[len][m + 1];
        for (int i = 0; i <= m; i++) {
            if (i >= A[0]) {
                dp[0][i] = A[0];
            } else
                dp[0][i] = 0;
        }

        for (int i = 1; i < len; i++) {
            for (int j = 0; j <= m; j++) {
                if (j >= A[i]) {
                    dp[i][j] = max(dp[i - 1][j - A[i]] + A[i], dp[i - 1][j]);
                } else {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }
        return dp[len - 1][m];
    }

    int max(int a, int b) {
        return a > b ? a : b;
    }
};

int main() {
    auto *so = new Solutiondp();
    vector<int> nums{2, 3, 5, 7};
    int size = 12;
    int res = so->backPack(size, nums);
    cout << res << endl;
    return 0;
}
