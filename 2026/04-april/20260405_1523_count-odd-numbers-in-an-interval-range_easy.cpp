/*
 * Problem 1523: Count Odd Numbers in an Interval Range
 * Difficulty: Easy
 * URL: https://leetcode.com/problems/count-odd-numbers-in-an-interval-range/
 *
 * Approach/Algorithm:
 * Uses a mathematical formula to count odd numbers in [low, high].
 * The count of odd numbers from 1 to n is given by (n + 1) / 2 (integer division).
 * By subtracting the count of odds below low from the count up to high, we get the result.
 *
 * Formula: (high + 1) / 2 - low / 2
 * - (high + 1) / 2 counts odd numbers in [1, high]
 * - low / 2 counts odd numbers in [1, low - 1]
 *
 * Time Complexity: O(1) - single arithmetic computation, no loops or recursion.
 * Space Complexity: O(1) - no extra data structures used.
 *
 * Runtime: 3 ms | Memory: 7.9 MB
 */

class Solution {
public:
    int countOdds(int low, int high) {
        return (high + 1) / 2 - low / 2;
    }
};
