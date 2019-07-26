
# include <iostream>

using namespace std;


/**
* This reference program is provided by @jiuzhang.com
* Copyright is reserved. Please indicate the source for forwarding
*/

class Solution0 {
    /*
     * 对于一个字符串，若其中某一个字符的数量小于k，则最终的答案中一定不会包含这个字符，因此答案只有可能在这个字符的左右两侧的字符串。
之后对于左右两边的串递归处理即可。
     */
public:
    int longestSubstring(string s, int k) {
        if (s.size() == 0) return 0;
        if (k <= 1) return s.size();
        map<char, int> cnt;
        for (int i = 0; i < s.size(); ++i) {
            cnt[s[i]]++;
        }
        bool allMoreK = true;
        for (auto a : cnt) {
            if (a.second < k) {
                allMoreK = false;
            }
        }
        if (allMoreK) return s.size();

        int longest = 0;
        int start = 0;
        while (start < s.size()) {
            while (start < s.size() && cnt[s[start]] < k) {
                start++;
            }
            int end = start;
            for (; end <= s.size(); ++end) {
                if ((end == s.size() && start < s.size()) || (end < s.size() && cnt[s[end]] < k)) {
                    longest = max(longest, longestSubstring(s.substr(start, end - start), k));
                    break;
                }
            }
            start = end + 1;
        }
        return longest;
    }
};

class Solution1 {
public:
    /**
     * @param s: a string
     * @param k: an integer
     * @return: return an integer
     */
    int longestSubstring(string &s, int k) {
        return helper(s, 0, s.size(), k);
    }

    int helper(string &s, int start, int end, int k) {
//        if (end-start < k) return 0;

        int res = 0;
        vector<int> cnt('z' + 1);
        for (int i = start; i < end; i++) {
            cnt[s[i]]++;
        }
        vector<pair<int, int>> idx;
        int last = start;
        for (int i = start; i < end; i++) {
            if (cnt[s[i]] < k) {
                if (i - last >= k) {
                    idx.emplace_back(last, i);
                }
                last = i + 1;
            }
        }
        if (end - last >= k) {
            idx.emplace_back(last, end);
        }

        if (last == start) return end - start;
        else if (idx.empty()) return 0;

        for (auto &p : idx) {
            res = max(res, helper(s, p.first, p.second, k));
        }

        return res;
    }
};

class Solution2 {
public:
    /**
     * @param s: a string
     * @param k: an integer
     * @return: return an integer
     */
    int longestSubstring(string &s, int k) {
        if (s.empty()) return 0;
        return helper(k, s, 0, s.size() - 1);
    }

    int helper(int k, string &s, int left, int right) {
        if (right - left + 1 < k) return 0;

        vector<int> count(26, 0);
        for (int i = left; i <= right; ++i) {
            ++count[s[i] - 'a'];
        }
        int res = 0, start = left;
        for (int i = left; i <= right; ++i) {
            if (count[s[i] - 'a'] < k) {
                res = max(res, helper(k, s, start, i - 1));
                start = i + 1;
            }
        }
        return start == left ? (right - left + 1) : max(res, helper(k, s, start, right));
    }
};

int main() {
    cout << "new file!" << endl;
    return 0;
}
