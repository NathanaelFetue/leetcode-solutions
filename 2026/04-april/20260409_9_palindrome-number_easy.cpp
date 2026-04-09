/*
 * Problem #9 - Palindrome Number (Easy)
 * https://leetcode.com/problems/palindrome-number/
 *
 * Approach: Digit Extraction and Two-Pointer Comparison
 * First, negative numbers are immediately rejected as non-palindromes.
 * The digits of the number are extracted by repeatedly taking modulo 10 and stored in a vector,
 * then a two-pointer technique compares digits from both ends moving inward to verify symmetry.
 *
 * Time Complexity: O(d) where d is the number of digits in x (log10(x)),
 * since we iterate once to extract digits and once more to compare them.
 *
 * Space Complexity: O(d) where d is the number of digits in x,
 * due to the vector used to store the individual digits.
 *
 * Runtime: 27 ms
 * Memory: 12.3 MB
 */

class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) return false;
        vector <int> digits;
        int i =0;
        while(x>0) {
            digits.push_back(x%10);
            x /= 10;
        }
        int deb=digits.size() -1 , fin = 0;
        while((deb -fin) >0){
            if (digits[deb] != digits[fin]) return false;
            deb--;
            fin++;
        }
        return true;
    }
};
