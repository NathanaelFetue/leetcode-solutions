/*
 * Problem #2211: Count Collisions on a Road
 * Difficulty: Medium
 * URL: https://leetcode.com/problems/count-collisions-on-a-road/
 *
 * Approach/Algorithm:
 * Cars moving 'L' from the leftmost positions and 'R' from the rightmost positions
 * will never collide with anything, so we skip them using two pointers.
 * Within the remaining window [l, r], every car that is not already stopped ('S')
 * must eventually collide, contributing exactly one collision per such car.
 *
 * Time Complexity: O(n) — single left-to-right pass plus two pointer trims over the string of length n.
 * Space Complexity: O(1) — only a constant number of integer variables are used, no auxiliary data structures.
 *
 * Runtime: 10 ms
 * Memory: 19.2 MB
 */

class Solution {
public:
    int countCollisions(string directions) {
        int n = directions.size();
        int l = 0, r = n - 1;

        while (l < n && directions[l] == 'L') l++;

        while (r >= 0 && directions[r] == 'R') r--;

        int collisions = 0;
        for (int i = l; i <= r; i++)
            if (directions[i] != 'S') collisions++;

        return collisions;
    }
};
