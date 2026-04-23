/*
 * Problem #67 - Add Binary
 * Difficulty: Easy
 * URL: https://leetcode.com/problems/add-binary/
 *
 * Approach/Algorithm:
 * Simulates binary addition digit-by-digit from the least significant bit (right to left)
 * using two pointers, one for each string. At each step, the sum of the two current bits
 * and the carry is computed; the remainder mod 2 becomes the result bit and the quotient
 * becomes the new carry. The loop continues until both strings are exhausted and carry is 0.
 *
 * Time Complexity: O(max(n, m)) where n and m are the lengths of strings a and b,
 * since every digit in both strings is visited exactly once.
 *
 * Space Complexity: O(max(n, m)) for the result string which holds at most max(n, m) + 1 digits.
 *
 * Runtime: 3 ms
 * Memory: 11.1 MB
 */

class Solution {
public:
    string addBinary(string a, string b) {
        string res = "";
        int i = a.size()-1, j = b.size()-1, carry = 0;
        
        while (i >= 0 || j >= 0 || carry) {
            int sum = carry;
            if (i >= 0) sum += a[i--] - '0';
            if (j >= 0) sum += b[j--] - '0';
            carry = sum / 2;
            res = (char)('0' + sum % 2) + res;
        }
        return res;
    }
};
