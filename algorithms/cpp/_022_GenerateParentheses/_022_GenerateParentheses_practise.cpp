#include <iostream>
#include <vector>

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

int main() {
//    2019-08-22 15:08:43
//2019-08-22 15:17:47
    auto *so = new Solution();
    int n = 3;
    vector<string> res = so->generateParenthesis(n);
    for (string &str :res)
        cout << str << endl;
    delete so;
    return 0;
}
