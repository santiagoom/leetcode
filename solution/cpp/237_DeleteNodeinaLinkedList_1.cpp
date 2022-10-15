
#include <iostream>
#include <cppUtils.h>
using namespace std;

                    
class Solution_237_DeleteNodeinaLinkedList_1 {
public:
    void deleteNode(ListNode* node) {
        // Since we know input node is not last node, so nextNode will not be null
        ListNode *nextNode = node->next;
        // Step 2
        node->val = nextNode->val;
        // Step 3
        node->next = nextNode->next;
        nextNode->next = nullptr;
        delete(nextNode);
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
                    