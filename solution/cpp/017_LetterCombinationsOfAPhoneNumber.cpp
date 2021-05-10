#include <iostream>
#include <vector>
#include <cppUtils.h>

using namespace std;

class Solution {
public:
    vector<string> keyboard{"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    vector<string> res;

    vector<string> letterCombinations(string &digits) {
        if (digits.length() == 0)
            return {};
        backtracking("", digits);
        return res;
    }

    void backtracking(string combination, string digits) {
        if (digits.length() == 0)
            res.push_back(combination);
        else {
            string letters = keyboard[digits[0] - '0'];
            for (char letter: letters)
                backtracking(combination + letter, digits.substr(1));
        }
    }
};

class Solution_p1 {
public:
    vector<string> letterCombinations(string &digits) {
        if (digits.length() == 0) return {};
        vector<string> keyboard{"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        vector<string> res;
        backtracking(keyboard, res, "", digits);
        return res;
    }

    void backtracking(vector<string> &keyboard, vector<string> &res, string combination, string digits) {
        if (digits.length() == 0)
            res.push_back(combination);
        else {
            string letters = keyboard[digits[0] - '0'];
            for (char letter: letters)
                backtracking(keyboard, res, combination + letter, digits.substr(1));
        }
    }
};

int main() {
//    auto *so = new Solution();
    auto *so = new Solution_p1();
    string s = "24";
    vector<string> res = so->letterCombinations(s);
    CppUtils::print_1d_vector(res);
    return 0;
}