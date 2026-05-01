/*
 * Problem #1952 - Three Divisors
 * Difficulty: Easy
 * URL: https://leetcode.com/problems/three-divisors/
 *
 * Approach/Algorithm:
 * Count the total number of divisors of n using trial division up to sqrt(n).
 * For each i that divides n, count both i and n/i as divisors (if they differ).
 * Return true if and only if the total divisor count equals exactly 3.
 *
 * Time Complexity: O(sqrt(n)) - iterates from 1 to sqrt(n) to find all divisors.
 * Space Complexity: O(1) - only a constant amount of extra space is used.
 *
 * Runtime: 0 ms
 * Memory: 7.6 MB
 */

class Solution {
public:
    int countDivisors(int n) {
        int count = 0;
        for (int i = 1; i * i <= n; i++) {
            if (n % i == 0) {
                count++;
                if (i != n / i) count++;
            }
        }
        return count;
    }
    bool isThree(int n) {
        return countDivisors(n) == 3 ;
    }
};
