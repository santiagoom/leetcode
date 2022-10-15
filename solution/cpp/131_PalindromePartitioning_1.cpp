
#include <iostream>
#include <cppUtils.h>
using namespace std;

                    
class Solution_131_PalindromePartitioning_1 {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> result;
        vector<string> currentList;
        dfs(result, s, 0, currentList);
        return result;
    }

    void dfs(vector<vector<string>> &result, string &s, int start, vector<string> &currentList) {
        if (start >= s.length()) result.push_back(currentList);
        for (int end = start; end < s.length(); end++) {
            if (isPalindrome(s, start, end)) {
                // add current substring in the currentList
                currentList.push_back(s.substr(start, end - start + 1));
                dfs(result, s, end + 1, currentList);
                // backtrack and remove the current substring from currentList
                currentList.pop_back();
            }
        }
    }

    bool isPalindrome(string &s, int low, int high) {
        while (low < high) {
            if (s[low++] != s[high--]) return false;
        }
        return true;
    }
};


int main() {
vector<int> nums{2, 7, 11, 15};
int target = 26;
string s = "aa";
vector<vector<int>> arrays;
CppUtils::print(s);
CppUtils::print_1d_vector(nums);
CppUtils::print_2d_vector(arrays);
return 0;
}
                    