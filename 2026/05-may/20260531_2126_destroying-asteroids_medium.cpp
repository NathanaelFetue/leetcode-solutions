/*
 * Problem 2126 - Destroying Asteroids (Medium)
 * https://leetcode.com/problems/destroying-asteroids/
 *
 * Approach: Greedy with sorting.
 * Sort the asteroids in ascending order, then greedily absorb each asteroid if the current
 * mass is greater than or equal to it. After absorbing, accumulate the asteroid's mass.
 * If at any point the current mass is less than the next asteroid, destruction is impossible.
 *
 * Time Complexity: O(n log n) - dominated by sorting the asteroids array of size n.
 * Space Complexity: O(1) - only a single long long variable is used for tracking mass.
 *
 * Runtime: 23 ms
 * Memory: 106.6 MB
 */

class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        sort(asteroids.begin(), asteroids.end());

        long long m = mass;
        for (int a : asteroids) {
            if (m < a) return false;
            m += a;
        }
        return true;
    }
};
