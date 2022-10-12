
#include <iostream>
#include <cppUtils.h>

using namespace std;

                    
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        while (headA != nullptr) {
            ListNode *pB = headB;
            while (pB != nullptr) {
                if (headA == pB) return headA;
                pB = pB->next;
            }
            headA = headA->next;
        }
        return nullptr;
    }
};

                    
int main() {
    vector<int> nums{2, 7, 11, 15};
    int target = 26;
    string s = "aa";
    auto *so = new Solution();
    vector<vector<int>> arrays;
    CppUtils::print(s);
    CppUtils::print_1d_vector(nums);
    CppUtils::print_2d_vector(arrays);
    delete so;
    return 0;
}
                    