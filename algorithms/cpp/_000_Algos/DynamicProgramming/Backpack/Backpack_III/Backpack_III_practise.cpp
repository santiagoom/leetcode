#include <iostream>
#include <vector>

using namespace std;

class SolutionRecursion {
//    Time Limit Exceeded
//    46% test cases passed
//    max(V[len - 1] + helper(m - A[len - 1], A, V, len) denote that it can hold the same one.
public:
    /**
     * @param m: An integer m denotes the size of a backpack
     * @param A: Given n items with size A[i]
     * @param V: Given n items with value V[i]
     * @return: The maximum value
     */
    int backPackIII(vector<int> &A, vector<int> &V, int m) {
        // write your code here
        int len = A.size();
        return helper(m, A, V, len);
    }

    int helper(int m, vector<int> &A, vector<int> &V, int len) {
        if (m <= 0 || len == 0)
            return 0;
        if (m >= A[len - 1])
            return max(V[len - 1] + helper(m - A[len - 1], A, V, len), helper(m, A, V, len - 1));
        else
            return helper(m, A, V, len - 1);
    }

    int max(int a, int b) {
        return a > b ? a : b;
    }
};

class SolutionDP {
//    else if (j < A[i-1])  not else if (m < A[i-1])
//    j < A[i-1] not A[i]
//    A subscript begin from 0;
//    类似于最基本的01背包, 我们设定 f[i][j] 表示前 i 种物品装到容量为 j 的背包里, 能获取的最大价值为多少.

public:
    /**
     * @param m: An integer m denotes the size of a backpack
     * @param A: Given n items with size A[i]
     * @param V: Given n items with value V[i]
     * @return: The maximum value
     */
    int backPackIII(vector<int> &A, vector<int> &V,int m ) {
        // write your code here
        int len = A.size();
        int dp[len + 1][m + 1];
        for (int i = 0; i < len + 1; i++) {
            for (int j = 0; j < m + 1; j++) {
                if (i == 0 || j == 0)
                    dp[i][j] = 0;
                else if (j < A[i - 1])
                    dp[i][j] = dp[i - 1][j];
                else
                    dp[i][j] = max(V[i - 1] + dp[i][j - A[i - 1]], dp[i - 1][j]);
            }
        }
        return dp[len][m];
    }

private:
    int max(int a, int b) {
        return a > b ? a : b;
    }
};

class SolutionDPopt {
//    else if (j < A[i-1])  not else if (m < A[i-1])
//    j < A[i-1] not A[i]
public:
    /**
     * @param m: An integer m denotes the size of a backpack
     * @param A: Given n items with size A[i]
     * @param V: Given n items with value V[i]
     * @return: The maximum value
     */
    int backPackIII( vector<int> &A, vector<int> &V,int m) {
        // write your code here
        int len = A.size();
        int dp[2][m + 1];
        bool bi;
        for (int i = 0; i < len + 1; i++) {
            bi = i & 1;
            for (int j = 0; j < m + 1; j++) {
                if (i == 0 || j == 0)
                    dp[bi][j] = 0;
                else if (j < A[i - 1])
                    dp[bi][j] = dp[1 - bi][j];
                else
                    dp[bi][j] = max(V[i - 1] + dp[bi][j - A[i - 1]], dp[1 - bi][j]);
            }
        }
        return dp[bi][m];
    }

private:
    int max(int a, int b) {
        return a > b ? a : b;
    }
};


int main() {
//    auto *so = new SolutionRecursion();
//    auto *so = new SolutionDP();
    auto *so = new SolutionDPopt();
    vector<int> A{2, 3, 5, 7};
    vector<int> V{1, 5, 2, 4};
    int m = 10;
    int res = so->backPackIII(A, V, m);
    cout << res << endl;
    return 0;
}
