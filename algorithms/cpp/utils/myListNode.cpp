//
// Created by tianm on 2019-09-05.
//
#include <iostream>
#include "myListNode.h"

using namespace std;


ListNode *createListNode(int value) {
    ListNode *pNode = new ListNode(value);
    return pNode;
}


void connectListNodes(ListNode *pCurrent, ListNode *pNext) {
    if (pCurrent == nullptr) {
        printf("Error to connect two nodes.\n");
        exit(1);
    }
    pCurrent->next = pNext;
}

void printList(ListNode *node) {
    while (node != NULL) {
        cout << node->val << " ";
        node = node->next;
    }
    cout << endl;
}
