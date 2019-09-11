#include <iostream>
#include <vector>
#include <stack>
#include <myutils.h>

using namespace std;

class Solution {
};

/**
* This reference program is provided by @jiuzhang.com
* Copyright is reserved. Please indicate the source for forwarding
*/

class MinStack1 {
public:
    stack<int> stk, minstk;

    void push(int number) {
        stk.push(number);
        if (minstk.empty() or number <= minstk.top()) {
            minstk.push(number);
        }
    }

    int pop() {
        int top = stk.top();
        stk.pop();
        if (top == minstk.top()) {
            minstk.pop();
        }
        return top;
    }

    int min() {
        return minstk.top();
    }
};

// 单调栈版本

class MinStack2 {
private:
    stack<int> stk, minStk;

public:
    MinStack2() {
        // do intialization if necessary
    }

    /*
     * @param number: An integer
     * @return: nothing
     */
    void push(int number) {
        stk.push(number);
        if (minStk.empty() || number <= minStk.top()) {
            minStk.push(number);
        }
    }

    /*
     * @return: An integer
     */
    int pop() {
        if (stk.top() == minStk.top()) {
            minStk.pop();
        }
        int ret = stk.top();
        stk.pop();
        return ret;
    }

    /*
     * @return: An integer
     */
    int min() {
        return minStk.top();
    }
};

int main() {
    auto *so = new Solution();
    vector<int> nums{};
    delete so;
    return 0;
}
