#include <iostream>

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
//    start: 2019-07-22 12:58:09
//end:
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        this->reverseRecursive(&l1);
        this->reverseRecursive(&l2);
        ListNode *dummy = new ListNode(-1);
        ListNode *prev = dummy;

        int sum = 0;
        int carry = 0;
        while (l1 || l2) {
            int val1 = l1 ? l1->val : 0;
            int val2 = l2 ? l2->val : 0;

            sum = (carry + val1 + val2) % 10;
            carry = (carry + val1 + val2) / 10;
            prev->next = new ListNode(sum);
            prev = prev->next;

            if (l1) l1 = l1->next;
            if (l2) l2 = l2->next;
        }
        if (carry > 0) prev->next = new ListNode(carry);

        this->reverseRecursive(&dummy->next);
        return dummy->next;
    }

    ListNode *reverseIterative(ListNode *l1) {
        ListNode *curr = l1;
        ListNode *prev = NULL, *next = NULL;

        while (curr != NULL) {
            next = curr->next;
            curr->next = prev;

            prev = curr;
            curr = next;
        }
        return prev;
    }

    void reverseUtils(ListNode *curr, ListNode *prev, ListNode **head_ref) {
        if (!curr->next) {
            *head_ref = curr;
            curr->next = prev;
            return;
        }

        ListNode *next = curr->next;
        curr->next = prev;

        reverseUtils(next, curr, head_ref);
    }

    void reverseRecursive(ListNode **l1) {
        if (!l1) return;
        reverseUtils(*l1, NULL, l1);
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

    l1 = so->reverseIterative(l1);
    l2 = so->reverseIterative(l2);
    ListNode *res = so->addTwoNumbers(l1, l2);
    res = so->reverseIterative(res);

    so->printList(res);
    so->reverseRecursive(&res);
    so->printList(res);

    return 0;
}