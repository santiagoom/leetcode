#include <iostream>
#include <vector>
#include <myutils.h>

using namespace std;

class Solution {

public:
    // A Dynamic Programming solution for Max Product Problem
    int maxProd(int n) {
        int val[n + 1];
        val[0] = val[1] = 0;
        // Build the table val[] in bottom up manner and return
        // the last entry from the table
        for (int i = 1; i <= n; i++) {
            int max_val = 0;
            for (int j = 1; j <= i / 2; j++)
                max_val = max(max_val, (i - j) * j, j * val[i - j]);
            val[i] = max_val;
        }
        return val[n];
    }

    int max(int a, int b) { return (a > b) ? a : b; }

    int max(int a, int b, int c) { return max(a, max(b, c)); }
};


int main() {
    auto *so = new Solution();
    int res = so->maxProd(100);
    print(res);
    delete so;
    return 0;
}
