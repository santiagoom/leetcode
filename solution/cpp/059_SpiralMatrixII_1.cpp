
#include <iostream>
#include <cppUtils.h>

using namespace std;


class Solution_059_SpiralMatrixII_1 {
public:

    vector<vector<int>> generateMatrix(int n) {

        vector<vector<int>> result(n, vector<int>(n));
        int cnt = 1;
        for (int layer = 0; layer < (n + 1) / 2; layer++) {
            // direction 1 - traverse from left to right
            for (int ptr = layer; ptr < n - layer; ptr++) {
                result[layer][ptr] = cnt++;
            }
            // direction 2 - traverse from top to bottom
            for (int ptr = layer + 1; ptr < n - layer; ptr++) {
                result[ptr][n - layer - 1] = cnt++;
            }
            // direction 3 - traverse from right to left
            for (int ptr = n - layer - 2; ptr >= layer; ptr--) {
                result[n - layer - 1][ptr] = cnt++;
            }
            // direction 4 - traverse from bottom to top
            for (int ptr = n - layer - 2; ptr > layer; ptr--) {
                result[ptr][layer] = cnt++;
            }
        }

        return result;
    }
};

int main() {
    int n = 3;
    auto *so = new Solution_059_SpiralMatrixII_1();
    auto res = so->generateMatrix(n);
    CppUtils::print_2d_vector(res);
    return 0;
}
                    