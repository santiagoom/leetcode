//
// Created by tianm on 2022/3/22.
//
#include <iostream>
#include <vector>
#include <cppUtils.h>

using namespace std;

class Solution {
public:
    ListNode *reverseKGroup(ListNode *head, int k) {
        if (!head || k == 1) return head;
        ListNode *dummy = new ListNode(-1), *pre = dummy, *cur = head;
        dummy->next = head;
        for (int i = 1; cur; ++i) {
            if (i % k == 0) {
                pre = reverseOneGroup(pre, cur->next);
                cur = pre->next;
            } else {
                cur = cur->next;
            }
        }
        return dummy->next;
    }

    ListNode *reverseOneGroup(ListNode *pre, ListNode *next) {
        ListNode *last = pre->next, *cur = last->next;
        while (cur != next) {
            last->next = cur->next;
            cur->next = pre->next;
            pre->next = cur;
            cur = last->next;
        }
        return last;
    }
};


int main() {
    auto *so = new Solution();
    ListNode *l1 = new ListNode(1);
    l1->next = new ListNode(2);
    l1->next->next = new ListNode(3);
    l1->next->next->next = new ListNode(4);
    l1->next->next->next->next = new ListNode(5);
    l1->next->next->next->next->next = new ListNode(6);

    int k = 3;

    ListNode *res = so->reverseKGroup(l1, k);
    CppUtils::printLinklist(res);
    delete so;
    return 0;
}
