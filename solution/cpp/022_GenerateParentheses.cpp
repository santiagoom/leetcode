#include <iostream>
#include <vector>
#include <cppUtils.h>

using namespace std;

class Solution {
public:
    vector<string> res;

    vector<string> generateParenthesis(int n) {
        backtracking("", 0, 0, n);
        return res;
    }

    void backtracking(string curr, int open, int close, int max) {
        if (curr.length() == 2 * max)
            res.push_back(curr);

        if (open < max)
            backtracking(curr + "(", open + 1, close, max);
        if (close < open)
            backtracking(curr + ")", open, close + 1, max);
    }
};

class Solution_p1 {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        backtracking(res, "", 0, 0, n);
        return res;
    }

    void backtracking(vector<string> &res, string curr, int open, int close, int max) {
        if (curr.length() == 2 * max)
            res.push_back(curr);

        if (open < max)
            backtracking(res, curr + "(", open + 1, close, max);
        if (close < open)
            backtracking(res, curr + ")", open, close + 1, max);
    }
};

int main() {
//    auto *so = new Solution();
    auto *so = new Solution_p1();
    int n = 3;
    vector<string> res = so->generateParenthesis(n);
    CppUtils::print_1d_vector(res);
    delete so;
    return 0;
}