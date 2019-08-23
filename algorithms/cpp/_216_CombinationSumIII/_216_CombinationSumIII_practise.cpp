#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> res;
        vector<int> templist;
        backtracking(res, templist, k, n, 1);
        return res;
    }

private:
    void backtracking(vector<vector<int>> &res, vector<int> &templist, int k, int n, int start) {
        if (templist.size() > k || n < 0)
            return;
        else if (templist.size() == k && n == 0)
            res.push_back(templist);
        else {
            for (int i = start; i < 10; i++) {
                templist.push_back(i);
                backtracking(res, templist, k, n - i, i + 1);
                templist.pop_back();
            }
        }
    }
};


int main() {
//    2019-08-22 22:27:01
//2019-08-22 22:41:29
    auto *so = new Solution();
    vector<vector<int>> res = so->combinationSum3(3, 9);
    for (auto &list: res) {
        for (auto ele: list) {
            cout << ele;
        }
        cout << endl;
    }
    delete so;
    return 0;
}
