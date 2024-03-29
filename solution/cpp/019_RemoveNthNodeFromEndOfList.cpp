#include <iostream>
#include <cppUtils.h>

using namespace std;

//int i = 0; 记录length, i>n

class Solution {
public:
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        ListNode *dummy = new ListNode(0);
        dummy->next = head;
        ListNode *first = dummy;
        ListNode *second = dummy;
        int i = 0;
        while (first->next && i++ < n) {
            first = first->next;
//            CppUtils::print(i);
//            CppUtils::print(first->val);
        }
        CppUtils::print(i);

        while (first->next) {
            first = first->next;
            second = second->next;
            i++;
        }
        CppUtils::print(i);

        if (n > i)
            return nullptr;
        else {
            second->next = second->next->next;
            return dummy->next;
        }

    }
};

int main() {
    auto *so = new Solution();
    ListNode *l1 = new ListNode(1);
    l1->next = new ListNode(2);
    l1->next->next = new ListNode(3);
    l1->next->next->next = new ListNode(4);
    l1->next->next->next->next = new ListNode(5);
    ListNode *res = so->removeNthFromEnd(l1, 2);
    CppUtils::printLinklist(res);
    delete res;
    delete so;
    return 0;
}
