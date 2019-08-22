#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
    string longestCommonPrefix(vector<string> &strs) {
        if (strs.empty())
            return "";

        string res;
        for (int i = 0; i < strs[0].length(); i++) {
            for (int j = 1; j < strs.size(); j++) {
                if (strs[j].length() < i || strs[0][i] != strs[j][i])
                    return res;
            }
            res.append(1, strs[0][i]);
        }
        return res;
    }
};

int main() {
//    2019-08-22 10:27:28
//2019-08-22 10:47:36
//    vector<string> strs{"flower", "flow", "flight"};
    vector<string> strs{"leet", "leetcode", "leetd"};
    auto *so = new Solution();
    string res = so->longestCommonPrefix(strs);
    cout << res << endl;
    return 0;
}
