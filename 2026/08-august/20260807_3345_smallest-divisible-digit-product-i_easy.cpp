/*
 * Problem 3345: Smallest Divisible Digit Product I (Easy)
 * https://leetcode.com/problems/smallest-divisible-digit-product-i/
 *
 * Approach: Linear search with digit product validation.
 * Starting from n, increment until we find a number whose digit product is divisible by t.
 * For each candidate, compute the product of all digits; if any digit is 0 the product short-circuits to 0.
 *
 * Time Complexity: O(k * d) where k is the number of increments needed to find a valid number
 * and d is the number of digits in each candidate (at most ~10 for 32-bit integers).
 * In practice k is very small since we are looking for the next valid number near n.
 *
 * Space Complexity: O(1) - only a constant amount of extra space is used.
 *
 * Runtime: 0 ms
 * Memory: 8.7 MB
 */

class Solution {
public:
    int smallestNumber(int n, int t) {
        auto check = [&](int num) -> bool {
            int product = 1;
            while (num) {
                product *= (num % 10);
                num /= 10;
                if (!product) {
                    break;
                }
            }
            return !(product % t);
        };
        while (!check(n)) {
            n++;
        }
        return n;
    }
};
