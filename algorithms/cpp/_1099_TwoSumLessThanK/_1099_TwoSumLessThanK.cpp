#include <iostream>
#include <vector>

using namespace std;

int main() {
    cout << "new file!" << endl;
    return 0;
}


class Solution {
    /*
     * INTUTIVE BRUTEFORCE ALGORITHM TO FIND MAXIMUM TOW SUM PAIR LESS THAN K
The bruteforce is the most intutive algorithm that we can use. We can bruteforce the two-pair in O(N^2) time complexity. Then, if the sum is less than K, we record the maxium.
     */
public:
    int twoSumLessThanK(vector<int> &A, int K) {
        int r = -1;
        for (int i = 0; i < A.size(); ++i) {
            for (int j = i + 1; j < A.size(); ++j) {
                if (A[i] + A[j] < K) {
                    r = max(r, A[i] + A[j]);
                }
            }
        }
        return r;
    }
};

class Solution2 {
    /*
     * SORT AND TWO POINTER ALGORITHM TO FIND MAXIMUM TOW SUM PAIR LESS THAN K
    If we sort the array which takes O(nlogN) time, we can apply the two-pointer algorithm by initialising the two points at two ends. If the current sum is less than K, we record and update the maximum. At each iteration, depending on the comparison between K and the current sum, we move the corresponding pointer.
     */
public:
    int twoSumLessThanK(vector<int> &A, int K) {
        sort(begin(A), end(A));
        int i = 0;
        int j = A.size() - 1;
        int ans = -1;
        while (i < j) {
            if (A[i] + A[j] >= K) {
                j--;
            } else {
                ans = max(ans, A[i] + A[j]);
                i++;
            }
        }
        return ans;
    }
};