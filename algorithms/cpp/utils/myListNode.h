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


#endif //CODING_INTERVIEWS_ALGO_MYLISTNODE_H


