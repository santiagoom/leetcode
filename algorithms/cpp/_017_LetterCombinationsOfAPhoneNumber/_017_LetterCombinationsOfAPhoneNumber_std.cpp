
#include <iostream>
#include <vector>

using namespace std;

class Solution {

};

/**
* This reference program is provided by @jiuzhang.com
* Copyright is reserved. Please indicate the source for forwarding
*/

//Time complexity : 3**n * 4**N
//Space complexity : 3**n * 4**N

class Solution1 {
public:
    const vector<string> keyboard{"", "", "abc", "def",     // '0','1','2',...
                                  "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

    vector<string> letterCombinations(const string &digits) {
        if (digits == "") return {};
        vector<string> result;
        dfs(digits, 0, "", result);
        return result;
    }

    void dfs(const string &digits, size_t cur, string path,
             vector<string> &result) {
        if (cur == digits.size()) {
            result.push_back(path);
            return;
        }
        for (auto c : keyboard[digits[cur] - '0']) {
            dfs(digits, cur + 1, path + c, result);
        }
    }
};


///////////// 方法二

class Solution2 {
public:
    vector<string> ans;

    void dfs(int x, int l, string str, string digits, char phone[][4]) {
        if (x == l) {
            ans.push_back(str);
            return;
        }
        int num = digits[x] - '0';
        for (int i = 0; i < 4; i++) {
            if (phone[num][i]) {
                dfs(x + 1, l, str + phone[num][i], digits, phone);
            }
        }
    }


    /**
     * @param digits A digital string
     * @return all posible letter combinations
     */
    vector<string> letterCombinations(string &digits) {
        char phone[10][4] = {{' '},
                             {},
                             {'a', 'b', 'c'},
                             {'d', 'e', 'f'},
                             {'g', 'h', 'i'},
                             {'j', 'k', 'l'},
                             {'m', 'n', 'o'},
                             {'p', 'q', 'r', 's'},
                             {'t', 'u', 'v'},
                             {'w', 'x', 'y', 'z'}};

        if (digits.size() == 0) {
            return ans;
        }
        dfs(0, digits.size(), "", digits, phone);
        return ans;
    }
};

class Solution3 {
public:
    /**
     * @param digits: A digital string
     * @return: all posible letter combinations
     */
    const vector<string> letters{"", "", "abc", "def", // '0','1','2',...
                                 "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

    vector<string> letterCombinations(string &digits) {
        // write your code here
        // DFS
        vector<string> res;
        int sizeD = digits.size();
        if (sizeD == 0) {
            return res;
        }
        dfs(digits, res, 0, "");
        return res;
    }

    void dfs(string &digits, vector<string> &res, int cur, string path) {
        if (cur == digits.size()) {
            res.push_back(path);
        }
        for (auto elem : letters[digits[cur] - '0']) {
            dfs(digits, res, cur + 1, path + elem);
        }
    }
};

class Solution4 {
private:
    vector<string> dict = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
public:
    /**
     * @param digits: A digital string
     * @return: all posible letter combinations
     */
    vector<string> letterCombinations(string &digits) {
        int len = digits.size();
        vector<string> res;
        string out;

        if (!len) return res;
        dfs(res, out, digits, 0);
        return res;
    }

    void dfs(vector<string> &res, string &out, string &digits, int idx) {
        if (idx == digits.size()) {
            res.push_back(out);
            return;
        }
        string cur = dict[digits[idx] - '0'];
        for (int i = 0; i < cur.size(); i++) {
            out.push_back(cur[i]);
            dfs(res, out, digits, idx + 1);
            out.pop_back();
        }
    }
};

int main() {
    auto *so = new Solution();
    cout << "new file!" << endl;
    return 0;
}
