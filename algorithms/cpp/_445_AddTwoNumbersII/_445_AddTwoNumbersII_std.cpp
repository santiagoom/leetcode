
# include <iostream>
#include <stack>
#include <myListNode.h>

using namespace std;

int main() {
    cout << "new file!" << endl;
    return 0;
}

/**
 * Definition of singly-linked-list:
 * class ListNode {
 * public:
 *     int val;
 *     ListNode *next;
 *     ListNode(int val) {
 *        this->val = val;
 *        this->next = NULL;
 *     }
 * }
 */

/**
 * Definition of singly-linked-list:
 * class ListNode {
 * public:
 *     int val;
 *     ListNode *next;
 *     ListNode(int val) {
 *        this->val = val;
 *        this->next = NULL;
 *     }
 * }
 */

class Solution1 {
public:
    /**
     * @param l1: The first list.
     * @param l2: The second list.
     * @return: the sum list of l1 and l2.
     */
    ListNode *addLists2(ListNode *l1, ListNode *l2) {
        // write your code here
        stack<int> s1, s2;
        while (l1) {
            s1.push(l1->val);
            l1 = l1->next;
        }

        while (l2) {
            s2.push(l2->val);
            l2 = l2->next;
        }

        int sum = 0;
        ListNode *res = new ListNode(0);
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
            cout << "res:" << res << endl;
            ListNode *head = new ListNode(sum / 10);
            head->next = res;
            res = head;
            sum /= 10;
        } //end of while

        return res->val == 0 ? res->next : res;
    }
};


/**
 * Definition of singly-linked-list:
 * class ListNode {
 * public:
 *     int val;
 *     ListNode *next;
 *     ListNode(int val) {
 *        this->val = val;
 *        this->next = NULL;
 *     }
 * }
 */
class Solution2 {
public:
    ListNode *addLists2(ListNode *l1, ListNode *l2) {
        l1 = reverse(l1);
        l2 = reverse(l2);

        ListNode ret(0);
        ListNode *ptr = &ret;

        int carry = 0;
        while (l1 != nullptr || l2 != nullptr) {
            int a = (l1 != nullptr) ? l1->val : 0;
            int b = (l2 != nullptr) ? l2->val : 0;

            int tmp = a + b + carry;
            ListNode *node = new ListNode(tmp % 10);
            carry = tmp / 10;

            ptr->next = node;
            ptr = node;
            if (l1 != nullptr) l1 = l1->next;
            if (l2 != nullptr) l2 = l2->next;
        }

        if (carry != 0) {
            ListNode *node = new ListNode(carry);
            ptr->next = node;
            ptr = node;
        }

        return reverse(ret.next);
    }

    ListNode *reverse(ListNode *head) {
        if (head == nullptr || head->next == nullptr) return head;

        ListNode *back = head;
        ListNode *ptr = head->next;
        ListNode *next = ptr;
        back->next = nullptr;

        while (ptr != nullptr) {
            next = ptr->next;
            ptr->next = back;
            back = ptr;
            ptr = next;
        }

        return back;
    }
};