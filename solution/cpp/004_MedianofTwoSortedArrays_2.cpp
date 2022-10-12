
#include <iostream>
#include <cppUtils.h>

using namespace std;


class Solution {
public:
    int kth(int a[], int m, int b[], int n, int k) {
        if (m < n) return kth(b, n, a, m, k);
        if (n == 0) return a[k - 1];
        if (k == 1) return min(a[0], b[0]);

        int j = min(n, k / 2);
        int i = k - j;
        if (a[i - 1] > b[j - 1]) return kth(a, i, b + j, n - j, k - j);
        return kth(a + i, m - i, b, j, k - i);
    }

    double findMedianSortedArrays(int a[], int m, int b[], int n) {
        int k = (m + n) / 2;
        int m1 = kth(a, m, b, n, k + 1);
        if ((m + n) % 2 == 0) {
            int m2 = kth(a, m, b, n, k);
            return ((double) m1 + m2) / 2.0;
        }
        return m1;
    }
};


int main() {
    vector<int> nums{2, 7, 11, 15};
    int target = 26;
    string s = "aa";
    auto *so = new Solution();
    vector<vector<int>> arrays;
    CppUtils::print(s);
    CppUtils::print_1d_vector(nums);
    CppUtils::print_2d_vector(arrays);
    delete so;
    return 0;
}
                    