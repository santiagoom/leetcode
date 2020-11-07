#include <iostream>
#include <vector>
#include <myVector.h>
#include <myutils.h>

using namespace std;

class Solution {

};

int main() {
    auto *so = new Solution();
    cout << "new file!" << endl;
    print(5);
    delete so;
    return 0;
}
