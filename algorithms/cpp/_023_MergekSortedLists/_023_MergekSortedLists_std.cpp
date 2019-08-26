#include <iostream>
#include <vector>

using namespace std;


//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;

    explicit ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    /**
     * @param lists: a list of ListNode
     * @return: The head of one sorted list.
     */
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        // write your code here
        if (lists.size() == 0) return nullptr;
        if (lists.size() == 1) return lists[0];
        ListNode *merged = mergeHelper(lists, 0, lists.size() - 1);
        return merged;
    }

    ListNode *mergeHelper(vector<ListNode *> &lists, int start, int end) {
        if (start >= end) return lists[start];
        int mid = (end - start) / 2 + start;
        ListNode *left = mergeHelper(lists, start, mid);
        ListNode *right = mergeHelper(lists, mid + 1, end);
        return merge(left, right);
    }

    ListNode *merge(ListNode *a, ListNode *b) {
        ListNode *dummy = new ListNode(0);
        ListNode *cur = dummy;
        while (a && b) {
            if (a->val < b->val) {
                cur->next = a;
                cur = cur->next;
                a = a->next;
            } else {
                cur->next = b;
                cur = cur->next;
                b = b->next;
            }
        }
        while (a) {
            cur->next = a;
            cur = cur->next;
            a = a->next;
        }
        while (b) {
            cur->next = b;
            cur = cur->next;
            b = b->next;
        }
        return dummy->next;
    }
};

int main() {
    auto *so = new Solution();
    cout << "new file!" << endl;
    return 0;
}
