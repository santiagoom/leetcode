
#include <iostream>
#include <cppUtils.h>

using namespace std;


class Solution_203_RemoveLinkedListElements_1 {
public:
    ListNode *removeElements(ListNode *head, int val) {
        ListNode *sentinel = new ListNode(0);
        sentinel->next = head;

        ListNode *prev = sentinel, *curr = head, *toDelete = nullptr;
        while (curr != nullptr) {
            if (curr->val == val) {
                prev->next = curr->next;
                toDelete = curr;
            } else prev = curr;

            curr = curr->next;

            if (toDelete != nullptr) {
                delete toDelete;
                toDelete = nullptr;
            }
        }

        ListNode *ret = sentinel->next;
        delete sentinel;
        return ret;
    }
};

int main() {
    auto *so = new Solution_203_RemoveLinkedListElements_1();
    vector<int> nums{2, 7, 11, 15};
    int target = 26;
    string s = "aa";
    vector<vector<int>> arrays;
    CppUtils::print(s);
    CppUtils::print_1d_vector(nums);
    CppUtils::print_2d_vector(arrays);
    return 0;
}
                    