#include <iostream>
#include <stack>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(NULL) {}
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
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
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

//        return res->val == 0 ? res->next : res;
        return res;
    }
    void printList(ListNode *node) {
        while (node != NULL) {
            cout << node->val << " ";
            node = node->next;
        }
        cout << endl;
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

    auto *so = new Solution1();
    ListNode *res = so->addTwoNumbers(l1, l2);

    so->printList(l1);
    so->printList(l2);
    so->printList(res);

    delete l1;
    delete l2;
    delete so;

    return 0;
}