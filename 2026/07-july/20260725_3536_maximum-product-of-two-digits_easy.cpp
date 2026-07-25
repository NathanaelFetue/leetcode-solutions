/*
 * Problem #3536 - Maximum Product of Two Digits
 * Difficulty: Easy
 * URL: https://leetcode.com/problems/maximum-product-of-two-digits/
 *
 * Approach/Algorithm:
 * Extract each digit of the number by repeatedly taking modulo 10 and dividing by 10.
 * Track the two largest digits seen so far using two variables (first and second).
 * Return the product of these two largest digits.
 *
 * Time Complexity: O(d) where d is the number of digits in n (at most 10 for a 32-bit integer), effectively O(1).
 * Space Complexity: O(1) — only a constant number of variables are used regardless of input size.
 *
 * Runtime: 0 ms
 * Memory: 8.5 MB
 */

class Solution {
public:
    int maxProduct(int n) {
        int first=0, second=0;
        while(n>0){
            int x = n%10;
            if(x > first){
                second = first;
                first = x;
            } else if (x > second) second = x;
            n = n/10;
        }
        return first*second;
    }
};
