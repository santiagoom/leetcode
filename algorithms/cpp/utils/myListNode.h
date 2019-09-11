//
// Created by tianm on 2019-09-05.
//

#ifndef CODING_INTERVIEWS_ALGO_MYLISTNODE_H
#define CODING_INTERVIEWS_ALGO_MYLISTNODE_H


//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;

    explicit ListNode(int x) : val(x), next(nullptr) {}
};

ListNode *createListNode(int value);

void connectListNodes(ListNode *pCurrent, ListNode *pNext);

void printList(ListNode *node);



//int main() {
//    auto *so = new Solution();
//    ListNode *l1 = new ListNode(1);
//    l1->next = new ListNode(2);
//    l1->next->next = new ListNode(3);
//    l1->next->next->next = new ListNode(4);
//    l1->next->next->next->next = new ListNode(5);
//    printList(l1);
//
//    ListNode *res = so->removeNthFromEnd(l1, 2);
//    printList(res);
//    delete res;
//    delete so;
//    return 0;
//}

#endif //CODING_INTERVIEWS_ALGO_MYLISTNODE_H


