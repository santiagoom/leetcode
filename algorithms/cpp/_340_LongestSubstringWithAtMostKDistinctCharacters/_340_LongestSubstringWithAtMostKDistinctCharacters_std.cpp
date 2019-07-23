
# include <iostream>

using namespace std;


/**
* This reference program is provided by @jiuzhang.com
* Copyright is reserved. Please indicate the source for forwarding
*/

class Solution1 {
public:
    /**
     * @param s : A string
     * @return : The length of the longest substring
     *           that contains at most k distinct characters.
     */
    int lengthOfLongestSubstringKDistinct(string s, int k) {
        // write your code here
        int start = 0, cnt = 0;
        int char_set[256] = {0};
        int ans = 0;
        for (int i = 0; i < s.size(); i++) {
            if (char_set[s[i]]++ == 0) cnt++;
            while (cnt > k) {
                char_set[s[start]]--;
                if (char_set[s[start++]] == 0) cnt--;
            }
            ans = max(i - start + 1, ans);
        }
        return ans;
    }
};

class Solution2
{
public:
    /**
     * @param s: A string
     * @param k: An integer
     * @return: An integer
     */
    int lengthOfLongestSubstringKDistinct(string &s, int k)
    {
        if(k <= 0)
            return 0;
        // 同向双指针，左指针为主指针
        int maxlen = 0, counter[128] = { 0 }, c = 0;
        for(const char *begin = s.c_str(), *end = begin; *end != '\0'; begin++)
        {
            while(*end != '\0' && (c < k || c == k && counter[*end] > 0))
            {
                if(counter[*end] == 0)
                    c++;
                counter[*end]++;
                end++;
            }
            maxlen = max(maxlen, (int)(end - begin));
            counter[*begin]--;
            if(counter[*begin] == 0)
                c--;
        }
        return maxlen;
    }
};
class Solution3 {
public:
    /**
     * @param s: A string
     * @param k: An integer
     * @return: An integer
     */
    int lengthOfLongestSubstringKDistinct(string &s, int k) {
        // write your code here
        int len = s.length();
        if (len <= k) return len;
        if (k == 0) return 0;
        //cout << (int)'z' << endl;

        int hash[256];
        memset(hash, 0, sizeof(int)*256);
        len = 1;
        int Max_len = 1;
        int num_char = 1;
        hash[s[0]] = 1;
        int start = 0;
        for (int i=1; i<s.length(); i++) {
            if (hash[s[i]] > 0) {
                hash[s[i]] ++;
                len ++;
                if (Max_len < len) Max_len = len;
            }
            else if (num_char < k){
                num_char ++;
                hash[s[i]] = 1;
                len ++;
                if (Max_len < len) Max_len = len;
            }
            else {
                while (num_char >= k) {
                    hash[s[start]] --;
                    if (hash[s[start]] == 0) num_char --;
                    len --;
                    start ++;
                }

                hash[s[i]] = 1;
                len ++;
                if (Max_len < len) Max_len = len;
                num_char ++;
            }
        }

        return Max_len;
    }
};
int main() {
    cout << "new file!" << endl;
    return 0;
}
