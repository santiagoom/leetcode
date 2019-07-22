
# include <iostream>

using namespace std;

int main() {
    cout << "new file!" << endl;
    return 0;
}

// Definition of singly-linked-list:
class ListNode {
public:
    int val;
    ListNode *next;

    ListNode(int val) {
        this->val = val;
        this->next = NULL;
    }
};

class Solution1 {
public:
    /**
     * @param l1: the first list
     * @param l2: the second list
     * @return: the sum list of l1 and l2
     */
    ListNode *addLists(ListNode *l1, ListNode *l2) {
        // write your code here
        int sum = 0, carry = 0;
        int val1 = 0, val2 = 0;
        ListNode *head = new ListNode(-1);
        ListNode *tmp = head;
        while (l1 || l2) {
            val1 = l1 ? l1->val : 0;
            val2 = l2 ? l2->val : 0;

            sum = (val1 + val2 + carry) % 10;

            carry = (val1 + val2 + carry) / 10;
            ListNode *res = new ListNode(sum);
            tmp->next = res;
            tmp = tmp->next;
            if (l1) {
                l1 = l1->next;
            }

            if (l2) {
                l2 = l2->next;
            }
        }

        if (carry) {
            tmp->next = new ListNode(carry);

        }

        return head->next;
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
    /**
     * @param l1: the first list
     * @param l2: the second list
     * @return: the sum list of l1 and l2
     */
    ListNode *addLists(ListNode *l1, ListNode *l2) {
        // write your code here
        ListNode dummy{-1};
        ListNode *prev = &dummy;
        int carry = 0;

        for (ListNode *pa = l1, *pb = l2;
             pa || pb;
             pa = pa == nullptr ? nullptr : pa->next, pb = pb == nullptr ? nullptr : pb->next, prev = prev->next) {
            const int a = pa == nullptr ? 0 : pa->val;
            const int b = pb == nullptr ? 0 : pb->val;
            const int sum = (a + b + carry) % 10;
            carry = (a + b + carry) / 10;

            prev->next = new ListNode{sum};
        }

        if (carry)
            prev->next = new ListNode{1};

        return dummy.next;
    }
};