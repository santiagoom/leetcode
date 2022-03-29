# include <iostream>
# include <vector>
#include <unordered_map>
# include <cppUtils.h>

using namespace std;

class Solution {
public:
    vector<int> findSubstring(string s, vector<string> &words) {
        if (s.empty() || words.empty()) return {};
        vector<int> res;
        int n = words.size(), len = words[0].size();
        unordered_map<string, int> wordCnt;
        for (auto &word: words) ++wordCnt[word];
        for (int i = 0; i <= (int) s.size() - n * len; ++i) {
            unordered_map<string, int> strCnt;
            int j = 0;
            for (j = 0; j < n; ++j) {
                string t = s.substr(i + j * len, len);
                if (!wordCnt.count(t)) break;
                ++strCnt[t];
                if (strCnt[t] > wordCnt[t]) break;
            }
            if (j == n) res.push_back(i);
        }
        return res;
    }
};

int main() {
    auto *so = new Solution();
    string s = "barfoothefoobarman";
    vector<string> words{"foo", "bar"};
    vector<int> res = so->findSubstring(s, words);
    CppUtils::print_1d_vector(res);
    cout << "new file!" << endl;
    delete so;
    return 0;
}