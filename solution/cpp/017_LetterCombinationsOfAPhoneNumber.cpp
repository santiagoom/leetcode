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


class Solution_p2 {
//    2021-5-17-1 17:51:42
public:
    vector<string> letterCombinations(string &digits) {
        vector<string> keyboard{"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        vector<string> res;
        backtracking(res, "", keyboard, digits, 0);
        return res;
    }

    void backtracking(vector<string> &res, string combine, vector<string> &keyboard, string &digits, int start) {
        if (combine.size() == digits.size())
            res.push_back(combine);
        else {
            for (int i = start; i < digits.size(); ++i) {
                char digit = digits[i];
                string letters = keyboard[digit - '0'];
                for (auto letter: letters) {
                    backtracking(res, combine + letter, keyboard, digits, i + 1);
                }
            }
        }
    }
};

int main() {
//    auto *so = new Solution();
//    auto *so = new Solution_p1();
    auto *so = new Solution_p2();
    string s = "24";
    vector<string> res = so->letterCombinations(s);
    CppUtils::print_1d_vector(res);
    return 0;
}
