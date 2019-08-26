#include <iostream>

using namespace std;

#include <stack>

class Solution {
public:
    bool isValid(string s) {
        stack<char> paren;
        for (char &c : s) {
            switch (c) {
                case '(':
                case '{':
                case '[':
                    paren.push(c);
                    break;
                case ')':
                    if (paren.empty() || paren.top() != '(') return false;
                    else paren.pop();
                    break;
                case '}':
                    if (paren.empty() || paren.top() != '{') return false;
                    else paren.pop();
                    break;
                case ']':
                    if (paren.empty() || paren.top() != '[') return false;
                    else paren.pop();
                    break;
                default:; // pass
            }
        }
        return paren.empty();
    }
};

int main() {
    auto *so = new Solution();
    cout << "new file!" << endl;
    return 0;
}