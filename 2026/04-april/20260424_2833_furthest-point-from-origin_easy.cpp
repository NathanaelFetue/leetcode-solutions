/*
 * Problem #2833 - Furthest Point From Origin
 * Difficulty: Easy
 * URL: https://leetcode.com/problems/furthest-point-from-origin/
 *
 * Approach: Count occurrences of 'L', 'R', and '_' (underscore/wildcard) moves separately.
 * The net displacement from fixed moves is abs(R - L). Each wildcard '_' can be assigned
 * to whichever direction maximizes distance, so all wildcards are added directly to the result.
 *
 * Time Complexity: O(n) - single pass through the moves string of length n.
 * Space Complexity: O(1) - only three integer counters are used regardless of input size.
 *
 * Runtime: 0 ms
 * Memory: 9.3 MB
 */

class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        int L = 0, R = 0, U = 0;
        for (char c : moves) {
            if (c == 'L') L++;
            else if (c == 'R') R++;
            else U++;
        }
        return abs(R - L) + U;
    }
};
