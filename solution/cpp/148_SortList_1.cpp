
#include <iostream>
#include <cppUtils.h>

using namespace std;


class Solution_148_SortList_1 {
public:
    ListNode *sortList(ListNode *head) {
        if (!head || !head->next)
            return head;
        ListNode *mid = getMid(head);
        ListNode *left = sortList(head);
        ListNode *right = sortList(mid);
        return merge(left, right);
    }

    ListNode *merge(ListNode *list1, ListNode *list2) {
        ListNode dummyHead(0);
        ListNode *ptr = &dummyHead;
        while (list1 && list2) {
            if (list1->val < list2->val) {
                ptr->next = list1;
                list1 = list1->next;
            } else {
                ptr->next = list2;
                list2 = list2->next;
            }
            ptr = ptr->next;
        }
        if (list1) ptr->next = list1;
        else ptr->next = list2;

        return dummyHead.next;
    }

    ListNode *getMid(ListNode *head) {
        ListNode *midPrev = nullptr;
        while (head && head->next) {
            midPrev = (midPrev == nullptr) ? head : midPrev->next;
            head = head->next->next;
        }
        ListNode *mid = midPrev->next;
        midPrev->next = nullptr;
        return mid;
    }
};


int main() {
    ListNode *l1 = new ListNode(-1);
    l1->next = new ListNode(5);
    l1->next->next = new ListNode(3);
    l1->next->next->next = new ListNode(4);
    l1->next->next->next->next = new ListNode(0);

    auto *so = new Solution_148_SortList_1();
    auto res = so->sortList(l1);
    CppUtils::printLinklist(res);
    return 0;
}
                    