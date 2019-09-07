#include <iostream>
#include <vector>

using namespace std;

class Solution {
//    100% test cases passedTotal runtime 1107 ms
//            Your submission beats 88.60% Submissions!
public:
    /**
     * @param arrays: k sorted integer arrays
     * @return: a sorted array
     */
    vector<int> mergekSortedArrays(vector<vector<int>> &arrays) {
        // write your code here
        if (arrays.empty())
            return {};
        return mergeHelper(arrays, 0, arrays.size() - 1);
    }

    vector<int> mergeHelper(vector<vector<int>> &arrays, int start, int end) {
        if (start >= end)
            return arrays[start];
        int mid = (end + start) / 2;

        vector<int> left = mergeHelper(arrays, start, mid);
        vector<int> right = mergeHelper(arrays, mid + 1, end);
        return mergeSortedArray(left, right);
    }

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
//    2019-08-25 11:11:36
//2019-08-25 11:17:09
    auto *so = new Solution();
    vector<int> nums1{1, 2, 4};
    vector<int> nums2{2, 4, 5};
    vector<int> nums3{2, 7, 8};
    vector<vector<int>> lists;
    lists.push_back(nums1);
    lists.push_back(nums2);
    lists.push_back(nums3);
    vector<int> res = so->mergekSortedArrays(lists);
    for (int x: res)
        cout << x << " ";
    cout << endl;
    return 0;
}
