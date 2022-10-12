
#include <iostream>
#include <cppUtils.h>

using namespace std;

                    
class Solution {
public:
    string multiply(string num1, string num2) {
        if (num1 == "0" || num2 == "0") {
            return "0";
        }
        
        // Reverse num1 and num2.
        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());
        
        // Initialize answer as a string of zeros of length N.
        int N = num1.size() + num2.size();
        string answer(N, '0');
        
        for (int place2 = 0; place2 < num2.size(); place2++) {
            int digit2 = num2[place2] - '0';
            
            // For each digit in num2 multiply the digit by all digits in num1.
            for (int place1 = 0; place1 < num1.size(); place1++) {
                int digit1 = num1[place1] - '0';
                
                // The number of zeros from multiplying to digits depends on the 
                // place of digit2 in num2 and the place of the digit1 in num1.
                int numZeros = place1 + place2;
                
                // The digit currently at position numZeros in the answer string
                // is carried over and summed with the current result.
                int carry = answer[numZeros] - '0';
                int multiplication = digit1 * digit2 + carry;
                
                // Set the ones place of the multiplication result.
                answer[numZeros] = (multiplication % 10) + '0';
                
                // Carry the tens place of the multiplication result by 
                // adding it to the next position in the answer array.
                answer[numZeros + 1] += (multiplication / 10);
            }
        }
        
        if (answer.back() == '0') {
            answer.pop_back();
        }
        reverse(answer.begin(), answer.end());
        return answer;
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
                    