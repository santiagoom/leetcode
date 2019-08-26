#include <iostream>
#include <vector>

using namespace std;

class Solution {
//    100% test cases passedTotal runtime 15 ms
//            Your submission beats 52.80% Submissions
public:
    /**
     * @param A: sorted integer array A
     * @param B: sorted integer array B
     * @return: A new sorted integer array
     */
    vector<int> mergeSortedArray(vector<int> &A, vector<int> &B) {
        // write your code here
        if (A.empty() || B.empty()) {
            if (A.empty())
                return B;
            else if (B.empty())
                return A;
            else return {};
        }

        vector<int> res;
        int i = 0, j = 0;
        while (i < A.size() || j < B.size()) {
            if (A.size() == i) {
                res.push_back(B[j]);
                j++;
                continue;
            }
            if (B.size() == j) {
                res.push_back(A[i]);
                i++;
                continue;
            }
            if (A[i] < B[j]) {
                res.push_back(A[i]);
                i++;
            } else {
                res.push_back(B[j]);
                j++;
            }
        }
        return res;
    }
};

int main() {
//    2019-08-25 09:15:40  change classroom
//2019-08-25 09:45:50
    auto *so = new Solution();
    vector<int> A{1, 2, 3, 4, 5};
    vector<int> B{2, 4, 5, 6};
    vector<int> res = so->mergeSortedArray(A, B);
    cout << res.size() << endl;
    for (int x: res)
        cout << x << " ";
    cout << endl;
    return 0;
}
