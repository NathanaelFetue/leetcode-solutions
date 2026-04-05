/*
 * Problem #1523: Count Odd Numbers in an Interval Range
 * Difficulty: Easy
 * URL: https://leetcode.com/problems/count-odd-numbers-in-an-interval-range/
 *
 * Approach/Algorithm:
 * Uses a mathematical formula based on the observation that the count of odd numbers
 * from 1 to n equals ceil(n/2), which is computed as (n+1)/2 using integer division.
 * The count of odds in [low, high] is derived by subtracting odds in [1, low-1] from
 * odds in [1, high], simplified to (high+1)/2 - low/2.
 *
 * Time Complexity: O(1) - constant time arithmetic operations only.
 * Space Complexity: O(1) - no additional data structures used.
 *
 * Runtime: 3 ms
 * Memory: 7.7 MB
 */

class Solution {
public:
    int countOdds(int low, int high) {
        return (high + 1) / 2 - low / 2;
    }
};
