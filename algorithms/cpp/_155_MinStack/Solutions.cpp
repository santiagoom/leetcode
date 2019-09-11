#include <iostream>
#include <vector>
#include <myutils.h>

using namespace std;

class Solution {
};

int main() {
    auto *so = new Solution();
    vector<int> nums{};
    delete so;
    return 0;
}
