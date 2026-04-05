/*
 * Problem #1523 - Count Odd Numbers in an Interval Range
 * Difficulty: Easy
 * URL: https://leetcode.com/problems/count-odd-numbers-in-an-interval-range/
 *
 * Approach/Algorithm:
 * Uses a mathematical formula to count odd numbers in [low, high] in O(1).
 * The count of odd numbers from 1 to n is given by (n + 1) / 2 (integer division).
 * Subtracting the count up to (low - 1) from the count up to high gives the answer:
 *   countOdds(low, high) = (high + 1) / 2 - low / 2
 *
 * Time Complexity: O(1) - single arithmetic expression, no loops or recursion.
 * Space Complexity: O(1) - no additional data structures used.
 *
 * Runtime: 0 ms
 * Memory: 7.9 MB
 */

class Solution {
public:
    int countOdds(int low, int high) {
        return (high + 1) / 2 - low / 2;
    }
};
