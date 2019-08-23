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
        for (int i = 0; i < len; i++) {
            for (int j = 0; j < m + 1; j++)
                cout << dp[i][j] << " ";
            cout << endl;
        }

        return dp[len - 1][m];
//        return vect[len - 1][m];
        return 0;
    }

    int max(int a, int b) {
        return a > b ? a : b;
    }

};

class Solutiondpopt {
public:
    int backPack(int m, vector<int> &A) {
        // write your code here
        int len = A.size();
        int dp[2][m + 1];
        bool bi;
        for (int i = 0; i <= m; i++) {

            if (i >= A[0]) {
                dp[0][i] = A[0];
            } else
                dp[0][i] = 0;
        }

        for (int i = 1; i < len; i++) {
            bi = i & 1;
            cout << i << ": " << bi << endl;
            for (int j = 0; j <= m; j++) {
                if (j >= A[i]) {
                    dp[bi][j] = max(dp[1 - bi][j - A[i]] + A[i], dp[1 - bi][j]);
                } else {
                    dp[bi][j] = dp[1 - bi][j];
                }
            }
        }
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < m + 1; j++)
                cout << dp[i][j] << " ";
            cout << endl;
        }

        return dp[bi][m];
//        return vect[len - 1][m];
        return 0;
    }

    int max(int a, int b) {
        return a > b ? a : b;
    }

};


int main() {
//    auto *so = new Solutionrecursive();
//    auto *so = new Solutiondp();
    auto *so = new Solutiondpopt();
//    vector<int> nums{3, 4, 8, 5};
//    int size = 10;
    vector<int> nums{2, 3, 5, 7};
    int size = 12;
//    Expected
//    5000
//        vector<int> nums{828, 125, 740, 724, 983, 321, 773, 678, 841, 842, 875, 377, 674, 144, 340, 467, 625, 916, 463,
//                         922,
//                         255, 662, 692, 123, 778, 766, 254, 559, 480, 483, 904, 60, 305, 966, 872, 935, 626, 691, 832,
//                         998,
//                         508, 657, 215, 162, 858, 179, 869, 674, 452, 158, 520, 138, 847, 452, 764, 995, 600, 568, 92,
//                         496,
//                         533, 404, 186, 345, 304, 420, 181, 73, 547, 281, 374, 376, 454, 438, 553, 929, 140, 298, 451,
//                         674,
//                         91, 531, 685, 862, 446, 262, 477, 573, 627, 624, 814, 103, 294, 388};
//        int size = 5000;


    int res = so->backPack(size, nums);
    cout << res << endl;
    return 0;
}
