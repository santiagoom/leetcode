#include <iostream>
#include <stack>

using namespace std;

/**
 * Definition for singly-linked list.
 */
struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
//    start: 2019-07-22 16:17:53
//    end: 2019-07-22 17:06:59
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        stack<int> s1, s2;
        while (l1) {
            s1.push(l1->val);
            l1 = l1->next;
        }
        while (l2) {
            s2.push(l2->val);
            l2 = l2->next;
        }

        ListNode *res = new ListNode(0);
        int sum = 0;
        while (!s1.empty() || !s2.empty()) {
            if (!s1.empty()) {
                sum += s1.top();
                s1.pop();
            }
            if (!s2.empty()) {
                sum += s2.top();
                s2.pop();
            }
            res->val = sum % 10;
            ListNode *head = new ListNode(sum / 10);
            head->next = res;
            res = head;
            sum = sum / 10;
        }
        return res->val == 0 ? res->next : res;
    }

    void printList(ListNode *node) {
        while (node != NULL) {
            cout << node->val << " ";
            node = node->next;
        }
        cout << endl;
    }
};

int main() {
//    Input: (7 -> 2 -> 4 -> 3) + (5 -> 6 -> 4)
//    Output: 7 -> 8 -> 0 -> 7
    ListNode *l1 = new ListNode(7);
    l1->next = new ListNode(2);
    l1->next->next = new ListNode(4);
    l1->next->next->next = new ListNode(3);

    ListNode *l2 = new ListNode(5);
    l2->next = new ListNode(6);
    l2->next->next = new ListNode(4);

    auto *so = new Solution();
    ListNode *res = so->addTwoNumbers(l1, l2);

    so->printList(l1);
    so->printList(l2);
    so->printList(res);

    delete l1;
    delete l2;
    delete so;
    return 0;
}