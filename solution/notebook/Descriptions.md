



## \4. Median of Two Sorted Arrays

Hard

199062274Add to ListShare

Given two sorted arrays `nums1` and `nums2` of size `m` and `n` respectively, return **the median** of the two sorted arrays.

The overall run time complexity should be `O(log (m+n))`.

 

**Example 1:**

```
Input: nums1 = [1,3], nums2 = [2]
Output: 2.00000
Explanation: merged array = [1,2,3] and median is 2.
```

**Example 2:**

```
Input: nums1 = [1,2], nums2 = [3,4]
Output: 2.50000
Explanation: merged array = [1,2,3,4] and median is (2 + 3) / 2 = 2.5.
```

 

**Constraints:**

- `nums1.length == m`
- `nums2.length == n`
- `0 <= m <= 1000`
- `0 <= n <= 1000`
- `1 <= m + n <= 2000`
- `-106 <= nums1[i], nums2[i] <= 106`

Accepted

1,614,035

Submissions

4,602,877

Seen this question in a real interview before?

Yes

No

Companies



Related Topics



Similar Questions



[Median of a Row Wise Sorted Matrix](https://leetcode.com/problems/median-of-a-row-wise-sorted-matrix/)

Medium

```

double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    int N1 = nums1.size();
    int N2 = nums2.size();
    if (N1 < N2) return findMedianSortedArrays(nums2, nums1);	// Make sure A2 is the shorter one.
    
    int lo = 0, hi = N2 * 2;
    while (lo <= hi) {
        int mid2 = (lo + hi) / 2;   // Try Cut 2 
        int mid1 = N1 + N2 - mid2;  // Calculate Cut 1 accordingly
        
        double L1 = (mid1 == 0) ? INT_MIN : nums1[(mid1-1)/2];	// Get L1, R1, L2, R2 respectively
        double L2 = (mid2 == 0) ? INT_MIN : nums2[(mid2-1)/2];
        double R1 = (mid1 == N1 * 2) ? INT_MAX : nums1[(mid1)/2];
        double R2 = (mid2 == N2 * 2) ? INT_MAX : nums2[(mid2)/2];
        
        if (L1 > R2) lo = mid2 + 1;		// A1's lower half is too big; need to move C1 left (C2 right)
        else if (L2 > R1) hi = mid2 - 1;	// A2's lower half too big; need to move C2 left.
        else return (max(L1,L2) + min(R1, R2)) / 2;	// Otherwise, that's the right cut.
    }
    return -1;
} 
```



```
class Solution {
public:
    int kth(int a[], int m, int b[], int n, int k) {
        if (m < n) return kth(b,n,a,m,k);
        if (n==0) return a[k-1];
        if (k==1) return min(a[0],b[0]);

        int j = min(n,k/2);
        int i = k-j;
        if (a[i-1] > b[j-1]) return kth(a,i,b+j,n-j,k-j);
        return kth(a+i,m-i,b,j,k-i);
    }

    double findMedianSortedArrays(int a[], int m, int b[], int n) {
        int k = (m+n)/2;
        int m1 = kth(a,m,b,n,k+1);
        if ((m+n)%2==0) {
            int m2 = kth(a,m,b,n,k);
            return ((double)m1+m2)/2.0;
        }
        return m1;
    }
};
```





## 6. Zigzag Conversion

Medium

44379779Add to ListShare

The string `"PAYPALISHIRING"` is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed font for better legibility)

```
P   A   H   N
A P L S I I G
Y   I   R
```

And then read line by line: `"PAHNAPLSIIGYIR"`

Write the code that will take a string and make this conversion given a number of rows:

```
string convert(string s, int numRows);
```

 

**Example 1:**

```
Input: s = "PAYPALISHIRING", numRows = 3
Output: "PAHNAPLSIIGYIR"
```

**Example 2:**

```
Input: s = "PAYPALISHIRING", numRows = 4
Output: "PINALSIGYAHRPI"
Explanation:
P     I    N
A   L S  I G
Y A   H R
P     I
```

**Example 3:**

```
Input: s = "A", numRows = 1
Output: "A"
```

 

**Constraints:**

- `1 <= s.length <= 1000`
- `s` consists of English letters (lower-case and upper-case), `','` and `'.'`.
- `1 <= numRows <= 1000`

Accepted

857,601

Submissions

2,000,768

Seen this question in a real interview before?

Yes

No

Companies



0 ~ 6 months6 months ~ 1 year1 year ~ 2 years

[Amazon|7](https://leetcode.com/company/amazon)[Apple|3](https://leetcode.com/company/apple)[Yahoo|3](https://leetcode.com/company/yahoo)[Adobe|2](https://leetcode.com/company/adobe)[Google|2](https://leetcode.com/company/google)

Related Topics



[String](https://leetcode.com/tag/string/)



### Approach 1: Sort by Row

```
class Solution {
public:
    string convert(string s, int numRows) {

        if (numRows == 1) return s;

        vector<string> rows(min(numRows, int(s.size())));
        int curRow = 0;
        bool goingDown = false;

        for (char c : s) {
            rows[curRow] += c;
            if (curRow == 0 || curRow == numRows - 1) goingDown = !goingDown;
            curRow += goingDown ? 1 : -1;
        }

        string ret;
        for (string row : rows) ret += row;
        return ret;
    }
};
```

#### Approach 2: Visit by Row

```
class Solution {
public:
    string convert(string s, int numRows) {

        if (numRows == 1) return s;

        string ret;
        int n = s.size();
        int cycleLen = 2 * numRows - 2;

        for (int i = 0; i < numRows; i++) {
            for (int j = 0; j + i < n; j += cycleLen) {
                ret += s[j + i];
                if (i != 0 && i != numRows - 1 && j + cycleLen - i < n)
                    ret += s[j + cycleLen - i];
            }
        }
        return ret;
    }
};
```



## \9. Palindrome Number

Easy

74122316Add to ListShare

Given an integer `x`, return `true` if `x` is palindrome integer.

An integer is a **palindrome** when it reads the same backward as forward.

- For example, `121` is a palindrome while `123` is not.

 

**Example 1:**

```
Input: x = 121
Output: true
Explanation: 121 reads as 121 from left to right and from right to left.
```

**Example 2:**

```
Input: x = -121
Output: false
Explanation: From left to right, it reads -121. From right to left, it becomes 121-. Therefore it is not a palindrome.
```

**Example 3:**

```
Input: x = 10
Output: false
Explanation: Reads 01 from right to left. Therefore it is not a palindrome.
```

 

**Constraints:**

- `-231 <= x <= 231 - 1`

 

**Follow up:** Could you solve it without converting the integer to a string?

Accepted

2,525,020

Submissions

4,783,379

Seen this question in a real interview before?

Yes

No

Companies



Related Topics



[Math](https://leetcode.com/tag/math/)

Similar Questions



[Palindrome Linked List](https://leetcode.com/problems/palindrome-linked-list/)

Easy

[Find Palindrome With Fixed Length](https://leetcode.com/problems/find-palindrome-with-fixed-length/)

Medium

[Strictly Palindromic Number](https://leetcode.com/problems/strictly-palindromic-number/)

Medium

Hide Hint 1



Beware of overflow when you reverse the integer.





```c#
public class Solution {
    public bool IsPalindrome(int x) {
        // Special cases:
        // As discussed above, when x < 0, x is not a palindrome.
        // Also if the last digit of the number is 0, in order to be a palindrome,
        // the first digit of the number also needs to be 0.
        // Only 0 satisfy this property.
        if(x < 0 || (x % 10 == 0 && x != 0)) {
            return false;
        }

        int revertedNumber = 0;
        while(x > revertedNumber) {
            revertedNumber = revertedNumber * 10 + x % 10;
            x /= 10;
        }

        // When the length is an odd number, we can get rid of the middle digit by revertedNumber/10
        // For example when the input is 12321, at the end of the while loop we get x = 12, revertedNumber = 123,
        // since the middle digit doesn't matter in palidrome(it will always equal to itself), we can simply get rid of it.
        return x == revertedNumber || x == revertedNumber/10;
    }
}
```





## \10. Regular Expression Matching

Hard

93411479Add to ListShare

Given an input string `s` and a pattern `p`, implement regular expression matching with support for `'.'` and `'*'` where:

- `'.'` Matches any single character.
- `'*'` Matches zero or more of the preceding element.

The matching should cover the **entire** input string (not partial).

 

**Example 1:**

```
Input: s = "aa", p = "a"
Output: false
Explanation: "a" does not match the entire string "aa".
```

**Example 2:**

```
Input: s = "aa", p = "a*"
Output: true
Explanation: '*' means zero or more of the preceding element, 'a'. Therefore, by repeating 'a' once, it becomes "aa".
```

**Example 3:**

```
Input: s = "ab", p = ".*"
Output: true
Explanation: ".*" means "zero or more (*) of any character (.)".
```

 

**Constraints:**

- `1 <= s.length <= 20`
- `1 <= p.length <= 30`
- `s` contains only lowercase English letters.
- `p` contains only lowercase English letters, `'.'`, and `'*'`.
- It is guaranteed for each appearance of the character `'*'`, there will be a previous valid character to match.

Accepted

744,954

Submissions

2,636,854

Seen this question in a real interview before?

Yes

No

Companies



Related Topics



Similar Questions



[Wildcard Matching](https://leetcode.com/problems/wildcard-matching/)

Hard





```
class Solution(object):
    def isMatch(self, text, pattern):
        if not pattern:
            return not text

        first_match = bool(text) and pattern[0] in {text[0], '.'}

        if len(pattern) >= 2 and pattern[1] == '*':
            return (self.isMatch(text, pattern[2:]) or
                    first_match and self.isMatch(text[1:], pattern))
        else:
            return first_match and self.isMatch(text[1:], pattern[1:])
```





```
class Solution(object):
    def isMatch(self, text, pattern):
        memo = {}
        def dp(i, j):
            if (i, j) not in memo:
                if j == len(pattern):
                    ans = i == len(text)
                else:
                    first_match = i < len(text) and pattern[j] in {text[i], '.'}
                    if j+1 < len(pattern) and pattern[j+1] == '*':
                        ans = dp(i, j+2) or first_match and dp(i+1, j)
                    else:
                        ans = first_match and dp(i+1, j+1)

                memo[i, j] = ans
            return memo[i, j]

        return dp(0, 0)
```



```
class Solution(object):
    def isMatch(self, text, pattern):
        dp = [[False] * (len(pattern) + 1) for _ in range(len(text) + 1)]

        dp[-1][-1] = True
        for i in range(len(text), -1, -1):
            for j in range(len(pattern) - 1, -1, -1):
                first_match = i < len(text) and pattern[j] in {text[i], '.'}
                if j+1 < len(pattern) and pattern[j+1] == '*':
                    dp[i][j] = dp[i][j+2] or first_match and dp[i+1][j]
                else:
                    dp[i][j] = first_match and dp[i+1][j+1]

        return dp[0][0]
```



## \12. Integer to Roman

```
class Solution:
    def intToRoman(self, num: int) -> str:
        digits = [(1000, "M"), (900, "CM"), (500, "D"), (400, "CD"), (100, "C"), 
                  (90, "XC"), (50, "L"), (40, "XL"), (10, "X"), (9, "IX"), 
                  (5, "V"), (4, "IV"), (1, "I")]
        
        roman_digits = []
        # Loop through each symbol.
        for value, symbol in digits:
            # We don't want to continue looping if we're done.
            if num == 0: break
            count, num = divmod(num, value)
            # Append "count" copies of "symbol" to roman_digits.
            roman_digits.append(symbol * count)
        return "".join(roman_digits)
```





```
class Solution:
    def intToRoman(self, num: int) -> str:
        thousands = ["", "M", "MM", "MMM"]
        hundreds = ["", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"]
        tens = ["", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"]
        ones = ["", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"]
        return (thousands[num // 1000] + hundreds[num % 1000 // 100] 
               + tens[num % 100 // 10] + ones[num % 10])
```







## \24. Swap Nodes in Pairs



```
# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None


class Solution(object):
    def swapPairs(self, head: ListNode) -> ListNode:
        """
        :type head: ListNode
        :rtype: ListNode
        """

        # If the list has no node or has only one node left.
        if not head or not head.next:
            return head

        # Nodes to be swapped
        first_node = head
        second_node = head.next

        # Swapping
        first_node.next  = self.swapPairs(second_node.next)
        second_node.next = first_node

        # Now the head is the second node
        return second_node
```





```
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def swapPairs(self, head: ListNode) -> ListNode:
        """
        :type head: ListNode
        :rtype: ListNode
        """
        # Dummy node acts as the prevNode for the head node
        # of the list and hence stores pointer to the head node.
        dummy = ListNode(-1)
        dummy.next = head

        prev_node = dummy

        while head and head.next:

            # Nodes to be swapped
            first_node = head;
            second_node = head.next;

            # Swapping
            prev_node.next = second_node
            first_node.next = second_node.next
            second_node.next = first_node

            # Reinitializing the head and prev_node for next swap
            prev_node = first_node
            head = first_node.next

        # Return the new head node.
        return dummy.next
```





## \25. Reverse Nodes in k-Group





```
class Solution:
    
    def reverseLinkedList(self, head, k):
        
        # Reverse k nodes of the given linked list.
        # This function assumes that the list contains 
        # atleast k nodes.
        new_head, ptr = None, head
        while k:
            
            # Keep track of the next node to process in the
            # original list
            next_node = ptr.next
            
            # Insert the node pointed to by "ptr"
            # at the beginning of the reversed list
            ptr.next = new_head
            new_head = ptr
            
            # Move on to the next node
            ptr = next_node
            
            # Decrement the count of nodes to be reversed by 1
            k -= 1
        
        # Return the head of the reversed list
        return new_head
                
    
    def reverseKGroup(self, head: ListNode, k: int) -> ListNode:
        
        count = 0
        ptr = head
        
        # First, see if there are atleast k nodes
        # left in the linked list.
        while count < k and ptr:
            ptr = ptr.next
            count += 1
        
        # If we have k nodes, then we reverse them
        if count == k: 
            
            # Reverse the first k nodes of the list and
            # get the reversed list's head.
            reversedHead = self.reverseLinkedList(head, k)
            
            # Now recurse on the remaining linked list. Since
            # our recursion returns the head of the overall processed
            # list, we use that and the "original" head of the "k" nodes
            # to re-wire the connections.
            head.next = self.reverseKGroup(ptr, k)
            return reversedHead
        return head
```





```
class Solution:
    
    def reverseLinkedList(self, head, k):
        
        # Reverse k nodes of the given linked list.
        # This function assumes that the list contains 
        # atleast k nodes.
        new_head, ptr = None, head
        while k:
            
            # Keep track of the next node to process in the
            # original list
            next_node = ptr.next
            
            # Insert the node pointed to by "ptr"
            # at the beginning of the reversed list
            ptr.next = new_head
            new_head = ptr
            
            # Move on to the next node
            ptr = next_node
            
            # Decrement the count of nodes to be reversed by 1
            k -= 1
        
        # Return the head of the reversed list
        return new_head
                
    
    def reverseKGroup(self, head: ListNode, k: int) -> ListNode:
        
        ptr = head
        ktail = None
        
        # Head of the final, moified linked list
        new_head = None
        
        # Keep going until there are nodes in the list
        while ptr:
            count = 0
            
            # Start counting nodes from the head
            ptr = head
            
            # Find the head of the next k nodes
            while count < k and ptr:
                ptr = ptr.next
                count += 1

            # If we counted k nodes, reverse them        
            if count == k:
                
                # Reverse k nodes and get the new head
                revHead = self.reverseLinkedList(head, k)
                
                # new_head is the head of the final linked list
                if not new_head:
                    new_head = revHead
                
                # ktail is the tail of the previous block of 
                # reversed k nodes
                if ktail:
                    ktail.next = revHead
                    
                ktail = head 
                head = ptr
        
        # attach the final, possibly un-reversed portion
        if ktail:
            ktail.next = head
        
        return new_head if new_head else head
```

