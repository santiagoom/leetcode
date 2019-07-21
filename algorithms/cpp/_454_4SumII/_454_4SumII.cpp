
# include <iostream>
#include <unordered_map>

using namespace std;

int main() {
    cout << "new file!" << endl;
    return 0;
}

class Solution {
public:
    /**
     * @param A: a list
     * @param B: a list
     * @param C: a list
     * @param D: a list
     * @return: how many tuples (i, j, k, l) there are such that A[i] + B[j] + C[k] + D[l] is zero
     */
    int fourSumCount(vector<int> &A, vector<int> &B, vector<int> &C, vector<int> &D) {
        unordered_map<int,int> mp;
        for(const auto &a:A) {
            for(const auto &b:B) {
                ++mp[a+b];
            }
        }
        int res=0;
        for(const auto &c:C) {
            for(const auto &d:D) {
                res+=mp[-c-d];
            }
        }
        return res;
    }
};