#include <iostream>
#include <vector>
#include <stack>
#include <myutils.h>

using namespace std;

/**
* This reference program is provided by @jiuzhang.com
* Copyright is reserved. Please indicate the source for forwarding
*/

class Solution1 {
public:
    /**
     * @param preorder: List[int]
     * @return: return a boolean
     */
    bool verifyPreorder(vector<int> &preorder) {
        // write your code here
        int low = -1e9;
        stack<int> path;
        for (int i = 0; i < preorder.size(); i++) {
            int p = preorder[i];
            if (p < low)
                return false;
            while (path.size() && p > path.top()) {
                low = path.top();
                path.pop();
            }
            path.push(p);
        }
        return true;
    }
};

class Solution2 {
public:
    /**
     * @param preorder: List[int]
     * @return: return a boolean
     */
    bool verifyPreorder(vector<int> &preorder) {
        int stack_top = -1;
        int min_val = numeric_limits<int>::min();
        for (auto &&num : preorder) {
            // 出现更小的数说明不是合法BST的前序遍历
            if (num < min_val) return false;
            // 将路径中所有小于当前值的数都pop出来
            // 为了记录最后一个pop的数，记录每次pop都记录其值
            // 这个最后被pop的数，其右子树是当前值
            // 并且之后的所有数都会比这个数大（BST特性）
            while (stack_top >= 0 && num > preorder[stack_top]) {
                min_val = preorder[stack_top--];
            }
            // 此时要么栈s为空，要么栈顶元素大于当前num
            preorder[++stack_top] = num;
        }
        return true;
    }
};

class Solution3 {
public:
    bool verifyPreorder(vector<int> &preorder) {
        int lowerBound = INT_MIN;
        int lowIndex = -1;
        for (int i = 0; i < preorder.size(); i++) {
            if (preorder[i] < lowerBound) return false;
            //using preorder as a stack
            while (lowIndex >= 0 and preorder[i] > preorder[lowIndex]) {
                lowerBound = preorder[lowIndex];
                lowIndex--;
            }
            //store the root of right sub tree
            preorder[++lowIndex] = preorder[i];
        }
        return true;
    }
};

int main() {
    auto *so = new Solution1();
    vector<int> nums{};
    delete so;
    return 0;
}
