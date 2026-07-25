/*
 * Problem #3536: Maximum Product of Two Digits
 * Difficulty: Easy
 * URL: https://leetcode.com/problems/maximum-product-of-two-digits/
 *
 * Approach: Extract all digits of the integer by repeatedly taking the remainder
 * when divided by 10 and appending to a vector. Sort the digits in descending
 * order and return the product of the two largest digits.
 *
 * Time Complexity: O(d log d) where d is the number of digits in n (at most 10),
 * making it effectively O(1) since d is bounded by a constant.
 *
 * Space Complexity: O(d) for storing the digits vector, also effectively O(1)
 * since the number of digits is bounded by a constant.
 *
 * Runtime: 2 ms
 * Memory: 9.1 MB
 */

class Solution {
public:
    int maxProduct(int n) {
        vector<int> digits;
        while(n>0){
            digits.push_back(n%10);
            n = n/10;
        }
        sort(digits.begin(), digits.end() , greater<int>());

        return digits[0]*digits[1];
    }
};
