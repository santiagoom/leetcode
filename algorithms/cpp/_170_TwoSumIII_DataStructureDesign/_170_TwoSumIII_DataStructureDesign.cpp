
#include <iostream>
#include <unordered_set>

using namespace std;


int main() {
    cout << "new file!" << endl;
    return 0;
}

class TwoSum_1 {
    unordered_multiset<int> nums;
public:

    // Add the number to an internal data structure.
    void add(int number) {
        // Write your code here
        nums.insert(number);
    }

    // Find if there exists any pair of numbers which sum is equal to the value.
    bool find(int value) {
        // Write your code here
        for (int i : nums) {
            int count = i == value - i ? 2 : 1;
            if (nums.count(value - i) >= count) {
                return true;
            }
        }
        return false;
    }
};

class TwoSum_2 {
public:
    unordered_multiset<int> nums;

    // Add the number to an internal data structure.
    void add(int number) {
        // Write your code here
        nums.insert(number);
    }

    // Find if there exists any pair of numbers which sum is equal to the value.
    bool find(int value) {
        // Write your code here
        for (int i:nums) {
            int count = i == value - i ? 2 : 1;
            if (nums.count(value - i) >= count) {
                return true;
            }
        }
        return false;
    }
};