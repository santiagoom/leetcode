#include <iostream>
#include <vector>
#include <cppUtils.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> res;
        vector<int> templist;
        backtracking(res, templist, n, k, 1);
        return res;
    }

private:
    void backtracking(vector<vector<int>> &res, vector<int> &templist, int n, int k, int start) {
        if (templist.size() == k)
            res.push_back(templist);
        else {
            for (int i = start; i <= n; i++) {
                templist.push_back(i);
                backtracking(res, templist, n, k, i + 1);
                templist.pop_back();
            }
        }
    }
};

int main() {
    auto *so = new Solution();
    int n = 4;
    int k = 3;
    vector<vector<int>> res = so->combine(n, k);
    CppUtils::print_2d_vector(res);
    return 0;
}

