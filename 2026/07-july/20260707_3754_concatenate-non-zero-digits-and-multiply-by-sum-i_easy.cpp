/*
 * Problem 3754: Concatenate Non-Zero Digits and Multiply by Sum I
 * Difficulty: Easy
 * URL: https://leetcode.com/problems/concatenate-non-zero-digits-and-multiply-by-sum-i/
 *
 * Approach: Convert the integer to a string and iterate through each digit.
 * For every non-zero digit, accumulate it into a sum and append it to a result string.
 * Finally, multiply the concatenated non-zero digits (parsed back to an integer) by their sum.
 *
 * Time Complexity: O(d) where d is the number of digits in n (at most 10 for a 32-bit int).
 * Space Complexity: O(d) for storing the string representation and the concatenated value string.
 *
 * Runtime: 0 ms
 * Memory: 9.3 MB
 */

class Solution {
public:
    long long sumAndMultiply(int n) {
        string s = to_string(n) , val = "";
        int sum =0;
        for(int i=0; i< s.length(); i++){
            if(s[i] - '0' != 0){
                sum += s[i] - '0';
                val += s[i];
            }
        }
        return (val != "") ? 1LL*stoi(val)*sum: 0;
    }
};
