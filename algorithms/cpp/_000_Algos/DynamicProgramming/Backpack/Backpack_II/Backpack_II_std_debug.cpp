#include <iostream>
#include <vector>

using namespace std;

class SolutionRecursion {
//    36% test cases passedTotal runtime 1104 ms
public:
    /**
     * @param m: An integer m denotes the size of a backpack
     * @param A: Given n items with size A[i]
     * @param V: Given n items with value V[i]
     * @return: The maximum value
     */
    int backPackII(int m, vector<int> &A, vector<int> &V) {
        // write your code here
        int len = A.size();
        return helper(m, A, V, len);
    }

private:
    int helper(int m, vector<int> &A, vector<int> &V, int len) {
        if (m == 0 || len == 0)
            return 0;
        if (m < A[len - 1])
            return helper(m, A, V, len - 1);
        else
            return max(V[len - 1] + helper(m - A[len - 1], A, V, len - 1), helper(m, A, V, len - 1));
    }

    int max(int a, int b) {
        return a > b ? a : b;
    }
};

class SolutionDP {
//    else if (j < A[i-1])  not else if (m < A[i-1])
//    j < A[i-1] not A[i]
public:
    /**
     * @param m: An integer m denotes the size of a backpack
     * @param A: Given n items with size A[i]
     * @param V: Given n items with value V[i]
     * @return: The maximum value
     */
    int backPackII(int m, vector<int> &A, vector<int> &V) {
        // write your code here
        int len = A.size();
        int dp[len + 1][m + 1];
        for (int i = 0; i < len + 1; i++) {
            for (int j = 0; j < m + 1; j++) {
                if (i == 0 || j == 0)
                    dp[i][j] = 0;
                else if (j < A[i-1])
                    dp[i][j] = dp[i - 1][j];
                else
                    dp[i][j] = max(V[i-1] + dp[i - 1][j - A[i-1]], dp[i - 1][j]);
            }
        }

        for (int i = 0; i < len + 1; i++) {
            for (int j = 0; j < m + 1; j++) {
                cout << dp[i][j] << " ";
            }
            cout << endl;
        }
        return dp[len][m];
    }

private:
    int max(int a, int b) {
        return a > b ? a : b;
    }
};

class SolutionDPopt {
public:
    /**
     * @param m: An integer m denotes the size of a backpack
     * @param A: Given n items with size A[i]
     * @param V: Given n items with value V[i]
     * @return: The maximum value
     */
    int backPackII(int m, vector<int> &A, vector<int> &V) {
        // write your code here
    }
};

int main() {
//    auto *so = new SolutionRecursion();
    auto *so = new SolutionDP();
    vector<int> A{2, 3, 5, 7};
    vector<int> V{1, 5, 2, 4};
    int m = 10;
    int res = so->backPackII(m, A, V);
    cout << res << endl;
    return 0;
}
