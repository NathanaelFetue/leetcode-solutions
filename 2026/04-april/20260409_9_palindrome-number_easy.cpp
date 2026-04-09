/*
 * Problem #9 - Palindrome Number (Easy)
 * LeetCode URL: https://leetcode.com/problems/palindrome-number/
 *
 * Approach/Algorithm:
 * First, negative numbers are immediately rejected as non-palindromes.
 * The digits of the number are extracted one by one (least significant first) using
 * modulo 10 and stored in a vector, then a two-pointer technique compares digits
 * from both ends of the vector moving inward until the pointers meet.
 *
 * Time Complexity: O(d) where d is the number of digits in x (log10(x)).
 * Both the digit extraction loop and the two-pointer comparison run in O(d).
 *
 * Space Complexity: O(d) where d is the number of digits, due to the digits vector
 * storing each digit of the input number.
 *
 * Runtime: 16 ms | Memory: 12.3 MB
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
