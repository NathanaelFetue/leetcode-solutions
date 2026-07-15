/*
 * Problem #3658 - GCD of Odd and Even Sums
 * Difficulty: Easy
 * URL: https://leetcode.com/problems/gcd-of-odd-and-even-sums/
 *
 * Approach: Mathematical Observation
 * The sum of odd-indexed elements and even-indexed elements in the array [1..n]
 * both equal n, so the GCD of two equal values is simply n itself.
 * This reduces the problem to a single call to std::gcd(n, n) which returns n.
 *
 * Time Complexity: O(log n) - due to the GCD computation via Euclidean algorithm,
 * though in practice gcd(n, n) = n is trivially resolved in one step.
 * Space Complexity: O(1) - only a constant amount of extra space is used.
 *
 * Runtime: 0 ms | Memory: 8.4 MB
 */

class Solution {
public:
    int gcdOfOddEvenSums(int n) {
        return gcd(n , n);
    }
};
