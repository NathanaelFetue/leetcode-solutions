/*
 * Problem #9 - Palindrome Number
 * Difficulty: Easy
 * URL: https://leetcode.com/problems/palindrome-number/
 *
 * Approach/Algorithm:
 * First, negative numbers are immediately rejected as non-palindromes.
 * The digits of the number are extracted one by one using modulo 10 and stored in a vector,
 * resulting in a reversed-order digit array. A two-pointer technique is then applied,
 * comparing digits from both ends moving inward to verify palindrome symmetry.
 *
 * Time Complexity: O(d) where d is the number of digits in x (log10(x)),
 * since we iterate through all digits once to extract and once to compare.
 *
 * Space Complexity: O(d) where d is the number of digits, due to the digit storage vector.
 *
 * Runtime: 12 ms
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
