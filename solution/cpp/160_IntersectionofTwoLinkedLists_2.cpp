
#include <iostream>
#include <cppUtils.h>
using namespace std;

                    
class Solution_160_IntersectionofTwoLinkedLists_2 {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        set<ListNode *> nodes_in_B;

        while (headB != nullptr) {
            nodes_in_B.insert(headB);
            headB = headB->next;
        }

        while (headA != nullptr) {
            // if we find the node pointed to by headA,
            // in our set containing nodes of B, then return the node
            if (nodes_in_B.find(headA) != nodes_in_B.end()) {
                return headA;
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
vector<vector<int>> arrays;
CppUtils::print(s);
CppUtils::print_1d_vector(nums);
CppUtils::print_2d_vector(arrays);
return 0;
}
                    