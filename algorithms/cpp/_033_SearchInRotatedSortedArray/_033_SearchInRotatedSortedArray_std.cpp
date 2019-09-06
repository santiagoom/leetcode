#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    /**
     * @param A: an integer rotated sorted array
     * @param target: an integer to be searched
     * @return: an integer
     */
    int search(vector<int> &A, int target) {
        // write your code here
        if (A.empty()) return -1;
        int left = 0, right = A.size() - 1;
        while (left + 1 < right) {
            int mid = left + (right - left) / 2;
            if (A[mid] == target) return mid;
            if (A[left] < A[mid]) {
                if (A[left] <= target && target <= A[mid]) right = mid;
                else left = mid;
            } else {
                if (A[mid] < target && target <= A[right]) left = mid;
                else right = mid;
            }
        }
        if (A[left] == target) return left;
        if (A[right] == target) return right;
        return -1;
    }
};

int main() {
    auto *so = new Solution();
    cout << "new file!" << endl;
    delete so;
    return 0;
}
